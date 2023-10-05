export module helloworld; // 模块声明

import <iostream>; // 导入声明

export void hello() // 导出声明
{
    std::cout << "Hello world!\n";
}