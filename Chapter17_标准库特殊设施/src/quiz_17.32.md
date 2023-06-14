如果我们在循环内定义 resp ，会发生什么？

```cpp
string resp;
default_random_engine e;
bernoulli_distribution b; // 非模板分布类，默认 p = 0.5

do {
    bool first = b(e);
    cout << (first ? "We go first" : "You go first") << endl;
    // 进行游戏
    cout << "play again? y or n." << endl;
} while (cin >> resp && resp[0] == 'y');
```

> 答：会发生编译错误。因为 while 条件访问 resp 时已经在大括号所表示的作用域外，定义在循环内的 resp 在离开作用域后就被销毁了。
