//
// Created by 陈鑫龙 on 2021/4/25.
//

#include <stdio.h>

/*
    C中：
    const修饰的量，可以不用初始化
    C中const不叫常量，是常变量
*/
int main()
{
    const int b;
    const int a = 20;
    //int array[a] = {};

    int *p = (int*)&a;
    *p = 30;

    // 30 30 30
    printf("%d %d %d \n", a, *p, *(&a));
}