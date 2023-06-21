#include "Token.hpp"
#include "Sales_data.hpp"
#include <string>

Token &Token::operator=(char c)
{
    // 先销毁类类型
    if (tok == STR)
    {
        sval.~basic_string();
    }
    if (tok == SAL)
    {
        item.~Sales_data();
    }

    cval = c;   // 为成员赋值
    tok = CHAR; // 更新判别式

    return *this;
}

Token &Token::operator=(int i)
{
    // 先销毁类类型
    if (tok == STR)
    {
        sval.~basic_string();
    }
    if (tok == SAL)
    {
        item.~Sales_data();
    }

    ival = i;  // 为成员赋值
    tok = INT; // 更新判别式

    return *this;
}

Token &Token::operator=(double d)
{
    // 先销毁类类型
    if (tok == STR)
    {
        sval.~basic_string();
    }
    if (tok == SAL)
    {
        item.~Sales_data();
    }

    dval = d;  // 为成员赋值
    tok = DBL; // 更新判别式

    return *this;
}

Token &Token::operator=(std::string s)
{
    if (tok == SAL) // 如果当前存储的就是 Sales_data ，则需要先销毁
    {
        item.~Sales_data();
    }

    if (tok == STR) // 如果当前存储的就是 string ，则可以直接赋值
    {
        sval = s;
    }
    else // 当前存储的是内置类型，需要使用定位 new 表达式，在 sval 的地址处构造 string 对象
    {
        new (&sval) std::string(s);
    }

    tok = STR; // 更新判别式

    return *this;
}

Token &Token::operator=(Sales_data sd)
{
    if (tok == STR) // 如果当前存储的就是 string ，则需要先销毁
    {
        sval.~basic_string();
    }

    if (tok == SAL) // 如果当前存储的就是 Sales_data ，则可以直接赋值
    {
        item = sd;
    }
    else // 当前存储的是内置类型，需要使用定位 new 表达式，在 item 的地址处构造 Sales_data 对象
    {
        new (&item) Sales_data(sd);
    }

    tok = SAL; // 更新判别式

    return *this;
}

void Token::copyUnion(const Token &t)
{
    // 内置类型直接拷贝
    // 类类型需要使用定位 new 表达式在对应地址处构造对象
    switch (t.tok)
    {
    case Token::CHAR:
        cval = t.cval;
        break;
    case Token::INT:
        ival = t.ival;
        break;
    case Token::DBL:
        dval = t.dval;
        break;
    case Token::STR:
        new (&sval) std::string(t.sval);
        break;
    case Token::SAL:
        new (&item) Sales_data(t.item);
        break;
    }
}

void Token::moveUnion(Token &&t)
{
    switch (t.tok)
    {
    case Token::CHAR:
        cval = std::move(t.cval);
        break;
    case Token::INT:
        ival = std::move(t.ival);
        break;
    case Token::DBL:
        dval = std::move(t.dval);
        break;
    case Token::STR:
        new (&sval) std::string(std::move(t.sval));
        break;
    case Token::SAL:
        new (&item) Sales_data(std::move(t.item));
        break;
    }
}
