#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str, pre_str, max_duplicated_str;
    int count = 0, max_duplicated_count = 0;

    while (cin >> str)
    {
        if (str == pre_str)
            ++count;
        else
            count = 0;

        if (count > max_duplicated_count)
        {
            max_duplicated_count = count;
            max_duplicated_str = str;
        }

        pre_str = str;
    }

    if (max_duplicated_str.empty())
        cout << "There is no duplicated string." << endl;
    else
        cout << "The word: \'" << max_duplicated_str << "\' occurred " << max_duplicated_count + 1 << " times." << endl;
    
    return 0;
}
