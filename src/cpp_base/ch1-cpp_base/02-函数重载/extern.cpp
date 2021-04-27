//
// Created by 陈鑫龙 on 2021/4/24.
//

#include <iostream>

using namespace std;

// C++ 调用 C函数
// C++代码中，按照C语言规则生成符号
extern "C" {
    int sum(int a, int b);
}
// C 调用 C++函数
// C++代码中使用extern C，C中没有extern
//extern "C" {
//    int sum(int a, int b) {
//        return a + b;
//    }
//}
int main() {
    int ans = sum(10, 20);
    cout << ans << endl;
}