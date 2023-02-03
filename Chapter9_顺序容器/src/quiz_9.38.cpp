/**
 * 编写程序，探究在你的标准库实现中，vector 是如何增长的？
 */

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec;

    std::cout << "空 vector" << std::endl;
    std::cout << "ivec size: " << ivec.size() << " capacity: " << ivec.capacity() << std::endl;

    for (std::vector<int>::size_type ix = 0; ix != 24; ++ix)
    {
        ivec.push_back(ix);
    }
    std::cout << "向 ivec 添加了 24 个元素" << std::endl;
    std::cout << "ivec size: " << ivec.size() << " capacity: " << ivec.capacity() << std::endl;

    ivec.reserve(50);
    std::cout << "预分配至少 50 个元素的空间" << std::endl;
    std::cout << "ivec size: " << ivec.size() << " capacity: " << ivec.capacity() << std::endl;

    while (ivec.size() != ivec.capacity())
    {
        ivec.push_back(0);
    }
    std::cout << "用光预分配的空间" << std::endl;
    std::cout << "ivec size: " << ivec.size() << " capacity: " << ivec.capacity() << std::endl;

    ivec.push_back(42);
    std::cout << "再添加一个元素" << std::endl;
    std::cout << "ivec size: " << ivec.size() << " capacity: " << ivec.capacity() << std::endl;

    return 0;
}
