/**
 * 分别编写前三题中所描述的 numbered 和 f ，验证你是否正确预测了输出结果。
 */

#include <cstddef>
#include <iostream>

static std::size_t unique = 1;

class numbered_first
{
  public:
    friend void f_first(numbered_first s);

  private:
    std::size_t mysn;

  public:
    numbered_first() : mysn(unique++)
    {
    }
};

class numbered_second
{
  public:
    friend void f_second(numbered_second s);

  private:
    std::size_t mysn;

  public:
    numbered_second() : mysn(unique++)
    {
    }
    numbered_second(const numbered_second &ns) : mysn(unique++)
    {
    }
};

class numbered_third
{
  public:
    friend void f_third(const numbered_third &s);

  private:
    std::size_t mysn;

  public:
    numbered_third() : mysn(unique++)
    {
    }
    numbered_third(const numbered_third &ns) : mysn(unique++)
    {
    }
};

void f_first(numbered_first s)
{
    std::cout << s.mysn << std::endl;
}

void f_second(numbered_second s)
{
    std::cout << s.mysn << std::endl;
}

void f_third(const numbered_third &s)
{
    std::cout << s.mysn << std::endl;
}

int main()
{
    std::cout << "quiz_13.14" << std::endl;
    numbered_first a1, b1 = a1, c1 = b1; // 使用合成的拷贝构造函数：1 1 1
    f_first(a1);                         // 1
    f_first(b1);                         // 1
    f_first(c1);                         // 1

    std::cout << "quiz_13.15" << std::endl;
    numbered_second a2, b2 = a2, c2 = b2; // 使用自定义的拷贝构造函数 2 3 4
    f_second(a2);                         // 5
    f_second(b2);                         // 6
    f_second(c2);                         // 7

    std::cout << "quiz_13.16" << std::endl;
    numbered_third a3, b3 = a3, c3 = b3; // 使用自定义的拷贝构造函数 8 9 10
    f_third(a3);                         // 8
    f_third(b3);                         // 9
    f_third(c3);                         // 10
    // 引用不发生拷贝

    return 0;
}
