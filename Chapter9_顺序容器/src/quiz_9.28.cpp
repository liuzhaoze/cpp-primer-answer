/**
 * 编写函数，接受一个 forward_list<string> 和两个 string 共三个参数。
 * 函数应在链表中查找第一个 string ，并将第二个 string 插入到紧接着第一个 string 之后的位置。
 * 若第一个 string 未在链表中，则将第二个 string 插入到链表末尾。
 */

#define PRINT_CONTAINER(a) print_container(std::cout, a.cbegin(), a.cend()) << std::endl

#include "../../lib/print_container.hpp"
#include <forward_list>
#include <iostream>
#include <string>

auto insert_string(std::forward_list<std::string> &flist_str, std::string str_pos, std::string str_obj)
{
    auto prev = flist_str.before_begin();
    auto curr = flist_str.begin();

    while (curr != flist_str.end())
    {
        if (*curr == str_pos)
        {
            curr = flist_str.insert_after(curr, str_obj);
            return curr;
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }

    // str_pos 不在链表中
    prev = flist_str.insert_after(prev, str_obj);
    return prev;
}

int main()
{
    std::forward_list<std::string> flist;

    // 向空链表中添加元素
    insert_string(flist, "something", "Apple");
    PRINT_CONTAINER(flist);

    // 在不存在的字符串后面添加元素
    insert_string(flist, "Banana", "Cherry");
    PRINT_CONTAINER(flist);

    // 在已存在的字符串后面添加元素
    insert_string(flist, "Apple", "Banana");
    PRINT_CONTAINER(flist);

    return 0;
}
