/**
 * 编写你自己的 Account 类。
 */

#ifndef QUIZ_7_57_HPP
#define QUIZ_7_57_HPP

#include <string>

class Account
{
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }

private:
    std::string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 42.42;
    static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();

#endif
