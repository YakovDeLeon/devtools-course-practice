// Copyright 2019 Trubina Anastasia

#ifndef MODULES_FIBONACCI_HEAP_INCLUDE_FIBONACCI_HEAP_H__
#define MODULES_FIBONACCI_HEAP_INCLUDE_FIBONACCI_HEAP_H__

class Node {
 private:
    int key_;
    Node* parent_;
    Node* child_;
    Node* left_;
    Node* right_;
    int degree_;
    bool mark_;

 public:
    Node();
    explicit Node(int _key);
    Node(const int _key, Node* _parent, Node* _child,
            Node* _left, Node* _right, int _degree, bool _mark);
    int GetKey();
    Node* GetParent();
    Node* GetChild();
    Node* GetLeft();
    Node* GetRight();
    int GetDegree();
    void SetKey(int _key);
    void SetParent(Node* _parent);
    void SetChild(Node* _child);
    void SetLeft(Node* _left);
    void SetRight(Node* _right);
    void SetDegree(int _d);
    void SetMark(bool _mark);
    bool IsMarked();
    bool HasChild();
    bool HasParent();
};

class FibonacciHeap {
 private:
    Node* heap_;
    void DeleteUnder(Node* n);
    Node* MergeInLess(Node* a, Node* b);
    Node* FindUnder(Node* _heap, int _key);
 public:
    FibonacciHeap();
    ~FibonacciHeap();
    bool IsEmpty();
    Node* GetHeap();
    int GetMinimum();
    void Insert(int _key);
    Node* Find(int _key);
    void Merge(const FibonacciHeap & other);
};

#endif  // MODULES_FIBONACCI_HEAP_INCLUDE_FIBONACCI_HEAP_H__
