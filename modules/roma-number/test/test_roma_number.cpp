// Copyright 2019 Bykovskaya Alina

#include <gtest/gtest.h>
#include <string>
#include "include/romanumber.h"

TEST(Test_Roma_Number, Can_Create_Roma_Number) {
    // Act & Assert
    ASSERT_NO_THROW(RomaNumber a);
}

TEST(Test_Roma_Number, Correct_Create_Empty_Roma_Number) {
    // Arrange
    RomaNumber a;

    // Act & Assert
    EXPECT_EQ(0, a.GetArabic());
    EXPECT_EQ("", a.GetRoma());
}

TEST(Test_Roma_Number, Can_Create_With_Arab) {
    // Act & Assert
    ASSERT_NO_THROW(RomaNumber a(90));
}

TEST(Test_Roma_Number, Cant_Create_With_Too_Big_Arab) {
    // Act & Assert
    ASSERT_ANY_THROW(RomaNumber a(5000));
}

TEST(Test_Roma_Number, Cant_Create_With_Negative_Number) {
    // Act & Assert
    ASSERT_ANY_THROW(RomaNumber a(-3));
}

TEST(Test_Roma_Number, Correct_Convert_Arab) {
    // Arrange
    RomaNumber s;

    // Act
    s.ArabToRoma(3);

    // Assert
    EXPECT_EQ(3, s.GetArabic());
    EXPECT_EQ("III", s.GetRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Arab2) {
    // Arrange
    RomaNumber s;

    // Act
    s.ArabToRoma(49);

    // Assert
    EXPECT_EQ(49, s.GetArabic());
    EXPECT_EQ("XLIX", s.GetRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Arab3) {
    // Arrange
    RomaNumber s;

    // Act
    s.ArabToRoma(978);

    // Assert
    EXPECT_EQ(978, s.GetArabic());
    EXPECT_EQ("CMLXXVIII", s.GetRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Arab4) {
    // Arrange
    RomaNumber s;

    // Act
    s.ArabToRoma(2395);

    // Assert
    EXPECT_EQ(2395, s.GetArabic());
    EXPECT_EQ("MMCCCXCV", s.GetRoma());
}

TEST(Test_Roma_Number, Cant_Convert_Too_Big_Arab) {
    // Arrange
    RomaNumber s;

    // Act & Assert
    ASSERT_ANY_THROW(s.ArabToRoma(4001));
}

TEST(Test_Roma_Number, Can_Create_With_String) {
    // Act & Assert
    ASSERT_NO_THROW(RomaNumber a("XX"));
}

TEST(Test_Roma_Number, Correct_Create_With_String) {
    // Arrange
    std::string r = "VIII";

    // Act
    RomaNumber a(r);

    // Assert
    EXPECT_EQ("VIII", a.GetRoma());
    EXPECT_EQ(8, a.GetArabic());
}

TEST(Test_Roma_Number, Cant_Create_With_Wrong_String) {
    // Arrange
    std::string r = "AX";

    // Act & Assert
    ASSERT_ANY_THROW(RomaNumber a(r));
}

TEST(Test_Roma_Number, Correct_Convert_Roma1) {
    // Arrange
    RomaNumber s;

    // Act
    s.RomaToArab("D");

    // Assert
    EXPECT_EQ(500, s.GetArabic());
    EXPECT_EQ("D", s.GetRoma());
}

TEST(Test_Roma_Number, Correct_Convert_All_Arab) {
    // Arrange
    RomaNumber a1, a2;

    // Act & Assert
    for (int i = 0; i < 4000; ++i) {
        a1.ArabToRoma(i);
        a2.RomaToArab(a1.GetRoma());
        EXPECT_EQ(i, a2.GetArabic());
    }
}

TEST(Test_Roma_Number, Can_Print) {
    // Arrange
    RomaNumber a(6);

    // Act & Assert
    ASSERT_NO_THROW(std::cout << a);
}
