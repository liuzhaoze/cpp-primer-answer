/**
 * 修改上一题的程序，使用 try 语句块去捕获异常。
 * catch 子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行 try 语句块的内容。
 */

#include <iostream>
#include <string>
#include <stdexcept>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int a, b;
    string cmd;

    do
    {
        cout << "Enter two numbers:" << endl;
        cin >> a >> b;

        try
        {
            if (b == 0)
                throw std::runtime_error("Divided by 0.");
            else
                cout << a << " divided by " << b << " equals to " << a / b << endl;
        }
        catch (std::runtime_error err)
        {
            cerr << err.what() << endl;
        }

        cout << "Continue? [y/n]" << endl;
        cin >> cmd;
    } while (!cmd.empty() && std::tolower(cmd[0]) == 'y');

    return 0;
}
