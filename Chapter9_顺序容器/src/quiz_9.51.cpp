/**
 * 设计一个类，它有三个 unsigned 的成员，分别表示年、月和日。
 * 为其编写构造函数，接受一个表示日期的 string 参数。
 * 你的构造函数应该能处理不同数据格式，如 January 1, 1900 、1/1/1900 、Jan 1 1900 等。
 */

#include <iostream>
#include <string>

class My_date
{
  private:
    unsigned year, month, day;
    enum Format
    {
        slash,
        letter
    };

  public:
    My_date(const std::string &date)
    {
        Format f;
        char split;

        // 1/1/1900
        if (date.find_first_of("/") != std::string::npos)
        {
            f = slash;
        }
        // January 1, 1900 或 Jan 1, 1900
        if ((date.find_first_of(",") != std::string::npos) && (date.find_first_of(",") >= 4))
        {
            f = letter;
            split = ',';
        }
        else
        { // Jan 1 1900
            if ((date.find_first_of(" ") != std::string::npos) && (date.find_first_of(" ") >= 3))
            {
                f = letter;
                split = ' ';
            }
        }

        switch (f)
        {
        case slash:
            day = std::stoi(date.substr(0, date.find_first_of("/")));
            month =
                std::stoi(date.substr(date.find_first_of("/") + 1, date.find_last_of("/") - date.find_first_of("/")));
            year = std::stoi(date.substr(date.find_last_of("/") + 1, 4));
            break;

        case letter:
            if (date.find("Jan") < date.size())
                month = 1;
            if (date.find("Feb") < date.size())
                month = 2;
            if (date.find("Mar") < date.size())
                month = 3;
            if (date.find("Apr") < date.size())
                month = 4;
            if (date.find("May") < date.size())
                month = 5;
            if (date.find("Jun") < date.size())
                month = 6;
            if (date.find("Jul") < date.size())
                month = 7;
            if (date.find("Aug") < date.size())
                month = 8;
            if (date.find("Sep") < date.size())
                month = 9;
            if (date.find("Oct") < date.size())
                month = 10;
            if (date.find("Nov") < date.size())
                month = 11;
            if (date.find("Dec") < date.size())
                month = 12;

            day = std::stoi(date.substr(date.find_first_of("123456789"),
                                        date.find_first_of(split) - date.find_first_of("123456789")));
            year = std::stoi(date.substr(date.find_last_of(" ") + 1, 4));

            break;
        }
    }

    void print(void)
    {
        std::cout << "Year: " << year << " Month: " << month << " Day: " << day << std::endl;
    }
};

int main()
{
    My_date d1("January 1, 1900");
    My_date d2("Feb 2 2000");
    My_date d3("Mar 9, 2010");
    My_date d4("13/12/2012");

    d1.print();
    d2.print();
    d3.print();
    d4.print();

    return 0;
}
