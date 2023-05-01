/**
 * 编写程序实现文本查询，不要定义类来管理数据。
 * 你的程序应该接受一个文件，并与用户交互来查询单词。
 * 使用 vector 、map 和 set 容器来保存来自文件的数据并生成查询结果。
 */

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    using line_no = std::vector<std::string>::size_type;
    std::ifstream infile("../data/storyDataFile");
    std::vector<std::string> file;
    std::map<std::string, std::set<line_no>> wm;

    // 建立索引
    std::string line;
    while (std::getline(infile, line))
    {
        file.push_back(line);

        int n = file.size();
        std::istringstream iss(line);
        std::string word;
        while (iss >> word)
        {
            auto &exist_lines = wm[word];
            exist_lines.insert(n);
        }
    }

    // 查询
    while (true)
    {
        std::cout << "Enter word to look for, or \'q\' to quit: ";
        std::string s;

        if (!(std::cin >> s) || s == "q")
        {
            std::cout << "Exited." << std::endl;
            break;
        }

        std::cout << "\'" << s << "\' occurs " << wm[s].size() << ((wm[s].size() > 1) ? " times." : " time.")
                  << std::endl;

        for (auto num : wm[s])
        {
            std::cout << "\t(line " << num << ") " << file[num - 1] << std::endl;
        }
    }

    return 0;
}
