/**
 * 下面的初始值是错误的，请找出问题所在并尝试修改他。
 */

struct X
{
    X(int i, int j) : base(i), rem(base % j) {}
    int rem, base;
};

// 错误：使用 base 初始化 rem
// 应改为：

struct X
{
    X(int i, int j) : base(i), rem(i % j) {}
    int rem, base;
};
