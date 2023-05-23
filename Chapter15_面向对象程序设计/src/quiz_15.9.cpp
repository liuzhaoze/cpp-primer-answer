/**
 * 在什么情况下表达式的静态类型可能与动态类型不同？
 * 请给出三个静态类型与动态类型不同的例子。
 *
 * 答：当静态类型是指向基类的指针或引用时，可能会与动态类型不同。
 */

#include "../../lib/Quote.hpp"
#include "quiz_15.7.hpp"

int main()
{
    Bulk_quote bulk_quote("bulk_quote_1", 10.10, 10, 0.5);

    // 指针的静态类型是 Quote ，但动态类型是 Bulk Quote
    Quote *quote_pointer = &bulk_quote;
    // Bulk Quote 类的 net_price() 被调用
    quote_pointer->net_price(5);

    // 引用的静态类型是 Quote ，但动态类型是 Bulk Quote
    Quote &quote_reference = bulk_quote;
    // Bulk Quote 类的 net_price() 被调用
    quote_reference.net_price(5);

    // Bulk Quote 类赋值给 Quote 类，只拷贝基类部分
    Quote quote = bulk_quote;
    // Quote 类的 net_price() 被调用
    quote.net_price(5);

    return 0;
}
