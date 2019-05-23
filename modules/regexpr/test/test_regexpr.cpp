// Copyright 2019 Zhivaev Artem

#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "include/nfa.h"
#include "include/regexpr.h"

TEST(RegExprTest_GeneratePatt, Create_Patt_With_Correct_Size) {
    // Arrange
    const std::string seq("abc");

    // Act
    auto patt = RegExprT::GeneratePatt(seq);

    // Assert
    EXPECT_EQ(3u, patt.size());
}

TEST(RegExprTest_GeneratePatt, Create_Patt_With_Correct_Values) {
    // Arrange
    const std::string seq("abc");
    std::vector<RegExprT::Atom> exp = {
        {RegExprT::Atom::kNone, false, {{'a'}}},
        {RegExprT::Atom::kNone, false, {{'b'}}},
        {RegExprT::Atom::kNone, false, {{'c'}}},
    };

    // Act
    auto patt = RegExprT::GeneratePatt(seq);

    // Assert
    EXPECT_EQ(exp, patt);
}

TEST(RegExprTest_GeneratePatt, Create_Patt_From_Sequence_With_Klean) {
    // Arrange
    const std::string seq("ab*c");

    // Act
    auto patt = RegExprT::GeneratePatt(seq);

    // Assert
    EXPECT_EQ(3u, patt.size());
}

TEST(RegExprTest_GeneratePatt,
     Create_Patt_From_Sequence_With_Char_Class_With_Correct_Size) {
    // Arrange
    const std::string seq("a[B-E]c");

    // Act
    auto patt = RegExprT::GeneratePatt(seq);

    // Assert
    EXPECT_EQ(3u, patt.size());
}

TEST(RegExprTest_GeneratePatt,
     Create_Patt_From_Sequence_With_Char_Class_With_Correct_Values) {
    // Arrange
    const std::string seq("a[B-E]c");
    std::vector<RegExprT::Atom> exp = {
        {RegExprT::Atom::kNone, false, {{'a'}}},
        {RegExprT::Atom::kNone, false, {{'B', 'C', 'D', 'E'}}},
        {RegExprT::Atom::kNone, false, {{'c'}}},
    };

    // Act
    auto patt = RegExprT::GeneratePatt(seq);

    // Assert
    EXPECT_EQ(exp, patt);
}

TEST(RegExprTest_GeneratePatt,
     Create_Patt_From_Sequence_With_Char_Class_And_Kleen_After_Size_Check) {
    // Arrange
    const std::string seq("a[B-G]*c");

    // Act
    auto patt = RegExprT::GeneratePatt(seq);

    // Assert
    EXPECT_EQ(3u, patt.size());
}

TEST(RegExprTest_GeneratePatt,
     Create_Patt_From_Sequence_With_Char_Class_And_Kleen_After_Values_Check) {
    // Arrange
    const std::string seq("a[B-G]*c");
    std::vector<RegExprT::Atom> exp = {
        {RegExprT::Atom::kNone, false, {{'a'}}},
        {RegExprT::Atom::kKleen, false, {{'B', 'C', 'D', 'E', 'F', 'G'}}},
        {RegExprT::Atom::kNone, false, {{'c'}}},
    };

    // Act
    auto patt = RegExprT::GeneratePatt(seq);

    // Assert
    EXPECT_EQ(exp, patt);
}

TEST(RegExprTest_GeneratePatt,
     Create_Patt_From_Sequence_With_Group_Size_Check) {
    // Arrange
    const std::string seq("ab(cde)fg");

    // Act
    auto patt = RegExprT::GeneratePatt(seq);

    // Assert
    EXPECT_EQ(5u, patt.size());
}

TEST(RegExprTest_GeneratePatt,
     Create_Patt_From_Sequence_With_Group_Values_Check) {
    // Arrange
    const std::string seq("ab(cde)fg");
    std::vector<RegExprT::Atom> exp = {
        {RegExprT::Atom::kNone, false, {{'a'}}},
        {RegExprT::Atom::kNone, false, {{'b'}}},
        {RegExprT::Atom::kNone, true, {{'c'}, {'d'}, {'e'}}},
        {RegExprT::Atom::kNone, false, {{'f'}}},
        {RegExprT::Atom::kNone, false, {{'g'}}},
    };

    // Act
    auto patt = RegExprT::GeneratePatt(seq);

    // Assert
    EXPECT_EQ(exp, patt);
}

TEST(RegExprTest_GeneratePatt,
     Create_Patt_From_Sequence_With_Group_And_Kleen_After_Values_Check) {
    // Arrange
    const std::string seq("ab(cde)*fg");
    std::vector<RegExprT::Atom> exp = {
        {RegExprT::Atom::kNone, false, {{'a'}}},
        {RegExprT::Atom::kNone, false, {{'b'}}},
        {RegExprT::Atom::kKleen, true, {{'c'}, {'d'}, {'e'}}},
        {RegExprT::Atom::kNone, false, {{'f'}}},
        {RegExprT::Atom::kNone, false, {{'g'}}},
    };

    // Act
    auto patt = RegExprT::GeneratePatt(seq);

    // Assert
    EXPECT_EQ(exp, patt);
}

TEST(RegExprTest_GeneratePatt,
     Create_Patt_From_Sequence_With_Group_And_QMark_After_Values_Check) {
    // Arrange
    const std::string seq("ab(cde)?fg");
    std::vector<RegExprT::Atom> exp = {
        {RegExprT::Atom::kNone, false, {{'a'}}},
        {RegExprT::Atom::kNone, false, {{'b'}}},
        {RegExprT::Atom::kQMark, true, {{'c'}, {'d'}, {'e'}}},
        {RegExprT::Atom::kNone, false, {{'f'}}},
        {RegExprT::Atom::kNone, false, {{'g'}}},
    };

    // Act
    auto patt = RegExprT::GeneratePatt(seq);

    // Assert
    EXPECT_EQ(exp, patt);
}

TEST(RegExprTest_GeneratePatt,
     Create_Patt_From_Sequence_With_Group_And_QMark_Inside_Values_Check) {
    // Arrange
    const std::string seq("ab(cd?e)fg");
    std::vector<RegExprT::Atom> exp = {
        {RegExprT::Atom::kNone, false, {{'a'}}},
        {RegExprT::Atom::kNone, false, {{'b'}}},
        {RegExprT::Atom::kNone, true, {{'c'}, {'d'}, {'?'}, {'e'}}},
        {RegExprT::Atom::kNone, false, {{'f'}}},
        {RegExprT::Atom::kNone, false, {{'g'}}},
    };

    // Act
    auto patt = RegExprT::GeneratePatt(seq);

    // Assert
    EXPECT_EQ(exp, patt);
}

TEST(RegExprTest_GeneratePatt,
     Create_Patt_From_Sequence_With_Group_And_Char_Class_Inside_Values_Check) {
    // Arrange
    const std::string seq("ab(cd[ASD]e)fg");
    std::vector<RegExprT::Atom> exp = {
        {RegExprT::Atom::kNone, false, {{'a'}}},
        {RegExprT::Atom::kNone, false, {{'b'}}},
        {RegExprT::Atom::kNone, true, {{'c'}, {'d'}, {'A', 'S', 'D'}, {'e'}}},
        {RegExprT::Atom::kNone, false, {{'f'}}},
        {RegExprT::Atom::kNone, false, {{'g'}}},
    };

    // Act
    auto patt = RegExprT::GeneratePatt(seq);

    // Assert
    EXPECT_EQ(exp, patt);
}

TEST(RegExprTest_GeneratePatt, Throws_If_Has_Backslash_Ath_The_End) {
    // Arrange
    const std::string seq("abc\\");

    // Act & Assert
    EXPECT_ANY_THROW(RegExprT::GeneratePatt(seq));
}

TEST(RegExprTest_Match, Search_Patt_From_Simple_Char_Sequence) {
    // Arrange
    const std::string seq("abc");
    const std::string str("abcd");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(0, 3), rx.Match(str));
}

TEST(RegExprTest_Match, Returns_Negative_If_No_Matches_Found) {
    // Arrange
    const std::string seq("abc");
    const std::string str("abd");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(-1, -1), rx.Match(str));
}

TEST(RegExprTest_Match, Can_Find_Matched_Substring_In_The_Middle_Of_String) {
    // Arrange
    const std::string seq("a(FGH)bc");
    const std::string str("uuuaFGHbc");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(3, 9), rx.Match(str));
}

TEST(RegExprTest_Match,
     Search_Patt_From_Sequence_With_QMark_After_Character) {
    // Arrange
    const std::string seq("ab?c");
    const std::string str("abc");
    const std::string str1("ac");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(0, 3), rx.Match(str));
    EXPECT_EQ(std::make_pair(0, 2), rx.Match(str1));
}

TEST(RegExprTest_Match,
     Search_Patt_From_Sequence_With_Kleen_After_Character) {
    // Arrange
    const std::string seq("ab*c");
    const std::string str("abbbbbbbc");
    const std::string str1("ac");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(0, 9), rx.Match(str));
    EXPECT_EQ(std::make_pair(0, 2), rx.Match(str1));
}

TEST(RegExprTest_Match, Dot_Matches_Any_Character) {
    // Arrange
    const std::string seq("a.c");
    const std::string str("abc");
    const std::string str1("a^c");
    const std::string str2("a{c");
    const std::string str3("a=c");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(0, 3), rx.Match(str));
    EXPECT_EQ(std::make_pair(0, 3), rx.Match(str1));
    EXPECT_EQ(std::make_pair(0, 3), rx.Match(str2));
    EXPECT_EQ(std::make_pair(0, 3), rx.Match(str3));
}

TEST(RegExprTest_Match,
     Search_Patt_From_Sequence_With_QMark_After_Char_Class) {
    // Arrange
    const std::string seq("a[FGH]?c");
    const std::string str("acuuu");
    const std::string str1("aGc");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(0, 2), rx.Match(str));
    EXPECT_EQ(std::make_pair(0, 3), rx.Match(str1));
}

TEST(RegExprTest_Match,
     Search_Patt_From_Sequence_With_QMark_After_Group_Works_Correct) {
    // Arrange
    const std::string seq("a(FGH)?c");
    const std::string str("acuuu");
    const std::string str1("uuuaFGHc");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(0, 2), rx.Match(str));
    EXPECT_EQ(std::make_pair(3, 8), rx.Match(str1));
}

TEST(RegExprTest_Match,
     Search_Patt_From_Sequence_With_Kleen_After_Group_Works_Correct) {
    // Arrange
    const std::string seq("a(FGH)*c");
    const std::string str("ac");
    const std::string str1("aFGHFGHc");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(0, 2), rx.Match(str));
    EXPECT_EQ(std::make_pair(0, 8), rx.Match(str1));
}

TEST(RegExprTest_Match, Search_Patt_From_Sequence_With_Kleen_After_Dot) {
    // Arrange
    const std::string seq("class .*");
    const std::string str("class Complex");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(0, 13), rx.Match(str));
}

TEST(RegExprTest_Match,
     Search_Patt_From_Sequence_With_QMark_After_Dot_Works_Correct) {
    // Arrange
    const std::string seq(".?");
    const std::string str("uuuu");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(0, 1), rx.Match(str));
}

TEST(RegExprTest_Match, Throws_If_Backslash_At_The_End) {
    // Arrange
    const std::string seq("abc\\");

    // Act & Assert
    EXPECT_ANY_THROW(new RegExprT(seq));
}

TEST(RegExprTest_Match, Escape_Character_Add_Next_Character) {
    // Arrange
    const std::string seq("abc\\*");
    const std::string str("abc*");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(0, 4), rx.Match(str));
}

TEST(RegExprTest_Match, Returns_Negative_If_Pattern_Longer_Than_String) {
    // Arrange
    const std::string seq("abcdef");
    const std::string str("abc");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(-1, -1), rx.Match(str));
}

TEST(RegExprTest_ParseBrackets,
     Throws_Error_If_First_Char_Is_Not_Bracket) {
    // Arrange
    const std::string seq("abc");
    size_t pos = 0;

    // Act & Assert
    EXPECT_ANY_THROW(RegExprT::ParseBrackets(seq, &pos));
}

TEST(RegExprTest_ParseParenthesis,
     Throws_Error_If_First_Char_Is_Not_Parenthes) {
    // Arrange
    const std::string seq("abc");
    size_t pos = 0;

    // Act & Assert
    EXPECT_ANY_THROW(RegExprT::ParseParenthesis(seq, &pos));
}

TEST(RegExprTest_ParseParenthesis, Modifires_Dont_Work_Inside_Parenthesis) {
    // Arrange
    const std::string seq("([EFG]*bc)");
    size_t pos = 0;

    // Act
    auto at = RegExprT::ParseParenthesis(seq, &pos);

    // Assert
    EXPECT_EQ('*', *(at.values_.at(1).begin()));
}

TEST(RegExprTest_ParseParenthesis,
     Move_Pos_To_Closing_Parenthes_Through_Dot) {
    // Arrange
    const std::string seq("(b.c)");
    size_t pos = 0;

    // Act
    auto at = RegExprT::ParseParenthesis(seq, &pos);

    // Assert
    EXPECT_EQ(4u, pos);
}

TEST(RegExprTest_ParseParenthesis,
     Escape_Character_Add_Next_Char_To_Pattern) {
    // Arrange
    const std::string seq("(b\\.c)");
    size_t pos = 0;

    // Act
    auto at = RegExprT::ParseParenthesis(seq, &pos);

    // Assert
    EXPECT_EQ('.', *(at.values_.at(1).begin()));
}

TEST(RegExprTest_ParseParenthesis,
     Escape_Character_Throws_If_Backslash_At_The_End) {
    // Arrange
    const std::string seq("(abc\\");
    size_t pos = 0;

    // Act & Assert
    EXPECT_ANY_THROW(RegExprT::ParseParenthesis(seq, &pos));
}

TEST(RegExprTest_ValidCheck, Not_Empty_Parenthesis) {
    // Arrange
    const std::string seq("(a)(a)");

    // Act & Assert
    EXPECT_TRUE(RegExprT::ValidCheck(seq));
}

TEST(RegExprTest_ValidCheck, Nested_Parenthesis) {
    // Arrange
    const std::string seq("((a))(a)");

    // Act & Assert
    EXPECT_FALSE(RegExprT::ValidCheck(seq));
}

TEST(RegExprTest_ValidCheck, Brackets) {
    // Arrange
    const std::string seq("[a][a]");

    // Act & Assert
    EXPECT_TRUE(RegExprT::ValidCheck(seq));
}

TEST(RegExprTest_ValidCheck, Extra_Closing_Bracket) {
    // Arrange
    const std::string seq("[a][a]]");

    // Act & Assert
    EXPECT_FALSE(RegExprT::ValidCheck(seq));
}

TEST(RegExprTest_ValidCheck, Empty_Brackets) {
    // Arrange
    const std::string seq("[][]");

    // Act & Assert
    EXPECT_FALSE(RegExprT::ValidCheck(seq));
}

TEST(RegExprTest_ValidCheck, Empty_Parenthesis) {
    // Arrange
    const std::string seq("()()");

    // Act & Assert
    EXPECT_FALSE(RegExprT::ValidCheck(seq));
}

TEST(RegExprTest_ValidCheck, Backslash_At_The_End) {
    // Arrange
    const std::string seq("abcdef\\");

    // Act & Assert
    EXPECT_FALSE(RegExprT::ValidCheck(seq));
}

TEST(RegExprTest_ValidCheck, Extra_Closing_Parenthes) {
    // Arrange
    const std::string seq("(a))");

    // Act & Assert
    EXPECT_FALSE(RegExprT::ValidCheck(seq));
}

TEST(RegExprTest_ValidCheck, Nested_Brackets) {
    // Arrange
    const std::string seq("[[a]]");

    // Act & Assert
    EXPECT_FALSE(RegExprT::ValidCheck(seq));
}

TEST(RegExprTest_Match, Match_Phone_Number) {
    // Arrange
    const std::string seq(
            "+7\\([0-9][0-9][0-9]\\)[0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9]");
    const std::string str("Sample_Name: +7(999)120-32-28");

    // Act
    RegExprT rx(seq);

    // Assert
    EXPECT_EQ(std::make_pair(13, 29), rx.Match(str));
}

