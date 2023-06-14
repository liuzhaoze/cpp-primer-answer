对于本节中的游戏程序，如果在 do 循环内定义 b 和 e ，会发生什么？

```cpp
string resp;
default_random_engine e;
bernoulli_distribution b; // 非模板分布类，默认 p = 0.5

do {
    bool first = b(e);
    cout << (first ? "We go first" : "You go first") << endl;
    // 进行游戏
    cout << "play again? y or n." << endl;
} while(cin >> resp && resp[0] == 'y');
```

> 答：如果在 do 循环内定义 b 和 e ，那么每次循环得到的 first 变量的值都是相同的。
