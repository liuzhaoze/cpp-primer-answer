/**
 * 编写程序，从一个 list<int> 拷贝元素到两个 deque 中。
 * 值为偶数的所有元素拷贝到一个 deque 中，而奇数值元素都拷贝到另一个 deque 中。
 */

#include "../../lib/print_container.hpp"
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>

#define ELEMENT_NUM 15

int main()
{
    std::srand(std::time(0));
    std::list<int> lst;
    std::deque<int> even, odd;

    for (int i = 0; i != ELEMENT_NUM; ++i)
    {
        lst.push_back(std::rand());
    }
    print_container(std::cout, lst.cbegin(), lst.cend()) << std::endl;

    for (const auto &each : lst)
    {
        if (each % 2 != 0)
        {
            odd.push_back(each);
        }
        else
        {
            even.push_back(each);
        }
    }

    print_container(std::cout, odd.cbegin(), odd.cend()) << std::endl;
    print_container(std::cout, even.cbegin(), even.cend()) << std::endl;

    return 0;
}
