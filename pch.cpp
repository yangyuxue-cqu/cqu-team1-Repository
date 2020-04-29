// pch.cpp: 与预编译标头对应的源文件
#define DLL_EXPORT
#include "pch.h"

// 当使用预编译的头时，需要使用此源文件，编译才能成功。

//下面为求绝对值函数
double myabs(double x)
{
    return((x > 0) ? x : -x);
}

extern "C" {
    DLL_EXPORT double c_sin(double x)
    {
        int i = 1, negation = 1;//取反
        double sum = 0;
        double index = x;//指数
        double Factorial = 1;//阶乘
        double TaylorExpansion = x;//泰勒展开式求和
        do
        {
            Factorial = Factorial * ((__int64)i + 1) * ((__int64)i + 2);//求阶乘
            index *= x * x;//求num2的次方
            negation = -negation;//每次循环取反
            sum = index / Factorial * negation;
            TaylorExpansion += sum;
            i += 2;
        } while (myabs(sum) > 1e-15);
        return (TaylorExpansion);
    }

    DLL_EXPORT double c_cos(double x)
    {
        x = (PI / 2) - x;
        return c_sin(x);
    }

    DLL_EXPORT double c_tan(double x)
    {
        return (c_sin(x) / c_cos(x));
    }

    DLL_EXPORT double c_cot(double x)
    {
        return (1 / c_tan(x));
    }
}

