/**
 * 修改 11.3.6 节中的单词转换程序，允许对一个给定单词有多种转换方式，每次随机选择一种进行实际转换。
 * 原注释见 quiz_11.33.cpp
 */

#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

std::default_random_engine e(time(0));

std::vector<std::string> split_value(const std::string &value)
{
    std::istringstream iss(value);
    std::string token;
    std::vector<std::string> ret;

    while (std::getline(iss, token, '|'))
    {
        ret.push_back(token);
    }

    return ret;
}

std::map<std::string, std::vector<std::string>> build_map(std::ifstream &map_file)
{
    std::map<std::string, std::vector<std::string>> trans_map; // 转换规则
    std::string key;
    std::string value;

    while (map_file >> key && std::getline(map_file, value)) // 每行第一个单词读入 key 其余单词读入 value
    {
        if (value.size() > 1) // 注意 getline 会读入 key 后面的空格
        {
            trans_map[key] = split_value(value.substr(1));
        }
        else
        {
            throw std::runtime_error("no rule for key: " + key);
        }
    }

    return trans_map;
}

const std::string &transform(const std::string &s, const std::map<std::string, std::vector<std::string>> &rules)
{
    auto iter = rules.find(s);

    if (iter != rules.cend())
    {
        std::uniform_int_distribution<> u(0, iter->second.size() - 1);
        return iter->second[u(e)];
    }
    else
    {
        return s;
    }
}

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
    std::ifstream rules_file("../data/rules_new"), text_file("../data/text");

    word_transform(rules_file, text_file);

    return 0;
}
