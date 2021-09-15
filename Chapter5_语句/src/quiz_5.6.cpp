/**
 * 改写上一题的程序，使用条件运算符代替 if else 语句。
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
        letter_grade = (grade < 60) ? level[0] : level[(grade - 50) / 10];
        
        if (grade != 100) {
            letter_grade += (grade % 10 > 7) ? "+"
                                             : ((grade % 10 < 3) ? "-" : "");
        }

        cout << grade << "\t" << letter_grade << endl;
    }

    return 0;
}
