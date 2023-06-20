下面的代码合法吗？如果合法，代码的意义是什么？如果不合法，解释原因。

```cpp
class Screen {
public:
    using pos = std::string::size_type;

private:
    std::string contents;
    pos cursor;
    pos height, width;

public:
    char get_cursor() const { return contents[cursor]; }
    char get() const;
    char get(pos ht, pos wd) const;
};

auto pmf = &Screen::get_cursor;
pmf = &Screen::get;
```

> 答：合法，两个函数都是返回值为 char ，形参列表为空的函数。pmf 先指向 get_cursor ，后指向 get 。
