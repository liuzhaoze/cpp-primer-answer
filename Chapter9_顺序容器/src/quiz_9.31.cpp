/**
 * 下面删除偶数值元素并复制奇数值元素的程序不能用于 list 或 forward_list 。为什么？
 * 修改程序，使之也能用于这些类型。
 */

// list 的迭代器不适用于 += 运算符，只适用于 ++ 运算符，advance 函数是通过重复执行 ++ 操作实现的
// forward_list 需要使用特殊的 insert_after 和 erase_after 操作来完成插入和删除

#include "../../lib/print_container.hpp"
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

void remove_even_duplicate_odd(std::vector<int> &ivec);
void remove_even_duplicate_odd(std::list<int> &ilst);
void remove_even_duplicate_odd(std::forward_list<int> &iflst);

int main()
{
    std::vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> li(vi.cbegin(), vi.cend());
    std::forward_list<int> fi(vi.cbegin(), vi.cend());

    std::cout << "Original:" << std::endl;

    print_container(std::cout, vi.cbegin(), vi.cend()) << std::endl;
    print_container(std::cout, li.cbegin(), li.cend()) << std::endl;
    print_container(std::cout, fi.cbegin(), fi.cend()) << std::endl;

    std::cout << "After process:" << std::endl;

    remove_even_duplicate_odd(vi);
    print_container(std::cout, vi.cbegin(), vi.cend()) << std::endl;

    remove_even_duplicate_odd(li);
    print_container(std::cout, li.cbegin(), li.cend()) << std::endl;

    remove_even_duplicate_odd(fi);
    print_container(std::cout, fi.cbegin(), fi.cend()) << std::endl;

    return 0;
}

void remove_even_duplicate_odd(std::vector<int> &ivec)
{
    auto iter = ivec.begin();

    while (iter != ivec.end())
    {
        if (*iter % 2)
        {
            iter = ivec.insert(iter, *iter);
            iter += 2;
        }
        else
        {
            iter = ivec.erase(iter);
        }
    }
}

void remove_even_duplicate_odd(std::list<int> &ilst)
{
    auto iter = ilst.begin();

    while (iter != ilst.end())
    {
        if (*iter % 2)
        {
            iter = ilst.insert(iter, *iter);
            std::advance(iter, 2); // 修改
        }
        else
        {
            iter = ilst.erase(iter);
        }
    }
}

void remove_even_duplicate_odd(std::forward_list<int> &iflst)
{
    auto prev = iflst.before_begin(); // 修改
    auto curr = iflst.begin();

    while (curr != iflst.end())
    {
        if (*curr % 2)
        {
            curr = iflst.insert_after(prev, *curr); // 修改
            std::advance(prev, 2);                  // 修改
            std::advance(curr, 2);                  // 修改
        }
        else
        {
            curr = iflst.erase_after(prev); // 修改
            // prev 无需改变
        }
    }
}
