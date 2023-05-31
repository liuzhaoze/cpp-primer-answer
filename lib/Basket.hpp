#ifndef _BASKET_HPP_
#define _BASKET_HPP_

#include "Quote.hpp"
#include <memory>
#include <ostream>
#include <set>

// 表示购物篮的类，可以存放不同价格策略的 Quote 类
class Basket
{
  private:
    // 用于给 shared_ptr<Quote> 排序
    static bool compare(const std::shared_ptr<Quote> &, const std::shared_ptr<Quote> &);
    // 用于保存多个报价，按照 compare 成员排序
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};

  public:
    // 直接将指针存入 multiset
    void add_item(const std::shared_ptr<Quote> &);
    // 将给定的对象拷贝到 multiset
    void add_item(const Quote &);
    // 将给定的对象移动到 multiset
    void add_item(Quote &&);

    // 打印每本书的总价和购物篮中所有书的总价
    double print_receipt(std::ostream &) const;
};

#endif
