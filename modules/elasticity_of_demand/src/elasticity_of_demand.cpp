// Copyright 2019 Vdovin Eugene

#include "include/elasticity_of_demand.h"
#include <cmath>

ElasticityOfDemand::ElasticityOfDemand() {}

double ElasticityOfDemand::PriceElasticityOfDemand(int quantity_1,
int quantity_2, double price_1, double price_2) {
    double dq = static_cast<double>(quantity_2 - quantity_1);
    double dp = price_2 - price_1;

    if ((fabs(dq) / static_cast<double>(quantity_1) < 0.05) &&
    fabs(dp) / price_1 < 0.05) {
        return (dq / static_cast<double>(quantity_1)) / (dp / price_1);
    } else {
        double p_ = (price_1 + price_2) / 2.0;
        double q_ = static_cast<double>(quantity_1 + quantity_2) / 2.0;

        return (dq / q_) / (dp / p_);
    }
}

double ElasticityOfDemand::IncomeElasticityOfDemand(int quantity_1,
int quantity_2, double income_1, double income_2) {
    double dq = static_cast<double>(quantity_2 - quantity_1);
    double di = income_2 - income_1;

    return (dq / static_cast<double>(quantity_1)) / (di / income_1);
}

double ElasticityOfDemand::CrossElasticityOfDemand(int quantity_1_product_1,
int quantity_2_product_1, double price_1_product_2, double price_2_product_2) {
    double dq = static_cast<double>(quantity_2_product_1 -
    quantity_1_product_1);
    double dp = price_2_product_2 - price_1_product_2;

    return (dq / static_cast<double>(quantity_1_product_1)) /
    (dp / price_1_product_2);
}
