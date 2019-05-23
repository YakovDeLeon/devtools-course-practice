// Copyright 2019 Vikhrev Ivan
#include <gtest/gtest.h>
#include <string>
#include "include/lcd_digits.h"

class LCDDigitsTest : public ::testing::Test {
 public:
      std::string colon = "  \n"
                          ". \n"
                          ". \n";
      std::string point = "  \n"
                          "  \n"
                          ". \n";
      std::string zero =  " _  \n"
                          "| | \n"
                          "|_| \n";

      std::string one = "  \n"
                        "| \n"
                        "| \n";

      std::string two =  " _  \n"
                         " _| \n"
                         "|_  \n";

      std::string three =  " _  \n"
                           " _| \n"
                           " _| \n";

      std::string four =  "    \n"
                          "|_| \n"
                          "  | \n";

      std::string five =  " _  \n"
                          "|_  \n"
                          " _| \n";

      std::string six =  " _  \n"
                         "|_  \n"
                         "|_| \n";

      std::string seven =  " _  \n"
                           "  | \n"
                           "  | \n";

      std::string eight =  " _  \n"
                           "|_| \n"
                           "|_| \n";

      std::string nine =  " _  \n"
                          "|_| \n"
                          " _| \n";

      std::string n98 = " _   _  \n"
                        "|_| |_| \n"
                        " _| |_| \n";

      std::string time = "   _     _   _     _   _  \n"
                         "| |_  . | | | | . |_  |_| \n"
                         "| |_| . |_| |_| .  _|  _| \n";

      std::string date = "   _     _         _   _   _   _  \n"
                         "|  _|    _| |_|   |_  |_    | |_| \n"
                         "| |_  .  _|   | .  _| |_|   | |_| \n";
};



TEST_F(LCDDigitsTest, can_create_LCD_zero_from_int) {
    // Act & Assert
    EXPECT_EQ(zero, LCDDigits::LCD(0));
}

TEST_F(LCDDigitsTest, can_create_LCD_one_from_int) {
    // Act & Assert
    EXPECT_EQ(one, LCDDigits::LCD(1));
}

TEST_F(LCDDigitsTest, can_create_LCD_two_from_int) {
    // Act & Assert
    EXPECT_EQ(two, LCDDigits::LCD(2));
}

TEST_F(LCDDigitsTest, can_create_LCD_three_from_int) {
    // Act & Assert
    EXPECT_EQ(three, LCDDigits::LCD(3));
}

TEST_F(LCDDigitsTest, can_create_LCD_four_from_int) {
    // Act & Assert
    EXPECT_EQ(four, LCDDigits::LCD(4));
}

TEST_F(LCDDigitsTest, can_create_LCD_five_from_int) {
    // Act & Assert
    EXPECT_EQ(five, LCDDigits::LCD(5));
}

TEST_F(LCDDigitsTest, can_create_LCD_six_from_int) {
    // Act & Assert
    EXPECT_EQ(six, LCDDigits::LCD(6));
}

TEST_F(LCDDigitsTest, can_create_LCD_seven_from_int) {
    // Act & Assert
    EXPECT_EQ(seven, LCDDigits::LCD(7));
}

TEST_F(LCDDigitsTest, can_create_LCD_eight_from_int) {
    // Act & Assert
    EXPECT_EQ(eight, LCDDigits::LCD(8));
}

TEST_F(LCDDigitsTest, can_create_LCD_nine_from_int) {
    // Act & Assert
    EXPECT_EQ(nine, LCDDigits::LCD(9));
}

TEST_F(LCDDigitsTest, can_create_LCD_number_from_int) {
    // Act & Assert
    EXPECT_EQ(n98, LCDDigits::LCD(98));
}

TEST_F(LCDDigitsTest, can_create_LCD_point_from_string) {
    // Act & Assert
    EXPECT_EQ(point, LCDDigits::LCD("."));
}

TEST_F(LCDDigitsTest, can_create_LCD_colon_from_string) {
    // Act & Assert
    EXPECT_EQ(colon, LCDDigits::LCD(":"));
}

TEST_F(LCDDigitsTest, can_create_LCD_zero_from_string) {
    // Act & Assert
    EXPECT_EQ(zero, LCDDigits::LCD("0"));
}

TEST_F(LCDDigitsTest, can_create_LCD_one_from_string) {
    // Act & Assert
    EXPECT_EQ(one, LCDDigits::LCD("1"));
}

TEST_F(LCDDigitsTest, can_create_LCD_two_from_string) {
    // Act & Assert
    EXPECT_EQ(two, LCDDigits::LCD("2"));
}

TEST_F(LCDDigitsTest, can_create_LCD_three_from_string) {
    // Act & Assert
    EXPECT_EQ(three, LCDDigits::LCD("3"));
}


TEST_F(LCDDigitsTest, can_create_LCD_four_from_string) {
    // Act & Assert
    EXPECT_EQ(four, LCDDigits::LCD("4"));
}

TEST_F(LCDDigitsTest, can_create_LCD_five_from_string) {
    // Act & Assert
    EXPECT_EQ(five, LCDDigits::LCD("5"));
}

TEST_F(LCDDigitsTest, can_create_LCD_six_from_string) {
    // Act & Assert
    EXPECT_EQ(six, LCDDigits::LCD("6"));
}

TEST_F(LCDDigitsTest, can_create_LCD_seven_from_string) {
    // Act & Assert
    EXPECT_EQ(seven, LCDDigits::LCD("7"));
}

TEST_F(LCDDigitsTest, can_create_LCD_eight_from_string) {
    // Act & Assert
    EXPECT_EQ(eight, LCDDigits::LCD("8"));
}

TEST_F(LCDDigitsTest, can_create_LCD_nine_from_string) {
    // Act & Assert
    EXPECT_EQ(nine, LCDDigits::LCD("9"));
}

TEST_F(LCDDigitsTest, can_create_LCD_number_from_string) {
    // Act & Assert
    EXPECT_EQ(n98, LCDDigits::LCD("98"));
}

TEST_F(LCDDigitsTest, can_create_LCD_time_from_string) {
    // Act & Assert
    EXPECT_EQ(time, LCDDigits::LCD("16:00:59"));
}

TEST_F(LCDDigitsTest, can_create_LCD_date_from_string) {
    // Act & Assert
    EXPECT_EQ(date, LCDDigits::LCD("12.34.5678"));
}

TEST_F(LCDDigitsTest, throw_with_incrorrect_data) {
    // Act & Assert
    ASSERT_ANY_THROW(LCDDigits::LCD("1f"));
}
