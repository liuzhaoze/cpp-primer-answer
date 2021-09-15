/**
 * 写一段自己的程序，使用 if else 语句实现把数字成绩转换成字母成绩的要求。
 */

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> level = {"F", "D", "C", "B", "A", "A++"};
    unsigned grade;
    string letter_grade;

    while (cin >> grade) {
        if (grade < 60) {
            letter_grade = level[0];
        }
        else {
            letter_grade = level[(grade - 50) / 10];
            if (grade != 100) {
                if (grade % 10 > 7) {
                    letter_grade += "+";
                }
                else if (grade % 10 < 3) {
                    letter_grade += "-";
                }
            }
        }

        cout << grade << "\t" << letter_grade << endl;
    }

    return 0;
}
