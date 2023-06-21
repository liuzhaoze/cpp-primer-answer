/**
 * 如果我们将一个 Token 对象赋给它自己将发生什么情况？
 *
 * 答：程序正常运行。
 */

#include "../../lib/Sales_data.hpp"
#include "../../lib/Token.hpp"
#include <utility>

int main()
{
    Token t;

    t = t;
    t = std::move(t);

    return 0;
}
