/**
 * 重做上一题，这次使用 shared_ptr 而不是内置指针。
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<int>> alloc_ivec(void)
{
    return std::make_shared<std::vector<int>>();
}

std::shared_ptr<std::vector<int>> input_ivec(std::shared_ptr<std::vector<int>> p)
{
    int i;

    while (std::cin >> i)
    {
        p->push_back(i);
    }

    return p;
}

std::shared_ptr<std::vector<int>> output_ivec(std::shared_ptr<std::vector<int>> p)
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

    return 0;
}
