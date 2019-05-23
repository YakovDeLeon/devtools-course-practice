// Copyright 2019 Vdovin Eugene

#ifndef MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_
#define MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_

class ElasticityOfDemand {
 public:
    ElasticityOfDemand();

    double PriceElasticityOfDemand(int quantity_1, int quantity_2,
    double price_1, double price_2);

    double IncomeElasticityOfDemand(int quantity_1, int quantity_2,
    double income_1, double income_2);

    double CrossElasticityOfDemand(int quantity_1_product_1,
    int quantity_2_product_1, double price_1_product_2,
    double price_2_product_2);
};

#endif  // MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_
