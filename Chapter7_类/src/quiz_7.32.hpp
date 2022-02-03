/**
 * 定义你自己的 Screen 和 Window_mgr ，
 * 其中 clear 是 Window_mgr 的成员，是 Screen 的友元。
 */

#ifndef QUIZ_7_32_HPP
#define QUIZ_7_32_HPP

#include <string>
#include <vector>
#include <iostream>

class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

class Screen
{
    friend void Window_mgr::clear(ScreenIndex);

public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd, char c = ' ') : height(ht), width(wd), contents(ht * wd, c) {}

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

private:
    void do_display(std::ostream &os) const { os << contents; }

public:
    Screen move(pos row, pos col);
    Screen set(char c);
    Screen set(pos row, pos col, char c);
    char get(pos row, pos col) const;
    Screen display(std::ostream &os);
    const Screen display(std::ostream &os) const;
};

inline Screen Screen::move(pos row, pos col)
{
    cursor = row * width + col;
    return *this;
}

inline Screen Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen Screen::set(pos row, pos col, char c)
{
    contents[row * width + col] = c;
    return *this;
}

inline char Screen::get(pos row, pos col) const
{
    return contents[row * width + col];
}

inline Screen Screen::display(std::ostream &os)
{
    do_display(os);
    return *this;
}

const Screen Screen::display(std::ostream &os) const
{
    do_display(os);
    return *this;
}

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

#endif
