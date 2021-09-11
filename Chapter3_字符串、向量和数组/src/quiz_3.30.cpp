/**
 * 指出下面代码中的索引错误。
 */

int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 1; ix <= array_size; ++ix)
        ia[ix] = ix;

    // ia 的索引范围是 0~9 ，循环中 ix 的范围是 1~10
    return 0;
}
