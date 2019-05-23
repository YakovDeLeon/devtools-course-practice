// Copyright 2019 Vdovin Eugene

#include <gtest/gtest.h>
#include "include/elasticity_of_demand.h"

TEST(ElasticityOfDemandTest, check_1_price_elasticity_of_demand) {
    // Arrange
    ElasticityOfDemand demand;

    int quantity_1 = 100;
    int quantity_2 = 98;

    double price_1 = 100.0;
    double price_2 = 102.0;

    // Act
    double elasticity = demand.PriceElasticityOfDemand(quantity_1,
    quantity_2, price_1, price_2);

    // Assert
    EXPECT_EQ(-1.0, elasticity);
}

TEST(ElasticityOfDemandTest, check_2_price_elasticity_of_demand) {
    // Arrange
    ElasticityOfDemand demand;

    int quantity_1 = 100000;
    int quantity_2 = 98000;

    double price_1 = 1000.0;
    double price_2 = 1020.0;

    // Act
    double elasticity = demand.PriceElasticityOfDemand(quantity_1,
    quantity_2, price_1, price_2);

    // Assert
    EXPECT_EQ(-1.0, elasticity);
}

TEST(ElasticityOfDemandTest, check_3_price_elasticity_of_demand) {
    // Arrange
    ElasticityOfDemand demand;

    int quantity_1 = 100;
    int quantity_2 = 60;

    double price_1 = 100.0;
    double price_2 = 140.0;

    // Act
    double elasticity = demand.PriceElasticityOfDemand(quantity_1,
    quantity_2, price_1, price_2);

    // Assert
    EXPECT_EQ(-1.5, elasticity);
}

TEST(ElasticityOfDemandTest, check_4_price_elasticity_of_demand) {
    // Arrange
    ElasticityOfDemand demand;

    int quantity_1 = 10000;
    int quantity_2 = 6000;

    double price_1 = 1000.0;
    double price_2 = 1400.0;

    // Act
    double elasticity = demand.PriceElasticityOfDemand(quantity_1,
    quantity_2, price_1, price_2);

    // Assert
    EXPECT_EQ(-1.5, elasticity);
}

TEST(ElasticityOfDemandTest, check_income_elasticity_of_demand) {
    // Arrange
    ElasticityOfDemand demand;

    int quantity_1 = 100;
    int quantity_2 = 102;

    double income_1 = 10000.0;
    double income_2 = 10200.0;

    // Act
    double elasticity = demand.IncomeElasticityOfDemand(quantity_1,
    quantity_2, income_1, income_2);

    // Assert
    EXPECT_EQ(1.0, elasticity);
}

TEST(ElasticityOfDemandTest, check_2_income_elasticity_of_demand) {
    // Arrange
    ElasticityOfDemand demand;

    int quantity_1 = 10000;
    int quantity_2 = 10200;

    double income_1 = 100000.0;
    double income_2 = 102000.0;

    // Act
    double elasticity = demand.IncomeElasticityOfDemand(quantity_1,
    quantity_2, income_1, income_2);

    // Assert
    EXPECT_EQ(1.0, elasticity);
}

TEST(ElasticityOfDemandTest, check_cross_elasticity_of_demand) {
    // Arrange
    ElasticityOfDemand demand;

    int quantity_1_product_1 = 100;
    int quantity_2_product_1 = 98;

    double price_1_product_2 = 100.0;
    double price_2_product_2 = 102.0;

    // Act
    double elasticity = demand.CrossElasticityOfDemand(quantity_1_product_1,
    quantity_2_product_1, price_1_product_2, price_2_product_2);

    // Assert
    EXPECT_EQ(-1.0, elasticity);
}

TEST(ElasticityOfDemandTest, check_2_cross_elasticity_of_demand) {
    // Arrange
    ElasticityOfDemand demand;

    int quantity_1_product_1 = 10000;
    int quantity_2_product_1 = 9800;

    double price_1_product_2 = 10000.0;
    double price_2_product_2 = 10200.0;

    // Act
    double elasticity = demand.CrossElasticityOfDemand(quantity_1_product_1,
    quantity_2_product_1, price_1_product_2, price_2_product_2);

    // Assert
    EXPECT_EQ(-1.0, elasticity);
}
