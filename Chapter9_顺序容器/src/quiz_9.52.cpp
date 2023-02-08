/**
 * 使用 stack 处理括号化的表达式。
 * 当你看到一个左括号，将其记录下来。
 * 当你在一个左括号之后看到一个右括号，从 stack 中 pop 对象直至遇到左括号，将左括号也一起弹出栈。
 * 然后将一个值（括号内的运算结果）push 到栈中，表示一个括号化的（子）表达式已经处理完毕，被其运算结果所替代。
 */

/**
 * 中缀表达式的计算：
 * 1. 遇到操作数：直接压入操作数栈
 * 2. 遇到 ( ：直接压入运算符栈
 * 3. 遇到 ) ：弹出 ( 上面的所有运算符，然后弹出 (
 * 4. 遇到运算符：先弹出比当前运算符优先级高的所有运算符，直到栈空或 ( 在栈顶
 *              然后将当前运算符压入运算符栈
 * 只要从运算符栈弹出一个运算符，就要从操作数栈先后弹出右操作数和左操作数，将运算结果压入操作数栈
 */

#include <cctype>
#include <iostream>
#include <stack>
#include <string>

double process_operator(const char op, std::stack<std::string> &number_stack)
{
    // 弹出右操作数
    double right = std::stod(number_stack.top());
    number_stack.pop();
    // 弹出左操作数
    double left = std::stod(number_stack.top());
    number_stack.pop();
    double result;

    switch (op)
    {
    case '+':
        result = left + right;
        break;
    case '-':
        result = left - right;
        break;
    case '*':
        result = left * right;
        break;
    case '/':
        result = left / right;
        break;
    }
    number_stack.push(std::to_string(result));

    return result;
}

int main(int argc, char **argv)
{
    std::string expression = "(12+13)/2+2*3-((15-3)/7+2)";
    std::stack<std::string> op_stk;
    std::stack<std::string> num_stk;
    std::string num_cache;

    if (argc == 1)
    {
        std::cout << "Build-in expression will be used:" << std::endl;
        std::cout << expression << std::endl;
    }
    else
    {
        expression = argv[1];
    }

    // 合法性检测
    if (expression.find_first_not_of("()+-*/. 0123456789") != std::string::npos)
    {
        std::cerr << "Invalid expression." << std::endl;
        return -1;
    }

    for (const char &c : expression)
    {
        if (c == ' ')
        {
            continue;
        }

        if (std::isalnum(c) || c == '.')
        {
            // 遇到了数字或小数点
            num_cache.append(1, c);
        }
        else
        {
            // 遇到了括号或者运算符
            if (!num_cache.empty())
            {
                num_stk.push(num_cache); // 前面的操作数直接入栈
                num_cache.clear();       // 入栈后清空缓存
            }
            switch (c)
            {
            case '(':
                // 遇到左括号直接入栈
                op_stk.push(std::string(&c, 1));
                break;

            case ')':
                // 遇到右括号弹出左括号上面的所有运算符，然后弹出左括号
                while ((!op_stk.empty()) && (op_stk.top() != std::string("(")))
                {
                    char op = op_stk.top()[0];
                    op_stk.pop();
                    process_operator(op, num_stk);
                }
                if ((!op_stk.empty()) && (op_stk.top() == std::string("(")))
                {
                    op_stk.pop();
                }
                break;

            default:
                // 遇到运算符
                // 首先弹出比当前运算符优先级高的所有运算符直到栈空或左括号在栈顶
                if ((c == '+') || (c == '-'))
                {
                    while ((!op_stk.empty()) && (op_stk.top() != std::string("(")) &&
                           ((op_stk.top() == std::string("*")) || (op_stk.top() == std::string("/"))))
                    {
                        char op = op_stk.top()[0];
                        op_stk.pop();
                        process_operator(op, num_stk);
                    }
                }

                // 然后当前运算符入栈
                op_stk.push(std::string(&c, 1));
                break;
            }
        }
    }

    // 处理缓存中的数据
    num_stk.push(num_cache);
    num_cache.clear();

    // 清空运算符栈元素
    while (!op_stk.empty())
    {
        char op = op_stk.top()[0];
        op_stk.pop();
        process_operator(op, num_stk);
    }

    // 输出结果
    std::cout << "result: " << num_stk.top() << std::endl;
    std::cout << "size of number stack: " << num_stk.size() << std::endl;

    return 0;
}
