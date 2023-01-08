/**
 * 修改上一节的书店程序，将结果保存到一个文件中。
 * 将输出文件名作为第二个参数传递给 main 函数。
 */

#include "../../lib/Sales_data.hpp"
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Need 2 file name. First is input. Second is output." << std::endl;
        return 1;
    }

    Sales_data total;
    std::string input_file_name = argv[1];
    std::string output_file_name = argv[2];
    std::ifstream istrm(input_file_name);
    std::ofstream ostrm(output_file_name);

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
                print(ostrm, total) << std::endl;
                total = trans;
            }
        }
        print(ostrm, total) << std::endl;
    }
    else
    {
        std::cerr << "No data in file: " << input_file_name << std::endl;
    }

    return 0;
}
