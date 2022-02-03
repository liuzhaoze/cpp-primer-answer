/**
 * 解释下面代码的含义，说明其中的 Type 和 initVal 分别使用了哪个定义。
 * 如果代码存在错误，尝试修改他。
 */

#include <string>

using std::string;

typedef string Type; // Type 是 string
Type initVal();      // Type 是 string

class Exercise
{
public:
    typedef double Type; // Type 是 double
    Type setVal(Type);   // Type 是 double
    Type initVal();      // Type 是 double

private:
    int val;
};

/*
Type Exercise::setVal(Type parm) // 第一个 Type 是 string ，第二个 Type 是 double
{
    val = parm + initVal();
    return val;
}
val 是 int ，与 string 不匹配。
*/
// 应改为：
Exercise::Type Exercise::setVal(Type parm)
{
    val = parm + initVal();
    return val;
}

// 同时， Exercise::initVal() 应该被定义
