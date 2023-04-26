/**
 * p 和 sp 的定义如下，对于接下来的对 process 的每个调用，如果合法，解释他做了什么，如果不合法，解释错误原因：
 */

#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
    std::cout << "reference count in function: " << ptr.use_count() << std::endl;
}

int main()
{
    auto p = new int();                // 内置指针
    auto sp = std::make_shared<int>(); // 智能指针
    std::cout << "p original: " << *p << std::endl;

    // (a) 合法
    process(sp); // 智能指针 sp 拷贝给形参 ptr ，引用计数加 1
    std::cout << "after (1): " << sp.use_count() << std::endl; // 形参销毁，引用计数减 1

    // (b) 不合法：不允许内置指针隐式转换为智能指针
    // process(new int());

    // (c) 不合法：不允许内置指针隐式转换为智能指针
    // process(p);

    // (d) 合法（但不推荐）
    process(std::shared_ptr<int>(p)); // 内置指针 p 拷贝给智能指针形参 ptr ，引用计数为 1
    // 形参销毁，引用计数减为 0 ，p 所指动态对象被释放
    std::cout << "p freed: " << *p << std::endl; // 非法：p 现在是悬空指针
    delete p;                                    // 非法：对同一内存释放两次

    return 0;
}
