/**
 * 根据自己的理解写出 Sales_data 类，
 * 最好与书中的例子有所区别。
 */

#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
