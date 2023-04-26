/**
 * 编写函数，返回一个动态分配的 int 的 vector 。
 * 将此 vector 传递给另一个函数，这个函数读取标准输入，将输入的值保存在 vector 元素中。
 * 再将 vector 传递给另一个函数，打印读入的值。
 * 记得在恰当的时刻 delete vector 。
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> *alloc_ivec(void)
{
    return new std::vector<int>;
}

std::vector<int> *input_ivec(std::vector<int> *p)
{
    int i;

    while (std::cin >> i)
    {
        p->push_back(i);
    }

    return p;
}

std::vector<int> *output_ivec(std::vector<int> *p)
{
    std::ostream_iterator<int> output_iter(std::cout, " ");
    std::copy(p->cbegin(), p->cend(), output_iter);
    std::cout << std::endl;

    return p;
}

int main()
{
    auto piv = alloc_ivec();
    input_ivec(piv);
    output_ivec(piv);

    delete piv;

    return 0;
}
