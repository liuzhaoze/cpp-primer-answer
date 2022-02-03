/**
 * 编写你自己的 Screen 类。
 */

#ifndef QUIZ_7_23_HPP
#define QUIZ_7_23_HPP

#include <string>

class Screen
{
public:
    using pos = std::string::size_type;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

#endif
