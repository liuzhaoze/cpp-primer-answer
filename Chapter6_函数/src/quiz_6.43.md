你会把下面的哪个声明和定义放在头文件中？哪个放在源文件中？为什么？

(a) `inline bool eq(const BigInt&, const BigInt&) { ... }`  
(b) `void putValues(int *arr, int size);`

> 答：两者都放在头文件中。  
> (a) 是内联函数的定义， (b) 是普通函数的声明。两者都应该放在头文件中。
