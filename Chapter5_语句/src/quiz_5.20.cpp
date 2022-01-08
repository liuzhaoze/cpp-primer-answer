/**
 * 编写一段程序，从标准输入中读取 string 对象的序列直到连续出现两个相同的单词或者所有单词都读完为止。
 * 使用 while 循环一次读取一个单词，当一个单词连续出现两次时使用 break 语句终止循环。
 * 输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的。
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str, pre_str;
    bool duplicated = false;

    while (cin >> str && !str.empty())
    {
        if (str == pre_str)
        {
            duplicated = true;
            break;
        }

        pre_str = str;
    }

    if (!duplicated)
        cout << "There is no duplicated word." << endl;
    else
        cout << "The duplicated word is \"" << pre_str << "\"." << endl;

    return 0;
}
