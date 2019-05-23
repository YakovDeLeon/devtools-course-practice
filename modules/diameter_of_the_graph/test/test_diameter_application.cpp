// Copyright 2019 Savkin Yuriy

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "include/diameter_application.h"

class TestDiameterApplication: public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("DiameterApplication");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_TRUE(::testing::internal::RE::PartialMatch(output_,
                        ::testing::internal::RE(expected)));
    }
 private:
    DiameterApplication app_;
    std::string output_;
};

TEST_F(TestDiameterApplication, Printing_Help_Info_Without_Args) {
    // Arrange
    std::vector<std::string> args = {};

    Act(args);

    Assert("Commands:\n");
}

TEST_F(TestDiameterApplication, Printing_Help_Info_With_help_Arg) {
    // Arrange
    std::vector<std::string> args = {"help"};

    Act(args);

    Assert("Commands:\n");
}

TEST_F(TestDiameterApplication, Cant_init_If_Has_No_Size) {
    // Arrange
    std::vector<std::string> args = {"init"};

    Act(args);

    Assert("Incorrect usage of command \"init\"");
}

TEST_F(TestDiameterApplication, Cant_Work_Without_Vertexs) {
    // Arrange
    std::vector<std::string> args = {"init", "0"};

    Act(args);

    Assert("Error: graph has no vertexes");
}

TEST_F(TestDiameterApplication, Cant_Use_add_As_First_Arg) {
    // Arrange
    std::vector<std::string> args = {"add", "1", "0"};

    Act(args);

    Assert("Incorrect usage of command \"add\"");
}

TEST_F(TestDiameterApplication, Cant_Use_del_As_First_Arg) {
    // Arrange
    std::vector<std::string> args = {"del", "1", "0"};

    Act(args);

    Assert("Incorrect usage of command \"del\"");
}

TEST_F(TestDiameterApplication, Cant_init_After_init) {
    // Arrange
    std::vector<std::string> args = {"init", "1", "init"};

    Act(args);

    Assert("Incorrect usage of command \"init\"");
}

TEST_F(TestDiameterApplication, Cant_Use_help_After_init) {
    // Arrange
    std::vector<std::string> args = {"init", "1", "help"};

    Act(args);

    Assert("Incorrect usage of command \"help\"");
}

TEST_F(TestDiameterApplication, Cant_Use_Unknown_Command) {
    // Arrange
    std::vector<std::string> args = {"abacaba"};

    Act(args);

    Assert("Unknown command: abacaba");
}

TEST_F(TestDiameterApplication, Cant_Use_Unknown_Command_After_init) {
    // Arrange
    std::vector<std::string> args = {"init", "1", "abacaba"};

    Act(args);

    Assert("Unknown command: abacaba");
}

TEST_F(TestDiameterApplication,
    Cant_Use_Anything_Without_Digits_In_Some_Args) {
    // Arrange
    std::vector<std::string> args = {"init", "a1"};

    Act(args);

    Assert("Error with argument 2: not a number");
}

TEST_F(TestDiameterApplication,
    Cant_Calculate_Diameter_With_Disconnected_Graph) {
    // Arrange
    std::vector<std::string> args = {"init", "8", "add", "3", "5"};

    Act(args);

    Assert("Error: disconnected graph");
}

TEST_F(TestDiameterApplication, Working_With_Correct_Args) {
    // Arrange
    std::vector<std::string> args = {"init", "2", "add", "0", "1"};

    Act(args);

    Assert("1");
}

TEST_F(TestDiameterApplication, Cant_Use_Very_Big_Numbers) {
    // Arrange
    std::vector<std::string> args = {"init", "90072231873"};

    Act(args);

    Assert("Error with argument 2: too big number");
}

TEST_F(TestDiameterApplication,
    Cant_Use_Very_Big_Numbers_With_Accseptable_Length) {
    // Arrange
    std::vector<std::string> args = {"init", "51"};

    Act(args);

    Assert("Error with argument 2: too big number");
}

TEST_F(TestDiameterApplication, Can_Use_With_Length_About_To_Max) {
    // Arrange
    std::vector<std::string> args = {"init", "49"};

    Act(args);

    Assert("Error: disconnected graph");
}

TEST_F(TestDiameterApplication, Cant_Use_add_With_Incorrect_First_Arg) {
    // Arrange
    std::vector<std::string> args = {"init", "2", "add", "53", "1"};

    Act(args);

    Assert("Error with argument 4: too big number");
}

TEST_F(TestDiameterApplication, Cant_Use_add_With_Too_Big_First_Arg) {
    // Arrange
    std::vector<std::string> args = {"init", "2", "add", "5", "1"};

    Act(args);

    Assert("Error with argument 4: out of range");
}

TEST_F(TestDiameterApplication, Cant_Use_add_With_Incorrect_Second_Arg) {
    // Arrange
    std::vector<std::string> args = {"init", "2", "add", "1", "53"};

    Act(args);

    Assert("Error with argument 5: too big number");
}

TEST_F(TestDiameterApplication, Cant_Use_add_With_Too_Big_Second_Arg) {
    // Arrange
    std::vector<std::string> args = {"init", "2", "add", "1", "5"};

    Act(args);

    Assert("Error with argument 5: out of range");
}

TEST_F(TestDiameterApplication, Cant_Use_add_With_Too_Few_Args) {
    // Arrange
    std::vector<std::string> args = {"init", "2", "add", "1"};

    Act(args);

    Assert("Error: add has too few arguments");
}

TEST_F(TestDiameterApplication, Cant_Use_del_With_Incorrect_First_Arg) {
    // Arrange
    std::vector<std::string> args = {"init", "2", "del", "53", "1"};

    Act(args);

    Assert("Error with argument 4: too big number");
}

TEST_F(TestDiameterApplication, Cant_Use_del_With_Too_Big_First_Arg) {
    // Arrange
    std::vector<std::string> args = {"init", "2", "del", "5", "1"};

    Act(args);

    Assert("Error with argument 4: out of range");
}

TEST_F(TestDiameterApplication, Cant_Use_del_With_Incorrect_Second_Arg) {
    // Arrange
    std::vector<std::string> args = {"init", "2", "del", "1", "53"};

    Act(args);

    Assert("Error with argument 5: too big number");
}

TEST_F(TestDiameterApplication, Cant_Use_del_With_Too_Big_Second_Arg) {
    // Arrange
    std::vector<std::string> args = {"init", "2", "del", "1", "5"};

    Act(args);

    Assert("Error with argument 5: out of range");
}

TEST_F(TestDiameterApplication, Cant_Use_del_With_Too_Few_Args) {
    // Arrange
    std::vector<std::string> args = {"init", "2", "del", "1"};

    Act(args);

    Assert("Error: del has too few arguments");
}

TEST_F(TestDiameterApplication, del_Works_Correctly) {
    // Arrange
    std::vector<std::string> args = {
        "init", "3", "add", "0", "1",
        "add", "1", "2", "add", "2", "0",
        "del", "2", "1"};

    Act(args);

    Assert("2");
}
