重新定义你的 Bulk_quote 类，令其继承构造函数。

> 答：

```cpp
class Bulk_quote : Disc_quote
{
  public:
    // 默认构造函数（无法继承）
    Bulk_quote()
    {
        std::cout << "Bulk_quote:\tdefault constructor" << std::endl;
    }
    // 构造函数（可以继承）
    using Disc_quote::Disc_quote;
    // 析构函数（无法继承）
    ~Bulk_quote() override
    {
        std::cout << "Bulk_quote:\tdestructor" << std::endl;
    }
    // 拷贝构造函数（无法继承）
    Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq)
    {
        std::cout << "Bulk_quote:\tcopy constructor" << std::endl;
    }
    // 移动构造函数（无法继承）
    Bulk_quote(Bulk_quote &&bq) noexcept : Disc_quote(std::move(bq))
    {
        std::cout << "Bulk_quote:\tmove constructor" << std::endl;
    }
    // 拷贝赋值运算符（无法继承）
    Bulk_quote &operator=(const Bulk_quote &);
    // 移动赋值运算符（无法继承）
    Bulk_quote &operator=(Bulk_quote &&) noexcept;

    double net_price(std::size_t) const override;
    void debug() const override;
};
```
