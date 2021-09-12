/**
 * 假设 ptr 的类型是 int * 、vec 的类型是 vector<int> 、
 * ival 的类型是 int ，说明下面的表达式是何含义？
 * 如果有表达式不正确，为什么？
 * 应该如何修改？
 */

#include <vector>

int main()
{
    int ival, *ptr;
    std::vector<int> vec;

    if (ptr != 0 && *ptr++) {
        return 1;
        // 首先检查 ptr 是否为空指针
        // 然后对 ptr 所指元素解引用，判断其是否为 0
        // 最后将 ptr 指向下一个元素的位置
    }

    if (ival++ && ival) {
        return 2;
        // 首先判断 ival 是否为 0
        // 如果是 0 ，不执行 if 内语句， ival 加 1
        // 如果不是 0 ，继续判断 ival 加 1 之后是否为 0
    }

    if (vec[ival++] <= vec[ival]) {
        return 3;
        // 该表达式有歧义
        // 如果先求左边的表达式，则是判断前一个元素是否小于等于后一个元素
        // 如果先求右边的表达式，则两个表达式恒等
    }

    return 0;
}
