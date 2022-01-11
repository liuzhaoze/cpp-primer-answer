/**
 * 编写你自己的 fact.cpp 和 main.cpp ，这两个文件都应该包含上一小节的练习中编写的 quiz_6.8.h 头文件。
 * 通过这些文件，理解你的编译器是如何支持分离式编译的。
 * g++ -c quiz_6.9_fact.cpp
 * g++ -c quiz_6.9_main.cpp
 * g++ quiz_6.9_fact.o quiz_6.9_main.o -o quiz_6.9.out
 */

#include "quiz_6.8.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned int val;

    cout << "Enter a number: ";
    cin >> val;
    cout << val << "! is " << fact(val) << endl;

    return 0;
}
