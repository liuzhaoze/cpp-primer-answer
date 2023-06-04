/**
 * 编写函数，接受一个容器的引用，打印容器中的元素。
 * 使用容器的 size_type 和 size 成员来控制打印元素的循环。
 */

#include <iostream>
#include <vector>

template <typename T> std::ostream &print(std::ostream &os, const T &container)
{
    for (typename T::size_type i = 0; i != container.size(); ++i)
    {
        std::cout << container[i] << " ";
    }

    return os;
}

int main()
{
    std::vector<int> ivec = {1, 23, 6, 4, 5, 7, 4};

    print(std::cout, ivec) << std::endl;

    return 0;
}
