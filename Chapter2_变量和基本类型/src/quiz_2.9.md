解释下列定义的含义。对于非法的定义，请说明错在何处并将其改正。

(a) `std::cin >> int input_value;`  
(b) `int i = { 3.14 };`  
(c) `double salary = wage = 9999.99;`  
(d) `int i = 3.14;`

> 答：  
> (a) 非法，定义和输入不能写在一个语句中。应改为
> `int input_value; std::cin >> input_value;`  
> (b) 非法，列表初始化不允许信息丢失。  
> (c) 非法，不能使用连等初始化，应改为：
> `double salary = 9999.99, wage = 9999.99;`  
> (d) 合法。
