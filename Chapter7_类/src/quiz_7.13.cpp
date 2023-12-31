/**
 * 使用 istream 构造函数重写第 229 页的程序。
 */

#include "quiz_7.12.hpp"

int main()
{
    Sales_data total(std::cin);
    if (!total.isbn().empty())
    {
        std::istream &is = std::cin;
        while (is)
        {
            Sales_data trans(is);
            if (!is)
                break;
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}
