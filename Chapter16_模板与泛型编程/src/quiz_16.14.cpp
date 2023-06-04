/**
 * 编写 Screen 类模板，用非类型参数定义 Screen 的高和宽。
 */

#include <iostream>
#include <string>

template <unsigned H, unsigned W> class Screen
{
  public:
    using pos = std::string::size_type;

  private:
    pos cursor = 0;
    pos height = H, width = W;
    std::string contents;

  public:
    Screen() = default; // 定义其他构造函数时，需要定义默认构造函数
    Screen(char c) : contents(H * W, c)
    {
    }

    // 获得光标处的字符
    char get() const
    {
        return contents[cursor];
    }
    // 移动光标
    Screen &move(pos r, pos c);

    friend std::ostream &operator<<(std::ostream &os, const Screen<H, W> &c)
    {
        unsigned int i, j;
        for (i = 0; i < c.height; i++)
        {
            os << c.contents.substr(0, W) << std::endl;
        }
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Screen &c)
    {
        char a;
        is >> a;
        std::string temp(H * W, a);
        c.contents = temp;
        return is;
    }
};

template <unsigned H, unsigned W> inline Screen<H, W> &Screen<H, W>::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

int main()
{
    Screen<5, 5> scr('c');
    Screen<5, 5> scr2;

    // output src to the screen
    std::cout << scr;
    // input connet  to the  src
    std::cin >> scr2;
    // test input
    std::cout << scr2;

    return 0;
}
