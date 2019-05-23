// Copyright 2019 Druzhinin Alexei

#include <gtest/gtest.h>

#include "include/temperature_converter.h"

TEST(TemperatureConverterTest, Celsius_To_Fahrenheit) {
    // Arrange
    double celsius = 0;
    double fahrenheit;

    // Act
    fahrenheit = TemperatureConverter::CelsiusToFahrenheit(celsius);

    // Assert
    EXPECT_NEAR(32.0, fahrenheit, 0.00001);
}

TEST(TemperatureConverterTest, Fahrenheit_To_Celsius) {
    // Arrange
    double fahrenheit = 5.0;
    double celsius;

    // Act
    celsius = TemperatureConverter::FahrenheitToCelsius(fahrenheit);

    // Assert
    EXPECT_NEAR(-15.0, celsius, 0.00001);
}

TEST(TemperatureConverterTest, Celsius_To_Kelvin) {
    // Arrange
    double celsius = 100.0;
    double kelvin;

    // Act
    kelvin = TemperatureConverter::CelsiusToKelvin(celsius);

    // Assert
    EXPECT_NEAR(373.15, kelvin, 0.00001);
}

TEST(TemperatureConverterTest, Kelvin_To_Celsius) {
    // Arrange
    double kelvin = 0.0;
    double celsius;

    // Act
    celsius = TemperatureConverter::KelvinToCelsius(kelvin);

    // Assert
    EXPECT_NEAR(-273.15, celsius, 0.00001);
}

TEST(TemperatureConverterTest, Celsius_To_Newton) {
    // Arrange
    double celsius = 100.0;
    double newton;

    // Act
    newton = TemperatureConverter::CelsiusToNewton(celsius);

    // Assert
    EXPECT_NEAR(33.0, newton, 0.00001);
}

TEST(TemperatureConverterTest, Newton_To_Celsius) {
    // Arrange
    double newton = 33.0;
    double celsius;

    // Act
    celsius = TemperatureConverter::NewtonToCelsius(newton);

    // Assert
    EXPECT_NEAR(100.0, celsius, 0.00001);
}
