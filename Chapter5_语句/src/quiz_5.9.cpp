/**
 * 编写一段程序，使用一系列 if 语句统计从 cin 读入的文本中有多少元音字母。
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0;
    char ch;

    while (cin >> ch) {
        if (ch == 'a')
            ++a_cnt;
        else if (ch == 'e')
            ++e_cnt;
        else if (ch == 'i')
            ++i_cnt;
        else if (ch == 'o')
            ++o_cnt;
        else if (ch == 'u')
            ++u_cnt;
    }

    cout << "Number of vowel a: \t" << a_cnt << endl;
    cout << "Number of vowel e: \t" << e_cnt << endl;
    cout << "Number of vowel i: \t" << i_cnt << endl;
    cout << "Number of vowel o: \t" << o_cnt << endl;
    cout << "Number of vowel u: \t" << u_cnt << endl;

    return 0;
}
