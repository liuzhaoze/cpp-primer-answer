/**
 * 用命名的强制类型转换改写下列旧式的转换语句。
 */

#include <string>

using std::string;

int main()
{
    int i;
    double d;
    const string *ps;
    char *pc;
    void *pv;

    // (a)
    pv = (void *)ps;
    pv = const_cast<string *>(ps);

    // (b)
    i = int(*pc);
    i = static_cast<int>(*pc);

    // (c)
    pv = &d;
    pv = static_cast<void *>(&d);

    // (d)
    pc = (char *)pv;
    pc = static_cast<char *>(pv);

    return 0;
}
