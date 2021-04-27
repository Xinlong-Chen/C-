//
// Created by 陈鑫龙 on 2021/4/25.
//

#include <iostream>

using namespace std;

/*
const  指针   引用   在函数当中的引用
const怎么理解？
const修饰的变量不能够再作为左值！！！初始化完成后，值不能被修改！！！

C和C++中const的区别是什么？
C++一定要初始化，C可以不初始化
const的编译方式不同，C中，const就是当作一个变量来编译生成指令的。
C++中，所有出现const常量名字的地方，都被常量的初始化替换了！！！

c++的const
必须初始化的，叫常量
叫常变量   因为初始值不是立即数，是一个变量
*/

int main()
{
    int b = 20;
    const int a = b;  // 已经改了！！！
//    int array[a] = {};

    int *p = (int*)&a;
    *p = 30;

    printf("%d %d %d \n", a, *p, *(&a));

    return 0;
}

