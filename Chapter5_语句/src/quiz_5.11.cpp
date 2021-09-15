/**
 * 修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量。
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0;
    unsigned space_cnt = 0, table_cnt = 0, return_cnt = 0;
    char ch;

    while (cin.get(ch)) {
        switch (ch) {
            case 'a': case 'A':
                ++a_cnt;
                break;
            case 'e': case 'E':
                ++e_cnt;
                break;
            case 'i': case 'I':
                ++i_cnt;
                break;
            case 'o': case 'O':
                ++o_cnt;
                break;
            case 'u': case 'U':
                ++u_cnt;
                break;
            case ' ':
                ++space_cnt;
                break;
            case '\t':
                ++table_cnt;
                break;
            case '\n':
                ++return_cnt;
                break;
            default:
                break;
        }
    }

    cout << "Number of vowel a: \t" << a_cnt << endl;
    cout << "Number of vowel e: \t" << e_cnt << endl;
    cout << "Number of vowel i: \t" << i_cnt << endl;
    cout << "Number of vowel o: \t" << o_cnt << endl;
    cout << "Number of vowel u: \t" << u_cnt << endl;
    cout << "Number of space: \t" << space_cnt << endl;
    cout << "Number of table: \t" << table_cnt << endl;
    cout << "Number of return: \t" << return_cnt << endl;

    return 0;
}
