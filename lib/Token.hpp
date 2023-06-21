#ifndef _TOKEN_HPP_
#define _TOKEN_HPP_

#include "Sales_data.hpp"
#include <string>
#include <utility>

/**
 * @ 使用 Token 类来管理含有类类型的 union
 * @ 管理含有类类型的 union 的类必须定义拷贝控制成员
 */
class Token
{
  private:
    // 匿名 union
    union {
        char cval;        // 内置类型的成员
        int ival;         // 内置类型的成员
        double dval;      // 内置类型的成员
        std::string sval; // string 类类型的成员
        Sales_data item;  // Sales_data 类类型的成员
    };

    enum
    {
        INT,
        CHAR,
        DBL,
        STR,
        SAL
    } tok; // 判别式

    // 检查判别式，然后酌情拷贝 union 成员
    void copyUnion(const Token &);
    // 检查判别式，然后酌情移动 union 成员
    void moveUnion(Token &&);

  public:
    // 默认构造函数
    Token() : tok(INT), ival(0)
    {
    }
    // 拷贝构造函数
    Token(const Token &t) : tok(t.tok)
    {
        copyUnion(t);
    }
    // 移动构造函数
    Token(Token &&t) : tok(std::move(t.tok))
    {
        moveUnion(std::move(t));
    }
    // 拷贝赋值运算符
    Token &operator=(const Token &t)
    {
        // 情况 1 ：左侧是 类类型 右侧不是 类类型
        if (tok == STR && t.tok != STR)
        {
            sval.~basic_string(); // 需要销毁左侧的 string
        }
        if (tok == SAL && t.tok != SAL)
        {
            item.~Sales_data(); // 需要销毁左侧的 Sales_data
        }

        // 情况 2 ：两侧都是 类类型
        if (tok == STR && t.tok == STR)
        {
            sval = t.sval; // 直接赋值
        }
        else if (tok == SAL && t.tok == SAL)
        {
            item = t.item; // 直接赋值
        }
        else // 情况 3 ：左侧不是 类类型
        {
            copyUnion(t); // 根据右侧类型决定是需要构造，还是直接拷贝内置类型
        }

        tok = t.tok; // 更新判别式

        return *this;
    }
    // 移动赋值运算符
    Token &operator=(Token &&t)
    {
        // 情况 1 ：左侧是 类类型 右侧不是 类类型
        if (tok == STR && t.tok != STR)
        {
            sval.~basic_string(); // 需要销毁左侧的 string
        }
        if (tok == SAL && t.tok != SAL)
        {
            item.~Sales_data(); // 需要销毁左侧的 Sales_data
        }

        // 情况 2 ：两侧都是 类类型
        if (tok == STR && t.tok == STR)
        {
            sval = std::move(t.sval); // 直接移动
        }
        else if (tok == SAL && t.tok == SAL)
        {
            item = std::move(t.item); // 直接移动
        }
        else // 情况 3 ：左侧不是 类类型
        {
            moveUnion(std::move(t)); // 根据右侧类型决定是需要构造，还是直接移动内置类型
        }

        tok = std::move(t.tok); // 更新判别式

        return *this;
    }
    // 析构函数
    ~Token()
    {
        // 如果当前存储的是类类型成员，那么必须显式调用析构函数
        if (tok == STR)
        {
            sval.~basic_string();
        }
        if (tok == SAL)
        {
            item.~Sales_data();
        }
    }

    // 处理将 char 赋值给 union
    Token &operator=(char);
    // 处理将 int 赋值给 union
    Token &operator=(int);
    // 处理将 double 赋值给 union
    Token &operator=(double);
    // 处理将 string 赋值给 union
    Token &operator=(std::string);
    // 处理将 Sales_data 赋值给 union
    Token &operator=(Sales_data);

    // 获得 Token 当前储存的对象
    auto get() const;
};

#endif
