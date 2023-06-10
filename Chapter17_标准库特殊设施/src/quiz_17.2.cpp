/**
 * 定义一个 tuple ，保存一个 string 、一个 vector<string> 和一个 pair<string, int> 。
 */

#include <string>
#include <tuple>
#include <utility>
#include <vector>

int main()
{
    std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> t("str1", {"0", "1", "2"},
                                                                                     {"str2", 2});

    return 0;
}
