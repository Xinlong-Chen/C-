//
// Created by 陈鑫龙 on 2021/4/24.
//

#include <iostream>
using namespace std;

/*
===> inline内联函数 和 普通函数的区别？？？
inline内联函数：在编译过程中，就没有函数的调用开销了，在函数的调用点直接
把函数的代码进行展开处理了

inline函数不再生成相应的函数符号

inline只是建议编译器把这个函数处理成内联函数
但是不是所有的inline都会被编译器处理成内联函数  -  递归

debug版本上，inline是不起作用的； inline只有在release版本下才能出现
目的：为了代码调试
 g++ -c main.cpp -O2
 objdump -t main.o
*/

/**
不使用inline的时候 标准的函数调用过程:
 1.(从右向左)参数压栈
 2.函数栈帧的开辟
 3.回退过程(ret)
有函数调用的开销
x+y  mov add mov     1000000 x+y
 */

inline int sum(int x, int y)  // *.o   sum_int_int  .text
{
    return x + y;
}
int main()
{
    int a = 10;
    int b = 20;

    int ret = sum(a, b);
    cout << ret << endl
    return 0;
}
