/**
 * 假设 iter 的类型是 vector<string>::iterator ，
 * 说明下面的表达式是否合法。
 * 如果合法，表达式的含义是什么？
 * 如果不合法，错在何处？
 */

#include <string>
#include <vector>

using std::string;
using std::vector;

int main()
{
    vector<string>::iterator iter;

    *iter++;  // 合法，对 iter 指向的元素解引用，然后 iter 指向下一个元素

    (*iter)++;  // 非法， string 对象没有自增操作

    *iter.empty();  // 非法，迭代器没有 empty 成员函数

    iter->empty();  // 合法，返回 iter 所指 string 对象是否为空

    ++*iter;  // 非法， string 对象没有自增操作

    iter++->empty();  // 合法，返回 iter 所指 string 对象是否为空，然后 iter 指向下一个元素

    return 0;
}
