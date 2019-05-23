// Copyright 2019 Kholobko Vladimir

#include <gtest/gtest.h>
#include "include/Convector.h"

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Create_Length) {
    // Act & Assert
    ASSERT_NO_THROW(Convector a);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Millimeters_To_Centimeters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::MMinCM(input);

    // Assert
    EXPECT_NEAR(0.3, output, 0.01);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Millimeters_To_Decimeters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::MMinDM(input);

    // Assert
    EXPECT_NEAR(0.03, output, 0.01);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Millimeters_To_Meters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::MMinM(input);

    // Assert
    EXPECT_NEAR(0.003, output, 0.001);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Millimeters_To_Kilometers) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::MMinKM(input);

    // Assert
    EXPECT_NEAR(0.000003, output, 0.000001);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Centimeters_To_Millimeters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::CMinMM(input);

    // Assert
    EXPECT_NEAR(30.0, output, 0.01);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Centimeters_To_Decimeters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::CMinDM(input);

    // Assert
    EXPECT_NEAR(0.3, output, 0.1);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Centimeters_To_Meters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::CMinM(input);

    // Assert
    EXPECT_NEAR(0.003, output, 0.001);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Centimeters_To_Kilometers) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::CMinKM(input);

    // Assert
    EXPECT_NEAR(0.00003, output, 0.00001);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Decimeters_To_Millimeters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::DMinMM(input);

    // Assert
    EXPECT_NEAR(300.0, output, 0.01);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Decimeters_To_Centimeters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::DMinCM(input);

    // Assert
    EXPECT_NEAR(30.0, output, 0.01);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Decimeters_To_Meters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::DMinM(input);

    // Assert
    EXPECT_NEAR(0.3, output, 0.1);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Decimeters_To_Kilometers) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::DMinKM(input);

    // Assert
    EXPECT_NEAR(0.0003, output, 0.00001);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Meters_To_Millimeters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::MinMM(input);

    // Assert
    EXPECT_NEAR(3000.0, output, 0.01);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Meters_To_Centimeters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::MinCM(input);

    // Assert
    EXPECT_NEAR(300.0, output, 0.01);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Meters_To_Decimeters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::MinDM(input);

    // Assert
    EXPECT_NEAR(30.0, output, 0.1);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Meters_To_Kilometers) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::MinKM(input);

    // Assert
    EXPECT_NEAR(0.3, output, 0.1);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Kilometers_To_Millimeters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::KMinMM(input);

    // Assert
    EXPECT_NEAR(3000000.0, output, 0.01);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Kilometers_To_Centimeters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::KMinCM(input);

    // Assert
    EXPECT_NEAR(300000.0, output, 0.1);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Kilometers_To_Decimeters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::KMinDM(input);

    // Assert
    EXPECT_NEAR(30000.0, output, 0.1);
}

TEST(Test_Kholobko_Vladimir_Convector_Length, Can_Kilometers_To_Meters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = Convector::KMinM(input);

    // Assert
    EXPECT_NEAR(300.0, output, 0.1);
}
