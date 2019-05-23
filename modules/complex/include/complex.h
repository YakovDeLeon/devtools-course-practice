// Copyright 2019 Likholat Ann

#ifndef MODULES_COMPLEX_INCLUDE_COMPLEX_H_
#define MODULES_COMPLEX_INCLUDE_COMPLEX_H_

class Complex {
 private:
    double real;
    double imaginary;

    bool about_zero(const Complex &c_number) const;

 public:
    Complex();
    explicit Complex(const double re);
    Complex(const double re, const double im);
    Complex(const Complex &c_number);

    double get_re() const;
    double get_im() const;
    void set_re(const double re);
    void set_im(const double im);

    bool operator == (const Complex &c_number) const;
    bool operator != (const Complex &c_number) const;

    Complex& operator = (const Complex &c_number);
    Complex& operator += (const Complex &c_number);
    Complex& operator -= (const Complex &c_number);
    Complex& operator *= (const Complex &c_number);
    Complex& operator /= (const Complex &c_number);

    Complex operator + (const Complex &c_number) const;
    Complex operator - (const Complex &c_number) const;
    Complex operator * (const Complex &c_number) const;
    Complex operator / (const Complex &c_number) const;

    double abs() const;
};

#endif  // MODULES_COMPLEX_INCLUDE_COMPLEX_H_
