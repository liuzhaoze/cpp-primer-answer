/**
 * 写出 map_it 的类型，不要使用 auto 或 decltype 。
 */

#include <cstddef>
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, std::size_t> word_count;
    std::map<std::string, std::size_t>::const_iterator map_it = word_count.cbegin();

    while (map_it != word_count.cend())
    {
        std::cout << map_it->first << " occurs " << map_it->second << " times" << std::endl;
        ++map_it;
    }

    return 0;
}
