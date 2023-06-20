/**
 * 定义一个成员指针，令其可以指向 Screen 类的 cursor 成员。
 * 通过该指针获得 Screen::cursor 的值。
 */

#include <iostream>
#include <string>

class Screen
{
  public:
    using pos = std::string::size_type;

  private:
    std::string contents;
    pos cursor;
    pos height, width;

  public:
    Screen(pos ht = 600, pos wd = 800) : contents(), cursor(0), height(ht), width(wd)
    {
    }

    static const pos Screen::*cursor_p()
    {
        return &Screen::cursor;
    }
};

int main()
{
    Screen myScreen, *pScreen = &myScreen;

    const Screen::pos Screen::*p = Screen::cursor_p();

    std::cout << myScreen.*p << std::endl;
    std::cout << pScreen->*p << std::endl;

    return 0;
}
