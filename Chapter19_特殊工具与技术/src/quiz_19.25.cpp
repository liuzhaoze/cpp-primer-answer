/**
 * 编写一系列赋值运算符，令其分别接受 union 中各种类型的值。
 */

#include "../../lib/Sales_data.hpp"
#include "../../lib/Token.hpp"
#include <string>

int main()
{
    Token t;

    t = 'c';
    t = 3.14;
    t = std::string("Hello World");
    t = Sales_data("0-201-70353-X", 4, 24.99);
    t = 42;

    return 0;
}
