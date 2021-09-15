/**
 * 修改统计元音字母的程序，使其能统计以下含有两个字符的字符序列的数量：
 * ff 、 fl 和 fi
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::noskipws;

int main()
{
    unsigned a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0;
    unsigned ff_cnt = 0, fl_cnt = 0, fi_cnt = 0;
    char ch;

    while (cin >> noskipws >> ch) {
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
            case 'f':
            {
                char ch2;
                cin >> noskipws >> ch2;
                switch (ch2) {
                    case 'a': case 'A':
                        ++a_cnt;
                        break;
                    case 'e': case 'E':
                        ++e_cnt;
                        break;
                    case 'i': 
                        ++fi_cnt;  // I 不用增加该变量
                    case 'I':
                        ++i_cnt;
                        break;
                    case 'o': case 'O':
                        ++o_cnt;
                        break;
                    case 'u': case 'U':
                        ++u_cnt;
                        break;
                    case 'f':
                        ++ff_cnt;
                        break;
                    case 'l':
                        ++fl_cnt;
                        break;
                }
            }
            default:
                break;
        }
    }

    cout << "Number of vowel a: \t" << a_cnt << endl;
    cout << "Number of vowel e: \t" << e_cnt << endl;
    cout << "Number of vowel i: \t" << i_cnt << endl;
    cout << "Number of vowel o: \t" << o_cnt << endl;
    cout << "Number of vowel u: \t" << u_cnt << endl;
    cout << "Number of ff: \t" << ff_cnt << endl;
    cout << "Number of fl: \t" << fl_cnt << endl;
    cout << "Number of fi: \t" << fi_cnt << endl;

    return 0;
}
