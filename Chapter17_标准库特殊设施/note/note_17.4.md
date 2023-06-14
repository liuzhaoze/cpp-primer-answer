# 17.4 随机数

> 本章术语：
>
> * 随机数引擎类（random-number engines）：生成 unsigned 随机数序列
> * 随机数分布类（random-number distribution）：使用引擎生成指定类型的、在给定范围内的、服从特定概率分布的随机数

[附录 A](../../AppendixA_%E6%A0%87%E5%87%86%E5%BA%93/A.3_%E9%9A%8F%E6%9C%BA%E6%95%B0.md)
列出了所有随机数分布和随机数引擎。

## 17.4.1 随机数引擎和分布

随机数引擎的操作：

* `Engine e;` ：使用默认构造函数定义一个随机数引擎
* `Engine e(s);` ：使用整型值 s 作为种子
* `e.seed(s)` ：使用种子 s 重置引擎的状态
* `e.max()` ：此引擎可以生成的最大值
* `e.min()` ：此引擎可以生成的最小值
* `Engine::result_type` ：此引擎生成的 unsigned 整型类型
* `e.discard(u)` ：将引擎推进 u 步；u 的类型为 unsigned long long

Engine 通常为 default_random_engine 。

随机数引擎和随机数分布都是函数对象类，都定义了对应的调用运算符。

**随机数发生器**指的是分布对象和引擎对象的组合。

一个给定的随机数发生器会一直生成**相同的**随机数序列。一个函数如果定义了**局部的**随机数发生器，应该将随机数引擎和随机数分布对象定义为 **static** 的。否则，每次调用函数都会生成相同的序列。

```cpp
vector<unsigned> bad_randVec()
{
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 9);
    vector<unsigned> ret;

    for (size_t i = 0; i < 100; ++i)
    {
        ret.push_back(u(e));
    }

    return ret;
}

vector<unsigned> good_randVec()
{
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0, 9);
    vector<unsigned> ret;

    for (size_t i = 0; i < 100; ++i)
    {
        ret.push_back(u(e));
    }

    return ret;
}

vector<unsigned> v1(bad_randVec()), v2(bad_randVec());   // v1 v2 具有相同的元素
vector<unsigned> v3(good_randVec()), v4(good_randVec()); // v3 v4 具有不同的元素
```

具有相同种子的引擎会生成相同的随机数序列。

通常使用 `<ctime>` 头文件中的 `time(0)` 函数作为种子。

*如果程序作为一个自动过程的一部分反复运行，将 time 的返回值作为种子的方式就无效了；它可能多次使用的都是相同的种子。*

## 17.4.2 其他随机数分布

随机数分布类的操作：

* `Dist d;` ：使用默认构造函数定义一个分布类对象（explicit 的）
* `d(e)` ：e 是一个随机数引擎对象；用相同的 e 连续调用 d 的话，会根据 d 的分布式类型生成一个随机数序列
* `d.max()` ：d(e) 能生成的最大值
* `d.min()` ：d(e) 能生成的最小值
* `d.reset()` ：重建 d 的状态，使得随后对 d 的使用不依赖于 d 已经生成的值

生成随机实数：

```cpp
default_random_engine e;
uniform_real_distribution<double> u(0, 1);
u(e);
```

分布类模板的尖括号为空时，生成浮点值的分布类型默认生成 double 值，生成整型值的分布类型默认生成 int 值。

由于引擎返回相同的随机数序列，所以我们必须在循环外声明引擎对象。否则，每步循环都会创建一个新引擎，从而每步循环都会生成相同的值。类似的，分布对象也要保持状态，因此也应该在循环外定义。

## 练习

* [练习 17.28](../src/quiz_17.28.cpp)
* [练习 17.29](../src/quiz_17.29.cpp)
* [练习 17.30](../src/quiz_17.30.cpp)
* [练习 17.31](../src/quiz_17.31.md)
* [练习 17.32](../src/quiz_17.32.md)
* [练习 17.33](../src/quiz_17.33.cpp)
