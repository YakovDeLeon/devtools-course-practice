// Copyright 2019 Zhivaev Artem

#include <gtest/gtest.h>

#include <string>

#include "include/nfa.h"

TEST(NFAStateTest_TryDoTrans, Pattern_With_One_Char_Returns_1_If_Matched) {
    // Arrange
    NFAStateT nd1, nd2;
    std::string str("ab");

    // Act
    nd2.isFinal_ = true;
    nd1.next_ = &nd2;
    nd1.AddCharNext('a');
    int res = nd1.Match(str.c_str());

    // Assert
    EXPECT_EQ(1, res);
}

TEST(NFAStateTest_TryDoTrans, Pattern_With_three_Chars_Return_3) {
    // Arrange
    NFAStateT nd1, nd2, nd3, nd4;
    std::string str("abcde");

    // Act
    nd4.isFinal_ = true;
    nd1.next_ = &nd2;
    nd2.next_ = &nd3;
    nd3.next_ = &nd4;
    nd1.AddCharNext('a');
    nd2.AddCharNext('b');
    nd3.AddCharNext('c');
    int res = nd1.Match(str.c_str());

    // Assert
    EXPECT_EQ(3, res);
}

TEST(NFAStateTest_TryDoTrans, Returns_Negative_If_No_Matches_Found) {
    // Arrange
    NFAStateT nd1, nd2, nd3, nd4;
    std::string str("abbde");

    // Act
    nd4.isFinal_ = true;
    nd1.next_ = &nd2;
    nd2.next_ = &nd3;
    nd3.next_ = &nd4;
    nd1.AddCharNext('a');
    nd2.AddCharNext('b');
    nd3.AddCharNext('c');
    int res = nd1.Match(str.c_str());

    // Assert
    EXPECT_EQ(-1, res);
}

TEST(NFAStateTest_TryDoTrans,
     Loop_Trans_Stops_When_Rest_String_Matches) {
    // Arrange
    NFAStateT nd1, nd2, nd3, nd4;
    std::string str("baab");

    // Act
    nd4.isFinal_ = true;
    nd1.next_ = &nd2;
    nd2.next_ = &nd3;
    nd3.next_ = &nd4;
    nd1.AddCharNext('b');
    nd2.AddCharsLoop({'a'});
    nd2.AddCharNext('a');
    nd3.AddCharNext('b');
    int res = nd1.Match(str.c_str());

    // Assert
    EXPECT_EQ(4, res);
}

TEST(NFAStateTest_TryDoTrans, Skip_Loop_If_Rest_String_Matches) {
    // Arrange
    NFAStateT nd1, nd2, nd3, nd4;
    std::string str("bab");

    // Act
    nd4.isFinal_ = true;
    nd1.next_ = &nd2;
    nd2.next_ = &nd3;
    nd3.next_ = &nd4;
    nd1.AddCharNext('b');
    nd2.AddCharsLoop({'a'});
    nd2.AddCharNext('a');
    nd3.AddCharNext('b');
    int res = nd1.Match(str.c_str());

    // Assert
    EXPECT_EQ(3, res);
}

TEST(NFAStateTest_TryDoTrans, Loop_Handle_Many_Same_Chars) {
    // Arrange
    NFAStateT nd1, nd2, nd3, nd4;
    std::string str("baaaaab");

    // Act
    nd4.isFinal_ = true;
    nd1.next_ = &nd2;
    nd2.next_ = &nd3;
    nd3.next_ = &nd4;
    nd1.AddCharNext('b');
    nd2.AddCharsLoop({'a'});
    nd2.AddCharNext('a');
    nd3.AddCharNext('b');
    int res = nd1.Match(str.c_str());

    // Assert
    EXPECT_EQ(7, res);
}

TEST(NFAStateTest_TryDoTrans,
     Loop_With_Two_Chars_Fails_If_String_Has_Only_One_That_Char) {
    // Arrange
    NFAStateT nd1, nd2, nd4;
    std::string str("baaab");

    // Act
    nd4.isFinal_ = true;
    nd1.next_ = &nd2;
    nd2.next_ = &nd4;
    nd1.AddCharNext('b');
    nd2.AddCharsLoop({'a'});
    nd2.AddCharsLoop({'a'});
    nd2.AddCharNext('b');
    int res = nd1.Match(str.c_str());

    // Assert
    EXPECT_EQ(-1, res);
}

TEST(NFAStateTest_TryDoTrans, Loop_With_Two_Chars) {
    // Arrange
    NFAStateT nd1, nd2, nd4;
    std::string str("baaaab");

    // Act
    nd4.isFinal_ = true;
    nd1.next_ = &nd2;
    nd2.next_ = &nd4;
    nd1.AddCharNext('b');
    nd2.AddCharsLoop({'a'});
    nd2.AddCharsLoop({'a'});
    nd2.AddCharNext('b');
    int res = nd1.Match(str.c_str());

    // Assert
    EXPECT_EQ(6, res);
}

TEST(NFAStateTest_TryDoTrans,
     Skip_Loop_With_Two_Chars_If_Rest_String_Matches) {
    // Arrange
    NFAStateT nd1, nd2, nd4;
    std::string str("bb");

    // Act
    nd4.isFinal_ = true;
    nd1.next_ = &nd2;
    nd2.next_ = &nd4;
    nd1.AddCharNext('b');
    nd2.AddCharsLoop({'a'});
    nd2.AddCharsLoop({'a'});
    nd2.AddCharNext('b');
    int res = nd1.Match(str.c_str());

    // Assert
    EXPECT_EQ(2, res);
}

TEST(NFAStateTest_TryDoTrans,
     If_ThrouLvl_Non_Zero_And_Char_Does_Not_Matches_Go_Next_State) {
    // Arrange
    NFAStateT nd1, nd2, nd3, nd4;
    std::string str("bb");

    // Act
    nd4.isFinal_ = true;
    nd1.next_ = &nd2;
    nd2.next_ = &nd3;
    nd3.next_ = &nd4;
    nd1.AddCharNext('b');
    nd2.AddCharNext('F');
    nd2.throughLvl_ = 1;
    nd3.AddCharNext('b');
    int res = nd1.Match(str.c_str());

    // Assert
    EXPECT_EQ(2, res);
}

TEST(NFAStateTest_TryDoTrans,
     If_ThrouLvl_Non_Zero_And_Char_Matches_Do_Not_Go_Next_State) {
    // Arrange
    NFAStateT nd1, nd2, nd3, nd4;
    std::string str("bFb");

    // Act
    nd4.isFinal_ = true;
    nd1.next_ = &nd2;
    nd2.next_ = &nd3;
    nd3.next_ = &nd4;
    nd1.AddCharNext('b');
    nd2.AddCharNext('F');
    nd2.throughLvl_ = 1;
    nd3.AddCharNext('b');
    int res = nd1.Match(str.c_str());

    // Assert
    EXPECT_EQ(3, res);
}

TEST(NFAStateTest_TryDoTrans, Throws_If_Nullptr_Passed) {
    // Act && Assert
    EXPECT_ANY_THROW(NFAStateT().TryDoTrans(nullptr, nullptr, 'a'));
}

TEST(NFAState_AddCharsLoop, Can_Add_Chars_To_Loop_Any_Times) {
    // Arrange
    const std::string str("abcdabcd");
    NFAStateT nd1;

    // Act
    nd1.AddCharsLoop({'a'});
    nd1.AddCharsLoop({'b'});
    nd1.AddCharsLoop({'c'});
    nd1.AddCharsLoop({'d'});
    nd1.isFinal_ = true;

    // Assert
    EXPECT_EQ(8, NFAStateT().TryDoTrans(&nd1, str.c_str(), 0));
}

