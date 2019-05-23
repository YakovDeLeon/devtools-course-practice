// Copyright 2019 Ryabova Alyona

#ifndef MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_H_
#define MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_H_

#include <array>

class CalculatePrice {
 private:
    std::array<int, 5> basket_;
    double DiscountCalculate(const int book);

 public:
    CalculatePrice(int first_book, int second_book,
        int third_book, int fourth_book, int fifth_book);

    double TotalSum();
};

#endif  // MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_H_
