/**
 * 编写函数的声明，令其接受两个 int 形参并且返回类型也是 int ；
 * 然后声明一个 vector 对象，令其元素是指向该函数的指针。
 */

#include <vector>

using std::vector;

int func(int, int);

int main(int argc, char **argv)
{
    vector<decltype(func) *> vec = {func};

    return 0;
}
