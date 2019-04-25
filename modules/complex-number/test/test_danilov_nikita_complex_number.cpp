// Copyright 2019 Danilov Nikita

#include <gtest/gtest.h>
#include <limits>

#include "include/complex_number.h"

/* Divided by zero exception */
/* C++ Standard 5.6.4
 * ...
 * If the second operand of / or % is zero the behavior is undefined
 *
 * division by zero in this case
 * should throw a real exception i think,
 * std::exception("Divided by zero") e.g.
 */
TEST(Danilov_Nikita_ComplexNumberTest, Divided_by_zero_exception) {
    /* Arrange */
    ComplexNumber zero(0.0, 0.0);
    ComplexNumber z(1.0, 1.0);

    /* Assert */
    /* ASSERT_THROW(z / zero, std::exception); is failed
     * 'cause division by zero throw std::string
     * adequately handle this as a standard exception
     * we will not be able to
     * standard exception handling:
     *
     * try {
     *     z / zero;
     * } catch (std::exception &e) {
     *     e.what();
     * }
     */
    ASSERT_ANY_THROW(z / zero);
}

/* Sum and multiply by two equality */
/* z + z must be equal 2 * z */
TEST(Danilov_Nikita_ComplexNumberTest, Sum_and_multiply_by_two_equality) {
    /* Arrange */
    ComplexNumber z2(2 * std::numeric_limits<double>::epsilon(),
                     2 * std::numeric_limits<double>::epsilon());
    ComplexNumber z(std::numeric_limits<double>::epsilon(),
                    std::numeric_limits<double>::epsilon());
    ComplexNumber two(2.0, 0.0);

    /* Assert */
    EXPECT_TRUE(((z + z) == z2) &&
                ((two * z) == z2));
}

/* Multiplying by zero gives zero */
TEST(Danilov_Nikita_ComplexNumberTest, Multiplying_by_zero_gives_zero) {
    /* Arrange */
    ComplexNumber z1(std::numeric_limits<double>::min(),
                     std::numeric_limits<double>::min());
    ComplexNumber zero(0.0, 0.0);
    ComplexNumber result;

    /* Act */
    result = z1 * zero;

    /* Assert */
    EXPECT_TRUE((result.getRe() == 0.0) &&
                (result.getIm() == 0.0));
}

/* Rounding of complex numbers has the same behavior
 * as rounding of doubles
 */
TEST(Danilov_Nikita_ComplexNumberTest, Rounding_behavior) {
    /* Arrange */
    ComplexNumber z1(std::numeric_limits<double>::max(),
                     std::numeric_limits<double>::max());
    ComplexNumber z2 = z1 + ComplexNumber(1.0, 1.0);

    /* Assert */
    EXPECT_EQ(z1, z2);
}
