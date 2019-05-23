// Copyright 2019 Prytov Denis

#include <gtest/gtest.h>

#include "include/currency_converter.h"

TEST(CurrencyConverterTest, Can_Ruble_To_Euro) {
    // Arrange
    double input = 72.29;
    double output;

    // Act
    output = CurrencyConverter::RubleToEuro(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Ruble_To_Dollar) {
    // Arrange
    double input = 64.82;
    double output;

    // Act
    output = CurrencyConverter::RubleToDollar(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Ruble_To_Shekel) {
    // Arrange
    double input = 17.9;
    double output;

    // Act
    output = CurrencyConverter::RubleToShekel(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Ruble_To_Grivna) {
    // Arrange
    double input = 2.45;
    double output;

    // Act
    output = CurrencyConverter::RubleToGrivna(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Ruble_To_Dirham) {
    // Arrange
    double input = 17.65;
    double output;

    // Act
    output = CurrencyConverter::RubleToDirham(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Euro_To_Dirham) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::EuroToDirham(input);

    // Assert
    EXPECT_NEAR(409.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Euro_To_Grivna) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::EuroToGrivna(input);

    // Assert
    EXPECT_NEAR(2953.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Euro_To_Shekel) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::EuroToShekel(input);

    // Assert
    EXPECT_NEAR(403.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Euro_To_Rubles) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = CurrencyConverter::EuroToRubles(input);

    // Assert
    EXPECT_NEAR(72.24, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Euro_To_Dollar) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::EuroToDollar(input);

    // Assert
    EXPECT_NEAR(111.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Dollar_To_Euro) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::DollarToEuro(input);

    // Assert
    EXPECT_NEAR(89.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Dollar_To_Rubles) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::DollarToRubles(input);

    // Assert
    EXPECT_NEAR(6482.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Dollar_To_Shekel) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::DollarToShekel(input);

    // Assert
    EXPECT_NEAR(362.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Dollar_To_Dirham) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::DollarToDirham(input);

    // Assert
    EXPECT_NEAR(367.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Dollar_To_Grivna) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::DollarToGrivna(input);

    // Assert
    EXPECT_NEAR(2647.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Shekel_To_Grivna) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::ShekelToGrivna(input);

    // Assert
    EXPECT_NEAR(731.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Shekel_To_Dirham) {
    // Arrange
    double input = 1000.0;
    double output;

    // Act
    output = CurrencyConverter::ShekelToDirham(input);

    // Assert
    EXPECT_NEAR(1010.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Shekel_To_Rubles) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::ShekelToRubles(input);

    // Assert
    EXPECT_NEAR(1788.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Shekel_To_Dollar) {
    // Arrange
    double input = 1000.0;
    double output;

    // Act
    output = CurrencyConverter::ShekelToDollar(input);

    // Assert
    EXPECT_NEAR(276.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Shekel_To_Euro) {
    // Arrange
    double input = 1000.0;
    double output;

    // Act
    output = CurrencyConverter::ShekelToEuro(input);

    // Assert
    EXPECT_NEAR(246.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Dirham_To_Dollar) {
    // Arrange
    double input = 1000.0;
    double output;

    // Act
    output = CurrencyConverter::DirhamToDollar(input);

    // Assert
    EXPECT_NEAR(273.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Dirham_To_Grivna) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::DirhamToGrivna(input);

    // Assert
    EXPECT_NEAR(720.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Dirham_To_Shekel) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::DirhamToShekel(input);

    // Assert
    EXPECT_NEAR(98.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Dirham_To_Euro) {
    // Arrange
    double input = 1000.0;
    double output;

    // Act
    output = CurrencyConverter::DirhamToEuro(input);

    // Assert
    EXPECT_NEAR(243.0, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Dirham_To_Rubles) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = CurrencyConverter::DirhamToRubles(input);

    // Assert
    EXPECT_NEAR(17.63, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Grivna_To_Dollar) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::GrivnaToDollar(input);

    // Assert
    EXPECT_NEAR(3.7, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Grivna_To_Euro) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = CurrencyConverter::GrivnaToEuro(input);

    // Assert
    EXPECT_NEAR(3.3, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Grivna_To_Rubles) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = CurrencyConverter::GrivnaToRubles(input);

    // Assert
    EXPECT_NEAR(2.443, output, 0.01);
}

TEST(CurrencyConverterTest, Can_Grivna_To_Dirham) {
    // Arrange
    double input = 1000.0;
    double output;

    // Act
    output = CurrencyConverter::GrivnaToDirham(input);

    // Assert
    EXPECT_NEAR(138.0, output, 0.1);
}

TEST(CurrencyConverterTest, Can_Grivna_To_Shekel) {
    // Arrange
    double input = 1000.0;
    double output;

    // Act
    output = CurrencyConverter::GrivnaToShekel(input);

    // Assert
    EXPECT_NEAR(136.0, output, 0.01);
}
