// 编写自定义数学库文件
#pragma once
#include <iostream>
#include <cmath>
// 如果是c++文件，需要加上,兼容c，如果是c文件,不需要
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif
namespace vMath
{
    // 生成动态链接库
    __declspec(dllexport) void getVersion();
    __declspec(dllexport) double vS_sqrt(double x);
    __declspec(dllexport) double vS_pow(double x, double y);
}