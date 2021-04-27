//
// Created by 陈鑫龙 on 2021/4/24.
//

#include <iostream>

using namespace std;

/*
函数重载
1.C++为什么支持函数重载，C语言不支持函数重载？
C++代码产生函数符号的时候，函数名+参数列表类型组成的！
C代码产生函数符号的时候，函数名来决定！

2.函数重载需要注意些什么？
3.C++和C语言代码之间如何互相调用

函数重载
1.一组函数，其中函数名相同，参数列表的个数或者类型不同，那么这一组函数
就称作-函数重载。
2.一组函数要称得上重载，一定先是处在同一个作用域当中的。
3.const或者volatile的时候，是怎么影响形参类型的。（int 和const int编译器认为是一样的）
4.一组函数，函数名相同，参数列表也相同，仅仅是返回值不同？不叫重载


C 调用 C++:无法直接调用了！怎么办？ 把C++源码扩在extern "C"
C++ 调用 C代码:无法直接调用了！怎么办？ 把C函数的声明扩在extern "C"里面
*/
//__FILE__
//__LINE__
// 只要是C++编译器，都内置了__cplusplus这个宏名

bool compare(int a, int b) // compare_int_int
{
    cout << "compare_int_int" << endl;
    return a > b;
}
bool compare(double a, double b) // compare_double_double
{
    cout << "compare_double_double" << endl;
    return a > b;
}
bool compare(const char *a, const char *b) // compare_const char*_const char*
{
    cout << "compare_char*_char*" << endl;
    return strcmp(a, b) > 0;
}

int main()
{
    // main中再次声明
    bool compare(int a, int b); // 函数的声明

    compare(10, 20); // call compare_int_int
    compare(10.0, 20.0); // double -> int
    // 使用compare报错！作用域不同！需要使用::compare，这里类似于全局变量和局部变量
    ::compare("aaa", "bbb"); // const char* => int

    return 0;
}