/**
 * 给你的 Screen 类添加三个构造函数：
 * 一个默认构造函数；
 * 另一个构造函数接受宽和高的值，然后将 contents 初始化成给定数量的空白；
 * 第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容。
 */

#ifndef QUIZ_7_24_HPP
#define QUIZ_7_24_HPP

#include <string>

class Screen
{
public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd, char c = ' ') : height(ht), width(wd), contents(ht * wd, c) {}

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

#endif
