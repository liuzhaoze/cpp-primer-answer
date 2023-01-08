/**
 * 重写 7.1.1 节的书店程序，从一个文件中读取交易记录。
 * 将文件名作为一个参数传递给 main 。
 */

#include "../../lib/Sales_data.hpp"
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Need 1 file name." << std::endl;
        return 1;
    }

    Sales_data total;
    std::string file_name = argv[1];
    std::ifstream istrm(file_name);

    if (read(istrm, total))
    {
        Sales_data trans;

        while (read(istrm, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
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
        std::cerr << "No data in file: " << file_name << std::endl;
    }

    return 0;
}
