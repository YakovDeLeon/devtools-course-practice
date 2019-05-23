// Copyright 2019 Ryabova Alyona

#include "include/calculate_price.h"

#include <stdio.h>
#include <string>

CalculatePrice::CalculatePrice(int first_book, int second_book,
        int third_book, int fourth_book, int fifth_book) {
    if ((first_book < 0) || (second_book < 0) ||
        (third_book < 0) || (fourth_book < 0) || (fifth_book < 0))
        throw std::string("Mustn't be contain negative numbers");
    basket_ = {{first_book, second_book, third_book,
        fourth_book, fifth_book}};
}

double CalculatePrice::DiscountCalculate(const int book) {
    double sum = 0.0;
    double price = 8.0;

    switch (book) {
        case 1:
            sum = price; break;
        case 2:
            sum = price * book * 0.95; break;
        case 3:
            sum = price * book * 0.9; break;
        case 4:
            sum = price * book * 0.8; break;
        case 5:
            sum = price * book * 0.75; break;
    }

    return sum;
}

double CalculatePrice::TotalSum() {
    double sum = 0.0;
    std::array<int, 5> shop_basket;

    for (int i = 0; i < 5; i++) {
        shop_basket[i] = basket_[i];
    }

    int books = 0;

    for (int i = 0; i < 5; i++) {
        books += shop_basket[i];
    }

    while (books) {
        int count = 0;
        for (int i = 0; i < 5; i++) {
            if (shop_basket[i]) {
                books--;
                shop_basket[i]--;
                count++;
            }
        }
        sum += DiscountCalculate(count);
    }

    return sum;
}
