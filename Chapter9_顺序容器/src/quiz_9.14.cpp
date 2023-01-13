/**
 * 编写程序，将一个 list 中的 char * 指针（指向 C 风格字符串）元素赋值给一个 vector 中的 string 。
 */
#include "../../lib/print_container.hpp"
#include <iostream>
#include <list>
#include <ostream>
#include <string>
#include <vector>


int main()
{
    std::list<const char *> lst = {"Apple", "Banana", "Cherry"};
    print_container(std::cout, lst.cbegin(), lst.cend()) << std::endl;

    std::vector<std::string> svec;
    svec.assign(lst.cbegin(), lst.cend());
    print_container(std::cout, svec.cbegin(), svec.cend()) << std::endl;

    return 0;
}
