// Copyright 2019 Korobeinikov Aleksey

#include <gtest/gtest.h>

#include <vector>

#include "include/diameter.h"

using list = std::initializer_list<std::initializer_list<int>>;

class DiameterTest : public ::testing::Test {
 protected:
    int n = 8;
    matrix v;
    list l;
    void init() {
        v.resize(n);
        int i = 0;
        for (auto it : l) {
            v[i].insert(v[i].end(), it.begin(), it.end());
            i++;
        }
    }
};

TEST_F(DiameterTest,
    check_correctness_of_DiameterOfGraph_with_equal_edges) {
    // Arrange
    l = { { 0, 1, 0, 0, 0, 1, 0, 0 }, { 1, 0, 1, 1, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 1, 0 }, { 0, 1, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 1, 0, 1 }, { 1, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 1, 0, 1, 0 } };
    init();
    Graph g(std::move(v), n);

    // Act
    int ans = g.DiameterOfGraph();

    // Assert
    EXPECT_EQ(3, ans);
}

TEST_F(DiameterTest,
    check_correctness_of_DiameterOfGraph_with_different_edges) {
    // Arrange
    l = { { 0, 3, 0, 0, 0, 6, 0, 0 }, { 3, 0, 9, 1, 0, 0, 0, 0 },
    { 0, 9, 0, 0, 0, 0, 5, 0 }, { 0, 1, 0, 0, 4, 0, 0, 0 },
    { 0, 0, 0, 4, 0, 1, 0, 2 }, { 6, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 5, 0, 0, 0, 0, 7 }, { 0, 0, 0, 0, 2, 0, 7, 0 } };
    init();
    Graph g(std::move(v), n);

    // Act
    int ans = g.DiameterOfGraph();

    // Assert
    EXPECT_EQ(16, ans);
}

TEST_F(DiameterTest,
    check_correctness_of_diameter_of_tree_with_equal_edges) {
    // Arrange
    l = { { 0, 0, 1, 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0, 0, 0 },
    { 1, 1, 0, 1, 0, 1, 0, 0 }, { 0, 0, 1, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0, 1, 1 },
    { 0, 0, 0, 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0, 1, 0, 0 } };
    init();
    Graph g(std::move(v), n);

    // Act
    int ans = g.DiameterOfGraph();

    // Assert
    EXPECT_EQ(4, ans);
}

TEST_F(DiameterTest,
    check_correctness_of_diameter_of_tree_with_different_edges) {
    // Arrange
    l = { { 0, 0, 2, 0, 0, 0, 0, 0 }, { 0, 0, 4, 0, 0, 0, 0, 0 },
    { 2, 4, 0, 3, 0, 2, 0, 0 }, { 0, 0, 3, 0, 2, 0, 0, 0 },
    { 0, 0, 0, 2, 0, 0, 0, 0 }, { 0, 0, 2, 0, 0, 0, 2, 1 },
    { 0, 0, 0, 0, 0, 2, 0, 0 }, { 0, 0, 0, 0, 0, 1, 0, 0 } };
    init();
    Graph g(std::move(v), n);

    // Act
    int ans = g.DiameterOfGraph();

    // Assert
    EXPECT_EQ(9, ans);
}

TEST_F(DiameterTest,
    check_correctness_of_copy_constructor) {
    // Arrange
    l = { { 0, 0, 2, 0, 0, 0, 0, 0 }, { 0, 0, 4, 0, 0, 0, 0, 0 },
    { 2, 4, 0, 3, 2, 0, 0, 0 }, { 0, 0, 3, 0, 2, 0, 0, 0 },
    { 0, 0, 0, 2, 0, 0, 0, 0 }, { 0, 0, 2, 0, 0, 0, 2, 1 },
    { 0, 0, 0, 0, 0, 2, 0, 0 }, { 0, 0, 0, 0, 0, 1, 0, 0 } };
    init();
    Graph a(std::move(v), n);
    Graph b(a);

    // Act
    int ans1 = a.DiameterOfGraph();
    int ans2 = b.DiameterOfGraph();

    // Assert
    EXPECT_EQ(1, ans1 == ans2);
}

TEST_F(DiameterTest,
    check_correctness_of_equality_operator) {
    // Arrange
    l = { { 0, 0, 2, 0, 0, 0, 0, 0 }, { 0, 0, 4, 0, 0, 0, 0, 0 },
    { 2, 4, 0, 3, 2, 0, 0, 0 }, { 0, 0, 3, 0, 2, 0, 0, 0 },
    { 0, 0, 0, 2, 0, 0, 0, 0 }, { 0, 0, 2, 0, 0, 0, 2, 1 },
    { 0, 0, 0, 0, 0, 2, 0, 0 }, { 0, 0, 0, 0, 0, 1, 0, 0 } };
    init();
    Graph a(std::move(v), n);
    Graph b;

    // Act
    int ans1 = a.DiameterOfGraph();
    b = a;
    int ans2 = b.DiameterOfGraph();

    // Assert
    EXPECT_EQ(1, ans1 == ans2);
}

TEST_F(DiameterTest,
    check_correctness_of_PrintDistance) {
    // Arrange
    l = { { 0, 3, 0, 0, 0, 6, 0, 0 }, { 3, 0, 9, 1, 0, 0, 0, 0 },
    { 0, 9, 0, 0, 0, 0, 5, 0 }, { 0, 1, 0, 0, 4, 0, 0, 0 },
    { 0, 0, 0, 4, 0, 1, 0, 2 }, { 6, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 5, 0, 0, 0, 0, 7 }, { 0, 0, 0, 0, 2, 0, 7, 0 } };
    init();
    Graph a(std::move(v), n);

    // Act & Assert
    EXPECT_NO_THROW(a.PrintDistance());
}
