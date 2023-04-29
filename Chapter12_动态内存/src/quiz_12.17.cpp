/**
 * 下面的 unique_ptr 声明中，哪些是合法的，哪些是可能导致后续的程序错误？
 * 解释每个错误的问题在哪里。
 */

#include <memory>

int main()
{
    typedef std::unique_ptr<int> IntP;
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);

    // (a) 错误：不能使用对象初始化指针
    // IntP p0(ix);

    // (b) 能通过编译，但会发生运行时错误：当 p1 离开作用域时，p1 指向的对象会被释放，此时 pi 就成为了悬空指针
    IntP p1(pi);

    // (c) 情况与 (b) 类似，pi2 会成为悬空指针
    IntP p2(pi2);

    // (d) 情况与 (b) 类型，pi 会成为悬空指针
    IntP p3(&ix);

    // (e) 正确
    IntP p4(new int(2048));

    // (f) 错误：unique_ptr p5 和 p2 都指向同一个内存区域，当两者均离开作用域时，该内存区域会被释放两次
    IntP p5(p2.get());

    return 0;
}
