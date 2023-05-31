#include "Basket.hpp"
#include "Quote.hpp"
#include <memory>
#include <utility>

bool Basket::compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
{
    return lhs->isbn() < rhs->isbn();
}

void Basket::add_item(const std::shared_ptr<Quote> &sale)
{
    items.insert(sale);
}

void Basket::add_item(const Quote &sale)
{
    items.insert(std::shared_ptr<Quote>(sale.clone()));
    // 虚函数 clone 会根据 sale 的动态类型返回相应类型的指针
}

void Basket::add_item(Quote &&sale)
{
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    // 虚函数 clone 会根据 sale 的动态类型返回相应类型的指针
}

double Basket::print_receipt(std::ostream &os) const
{
    double sum = 0.0;

    // upper_bound 每次指向下一个关键字不同的元素（也就是具有相同关键字元素子序列的尾后位置）
    // 通过对相邻两个元素调用 Basket::compare 来判断关键字是否相同
    // 返回值为 False 说明关键字相同，返回值为 True 说明关键字不同
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter)); // items 中的每个元素代表一本书
    }

    os << "Total sale: " << sum << std::endl;

    return sum;
}
