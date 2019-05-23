// Copyright_ 2019 Ivan Blagin

#include <algorithm>
#include <vector>
#include <random>
#include <string>

#include "include/dictionary.h"

using std::max;
using std::string;

Node* Dictionary::Insert(const Word& x, Node* t) {
    if (t == nullptr) {
        t = new Node;
        t->data_ = x;
        t->height_ = 0;
        t->left_ = t->right_ = nullptr;
    } else if (x.first < t->data_.first) {
        t->left_ = Insert(Word(x), t->left_);
        if (Height(t->left_) - Height(t->right_) == 2) {
            if (x.first < t->left_->data_.first) {
                t = SingleRightRotate(t);
            } else {
                t = DoubleRightRotate(t);
            }
        }
    } else if (x.first > t->data_.first) {
        t->right_ = Insert(Word(x), t->right_);
        if (Height(t->right_) - Height(t->left_) == 2) {
            if (x.first > t->right_->data_.first) {
                t = SingleLeftRotate(t);
            } else {
                t = DoubleLeftRotate(t);
            }
        }
    } else if (x.first == t->data_.first) {
        t->data_.second = x.second;
    }

    t->height_ = max(Height(t->left_), Height(t->right_)) + 1;
    return t;
}

Node* Dictionary::SingleRightRotate(Node* t) {
    Node* u = t->left_;
    t->left_ = u->right_;
    u->right_ = t;
    t->height_ = max(Height(t->left_), Height(t->right_)) + 1;
    u->height_ = max(Height(u->left_), t->height_) + 1;
    return u;
}

Node* Dictionary::SingleLeftRotate(Node* t) {
    Node* u = t->right_;
    t->right_ = u->left_;
    u->left_ = t;
    t->height_ = max(Height(t->left_), Height(t->right_)) + 1;
    u->height_ = max(Height(t->right_), t->height_) + 1;
    return u;
}

Node* Dictionary::DoubleLeftRotate(Node* t) {
    t->right_ = SingleRightRotate(t->right_);
    return SingleLeftRotate(t);
}

Node* Dictionary::DoubleRightRotate(Node* t) {
    t->left_ = SingleLeftRotate(t->left_);
    return SingleRightRotate(t);
}

Node* Dictionary::FindMin(Node* t) {
    if (t->left_ == nullptr) {
        return t;
    } else {
        return FindMin(t->left_);
    }
}

Node * Dictionary::FindMax(Node * t) {
    if (t->right_ == nullptr) {
        return t;
    } else {
        return FindMax(t->right_);
    }
}

Node* Dictionary::Remove(const Word& x, Node* t) {
    Node* temp;

    if (t == nullptr) {
        //
        // Element not found
        //
        return nullptr;
    } else if (x.first < t->data_.first) {
        //
        // Searching for element
        //
        t->left_ = Remove(x, t->left_);
    } else if (x.first > t->data_.first) {
        t->right_ = Remove(x, t->right_);
    } else if (t->left_ && t->right_) {
        //
        // Element found
        // With 2 children
        //
        temp = FindMin(t->right_);
        t->data_ = temp->data_;
        t->right_ = Remove(t->data_, t->right_);
    } else {
        //
        // With one or zero child
        //
        temp = t;
        if (t->left_ == nullptr) {
            t = t->right_;
        } else if (t->right_ == nullptr) {
            t = t->left_;
        }
        delete temp;
    }
    if (t == nullptr)
        return t;

    t->height_ = max(Height(t->left_), Height(t->right_)) + 1;

    if (Height(t->left_) - Height(t->right_) == 2) {
        //
        // If Node is unbalanced
        // If left Node is deleted, right case
        //
        if (Height(t->left_->right_) - Height(t->left_->left_) == 1) {
            //
            // right right case
            //
            return DoubleRightRotate(t);
        } else {
            //
            // Single right case
            //
            return SingleRightRotate(t);
        }
    } else if (Height(t->right_) - Height(t->left_) == 2) {
        //
        // If right Node is deleted, left case
        //
        if (Height(t->right_->left_) - Height(t->right_->right_) == 1) {
            //
            // left left case
            //
            return DoubleLeftRotate(t);
        } else {
            //
            // Single left case
            //
            return SingleLeftRotate(t);
        }
    }
    return t;
}

int Dictionary::Height(Node* t) {
    return (t == nullptr ? -1 : t->height_);
}

Dictionary::Dictionary() {
    root_ = nullptr;
}

void Dictionary::Insert(const Word& x) {
    root_ = Insert(x, root_);
}

void Dictionary::Remove(const Word& x) {
    root_ = Remove(x, root_);
}

Word Dictionary::Find(const string & x) {
    Node * t = this->root_;
    while (t != nullptr) {
        if (x < t->data_.first) {
            t = t->left_;
        } else if (x > t->data_.first) {
            t = t->right_;
        } else if (x == t->data_.first) {
            return (t->data_);
        }
    }
    return Word();
}

Word Dictionary::GetRoot() const {
    if (root_) {
        return root_->data_;
    } else {
        return Word();
    }
}

Word Dictionary::FindMin() {
    Node* t = FindMin(root_);
    return t->data_;
}

Word Dictionary::FindMax() {
    Node* t = FindMax(root_);
    return t->data_;
}

char GetRandomChar() {
    static std::random_device random_device;
    static std::mt19937 generator(random_device());

    static std::uniform_int_distribution<int32_t> distribution(-128, 127);

    return distribution(generator);
}

string GetRandomString(int sizeWord) {
    string tmp{};
    for (int i = 0; i < sizeWord; i++) {
        tmp += GetRandomChar();
    }
    return tmp;
}
