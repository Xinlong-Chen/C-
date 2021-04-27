//
// Created by 陈鑫龙 on 2021/4/26.
//

#ifndef CPP_LEARN_Complex_H
#define CPP_LEARN_Complex_H

class complex;

complex &
__doapl(complex *ths, const complex &r);

complex &
__doami(complex *ths, const complex &r);

complex &
__doaml(complex *ths, const complex &r);


class complex {
// 访问级别，一个class对外部的可见性
public:
    // :后内容为初始化，如果写在{ }里就叫赋值
    // C++规定，对象的成员变量的初始化动作发生在进入构造函数本体之前。
    complex(double r = 0, double i = 0) : re(r), im(i) {}

    // 形参加const代表函数不会改变之内容
    complex &operator+=(const complex &);
    complex &operator-=(const complex &);
    // 其实类里边的函数暗含了一个this指针，类似于Python的self，C++中不显示的写
    // 实际调用应为 complex::operator*=(complex* this, const complex& r)
    complex &operator*=(const complex &);
    // 参数传递，pass by value 和 pass by reference
    // 复杂对象pass by reference效率更高，简单对象(int)更推荐pass by value
    complex &operator/=(const complex &);

    // class body内定义，编译器优先将其编译为inline
    double real() const { return re; }
    // const member functions 常量成员函数
    // 常量对象只能调用它的常量成员函数，而不能调用普通成员函数
    // 普通对象既可以调用常量成员函数，也可以调用普通成员函数
    double imag() const { return im; }

private:
    double re, im;
    // 友元函数，可自由取得friend的private成员
    friend complex &__doapl(complex *, const complex &);
    // 相同class的各个objects互为friends, 可以直接访问friends的私有成员
    friend complex &__doami(complex *, const complex &);
    friend complex &__doaml(complex *, const complex &);
};


inline complex &
__doapl(complex *ths, const complex &r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex &
complex::operator+=(const complex &r) {
    return __doapl(this, r);
}

inline complex &
__doami(complex *ths, const complex &r) {
    ths->re -= r.re;
    ths->im -= r.im;
    return *ths;
}

inline complex &
complex::operator-=(const complex &r) {
    return __doami(this, r);
}

inline complex &
__doaml(complex *ths, const complex &r) {
    double f = ths->re * r.re - ths->im * r.im;
    ths->im = ths->re * r.im + ths->im * r.re;
    ths->re = f;
    return *ths;
}

inline complex &
complex::operator*=(const complex &r) {
    return __doaml(this, r);
}

inline double
imag(const complex &x) {
    return x.imag();
}

inline double
real(const complex &x) {
    return x.real();
}

// 该设计中+操作支持复数加一个double类型的，也支持double加复数
// 放入class中，则固定了第一个参数为this，不能支持double加复数
// 参数不同，三个operator+构成重载
inline complex
operator+(const complex &x, const complex &y) {
    return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex
operator+(const complex &x, double y) {
    return complex(real(x) + y, imag(x));
}

inline complex
operator+(double x, const complex &y) {
    return complex(x + real(y), imag(y));
}

inline complex
operator-(const complex &x, const complex &y) {
    return complex(real(x) - real(y), imag(x) - imag(y));
}

inline complex
operator-(const complex &x, double y) {
    return complex(real(x) - y, imag(x));
}

inline complex
operator-(double x, const complex &y) {
    return complex(x - real(y), -imag(y));
}

inline complex
operator*(const complex &x, const complex &y) {
    return complex(real(x) * real(y) - imag(x) * imag(y),
                   real(x) * imag(y) + imag(x) * real(y));
}

inline complex
operator*(const complex &x, double y) {
    return complex(real(x) * y, imag(x) * y);
}

inline complex
operator*(double x, const complex &y) {
    return complex(x * real(y), x * imag(y));
}

complex
operator/(const complex &x, double y) {
    return complex(real(x) / y, imag(x) / y);
}


// 此处和上面的operator+ or operator-构成重载
inline complex
operator+(const complex &x) {
    return x;
}

inline complex
operator-(const complex &x) {
    return complex(-real(x), -imag(x));
}

inline bool
operator==(const complex &x, const complex &y) {
    return real(x) == real(y) && imag(x) == imag(y);
}

inline bool
operator==(const complex &x, double y) {
    return real(x) == y && imag(x) == 0;
}

inline bool
operator==(double x, const complex &y) {
    return x == real(y) && imag(y) == 0;
}

inline bool
operator!=(const complex &x, const complex &y) {
    return real(x) != real(y) || imag(x) != imag(y);
}

inline bool
operator!=(const complex &x, double y) {
    return real(x) != y || imag(x) != 0;
}

inline bool
operator!=(double x, const complex &y) {
    return x != real(y) || imag(y) != 0;
}

#include <cmath>

// return by reference 是比 return by value要好的
// 但是由于返回的是complex的临时对象(local object)，在其返回后（出了作用域）其内存就已经被析构/回收了
// 这样就不知道这玩意是个什么东西了
inline complex
polar(double r, double t) {
    return complex(r * cos(t), r * sin(t));
}

inline complex
conj(const complex &x) {
    return complex(real(x), -imag(x));
}

inline double
norm(const complex &x) {
    return real(x) * real(x) + imag(x) * imag(x);
}

#endif //CPP_LEARN_Complex_H
