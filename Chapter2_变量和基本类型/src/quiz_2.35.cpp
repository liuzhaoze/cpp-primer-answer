/**
 * 判断下列定义推断出的类型是什么，然后编写程序进行验证。
 */

int main()
{
    const int i = 42;

    auto j = i;                  // j 是 int （忽略 i 的顶层 const ）
    const auto &k = i;           // k 是 const int &
    auto *p = &i;                // p 是 const int * （&i 是 const int * ，是底层 const）
    const auto j2 = i, &k2 = i;  // j2 是 const int ，k2 是 const int &

    return 0;
}
