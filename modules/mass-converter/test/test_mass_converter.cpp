// Copyright 2019 Prytov Denis

#include <gtest/gtest.h>

#include "include/mass_converter.h"

TEST(MassConverterTest, Can_Tons_To_Kilograms) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = MassConverter::TonsToKilograms(input);

    // Assert
    EXPECT_NEAR(1000.0, output, 0.01);
}

TEST(MassConverterTest, Can_Tons_To_Grams) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = MassConverter::TonsToGrams(input);

    // Assert
    EXPECT_NEAR(1000000.0, output, 0.01);
}

TEST(MassConverterTest, Can_Tons_To_Milligrams) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = MassConverter::TonsToMilligrams(input);

    // Assert
    EXPECT_NEAR(1000000000.0, output, 0.01);
}

TEST(MassConverterTest, Can_Tons_To_Pounds) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = MassConverter::TonsToPounds(input);

    // Assert
    EXPECT_NEAR(2204.623, output, 0.01);
}

TEST(MassConverterTest, Can_Tons_To_Ounces) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = MassConverter::TonsToOunces(input);

    // Assert
    EXPECT_NEAR(35274.962, output, 0.01);
}

TEST(MassConverterTest, Can_Kilograms_To_Tons) {
    // Arrange
    double input = 1000.0;
    double output;

    // Act
    output = MassConverter::KilogramsToTons(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(MassConverterTest, Can_Kilograms_To_Grams) {
    // Arrange
    double input = 2.0;
    double output;

    // Act
    output = MassConverter::KilogramsToGrams(input);

    // Assert
    EXPECT_NEAR(2000.0, output, 0.01);
}

TEST(MassConverterTest, Can_Kilograms_To_Milligrams) {
    // Arrange
    double input = 2.0;
    double output;

    // Act
    output = MassConverter::KilogramsToMilligrams(input);

    // Assert
    EXPECT_NEAR(2000000.0, output, 0.01);
}

TEST(MassConverterTest, Can_Kilograms_To_Pounds) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = MassConverter::KilogramsToPounds(input);

    // Assert
    EXPECT_NEAR(2.205, output, 0.01);
}

TEST(MassConverterTest, Can_Kilograms_To_Ounces) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = MassConverter::KilogramsToOunces(input);

    // Assert
    EXPECT_NEAR(35.274, output, 0.01);
}

TEST(MassConverterTest, Can_Grams_To_Tons) {
    // Arrange
    double input = 1000000.0;
    double output;

    // Act
    output = MassConverter::GramsToTons(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(MassConverterTest, Can_Grams_To_Kilograms) {
    // Arrange
    double input = 1000.0;
    double output;

    // Act
    output = MassConverter::GramsToKilograms(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(MassConverterTest, Can_Grams_To_Milligrams) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = MassConverter::GramsToMilligrams(input);

    // Assert
    EXPECT_NEAR(1000.0, output, 0.01);
}

TEST(MassConverterTest, Can_Grams_To_Pounds) {
    // Arrange
    double input = 1000.0;
    double output;

    // Act
    output = MassConverter::GramsToPounds(input);

    // Assert
    EXPECT_NEAR(2.204, output, 0.01);
}

TEST(MassConverterTest, Can_Grams_To_Ounces) {
    // Arrange
    double input = 1000.0;
    double output;

    // Act
    output = MassConverter::GramsToOunces(input);

    // Assert
    EXPECT_NEAR(35.274, output, 0.01);
}

TEST(MassConverterTest, Can_Milligrams_To_Tons) {
    // Arrange
    double input = 1000000000.0;
    double output;

    // Act
    output = MassConverter::MilligramsToTons(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(MassConverterTest, Can_Milligrams_To_Kilograms) {
    // Arrange
    double input = 1000000.0;
    double output;

    // Act
    output = MassConverter::MilligramsToKilograms(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(MassConverterTest, Can_Milligrams_To_Grams) {
    // Arrange
    double input = 1000.0;
    double output;

    // Act
    output = MassConverter::MilligramsToGrams(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(MassConverterTest, Can_Milligrams_To_Pounds) {
    // Arrange
    double input = 1000000.0;
    double output;

    // Act
    output = MassConverter::MilligramsToPounds(input);

    // Assert
    EXPECT_NEAR(2.204, output, 0.01);
}

TEST(MassConverterTest, Can_Milligrams_To_Ounces) {
    // Arrange
    double input = 1000000.0;
    double output;

    // Act
    output = MassConverter::MilligramsToOunces(input);

    // Assert
    EXPECT_NEAR(35.273, output, 0.01);
}

TEST(MassConverterTest, Can_Pounds_To_Tons) {
    // Arrange
    double input = 10000.0;
    double output;

    // Act
    output = MassConverter::PoundsToTons(input);

    // Assert
    EXPECT_NEAR(4.535, output, 0.01);
}

TEST(MassConverterTest, Can_Pounds_To_Kilograms) {
    // Arrange
    double input = 10000.0;
    double output;

    // Act
    output = MassConverter::PoundsToKilograms(input);

    // Assert
    EXPECT_NEAR(4535.14, output, 0.01);
}

TEST(MassConverterTest, Can_Pounds_To_Grams) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = MassConverter::PoundsToGrams(input);

    // Assert
    EXPECT_NEAR(453.592, output, 0.01);
}

TEST(MassConverterTest, Can_Pounds_To_Milligrams) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = MassConverter::PoundsToMilligrams(input);

    // Assert
    EXPECT_NEAR(453592.37, output, 0.01);
}

TEST(MassConverterTest, Can_Pounds_To_Ounces) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = MassConverter::PoundsToOunces(input);

    // Assert
    EXPECT_NEAR(16.0, output, 0.01);
}

TEST(MassConverterTest, Can_Ounces_To_Tons) {
    // Arrange
    double input = 100000.0;
    double output;

    // Act
    output = MassConverter::OuncesToTons(input);

    // Assert
    EXPECT_NEAR(2.834, output, 0.01);
}

TEST(MassConverterTest, Can_Ounces_To_Kilograms) {
    // Arrange
    double input = 100000.0;
    double output;

    // Act
    output = MassConverter::OuncesToKilograms(input);

    // Assert
    EXPECT_NEAR(2834.9523, output, 0.01);
}

TEST(MassConverterTest, Can_Ounces_To_Grams) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = MassConverter::OuncesToGrams(input);

    // Assert
    EXPECT_NEAR(28.3495, output, 0.01);
}

TEST(MassConverterTest, Can_Ounces_To_Milligrams) {
    // Arrange
    double input = 1.0;
    double output;

    // Act
    output = MassConverter::OuncesToMilligrams(input);

    // Assert
    EXPECT_NEAR(28349.5, output, 0.1);
}

TEST(MassConverterTest, Can_Ounces_To_Pounds) {
    // Arrange
    double input = 100.0;
    double output;

    // Act
    output = MassConverter::OuncesToPounds(input);

    // Assert
    EXPECT_NEAR(6.25, output, 0.01);
}
