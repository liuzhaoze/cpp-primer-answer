/**
 * 编写你自己版本的翻转函数，通过调用接受左值和右值引用参数的函数来测试它。
 */

#include <iostream>
#include <string>
#include <utility>

/**
 * @brief t1 是左值/右值，调用 f 时 t1 仍然是左值/右值（const 同样保持不变）
 *
 * @tparam F
 * @tparam T1
 * @tparam T2
 * @param f
 * @param t1
 * @param t2
 */
template <typename F, typename T1, typename T2> void flip(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void func_lvalue(std::string &lhs, std::string &rhs)
{
    lhs = "Wang";
    rhs = "Alan";
}

void func_rvalue(int &&lhs, int &&rhs)
{
    // allocate enough space
    std::allocator<int> alloc;
    int *data(alloc.allocate(3));

    // move into the spaced newly allocated
    alloc.construct(data, lhs);
    alloc.construct(data + 1, 0);
    alloc.construct(data + 2, rhs);

    // print
    for (auto p = data; p != data + 3; ++p)
        std::cout << *p << std::endl;

    // destroy and deallocation
    for (auto p = data + 3; p != data;)
        alloc.destroy(--p);
    alloc.deallocate(data, 3);
}

int main()
{
    // test for lvalue reference
    std::string s1, s2;
    flip(func_lvalue, s1, s2);
    std::cout << s1 << " " << s2 << std::endl;

    // test for rvalue reference
    flip(func_rvalue, 99, 88);

    return 0;
}
