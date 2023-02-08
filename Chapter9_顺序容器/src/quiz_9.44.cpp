/**
 * 重写上一题的函数，这次使用一个下标和 replace 。
 */

#include <iostream>
#include <string>

void my_replace(std::string &s, const std::string oldVal, const std::string newVal)
{
    for (std::string::size_type i = 0; i != (s.size() - oldVal.size() + 1); ++i)
    {
        if (s.substr(i, oldVal.size()) == oldVal)
        {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size() - 1;
        }
    }
}

int main()
{
    std::string s = "To drive straight thru is a foolish, tho courageous act.";

    my_replace(s, "tho", "though");
    my_replace(s, "thru", "through");
    std::cout << s << std::endl;

    return 0;
}
