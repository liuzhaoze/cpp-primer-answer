/**
 * 重写上一题的函数，使用 begin 和 end 返回的迭代器来控制循环。
 */

#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T> std::ostream &print(std::ostream &os, const T &container)
{
    for (auto iter = container.begin(); iter != container.end(); ++iter)
    {
        std::cout << *iter << " ";
    }

    return os;
}

int main()
{
    std::vector<int> ivec = {1, 23, 6, 4, 5, 7, 4};
    std::list<std::string> slst = {"ss", "sszz", "saaas", "s333s", "ss2", " sss"};

    print(std::cout, ivec) << std::endl;
    print(std::cout, slst) << std::endl;

    return 0;
}
