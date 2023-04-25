/**
 * 可以用什么类型来对一个 map 进行下标操作？
 * 下标运算符返回的类型是什么？
 * 请给出一个具体例子——即，定义一个 map ，然后写出一个可以用来对 map 进行下标操作的类型以及下标运算符将会返回的类型。
 */

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>

int main()
{
    std::map<int, std::string> m = {{1, "one"}, {2, "two"}};

    // 可以用 key_type 类型对 map 进行下标操作，本例中 key_type 是 int 类型
    using Type = std::map<int, std::string>::key_type;
    std::cout << typeid(Type).name() << std::endl;

    Type k = 2;
    // 下标运算符返回的类型是 mapped_type ，本例中 mapped_type 是 string 类型
    std::cout << typeid(decltype(m[k])).name() << std::endl;

    return 0;
}
