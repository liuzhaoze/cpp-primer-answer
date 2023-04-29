shared_ptr 为什么没有 release 成员？

> 答：因为多个 shared_ptr 可以指向同一个动态对象，并且他们都可以释放对象。因此没必要为 shared_ptr 提供单独的释放对象的功能。
