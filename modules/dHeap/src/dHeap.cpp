// Copyright 2019 Soluyanov Alexsey

#include <algorithm>
#include <vector>

#include "include/dHeap.h"

DHeap::DHeap(int d) : d_(d) {
    weight_ = std::vector<int>();
}

DHeap::DHeap(int d, std::vector<int> w) : d_(d), weight_(w) {
    Make();
}

int DHeap::Parent(int node) {
    if (node % d_ == 0) {
        return (node / d_) - 1;
    }
    return node / d_;
}

int DHeap::Left_child(int node) {
    int leftch = node * d_ + 1;
    if (leftch > static_cast<int>(weight_.size()) - 1) {
        return -1;
    }
    return leftch;
}

int DHeap::Right_child(int node) {
    int leftch = Left_child(node);
    if (leftch == -1) {
        return -1;
    }
    return std::min(leftch + d_ - 1, static_cast<int>(weight_.size()) - 1);
}

int DHeap::Min_child(int node) {
    int leftch = Left_child(node);
    if (leftch == -1) {
        return -1;
    }
    int minch = leftch;
    int rightch = Right_child(node);
    for (int i = 0; i <= rightch - leftch; i++) {
        if (weight_[minch + i] < weight_[minch]) {
            minch = minch + i;
        }
    }
    return minch;
}

void DHeap::Swap(int child, int parent) {
    int temp = weight_[child];
    weight_[child] = weight_[parent];
    weight_[parent] = temp;
}

void DHeap::Diving(int node) {
    int parent = node;
    int minch = Min_child(node);
    while (minch != -1 && weight_[parent] > weight_[minch]) {
        Swap(minch, parent);
        parent = minch;
        minch = Min_child(parent);
    }
}

void DHeap::Emersion(int node) {
    int child = node;
    int prnt = Parent(node);
    while (prnt != -1 && weight_[child] < weight_[prnt]) {
        Swap(child, prnt);
        child = prnt;
        prnt = Parent(child);
    }
}

void DHeap::Insert(int w) {
    weight_.push_back(w);
    Emersion(weight_.size() - 1);
}

void DHeap::Delete_min() {
    Swap(0, weight_.size() - 1);
    weight_.pop_back();
    Diving(0);
}

void DHeap::Delete(int node) {
    Decrease_weight(node, INT16_MAX);
    Delete_min();
}

void DHeap::Decrease_weight(int node, int w) {
    weight_[node] -= w;
    Emersion(node);
}

void DHeap::Make() {
    for (unsigned int i = weight_.size(); i > 0; i--) {
        Diving(i - 1);
    }
}

int DHeap::get_d() {
    return d_;
}

std::vector<int> DHeap::get_weight() {
    return weight_;
}

int DHeap::get_left_child(int i) {
    return Left_child(i);
}

int DHeap::get_right_child(int i) {
    return Right_child(i);
}

int DHeap::get_parent(int i) {
    return Parent(i);
}

int DHeap::get_min_child(int i) {
    return Min_child(i);
}
