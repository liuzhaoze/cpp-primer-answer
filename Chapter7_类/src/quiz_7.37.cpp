/**
 * 使用本节提供的 Sales_data 类，
 * 确定初始化下面的变量时分别使用了哪个构造函数，
 * 然后罗列出每个对象所有数据成员的值。
 */

Sales_data first_item(cin); // use Sales_data(std::istream &is) ; its value are up to your input.

int main()
{
    Sales_data next;                  // use Sales_data(std::string s = ""); bookNo = "", cnt = 0, revenue = 0.0
    Sales_data last("9-999-99999-9"); // use Sales_data(std::string s = ""); bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0
}
