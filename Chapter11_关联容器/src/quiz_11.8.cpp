/**
 * 编写一个程序，在一个 vector 而不是一个 set 中保存不重复的单词。
 * 使用 set 的优点是什么？
 */

// 使用 set 可以使元素始终保持有序、唯一
// 在 set 中插入/删除元素的时间复杂度比 vector 低（O(log(n)) vs O(n)）

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end()); // 按字典排序
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end()); // 删除重复的单词
}

int main()
{
    std::ifstream ifstrm("../data/accum");
    std::istream_iterator<std::string> in_iter(ifstrm), eof;
    std::vector<std::string> svec(in_iter, eof);
    std::cout << "Original count: " << svec.size() << std::endl;

    auto start = std::chrono::steady_clock::now();
    std::set<std::string> sset(svec.cbegin(), svec.cend());
    auto end = std::chrono::steady_clock::now();
    std::cout << "Set run time is " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds." << std::endl;

    start = std::chrono::steady_clock::now();
    elimDups(svec);
    end = std::chrono::steady_clock::now();
    std::cout << "Vector run time is " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds." << std::endl;

    std::cout << "Unique count: " << svec.size() << " " << sset.size() << std::endl;

    return 0;
}
