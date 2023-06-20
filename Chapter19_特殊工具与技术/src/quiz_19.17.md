为 Screen 的所有成员函数类型各定义一个类型别名。

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
```

> 答：  
> `using Name1 = char (Screen::*)() const;`  
> `using Name2 = char (Screen::*)(Screen::pos, Screen::pos) const;`
