假设下面的 `operator*` 声明的是嵌套的命名空间 `mathLib::MatrixLib` 的一个成员：

```cpp
namespace mathLib {
    namespace MatrixLib {
        class matrix { /* ... */ };
        matrix operator*(const matrix &, const matrix &);
    }
}
```

请问你应该如何在全局作用域中声明该运算符？

> 答：`mathLib::MatrixLib::matrix mathLib::MatrixLib::operator*(const mathLib::MatrixLib::matrix &, const mathLib::MatrixLib::matrix &)`
>
> 或者 `mathLib::MatrixLib::matrix mathLib::MatrixLib::operator*(const matrix &, const matrix &)`
