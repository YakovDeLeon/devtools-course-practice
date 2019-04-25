// Copyright 2019 Sitkin Dmitry

#ifndef MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_H_
#define MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_H_

class DepositCalculator {
 public:
    DepositCalculator() = default;
    DepositCalculator(DepositCalculator&&) = default;

    int GetInitialAmount();
    int GetTerm();
    double GetAnnualInterest();
    int GetCapitalization();

    void SetInitialAmount(int initial_amount);
    void SetTerm(int term);
    void SetAnnualInterest(double annual_interest);
    void SetCapitalization(int capitalization);

    double Calculate();

 private:
     int initial_amount_;
     int term_;
     double annual_interest_;
     int capitalization_;
};

#endif  // MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_H_

