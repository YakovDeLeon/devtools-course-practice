// Copyright 2019 Timakin Nikita

#include <gtest/gtest.h>

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

#include "include/rb_tree.h"

TEST(RedBlackTreeNodeTest, Can_Create_Node_Default) {
    ASSERT_NO_THROW(Node{});
}

TEST(RedBlackTreeNodeTest, Can_Create_Node_from_Another) {
    Node node;

    ASSERT_NO_THROW(Node{node});
}

TEST(RedBlackTreeNodeTest, Can_Assign_Node) {
    Node x(1), y(2);

    ASSERT_NO_THROW(x = y);
}

TEST(RedBlackTreeNodeTest, Assigned_Node_Equals_to_Original) {
    Node x(1);

    Node y = x;

    ASSERT_TRUE(x == y);
}

TEST(RedBlackTreeNodeTest, The_Same_Nodes_Are_Equal) {
    Node x(1), y(1);

    ASSERT_TRUE(x == y);
}

TEST(RedBlackTreeNodeTest, Different_Nodes_Are_Not_Equal) {
    Node x(1), y(2);

    ASSERT_TRUE(x != y);
}

TEST(RedBlackTreeNodeTest, Can_cout_Node) {
    Node x;

    ASSERT_NO_THROW(std::cout << x << std::endl;);
}

TEST(RedBlackTreeTest, Can_Create_Tree_Default) {
    ASSERT_NO_THROW(RBTree{});
}

TEST(RedBlackTreeTest, Can_Create_Tree_from_Node) {
    Node *node = new Node{};

    ASSERT_NO_THROW(RBTree{node});
}

TEST(RedBlackTreeTest, Can_Create_Tree_from_Vector) {
    std::vector<int> vec{0, 1, 2};

    ASSERT_NO_THROW(RBTree{vec});
}

TEST(RedBlackTreeTest, Copy_Constructor_Does_Not_Raise_Any_Exceptions) {
    std::vector<int> vec{0, 1, 2};
    RBTree tree{vec};

    ASSERT_NO_THROW(RBTree{tree});
}

TEST(RedBlackTreeTest, Can_Get_Root) {
    Node *node = new Node(1);
    RBTree tree{node};

    ASSERT_EQ(1, tree.GetRoot()->value);
}

TEST(RedBlackTreeTest, Can_Get_Current) {
    Node *node = new Node(1);
    RBTree tree{node};

    tree.Begin();

    ASSERT_EQ(1, tree.GetCurrent()->value);
}

TEST(RedBlackTreeTest, Can_Get_Nodes_Number) {
    Node *node = new Node(1);
    RBTree tree{node};

    ASSERT_EQ(static_cast<unsigned>(1), tree.GetNodesNumber());
}

TEST(RedBlackTreeTest, Can_Find_Existing_Item) {
    std::vector<int> vec{-10, 35, 2};
    RBTree tree{vec};

    bool is_found = tree.Find(35);

    ASSERT_TRUE(is_found);
}

TEST(RedBlackTreeTest, Can_Not_Find_Nonexistent_Item) {
    std::vector<int> vec{-10, 35, 2};
    RBTree tree{vec};

    bool is_found = tree.Find(0);

    ASSERT_FALSE(is_found);
}

TEST(RedBlackTreeTest, Can_Insert_New_Item) {
    std::vector<int> vec{0, 1, 2};
    RBTree tree{vec};

    Node *new_node = new Node(3);

    ASSERT_NO_THROW(tree.Insert(new_node));
}

TEST(RedBlackTreeTest, Can_Not_Insert_Existing_Item) {
    std::vector<int> vec{0, 1, 2};
    RBTree tree{vec};

    Node *existing_node = new Node(1);

    ASSERT_ANY_THROW(tree.Insert(existing_node));
}

TEST(RedBlackTreeTest, Can_Remove_Existing_Item) {
    std::vector<int> vec{0, 1, 2};
    RBTree tree{vec};

    ASSERT_NO_THROW(tree.Remove(1));
}

TEST(RedBlackTreeTest, Can_Not_Remove_Nonexistent_Item) {
    std::vector<int> vec{0, 1, 2};
    RBTree tree{vec};

    ASSERT_ANY_THROW(tree.Remove(3));
}

TEST(RedBlackTreeTest, Begin_Sets_Current_to_Smallest_Item) {
    std::vector<int> vec{10, 1, 8};
    RBTree tree{vec};

    tree.Begin();

    ASSERT_EQ(1, tree.GetCurrent()->value);
}

TEST(RedBlackTreeTest, Iterator_Represents_All_Items) {
    std::vector<int> vec{0, 1, 2};
    RBTree tree{vec};
    bool result = true;
    unsigned i = 0;

    for (tree.Begin(); !tree.End(); tree.Next(), ++i)
        if (vec[i] != tree.GetCurrent()->value)
            result = false;

    result &= (i == vec.size());

    ASSERT_TRUE(result);
}

TEST(RedBlackTreeTest, Removing_All_Nodes_Clears_a_Tree) {
    std::vector<int> vec{10, 1, 8, -6, 35, 0, -11};
    RBTree tree{vec};

    std::random_device rd;
    std::mt19937 g(rd());

    std::default_random_engine re(0);
    std::shuffle(vec.begin(), vec.end(), re);

    for (auto i = vec.begin(); i < vec.end(); ++i)
        tree.Remove(*i);

    ASSERT_EQ(static_cast<unsigned>(0), tree.GetNodesNumber());
}

TEST(RedBlackTreeTest, Stack_Clears_Before_Iteration) {
    std::vector<int> vec{10, 1, 8, -6, 35, 0, -11};
    RBTree tree{vec};

    tree.Begin();
    tree.Next();
    tree.Next();

    unsigned i = 0;
    for (tree.Begin(); !tree.End(); tree.Next()) {
        Node *node = tree.GetCurrent();
        ++i;
    }

    ASSERT_EQ(i, tree.GetNodesNumber());
}

TEST(RedBlackTreeTest, Can_Operate_with_Large_Tree) {
    std::vector<int> vec;

    for (int i = -500; i <= 500; ++i)
        vec.emplace_back(i);

    std::default_random_engine re(0);
    std::shuffle(vec.begin(), vec.end(), re);

    RBTree tree{vec};

    auto some_tree_operations = [&tree, &vec, &re] {
        for (tree.Begin(); !tree.End(); tree.Next())
            Node *node = tree.GetCurrent();

        std::shuffle(vec.begin(), vec.end(), re);

        for (auto i = vec.begin(); i < vec.end(); ++i)
            tree.Remove(*i);
    };

    ASSERT_NO_THROW(some_tree_operations());
}
