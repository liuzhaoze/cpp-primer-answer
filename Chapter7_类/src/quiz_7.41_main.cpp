/**
 * 使用委托构造函数重新编写你的 Sales_data 类，
 * 给每个构造函数体添加一条语句，令其一旦执行就打印一条消息。
 * 用各种可能的方式分别创建 Sales_data 对象，
 * 认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。
 */

#include "quiz_7.41.hpp"

using std::cout;
using std::endl;

int main()
{
    cout << "1. default way: " << endl;
    cout << "----------------" << endl;
    Sales_data s1;

    cout << "\n2. use std::string as parameter: " << endl;
    cout << "----------------" << endl;
    Sales_data s2("CPP-Primer-5th");

    cout << "\n3. complete parameters: " << endl;
    cout << "----------------" << endl;
    Sales_data s3("CPP-Primer-5th", 3, 25.8);

    cout << "\n4. use istream as parameter: " << endl;
    cout << "----------------" << endl;
    Sales_data s4(std::cin);

    return 0;
}
