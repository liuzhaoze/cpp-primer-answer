/**
 * 下面的函数合法吗？如果合法，说明其功能；
 * 如果不合法，修改其中的错误并解释原因。
 */

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

/**
 * @brief 获得数组对应元素的引用
 * 
 * @param array 
 * @param index 
 * @return int& 
 */
int &get(int *array, int index)
{
    return array[index];
}

int main(int argc, char *argv[])
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;

    for (int i = 0; i != 10; ++i)
        cout << ia[i] << " ";
    cout << endl;

    return EXIT_SUCCESS;
}
