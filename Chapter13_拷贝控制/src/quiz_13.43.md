重写 free 成员，用 for_each 和 lambda 来代替 for 循环 destroy 元素。
你更倾向于哪种实现，为什么？

> 答：见 [StrVec.hpp](../../lib/StrVec.hpp) 和 [StrVec.cpp](../../lib/StrVec.cpp) 。  
> 我更倾向于使用 for_each 和 lambda ，因为新写法不用考虑指针的递减操作以及范围问题，使用起来更加方便。
