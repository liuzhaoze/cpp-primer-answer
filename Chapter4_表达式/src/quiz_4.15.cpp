/**
 * 下面的赋值是非法的，为什么？
 * 应该如何修改？
 */

int main()
{
    double dval;
    int ival;
    int *pi;

    dval = ival = pi = 0;  // 非法，指针不能赋值给整型变量

    // 应改为：
    dval = ival = 0;
    pi = 0;

    return 0;
}
