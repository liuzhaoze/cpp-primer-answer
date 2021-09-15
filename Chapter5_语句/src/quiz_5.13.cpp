/**
 * 下面显示的每个程序都含有一个常见的编程错误，指出错误在哪里，然后修改它们。
 */

#include <vector>

#define A 1
#define B 1
#define C 0
#define D 0

#if A
char next_text(void);
#endif

#if B
unsigned some_value(void);
int get_value(void);
#endif

#if C
int get_num(void);
#endif

#if D
unsigned get_bufCnt(void);
#endif

int main()
{
    #if A
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a':
            aCnt++;
        case 'e':
            eCnt++;
        default:
            iouCnt++;
    }
    // 错误：每个部分都没有加 break;
    #endif

    #if B
    std::vector<int> ivec;
    unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ix] = index;
            break;
        default:
            ix = ivec.size() - 1;
            ivec[ix] = index;
    }
    // 错误：变量 ix 的声明在 index 不等于 1 时会被跳过，从 default 开始运行时 ix 未定义
    // 应该声明在 switch 外面
    #endif

    #if C
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddCnt++;
            break;
        case 2, 4, 6, 8, 10:
            evenCnt++;
            break;
    }
    // 错误：多重变量应改写为：
    // case 1: case 3: case 5: case 7: case 9:
    // case 2: case 4: case 6: case 8: case 10:
    #endif

    #if D
    unsigned ival = 512, jval = 1024, kval = 4069;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch (swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
    // 错误：表达式必须是常量，不能是变量
    // 应该直接替换成 512 、 1024 、 4096
    #endif

    return 0;
}
