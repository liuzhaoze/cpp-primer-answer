#include "strip.hpp"

/**
 * @brief 将单词转换为小写，并去除可能的标点符号
 *
 * @param str
 * @return std::string
 */
std::string strip(std::string str)
{
    for (auto &c : str)
    {
        c = std::tolower(c);
    }
    str.erase(std::remove_if(str.begin(), str.end(), std::ispunct), str.end());
    return str;

    /**
     * remove_if 返回一个迭代器，指向被移除后的新容器的结尾位置。
     * remove_if 仅仅是将满足条件的元素移动到容器尾部，并不会真正删除这些元素。
     * ※ 算法不会改变容器的大小
     * 因此需要再将这些被移动到容器尾部的元素用 erase 函数真正地从容器中删除掉。
     * 如果只使用 remove_if 而不使用 erase ，则容器中仍会保留这些被移动到容器尾部的元素。
     */
}
