使用标准库函数对象及适配器定义一条表达式，令其

(a) 统计大于 1024 的值有多少个  
(b) 找到第一个不等于 pooh 的字符串  
(c) 将所有的值乘以 2

> 答：  
> (a) `std::count_if(ivec.cbegin(), ivec.cend(), std::bind(std::greater<int>(), _1, 1024));`  
> (b) `std::find_if(svec.cbegin(), svec.cend(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));`  
> (c) `std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::bind(std::multiplies<int>(), _1, 2));`

见 [10.3.4 节](../../Chapter10_%E6%B3%9B%E5%9E%8B%E7%AE%97%E6%B3%95/note/note_10.3.md)参数绑定。
