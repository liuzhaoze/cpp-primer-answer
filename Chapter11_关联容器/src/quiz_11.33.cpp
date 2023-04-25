/**
 * 实现你自己版本的单词转换程序。
 */

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

/**
 * @brief 读入给定文件，建立单词转换映射
 *
 * @param map_file
 * @return std::map<std::string, std::string>
 */
std::map<std::string, std::string> build_map(std::ifstream &map_file)
{
    std::map<std::string, std::string> trans_map; // 转换规则
    std::string key;
    std::string value;

    while (map_file >> key && std::getline(map_file, value)) // 每行第一个单词读入 key 其余单词读入 value
    {
        if (value.size() > 1) // 注意 getline 会读入 key 后面的空格
        {
            trans_map[key] = value.substr(1);
        }
        else
        {
            throw std::runtime_error("no rule for key: " + key);
        }
    }

    return trans_map;
}

/**
 * @brief 查找输入单词 s 是否在字典 rules 中。
 *        如果存在，返回 s 对应的替换结果；否则返回原单词。
 *
 * @param s
 * @param rules
 * @return const std::string&
 */
const std::string &transform(const std::string &s, const std::map<std::string, std::string> &rules)
{
    auto iter = rules.find(s);
    return (iter != rules.cend()) ? iter->second : s;
}

/**
 * @brief 根据替换规则输出替换单词之后的文本
 *
 * @param map_file 保存替换规则的文件
 * @param input 保存将要替换单词的文本
 */
void word_transform(std::ifstream &map_file, std::ifstream &input)
{
    auto trans_map = build_map(map_file);
    std::string line;

    while (std::getline(input, line))
    {
        std::istringstream stream(line);
        std::string word;
        bool first_word = true; // 控制第一个单词不输出空格

        while (stream >> word)
        {
            if (first_word)
            {
                first_word = false;
            }
            else
            {
                std::cout << " ";
            }
            std::cout << transform(word, trans_map);
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::ifstream rules_file("../data/rules"), text_file("../data/text");

    word_transform(rules_file, text_file);

    return 0;
}
