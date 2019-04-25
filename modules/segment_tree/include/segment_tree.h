// Copyright 2019 Savkin Yuriy

#ifndef MODULES_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_H_
#define MODULES_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_H_

#include <functional>

class SegmentTree {
 private:
    struct Node {
        Node* left_n;
        Node* right_n;
        int value;
        int push_value;
        bool is_changed;
        explicit Node(int _v, Node* _l = nullptr, Node* _r = nullptr);
    };

    struct Position {
        int left, right;
        Node* p;
    };

    int base_elem_;
    int left_barr_;
    int right_barr_;
    std::function<int(int, int, int)> operation_;
    Node* root_;

    void CorrectNode(Node** p);
    bool IsCorrectNode(const Node* const p) const;

 public:
    SegmentTree(const int left_barr, const int right_barr, const
        std::function<int(int, int, int)>& fu =
                [](int a, int b, int c) { return a + b * c; },
                    const int base_elem = 0);
    SegmentTree(const SegmentTree& st);
    ~SegmentTree();
    SegmentTree& operator=(const SegmentTree& st);

    void AddValue(int pos, int value);
    void AddValue(int l_pos, int r_pos, int value);
    void SetValue(int pos, int value);
    void SetValue(int l_pos, int r_pos, int value);
    int GetValue(int pos) const;
    int GetValue(int l_pos, int r_pos) const;

    const int GetBaseElem() const;
    const int GetLeftBarr() const;
    const int GetRightBarr() const;
};

#endif  // MODULES_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_H_
