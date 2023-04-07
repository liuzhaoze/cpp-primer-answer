在本节对名册（roster）调用 equal 的例子中，如果两个名册中保存的都是 C 风格字符串而不是 string ，会发生什么？

```cpp
vector<const char*> roster1 = { "C++", "Primer", "Plus" };
vector<const char*> roster2 = { "C++", "Primer", "Plus" };
equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
```

> 答：equal 的结果可能是 false ，也可能是 true 。  
> vector 中存放的实际元素是指向字符串字面量的指针，实际比较的是两者地址是否相等。  
> 使用 g++ 编译时，编译器使用相同的地址存放两个 vector 中相同的字符串，此时 equal 返回 true；  
> 使用 cl 编译时，编译器将 vector 中相同的字符串存放在独立的地址中，此时 equal 返回 false。
