/**
 * 假设 txt_size 是一个无参数的函数，它的返回值是 int 。
 * 请回答下列哪个定义是非法的？为什么？
 */

int txt_size(void);

int main()
{
    unsigned buf_size = 1024;

    int ia[buf_size];    // 非法， buf_size 不是常量表达式
    int ib[4 * 7 - 14];  // 合法， 4 * 7 - 14 是常量表达式
    int ic[txt_size()];  // 非法， txt_size 不是 constexpr
    char st[11] = "fundamental";  // 非法，没有空间存放空字符'\0'
}
