/**
 * 编写程序令其对两个 ISBN 编号不相同的对象执行 Sales_data 的加法运算。
 * 为该程序编写两个不同的版本：一个处理异常，另一个不处理异常。
 * 观察并比较这两个程序的行为，用心体会当出现了一个未被捕获的异常时程序会发生什么情况。
 * 处理异常：clang++ quiz_18.10.cpp ../../lib/Sales_data.cpp -D CATCH_EXCEPTION -o a.exe
 * 不处理异常：clang++ quiz_18.10.cpp ../../lib/Sales_data.cpp -o a.exe
 */

#include "../../lib/Sales_data.hpp"
#include <iostream>

int main()
{
    Sales_data item1("0-201-70353-X", 4, 24.99), item2("0-201-82470-1", 4, 45.39), sum;

#ifdef CATCH_EXCEPTION

    try
    {
        sum = item1 + item2;
    }
    catch (const isbn_mismatch &e)
    {
        std::cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << std::endl;
    }

#else

    sum = item1 + item2;

#endif

    return 0;
}
