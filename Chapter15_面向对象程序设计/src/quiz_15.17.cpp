/**
 * 尝试定义一个 Disc_quote 的对象，看看编译器给出的错误信息是什么？
 *
 * 答：error: variable type 'Disc_quote' is an abstract class
 */

#include "../../lib/Quote.hpp"

int main()
{
    Disc_quote dq;

    return 0;
}
