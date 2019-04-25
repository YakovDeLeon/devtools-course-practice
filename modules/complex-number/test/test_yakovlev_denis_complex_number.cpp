// Copyright 2019 Yakovlev Denis

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Yakovlev_Denis_ComplexNumberTest,
    Can_Set_Values) {
    // Arrange
    double re = 5.0;
    double im = 6.0;

    // Act
    ComplexNumber z;
    z.setRe(re);
    z.setIm(im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Yakovlev_Denis_ComplexNumberTest,
    Can_Multiplicate_By_Zero) {
    // Arrange
    double re = 1110.0;
    double im = 1234.0;
    double zero = 0.0;

    // Act
    ComplexNumber x(re, im);
    ComplexNumber y(zero, zero);
    ComplexNumber z = x * y;

    // Assert
    EXPECT_EQ(z, y);
}

TEST(Yakovlev_Denis_ComplexNumberTest,
    Can_Multiplicate_Complex_Numbers) {
    // Arrange
    double re1 = 2.0;
    double im1 = 3.0;
    double re2 = -1.0;
    double im2 = 1.0;
    double reRes = -5.0;
    double imRes = -1.0;

    // Act
    ComplexNumber x(re1, im1);
    ComplexNumber y(re2, im2);
    ComplexNumber z = x * y;
    ComplexNumber Res(reRes, imRes);

    // Assert
    EXPECT_EQ(z, Res);
}

TEST(Yakovlev_Denis_ComplexNumberTest,
    Can_Initialize_Complex_With_Values_Of_Type_Int) {
    // Arrange
    int re = 2;
    int im = 3;

    // Act
    ComplexNumber x(re, im);

    // Assert
    EXPECT_EQ(x.getRe(), re);
    EXPECT_EQ(x.getIm(), im);
}

TEST(Yakovlev_Denis_ComplexNumberTest,
    Can_Multiplicate_By_Negative_One) {
    // Arrange
    ComplexNumber negativeOne(-1, 0);
    double re = 2;
    double im = 3;

    // Act
    ComplexNumber x(re, im);
    ComplexNumber res = x * negativeOne;

    // Assert
    EXPECT_EQ(res.getRe(), -re);
    EXPECT_EQ(res.getIm(), -im);
}

TEST(Yakovlev_Denis_ComplexNumberTest,
    Cannot_Destuctor_Assign_Ptr_To_Null) {
    // Arrange
    ComplexNumber *pComplex = new ComplexNumber();
    // Act
    delete pComplex;
    // Assert
    EXPECT_NE(pComplex, nullptr);
}

TEST(Yakovlev_Denis_ComplexNumberTest,
    Can_Pass_Temporary_Object_To_Copy_Constructor) {
    // Arrange
    ComplexNumber Complex{ ComplexNumber(5, 6) };
    // Act
    // Assert
    EXPECT_EQ(Complex.getRe(), 5);
    EXPECT_EQ(Complex.getIm(), 6);
}

TEST(Yakovlev_Denis_ComplexNumberTest,
    Can_Pass_Temp_Matryoshka_Object_To_Copy_Constructor) {
    // Act
    ComplexNumber Complex{
        ComplexNumber {
            ComplexNumber {
                ComplexNumber {
                    ComplexNumber {
                        ComplexNumber {
                            ComplexNumber {
                                ComplexNumber {
                                    ComplexNumber {5, 6}
                                }
                            }
                        }
                    }
                }
            }
        }
    };
    // Assert
    EXPECT_EQ(Complex.getRe(), 5);
    EXPECT_EQ(Complex.getIm(), 6);
}
