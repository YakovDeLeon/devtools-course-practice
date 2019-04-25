// Copyright 2019 Savkin Yuriy

#include <algorithm>
#include <stack>
#include <stdexcept>

#include "include/segment_tree.h"

SegmentTree::Node::Node(int _v, Node* _l, Node* _r): left_n(_l),
    right_n(_r), value(_v), push_value(_v) {
    is_changed = false;
}

SegmentTree::SegmentTree(const int left_barr, const int right_barr,
    const std::function<int(int, int, int)>& fu, const int base_elem):
        base_elem_(base_elem), left_barr_(left_barr), right_barr_(right_barr),
            operation_(fu) {
    if (left_barr_ > right_barr_)
        throw std::runtime_error("the right barrier is lesser then the left");
    root_ = nullptr;
}

SegmentTree::SegmentTree(const SegmentTree& st): base_elem_(st.base_elem_),
    left_barr_(st.left_barr_), right_barr_(st.right_barr_),
        operation_(st.operation_) {
    std::stack<Node*> s;
    root_ = nullptr;
    if (IsCorrectNode(st.root_)) {
        s.push(st.root_);
        root_ = new Node(st.base_elem_);
        root_->value = st.root_->value;
        root_->push_value = st.root_->push_value;
        s.push(root_);
    }
    while (!s.empty()) {
        Node* p = s.top();
        s.pop();
        Node* q = s.top();
        s.pop();
        if (IsCorrectNode(q->left_n)) {
            s.push(q->left_n);
            p->left_n = new Node(st.base_elem_);
            p->left_n->value = q->left_n->value;
            p->left_n->push_value = q->left_n->push_value;
            s.push(p->left_n);
        }
        if (IsCorrectNode(q->right_n)) {
            s.push(q->right_n);
            p->right_n = new Node(st.base_elem_);
            p->right_n->value = q->right_n->value;
            p->right_n->push_value = q->right_n->push_value;
            s.push(p->right_n);
        }
    }
}

SegmentTree::~SegmentTree() {
    std::stack<Node*> s;
    s.push(root_);
    while (!s.empty()) {
        Node* p = s.top();
        s.pop();
        if (p != nullptr) {
            s.push(p->left_n);
            s.push(p->right_n);
            delete p;
        }
    }
}

SegmentTree& SegmentTree::operator=(const SegmentTree& st) {
    if (&st == this)
        return *this;
    std::stack<Node*> s;
    s.push(root_);
    while (!s.empty()) {
        Node* p = s.top();
        s.pop();
        if (p != nullptr) {
            s.push(p->left_n);
            s.push(p->right_n);
            delete p;
        }
    }
    root_ = nullptr;
    base_elem_ = st.base_elem_;
    left_barr_ = st.left_barr_;
    right_barr_ = st.right_barr_;
    operation_ = st.operation_;
    if (IsCorrectNode(st.root_)) {
        s.push(st.root_);
        root_ = new Node(st.base_elem_);
        root_->value = st.root_->value;
        root_->push_value = st.root_->push_value;
        s.push(root_);
    }
    while (!s.empty()) {
        Node* p = s.top();
        s.pop();
        Node* q = s.top();
        s.pop();
        if (IsCorrectNode(q->left_n)) {
            s.push(q->left_n);
            p->left_n = new Node(st.base_elem_);
            p->left_n->value = q->left_n->value;
            p->left_n->push_value = q->left_n->push_value;
            s.push(p->left_n);
        }
        if (IsCorrectNode(q->right_n)) {
            s.push(q->right_n);
            p->right_n = new Node(st.base_elem_);
            p->right_n->value = q->right_n->value;
            p->right_n->push_value = q->right_n->push_value;
            s.push(p->right_n);
        }
    }
    return *this;
}

void SegmentTree::CorrectNode(Node** p) {
    if (*p == nullptr) {
        *p = new Node(base_elem_);
    } else if ((*p)->is_changed) {
        (*p)->value = base_elem_;
        (*p)->push_value = base_elem_;
        (*p)->is_changed = false;
        if ((*p)->left_n != nullptr)
            (*p)->left_n->is_changed = true;
        if ((*p)->right_n != nullptr)
            (*p)->right_n->is_changed = true;
    }
}

bool SegmentTree::IsCorrectNode(const Node* const p) const {
    if (p == nullptr)
        return false;
    if (p->is_changed)
        return false;
    return true;
}

const int SegmentTree::GetBaseElem() const {
    return base_elem_;
}

const int SegmentTree::GetLeftBarr() const {
    return left_barr_;
}

const int SegmentTree::GetRightBarr() const {
    return right_barr_;
}

void SegmentTree::AddValue(int pos, int value) {
    if ((pos > right_barr_) || (pos < left_barr_))
        throw std::runtime_error("position is out of segment");
    int left = left_barr_, right = right_barr_;
    CorrectNode(&root_);
    root_->value = operation_(root_->value, value, 1);
    Node* p = root_;
    while (left < right) {
        int c = left + (right - left) / 2;
        if (pos <= c) {
            CorrectNode(&p->left_n);
            p = p->left_n;
            p->value = operation_(p->value, value, 1);
            right = c;
        } else {
            CorrectNode(&p->right_n);
            p = p->right_n;
            p->value = operation_(p->value, value, 1);
            left = c + 1;
        }
    }
}

void SegmentTree::AddValue(int l_pos, int r_pos, int value) {
    if ((l_pos < left_barr_) || (r_pos > right_barr_))
        throw std::runtime_error("barriers are out of segment");
    if (l_pos > r_pos)
        throw std::runtime_error("the right barrier is lesser then the left");
    int c, left, right;
    std::stack<Position> s;
    CorrectNode(&root_);
    if ((left_barr_ >= l_pos) && (right_barr_ <= r_pos)) {
        root_->value =
            operation_(root_->value, value, right_barr_ - left_barr_ + 1);
        root_->push_value = operation_(root_->push_value, value, 1);
    } else {
        c = left_barr_ + (right_barr_ - left_barr_) / 2;
        if (l_pos <= c) {
            left = std::max(l_pos, left_barr_);
            right = std::min(r_pos, c);
            root_->value = operation_(root_->value, value, right - left + 1);
            CorrectNode(&root_->left_n);
            s.push({left_barr_, c, root_->left_n});
        }
        if (r_pos > c) {
            left = std::max(l_pos, c + 1);
            right = std::min(r_pos, right_barr_);
            root_->value = operation_(root_->value, value, right - left + 1);
            CorrectNode(&root_->right_n);
            s.push({c + 1, right_barr_, root_->right_n});
        }
    }
    while (!s.empty()) {
        Position t = s.top();
        s.pop();
        if ((t.left >= l_pos) && (t.right <= r_pos)) {
            t.p->value = operation_(t.p->value, value, t.right - t.left + 1);
            t.p->push_value = operation_(t.p->push_value, value, 1);
        } else {
            c = t.left + (t.right - t.left) / 2;
            if (l_pos <= c) {
                left = std::max(l_pos, t.left);
                right = std::min(r_pos, c);
                t.p->value = operation_(t.p->value, value, right - left + 1);
                CorrectNode(&t.p->left_n);
                s.push({t.left, c, t.p->left_n});
            }
            if (r_pos > c) {
                left = std::max(l_pos, c + 1);
                right = std::min(r_pos, t.right);
                t.p->value = operation_(t.p->value, value, right - left + 1);
                CorrectNode(&t.p->right_n);
                s.push({c + 1, t.right, t.p->right_n});
            }
        }
    }
}

int SegmentTree::GetValue(int pos) const {
    if ((pos > right_barr_) || (pos < left_barr_))
        throw std::runtime_error("position is out of segment");
    int left = left_barr_, right = right_barr_;
    int value = base_elem_;
    if (!IsCorrectNode(root_))
        return value;
    if (left_barr_ == right_barr_) {
        value = operation_(value, root_->value, 1);
        return value;
    }
    Node* t = root_;
    while (left < right) {
        int c = left + (right - left) / 2;
        value = operation_(value, t->push_value, 1);
        if (pos <= c) {
            right = c;
            if (!IsCorrectNode(t->left_n))
                break;
            t = t->left_n;
            if (left == right) {
                value = operation_(value, t->value, 1);
                break;
            }
        } else {
            left = c + 1;
            if (!IsCorrectNode(t->right_n))
                break;
            t = t->right_n;
            if (left == right) {
                value = operation_(value, t->value, 1);
                break;
            }
        }
    }
    return value;
}

int SegmentTree::GetValue(int l_pos, int r_pos) const {
    if ((l_pos < left_barr_) || (r_pos > right_barr_))
        throw std::runtime_error("barriers are out of segment");
    if (l_pos > r_pos)
        throw std::runtime_error("the right barrier is lesser then the left");
    int c, value = base_elem_, left, right;
    std::stack<Position> s;
    if (!IsCorrectNode(root_))
        return value;
    if ((left_barr_ >= l_pos) && (right_barr_ <= r_pos)) {
        value = operation_(value, root_->value, 1);
    } else {
        c = left_barr_ + (right_barr_ - left_barr_) / 2;
        if (l_pos <= c) {
            left = std::max(l_pos, left_barr_);
            right = std::min(r_pos, c);
            value = operation_(value, root_->push_value, right - left + 1);
            if (IsCorrectNode(root_->left_n))
                s.push({left_barr_, c, root_->left_n});
        }
        if (r_pos > c) {
            left = std::max(l_pos, c + 1);
            right = std::min(r_pos, right_barr_);
            value = operation_(value, root_->push_value, right - left + 1);
            if (IsCorrectNode(root_->right_n))
                s.push({c + 1, right_barr_, root_->right_n});
        }
    }
    while (!s.empty()) {
        Position t = s.top();
        s.pop();
        if ((t.left >= l_pos) && (t.right <= r_pos)) {
            value = operation_(value, t.p->value, 1);
        } else {
            c = t.left + (t.right - t.left) / 2;
            if (l_pos <= c) {
                left = std::max(l_pos, t.left);
                right = std::min(r_pos, c);
                value = operation_(value, t.p->push_value, right - left + 1);
                if (IsCorrectNode(t.p->left_n))
                    s.push({t.left, c, t.p->left_n});
            }
            if (r_pos > c) {
                left = std::max(l_pos, c + 1);
                right = std::min(r_pos, t.right);
                value = operation_(value, t.p->push_value, right - left + 1);
                if (IsCorrectNode(t.p->right_n))
                    s.push({c + 1, t.right, t.p->right_n});
            }
        }
    }
    return value;
}

void SegmentTree::SetValue(int pos, int value) {
    if ((pos > right_barr_) || (pos < left_barr_))
        throw std::runtime_error("position is out of segment");
    int left = left_barr_, right = right_barr_;
    std::stack<Node*> s;
    CorrectNode(&root_);
    if (left == right) {
        root_->value = value;
        return;
    }
    Node* t = root_;
    s.push(root_);
    while (left < right) {
        int c = left + (right - left) / 2;
        CorrectNode(&t->left_n);
        CorrectNode(&t->right_n);
        t->left_n->value =
            operation_(t->left_n->value, t->push_value, c - left + 1);
        t->left_n->push_value =
            operation_(t->left_n->push_value, t->push_value, 1);
        t->right_n->value =
            operation_(t->right_n->value, t->push_value, right - c);
        t->right_n->push_value =
            operation_(t->right_n->push_value, t->push_value, 1);
        t->push_value = base_elem_;
        if (pos <= c) {
            s.push(t->left_n);
            t = t->left_n;
            right = c;
        } else {
            s.push(t->right_n);
            t = t->right_n;
            left = c + 1;
        }
    }
    t = s.top();
    s.pop();
    t->value = operation_(base_elem_, value, 1);
    t->push_value = operation_(base_elem_, value, 1);
    while (!s.empty()) {
        t = s.top();
        s.pop();
        t->value = base_elem_;
        t->value = operation_(t->value, t->left_n->value, 1);
        t->value = operation_(t->value, t->right_n->value, 1);
    }
}

void SegmentTree::SetValue(int l_pos, int r_pos, int value) {
    if ((l_pos < left_barr_) || (r_pos > right_barr_))
        throw std::runtime_error("barriers are out of segment");
    if (l_pos > r_pos)
        throw std::runtime_error("the right barrier is lesser then the left");
    int c;
    std::stack<Position> s;
    std::stack<Node*> s2;
    CorrectNode(&root_);
    s.push({left_barr_, right_barr_, root_});
    while (!s.empty()) {
        Position t = s.top();
        s.pop();
        if ((t.left >= l_pos) && (t.right <= r_pos)) {
            t.p->value = operation_(base_elem_, value, t.right - t.left + 1);
            t.p->push_value = operation_(base_elem_, value, 1);
            if (IsCorrectNode(t.p->left_n))
                t.p->left_n->is_changed = true;
            if (IsCorrectNode(t.p->right_n))
                t.p->right_n->is_changed = true;
        } else {
            c = t.left + (t.right - t.left) / 2;
            CorrectNode(&t.p->left_n);
            CorrectNode(&t.p->right_n);
            t.p->left_n->value =
                operation_(t.p->left_n->value,
                    t.p->push_value, c - t.left + 1);
            t.p->left_n->push_value =
                operation_(t.p->left_n->push_value, t.p->push_value, 1);
            t.p->right_n->value =
                operation_(t.p->right_n->value, t.p->push_value, t.right - c);
            t.p->right_n->push_value =
                operation_(t.p->right_n->push_value, t.p->push_value, 1);
            t.p->push_value = base_elem_;
            s2.push(t.p);
            if (l_pos <= c)
                s.push({t.left, c, t.p->left_n});
            if (r_pos > c)
                s.push({c + 1, t.right, t.p->right_n});
        }
    }
    while (!s2.empty()) {
        Node* t = s2.top();
        s2.pop();
        t->value = base_elem_;
        t->value = operation_(t->value, t->left_n->value, 1);
        t->value = operation_(t->value, t->right_n->value, 1);
    }
}
