/**
 * 编写一个类令其检查两个值是否相等。
 * 使用该对象及标准库算法编写程序，令其替换某个序列中具有给定值的所有实例。
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class IsEqual
{
  private:
    int value;

  public:
    IsEqual(int v) : value(v)
    {
    }

    bool operator()(int i)
    {
        return i == value;
    }
};

int main()
{
    std::vector<int> vec = {3, 2, 1, 4, 3, 7, 8, 6};

    std::replace_if(vec.begin(), vec.end(), IsEqual(3), 99);

    std::ostream_iterator<int> out(std::cout, " ");
    std::copy(vec.begin(), vec.end(), out);
    std::cout << std::endl;

    return 0;
}
