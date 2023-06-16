/**
 * 定义本节描述的书店程序异常类，然后为 Sales_data 类重新编写一个复合赋值运算符并令其抛出一个异常。
 */

#include "../../lib/Sales_data.hpp"
#include <fstream>
#include <iostream>

int main()
{
    Sales_data item1, item2, sum;
    std::ifstream in_file("../data/book_sales");

    while (in_file >> item1 >> item2)
    {
        try
        {
            sum = item1 + item2;
        }
        catch (const isbn_mismatch &e)
        {
            std::cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << std::endl;
        }
    }

    return 0;
}
