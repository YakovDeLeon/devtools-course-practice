// Copyright 2019 Kutovoi Vadim

#include <gtest/gtest.h>

#include <string>

#include "include/sdb.h"

TEST(StudentDataBaseTest,
    Can_Add_Record) {
    // Arrange
    Sdb db;
    std::string first_name = "Alan", last_name = "Turing";

    // Act & Assert

    ASSERT_TRUE(db.AddStudent(first_name, last_name));
}

TEST(StudentDataBaseTest,
    Cant_Add_Existing_Record) {
    // Arrange

    Sdb db;
    std::string first_name = "Alan", last_name = "Turing";
    db.AddStudent(first_name, last_name);

    // Act & Assert

    ASSERT_FALSE(db.AddStudent(first_name, last_name));
}

TEST(StudentDataBaseTest,
    Can_Remove_Record) {
    // Arrange

    Sdb db;
    std::string first_name = "Alan", last_name = "Turing";
    db.AddStudent(first_name, last_name);

    // Act & Assert

    EXPECT_TRUE(db.RemoveStudent(last_name));
}

TEST(StudentDataBaseTest,
    Cant_Remove_Non_Existing_Record) {
    // Arrange

    Sdb db;
    std::string first_name = "Alan", last_name = "Turing";

    db.AddStudent(first_name, last_name);

    last_name = "Cormen";

    EXPECT_FALSE(db.RemoveStudent(last_name));
}

TEST(StudentDataBaseTest,
    Can_Add_Mark) {
    // Arrange

    Sdb db;
    Sdb::uint mark = 5;
    std::string first_name = "Alan",
        last_name = "Turing",
        subject_name = "Algebra";

    db.AddStudent(first_name, last_name);

    // Act & Assert

    EXPECT_TRUE(db.AddMark(last_name, subject_name, mark));
}

TEST(StudentDataBaseTest,
    Cant_Add_Mark_If_Record_Not_Exists) {
    // Arrange

    Sdb db;
    Sdb::uint mark = 5;
    std::string first_name = "Alan",
        last_name = "Turing",
        subject_name = "Algebra";

    db.AddStudent(first_name, last_name);

    last_name = "Cormen";

    // Act & Assert

    EXPECT_FALSE(db.AddMark(last_name, subject_name, mark));
}

TEST(StudentDataBaseTest,
    Can_Get_Avg_Mark) {
    // Arrange

    Sdb db;

    Sdb::uint mark = 5;
    std::string first_name = "Alan",
        last_name = "Turing",
        subject_name = "Algebra";

    db.AddStudent(first_name, last_name);
    db.AddMark(last_name, subject_name, mark);

    mark = 3;
    db.AddMark(last_name, subject_name, mark);

    mark = 4;
    db.AddMark(last_name, subject_name, mark);

    // Act & Assert

    EXPECT_EQ(db.GetAvgMark(last_name), 4);
}

TEST(StudentDataBaseTest,
    Cant_Get_Avg_Mark_If_Record_Not_Exists) {
    // Arrange

    Sdb db;

    Sdb::uint mark = 5;
    std::string first_name = "Alan",
        last_name = "Turing",
        subject_name = "Algebra";

    db.AddStudent(first_name, last_name);
    db.AddMark(last_name, subject_name, mark);

    mark = 3;
    db.AddMark(last_name, subject_name, mark);

    mark = 4;
    db.AddMark(last_name, subject_name, mark);

    last_name = "Cormen";

    // Act & Assert

    EXPECT_EQ(db.GetAvgMark(last_name), -1);
}

TEST(StudentDataBaseTest,
    Can_Get_Num_Of_Records) {
    // Arrange

    Sdb db;

    std::string first_name = "Alan", last_name = "Turing";

    db.AddStudent(first_name, last_name);

    last_name = "Cormen";
    first_name = "Thomas";

    db.AddStudent(first_name, last_name);

    // Act & Assert

    EXPECT_EQ(db.GetNumberOfStudents(), 2);
}

TEST(StudentDataBaseTest,
    Can_Get_Number_Of_Good_Students) {
    // Arrange

    Sdb db;

    Sdb::uint mark = 5;
    std::string first_name = "Alan",
        last_name = "Turing",
        subject_name = "Algebra";

    db.AddStudent(first_name, last_name);
    db.AddMark(last_name, subject_name, mark);

    last_name = "Cormen";
    first_name = "Thomas";
    mark = 4;

    db.AddStudent(first_name, last_name);
    db.AddMark(last_name, subject_name, mark);

    last_name = "Zuckerberg";
    first_name = "Mark";
    mark = 3;

    // Act & Assert

    EXPECT_EQ(db.GetNumberOfGoodStudents(), 2);
}

TEST(StudentDataBaseTest,
    Can_Get_Number_Of_Bad_Students) {
    // Arrange

    Sdb db;

    Sdb::uint mark = 5;
    std::string first_name = "Alan",
        last_name = "Turing",
        subject_name = "Algebra";

    db.AddStudent(first_name, last_name);
    db.AddMark(last_name, subject_name, mark);

    last_name = "Cormen";
    first_name = "Thomas";
    mark = 4;

    db.AddStudent(first_name, last_name);
    db.AddMark(last_name, subject_name, mark);

    last_name = "Zuckerberg";
    first_name = "Mark";
    mark = 3;

    db.AddStudent(first_name, last_name);
    db.AddMark(last_name, subject_name, mark);

    // Act & Assert

    EXPECT_EQ(db.GetNumberOfBadStudents(), 1);
}

TEST(StudentDataBaseTest,
    Can_Add_Several_Subjects) {
    // Arrange

    Sdb db;
    Sdb::uint mark = 5;
    std::string first_name = "Alan",
        last_name = "Turing",
        subject_name = "Algebra";

    db.AddStudent(first_name, last_name);

    // Act & Assert

    EXPECT_TRUE(db.AddMark(last_name, subject_name, mark));
}

TEST(StudentDataBaseTest,
    Can_Get_Avg_Mark_From_Several_Subjects) {
    // Arrange

    Sdb db;
    Sdb::uint mark = 5;
    std::string first_name = "Alan",
        last_name = "Turing",
        first_subject_name = "Algebra",
        second_subject_name = "Philosophy";

    db.AddStudent(first_name, last_name);
    db.AddMark(last_name, first_subject_name, mark);
    mark = 3;
    db.AddMark(last_name, second_subject_name, mark);

    // Act & Assert

    EXPECT_EQ(db.GetAvgMark(last_name), 4);
}
