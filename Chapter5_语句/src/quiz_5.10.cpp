/**
 * 之前的程序不能统计大写的元音字母。
 * 编写一段程序，既统计元音字母的小写形式，也统计大写形式。
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
        }
    }

    cout << "Number of vowel a: \t" << a_cnt << endl;
    cout << "Number of vowel e: \t" << e_cnt << endl;
    cout << "Number of vowel i: \t" << i_cnt << endl;
    cout << "Number of vowel o: \t" << o_cnt << endl;
    cout << "Number of vowel u: \t" << u_cnt << endl;

    return 0;
}
