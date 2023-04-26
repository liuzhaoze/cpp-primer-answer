/**
 * 编写你自己的 StrBlob 类，包含 const 版本的 front 和 back 。
 */

#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlob
{
  public:
    using size_type = std::vector<std::string>::size_type;

  private:
    std::shared_ptr<std::vector<std::string>> data; // 多个 StrBlob 对象共享一个 vector

    void check(size_type i, const std::string &msg) const
    {
        if (i >= data->size())
        {
            throw std::out_of_range(msg);
        }
    }

  public:
    StrBlob() : data(std::make_shared<std::vector<std::string>>())
    {
    }
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il))
    {
    }

    size_type size() const
    {
        return data->size();
    }
    bool empty() const
    {
        return data->empty();
    }

    void push_back(const std::string &t)
    {
        data->push_back(t);
    }
    void pop_back()
    {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    std::string &front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    std::string &back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }
    const std::string &front() const
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const std::string &back() const
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }
};

int main()
{
    const StrBlob csb{"hello", "world", "pezy"};
    StrBlob sb{"hello", "world", "Mooophy"};

    std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.front() = "pezy";
    std::cout << sb.front() << " " << sb.back() << std::endl;
}
