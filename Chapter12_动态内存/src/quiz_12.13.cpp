/**
 * 如果执行下面的代码，会发生什么？
 */

#include <memory>

int main()
{
    auto sp = std::make_shared<int>();
    auto p = sp.get();

    delete p; // 销毁 p (sp) 所指动态对象，但是 sp 的引用计数并未减少

    return 0;
    // sp 被销毁，引用计数从 1 减为 0 ，动态对象所在内存被二次释放
}
