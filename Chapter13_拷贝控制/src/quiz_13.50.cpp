/**
 * 在你的 String 类的移动操作中添加打印语句，并重新运行 13.6.1 节的练习 13.48 中的程序，它使用了一个 vector<String>
 * ，观察什么时候会避免拷贝。
 */

#include "../../lib/String.hpp"
#include <iostream>
#include <string>
#include <vector>

// Test reference to http://coolshell.cn/articles/10478.html

void foo(String x)
{
    std::cout << x.c_str() << std::endl;
}

void bar(const String &x)
{
    std::cout << x.c_str() << std::endl;
}

String baz()
{
    String ret("world");
    return ret; // NOTE: 此处避免拷贝
}

int main()
{
    char text[] = "world";

    std::cout << std::string(10, '-') << " 变量初始化和拷贝测试 " << std::string(10, '-') << std::endl;

    String s0;
    String s1("hello");
    String s2(s0);
    String s3 = s1;
    String s4(text);
    s2 = s1;

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    String s5 = baz(); // NOTE: 此处避免拷贝

    std::cout << '\n' << std::string(10, '-') << " vector 的 push_back 测试 " << std::string(10, '-') << std::endl;

    std::vector<String> svec;
    svec.reserve(8);
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);
    svec.push_back(baz());
    svec.push_back("good job");

    std::cout << '\n' << std::string(10, '-') << " 打印 vector " << std::string(10, '-') << std::endl;

    for (const auto &s : svec)
    {
        std::cout << s.c_str() << std::endl;
    }

    return 0;
}
