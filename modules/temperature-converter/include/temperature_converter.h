// Copyright 2019 Druzhinin Alexei

#ifndef MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
#define MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_

class TemperatureConverter {
 public:
    static double CelsiusToFahrenheit(const double celsius) {
        return 32 + celsius * (9.0 / 5.0);
    }
    static double FahrenheitToCelsius(const double fahrenheit) {
        return (fahrenheit - 32) * (5.0 / 9.0);
    }
    static double CelsiusToKelvin(const double celsius) {
        return celsius + 273.15;
    }
    static double KelvinToCelsius(const double kelvin) {
        return kelvin - 273.15;
    }
    static double CelsiusToNewton(const double celsius) {
        return celsius * 0.33;
    }
    static double NewtonToCelsius(const double newton) {
        return newton / 0.33;
    }
};

#endif  // MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_

