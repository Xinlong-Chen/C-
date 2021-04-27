//
// Created by 陈鑫龙 on 2021/4/24.
//

#include <iostream>

using namespace std;

/*
===>形参带默认值的函数
1.给默认值的时候，从右向左给
 （放前边调用为sum(, 20);，不符合语法）
2.调用效率的问题
 （调用函数是在构造栈帧，有默认值就是直接是立即数，少一条mov指令）
3.定义出可以给形参默认值，声明也可以给形参默认值
4.形参给默认值的时候，不管是定义处给，还是声明处给，形参默认值只能出现一次
*/
int sum(int a, int b = 20);
int sum(int a = 10, int b);
int main()
{
    int a = 10;
    int b = 20;

    int ret = sum(a, b);
    /*
    mov eax, dword ptr[ebp-8]
    push eax

    push 28H
    mov ecx, dword ptr[ebp-4]
    push ecx
    call sum
    */
    cout << "ret:" << ret << endl;

    /*
    push 14H
    mov ecx, dword ptr[ebp-4]
    push ecx
    call sum
    */
    ret = sum(a);

    /*
    push 14H
    push 0Ah
    call sum
    */
    ret = sum(); // sum(20, 50);

    return 0;
}

int sum(int a, int b)
{
    return a + b;
}