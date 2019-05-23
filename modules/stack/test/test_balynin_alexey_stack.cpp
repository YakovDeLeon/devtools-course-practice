// Copyright 2019 Balynin Alexey

#include <gtest/gtest.h>
#include "include/TStack.h"

TEST(Test_Balynin_Alexey_Stack, Can_Crate_Stack) {
    // Arrange & Assert
    ASSERT_NO_THROW(TStack a);
}

TEST(Test_Balynin_Alexey_Stack, Can_Add_And_Remove_Element) {
    // Arrange
    TStack a;
    // Assert
    EXPECT_NO_THROW(a.Put(1));
    EXPECT_NO_THROW(a.Get());
}

TEST(Test_Balynin_Alexey_Stack, Cant_Add_Element_If_Stack_Has_No_Data) {
    // Arrange
    TStack a(0);
    // Act
    a.Put(1);
    // Assert
    EXPECT_EQ(DataNoMem, a.IsValid());
}

TEST(Test_Balynin_Alexey_Stack, Cant_Remove_Element_If_Stack_Has_No_Data) {
    // Arrange
    TStack a(0);
    // Act & Assert
    try {
        a.Get();
    }
    catch (int b) {
        EXPECT_EQ(DataNoMem, a.IsValid());
    }
}

TEST(Test_Balynin_Alexey_Stack, Cant_Add_Element_If_Stack_Is_Full) {
    // Arrange
    TStack a(1);
    // Act
    a.Put(1);
    a.Put(1);
    // Assert
    EXPECT_EQ(DataFull, a.IsValid());
}

TEST(Test_Balynin_Alexey_Stack, Cant_Remove_Element_If_Stack_Is_Empty) {
    // Arrange
    TStack a(1);
    // Act & Assert
    try {
        a.Get();
    }
    catch (int b) {
        EXPECT_EQ(DataEmpty, a.IsValid());
    }
}

TEST(Test_Balynin_Alexey_Stack, Cant_Get_Top_Element_If_Stack_Has_No_Data) {
    // Arrange
    TStack a(0);
    // Act & Assert
    try {
        a.TopElem();
    }
    catch (int b) {
        EXPECT_EQ(DataNoMem, a.IsValid());
    }
}

TEST(Test_Balynin_Alexey_Stack, Cant_Get_Top_Element_If_Stack_Is_Empty) {
    // Arrange
    TStack a(1);
    // Act & Assert
    try {
        a.TopElem();
    }
    catch (int b) {
        EXPECT_EQ(DataEmpty, a.IsValid());
    }
}

TEST(Test_Balynin_Alexey_Stack, Can_Get_Top_Element) {
    // Arrange
    TStack a;
    // Assert
    EXPECT_NO_THROW(a.Put(1));
    EXPECT_NO_THROW(a.TopElem());
}
