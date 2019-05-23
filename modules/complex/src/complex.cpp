// Copyright 2019 Likholat Ann

#include "include/complex.h"

#include <stdexcept>
#include <cfloat>
#include <cmath>
#include <string>

Complex::Complex(): real(0), imaginary(0) {}
Complex::Complex(const double re) : real(re), imaginary(0) {}
Complex::Complex(const double re, const double im)
                 : real(re), imaginary(im) {}
Complex::Complex(const Complex &c_number)
                 : real(c_number.real), imaginary(c_number.imaginary) {}


double Complex::get_re() const {
    return real;
}

double Complex::get_im() const {
    return imaginary;
}

void Complex::set_re(const double re) {
    real = re;
}

void Complex::set_im(const double im) {
    imaginary = im;
}

bool Complex::operator == (const Complex &c_number) const {
    return real == c_number.get_re() &&
           imaginary == c_number.get_im();
}

bool Complex::operator != (const Complex &c_number) const {
    return !(*this == c_number);
}

Complex& Complex:: operator = (const Complex &c_number) {
    real = c_number.get_re();
    imaginary = c_number.get_im();

    return *this;
}

Complex& Complex::operator += (const Complex &c_number) {
    real += c_number.get_re();
    imaginary += c_number.get_im();

    return *this;
}

Complex& Complex::operator -= (const Complex &c_number) {
    real -= c_number.get_re();
    imaginary -= c_number.get_im();

    return *this;
}

Complex& Complex::operator *= (const Complex &c_number) {
    double copy_re = real;

    real = real * c_number.get_re() -
           imaginary * c_number.get_im();
    imaginary = imaginary * c_number.get_re() +
                copy_re * c_number.get_im();

    return *this;
}

Complex& Complex::operator /= (const Complex &c_number) {
    if (about_zero(c_number)) {
        throw std::string("Division by zero!");
    } else {
        double copy_re = real;
        double den = c_number.get_re() * c_number.get_re() +
            c_number.get_im() * c_number.get_im();

        real = (real * c_number.get_re() +
            imaginary * c_number.get_im()) / den;
        imaginary = (imaginary * c_number.get_re() -
            copy_re * c_number.get_im()) / den;

        return *this;
    }
}

Complex Complex::operator + (const Complex &c_number) const {
    return Complex(real + c_number.get_re(),
                   imaginary + c_number.get_im());
}

Complex Complex::operator - (const Complex &c_number) const {
    return Complex(real - c_number.get_re(),
                   imaginary - c_number.get_im());
}

Complex Complex::operator * (const Complex &c_number) const {
    return Complex(real * c_number.get_re() -
                   imaginary * c_number.get_im(),
                   real * c_number.get_im() +
                   imaginary * c_number.get_re());
}

bool Complex::about_zero(const Complex &c_number) const {
    return c_number.get_re() > -DBL_EPSILON &&
           c_number.get_re() < DBL_EPSILON &&
           c_number.get_im() > -DBL_EPSILON &&
           c_number.get_im() < DBL_EPSILON;
}

Complex Complex::operator / (const Complex &c_number) const {
    if (about_zero(c_number)) {
        throw std::string("Division by zero!");
    } else {
        Complex res;
        double den = c_number.get_re() * c_number.get_re() +
                     c_number.get_im() * c_number.get_im();

        res.set_re((real * c_number.get_re() +
                    imaginary * c_number.get_im()) / den);
        res.set_im((imaginary * c_number.get_re() -
                    real * c_number.get_im()) / den);

        return res;
    }
}

double Complex::abs() const {
    return sqrt(real * real +
                imaginary*imaginary);
}
