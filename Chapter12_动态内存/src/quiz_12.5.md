我们未编写接受一个 `initializer_list explicit` 参数的构造函数。讨论这个设计策略的优点和缺点。

> 答：
>
> * 优点：
>   * 使用 `explicit` 可以避免编译器将初始化列表隐式类型转换为 StrBlob
>   * 使用 `explicit` 可以明确到底是用的哪一个类
> * 缺点：
>   * 必须显式使用构造函数来构造临时的 StrBlob 对象
>   * 不能简单地将初始化列表赋值给 StrBlob 对象来完成初始化
