// Copyright 2019 Vorobev Pavel

#include <string>

#ifndef  MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_H_
#define  MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_H_

class MortgageCalculator {
 public:
    MortgageCalculator() = default;
    MortgageCalculator(MortgageCalculator&&) = default;

    double CalculatePayments(int sum, int first_payment,
        int credit_term, int annual_interest_rate);

    int CalculateLoanOverpayment(int monthly_payment,
        int credit_term, int sum);

    double GetCalculatedMonthlyPayment();

 private:
    double monthly_payment_;

    double ConvertToMonthlyInterestRate(int interest_rate);
    double CalculateAnnuityRate(double interest_rate, int credit_term);
};

#endif  // MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_H_
