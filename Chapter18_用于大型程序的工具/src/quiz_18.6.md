已知下面的异常类型和 catch 语句，书写一个 throw 表达式使其创建的异常对象能被这些 catch 语句捕获：

```cpp
class exceptionType { };
catch (exceptionType *pet) { } // (a)

catch (...) { } // (b)

typedef int EXCPTYPE;
catch (EXCPTYPE) { } // (c)
```

> 答：  
> (a) `throw &exceptionType();`  
> (b) throw 任何类型的表达式都能被捕获  
> (c) `throw 42;`
