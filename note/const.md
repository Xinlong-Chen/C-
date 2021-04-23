#### const限定符

const修饰的变量，它的值不能被改变。只能执行不改变其内容的操作。const修饰的变量一样能进行算数运算等操作。

```cpp
const int bufSize = 512;
```

如果对其进行修改，则会引发错误。

```cpp
bufSize = 1024; //error
```

* const对象必须初始化

* const修饰不具有传递性

  ```cpp
  const int j = get_size();  //correct
  const int j = 42;          //correct
  const int k;   // error
  
  int i = 1024;
  const int ci = i; //correct
  int j = ci;       //correct
  ```

* 默认状态下，const对象仅在文件内有效

编译时，编译器将变量替换成对应的值（类似于define），因为const对象仅在文件内有效，如果要让其他文件访问到，需要添加extern关键字。

```cpp
//file1.cc 定义并初始化一个常量，它可以被其他文件访问
extern const int bufSize = fcn();
//file1.h 头文件
extern const int bufSize; // 与file1.cc的相同
```

---

对常量的引用（***reference to const***）：把引用绑定到const对象上。对常量的引用不可以修改它所绑定的对象。

```cpp
const int ci =1024;
const int &r1 = ci; //correct
r1 = 41; //error
int &r2 = ci; //correct,r2非常量引用
```

对const的引用的初始化：

* 初始化常量引用可以用任何表达式作为初始值

```cpp
int i = 42;
const int &r1 = i;  //correct
const int &r2 = r1*2; //correct
int &r3 = r1*2; //error，结合下文，error原因为绑定的为一个临时量对象，
```

解释：

假设有如下代码：

```cpp
double dval = 3.14;
const int &ri = dval;
```

dval为双精度浮点数，为了确保让ri绑定上一个整数，编译器将上述代码变成如下形式：

```cpp
const int temp = dval;  //由浮点数生产一个临时的整形变量
const int &ri = temp;
```

ri绑定了一个临时量对象。这个临时量对象是当编译器需要一个空间来暂存表达式的求值结果时临时创建的一个未命名的对象。

* 对const的引用可能引用一个并非const的对象

```cpp
int i = 42;
int &r1 = i;
const int &r2 = i;
r1 = 0; //correct
r2 = 0; //error
```

---

指向常量的指针（***pointer to const***）

要想存放常量对象的地址，必须使用指向常量的指针。

```cpp
const double pi = 3.14;
double *ptr = &pi;  //error
const double *cptr = &pi; //correct
*cptr = 1; //error
```

**对象的值能不能改变，还得看自身是不是const，引用和指针的const是保证自己不去改变变量的值。**

---

const指针：指针是一个对象，因此可以将指针定义为const。

常量指针（const pointer）必须初始化，一旦初始化完成，他的值（指向的地址）就不能改变。

*放const之前，说明指针是一个常量（另一层意思：指针本身的值不变，指向的值可以变）

```cpp
int errNum = 0;
int *const curErr = &errNum; //curErr一直指向errNum
const double pi = 3.14;
const double *const pop = &pi; // pop是一个指向常量对象的常量指针
//阅读方法：从右往左读
```

---

顶层const

顶层const：指针本身是个常量（靠近变量）

底层const：指针所指对象是一个常量

