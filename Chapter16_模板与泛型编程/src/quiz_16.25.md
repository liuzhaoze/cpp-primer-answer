解释下面这些声明的含义：

```cpp
extern template class vector<string>;
template class vector<Sales_data>;
```

> 答：  
> `extern template class vector<string>;` 实例化声明：表明该类的实例化在其他文件中  
> `template class vector<Sales_data>;` 实例化定义：表明在本文件中实例化了该类（产生代码）
