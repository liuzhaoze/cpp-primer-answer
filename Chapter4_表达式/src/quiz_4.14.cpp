/**
 * 执行下述 if 语句后将发生什么情况？
 */

int main()
{
    int i;

    // 非法， 42 不是左值
    if (42 = i) {
        return 1;
    }

    // if 条件恒为真
    if (i = 42) {
        return 2;
    }

    return 0;
}
