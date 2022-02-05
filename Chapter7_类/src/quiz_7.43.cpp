/**
 * 假定有一个名为 NoDefault 的类，他有一个接受 int 的构造函数，
 * 但是没有默认构造函数。
 * 定义类 C ， C 有一个 NoDefault 类型的成员，
 * 定义 C 的默认构造函数。
 */

class NoDefault
{
public:
    NoDefault(int i) : number(i) {}

private:
    int number;
};

class C
{
public:
    C() : nod(0) {}

private:
    NoDefault nod;
};
