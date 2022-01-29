/**
 * 使用这些新函数重写 7.1.2 节练习中的交易处理程序。
 */

#include "quiz_7.6.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_data total;
    if (read(cin, total))
    {
        Sales_data trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
