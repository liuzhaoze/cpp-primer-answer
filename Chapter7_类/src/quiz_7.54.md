Debug 中以 set_ 开头的成员应该被声明成 constexpr 吗？如果不，为什么？

> 答：在 C++11 中，以 set_ 开头的成员函数会修改成员变量的值，因此不能被声明成 constexpr 的。在 C++14 中，该特性被移除，所以可以被声明成 constexpr 的。
