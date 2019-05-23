// Copyright 2019 Trubina Anastasia

#include "include/fibonacci_heap.h"

Node::Node() : key_(0), parent_(nullptr), child_(nullptr), left_(nullptr),
            right_(nullptr), degree_(0), mark_(true) {}

Node::Node(int _key) : key_(_key), parent_(nullptr), child_(nullptr),
            left_(nullptr), right_(nullptr), degree_(0), mark_(true) {}

Node::Node(const int _key, Node* _parent, Node* _child, Node* _left,
        Node* _right, int _degree, bool _mark)
            : key_(_key), parent_(_parent), child_(_child), left_(_left),
            right_(_right), degree_(_degree), mark_(_mark) {}

int Node::GetKey() {
    return key_;
}

Node* Node::GetParent() {
    return parent_;
}

Node* Node::GetChild() {
    return child_;
}

Node* Node::GetLeft() {
    return left_;
}

Node* Node::GetRight() {
    return right_;
}

int Node::GetDegree() {
    return degree_;
}

void Node::SetParent(Node* _parent) {
    this->parent_ = _parent;
}

void Node::SetChild(Node* _child) {
    this->child_ = _child;
}

void Node::SetLeft(Node* _left) {
    this->left_ = _left;
}

void Node::SetRight(Node* _right) {
    this->right_ = _right;
}

void Node::SetDegree(int d) {
    this->degree_ = d;
}

void Node::SetKey(int _key) {
    this->key_ = _key;
}

void Node::SetMark(bool _mark) {
    this->mark_ = _mark;
}

bool Node::IsMarked() {
    return mark_;
}

bool Node::HasChild() {
    return (child_ != nullptr);
}

bool Node::HasParent() {
    return (parent_ != nullptr);
}

FibonacciHeap::FibonacciHeap() : heap_(nullptr) {}

FibonacciHeap::~FibonacciHeap() {
    if (heap_) {
    DeleteUnder(heap_);
    }
}

Node* FibonacciHeap::GetHeap() {
    return heap_;
}

int FibonacciHeap::GetMinimum() {
    return heap_->GetKey();
}

bool FibonacciHeap::IsEmpty() {
    return heap_ == nullptr;
}

void FibonacciHeap::DeleteUnder(Node* n) {
    if (n != nullptr) {
    Node* c = n;
    do {
    Node* d = c;
    c = c->GetRight();
    DeleteUnder(d->GetChild());
    delete d;
    } while (c != n);
    }
}

void FibonacciHeap::Insert(int _key) {
    Node *ins = new Node();
    ins->SetKey(_key);
    ins->SetRight(ins);
    ins->SetLeft(ins);
    ins->SetDegree(0);
    ins->SetMark(false);
    ins->SetChild(nullptr);
    ins->SetParent(nullptr);
    heap_ = MergeInLess(heap_, ins);
}

Node* FibonacciHeap::Find(int _key) {
    Node* n;
    n = FindUnder(heap_, _key);
    return n;
}

Node* FibonacciHeap::FindUnder(Node* _heap, int key) {
    Node* n = _heap;
    if (n == nullptr) return nullptr;
    do {
    if (n->GetKey() == key) return n;
    Node* ret = FindUnder(n->GetChild(), key);
    if (ret) return ret;
    n = n->GetRight();
    } while (n != _heap);
    return nullptr;
}

void FibonacciHeap::Merge(const FibonacciHeap& other) {
    heap_ = MergeInLess(heap_, other.heap_);
}

Node* FibonacciHeap::MergeInLess(Node* a, Node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    if (a->GetKey() > b->GetKey()) {
    Node* tmp = a;
    a = b;
    b = tmp;
    }
    Node* an = a->GetRight();
    Node* bp = b->GetLeft();
    a->SetRight(b);
    b->SetLeft(a);
    an->SetLeft(bp);
    bp->SetRight(an);
    return a;
}
