/**
 * 编写 4 个函数，分别对两个 int 值执行加、减、乘、除运算；
 * 在上一题创建的 vector 对象中保存指向这些函数的指针。
 */

#include <vector>

using std::vector;

int int_sum(int, int);
int int_minus(int, int);
int int_multiply(int, int);
int int_divide(int, int);

int main(int argc, char **argv)
{
    vector<decltype(int_sum) *> vec = {int_sum, int_minus, int_multiply, int_divide};

    return 0;
}
