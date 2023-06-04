/**
 * 编写行为类似标准库 find 算法的模板。
 * 函数需要两个模板类型参数，一个表示函数的迭代器参数，另一个表示值的类型。
 * 使用你的函数在一个 vector<int> 和一个 list<string> 中查找给定值。
 */

#include <iostream>
#include <list>
#include <string>
#include <vector>

namespace quiz
{
template <typename Iterator, typename Value> auto find(Iterator first, Iterator last, Value const &value)
{
    while (first != last && *first != value)
    {
        ++first;
    }
    return first;
}
} // namespace quiz

int main()
{
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto is_in_vec = vec.cend() != quiz::find(vec.cbegin(), vec.cend(), 5);
    std::cout << (is_in_vec ? "found" : "not found") << std::endl;

    std::list<std::string> lst = {"aa", "bb", "cc", "dd", "ee"};
    auto is_in_lst = lst.cend() != quiz::find(lst.cbegin(), lst.cend(), "zz");
    std::cout << (is_in_lst ? "found" : "not found") << std::endl;

    return 0;
}
