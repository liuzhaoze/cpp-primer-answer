根据表中所示的虚函数的定义情况，逐一说明：

* 指向 Panda 对象的 Bear 指针
* 指向 Panda 对象的 Endangered 指针
* 指向 Panda 对象的 ZooAnimal 指针

的一系列调用。

|函数|含有自定义版本的类|
|:-:|:-:|
|print|ZooAnimal <br> Bear <br> Endangered <br> Panda|
|highlight|Endangered <br> Panda|
|toes|Bear <br> Panda|
|cuddle|Panda|
|析构函数|ZooAnimal<br> Endangered|

> 答：

```cpp
Bear *pb = new Panda("ying_yang");
pb->print();     // 正确：静态类型 Bear 中含有 print ，调用动态类型 Panda 的 print
pb->cuddle();    // 错误：静态类型 Bear 中未定义 cuddle
pb->highlight(); // 错误：静态类型 Bear 中未定义 highlight
delete pb;       // 正确：调用动态类型 Panda 的析构函数

Endangered *pe = new Panda("ying_yang");
pe->print();     // 正确：静态类型 Endangered 中含有 print ，调用动态类型 Panda 的 print
pe->toes();      // 错误：静态类型 Endangered 中未定义 toes
pe->cuddle();    // 错误：静态类型 Endangered 中未定义 cuddle
pe->highlight(); // 正确：静态类型 Endangered 中含有 highlight ，调用动态类型 Panda 的 highlight
delete pe;       // 正确：调用动态类型 Panda 的析构函数

ZooAnimal *pz = new Panda("ying_yang");
pz->print();     // 正确：静态类型 ZooAnimal 中含有 print ，调用动态类型 Panda 的 print
pz->toes();      // 错误：静态类型 ZooAnimal 中未定义 toes
pz->cuddle();    // 错误：静态类型 ZooAnimal 中未定义 cuddle
pz->highlight(); // 错误：静态类型 ZooAnimal 中未定义 highlight
delete pz;       // 正确：调用动态类型 Panda 的析构函数
```
