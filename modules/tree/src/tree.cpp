// Copyright 2019 Konnov Sergey

#include "include/tree.h"

Tree::Node::Node() {
    data = 0;
    count = 0;
    left = right = nullptr;
}

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    DelAll(root);
}

void Tree::Add(int data) {
    root = AddNode(root, data);
}

void Tree::Del(int data) {
    root = DelNode(root, data);
}

int Tree::Search(int data) {
    return SearchNode(root, data);
}

void Tree::Clear() {
    DelAll(root);
    root = nullptr;
}

Tree::Node* Tree::AddNode(Node * node, int data, int cnt) {
    if (node == nullptr) {
        node = new Node;
        node->data = data;
        node->count = cnt;
        node->left = node->right = nullptr;
    } else if (data < node->data) {
        node->left = AddNode(node->left, data);
    } else if (data > node->data) {
        node->right = AddNode(node->right, data);
    } else {
        node->count+=cnt;
    }
    return node;
}

Tree::Node* Tree::CopyTree(Node* node, Node* copyroot) {
    if (copyroot == nullptr)
        return node;
    node = AddNode(node, copyroot->data, copyroot->count);
    if (copyroot->left != nullptr)
        node->left = CopyTree(node->left, copyroot->left);
    if (copyroot->right != nullptr)
        node->right = CopyTree(node->right, copyroot->right);
    return node;
}

Tree::Node* Tree::DelNode(Node* node, int data) {
    if (node == nullptr)
        return nullptr;
    if (data < node->data) {
        node->left = DelNode(node->left, data);
    } else if (data > node->data) {
        node->right = DelNode(node->right, data);
    } else {
        Node *p, *v;
        if (node->left == node->right && node->left == nullptr) {
            p = node;
        } else if (node->right == nullptr) {
            p = node;
            node = node->left;
        } else if (node->left == nullptr) {
            p = node;
            node = node->right;
        } else {
            v = node->left;
            if (v->right != nullptr) {
                while (v->right->right != nullptr)
                    v = v->right;
                node->data = v->right->data;
                node->count = v->right->count;
                p = v->right;
                v->right = v->right->left;
            } else {
                node->data = v->data;
                node->count = v->count;
                p = v;
                node->left = node->left->left;
            }
        }
        if (p == node)
            node = nullptr;
        delete p;
        p = nullptr;
    }
    return node;
}

int Tree::SearchNode(Node* node, int data) {
    if (node == nullptr)
        return 0;
    else if (data < node->data)
        return SearchNode(node->left, data);
    else if (data > node->data)
        return SearchNode(node->right, data);
    else
        return node->count;
}

void Tree::DelAll(Node* node) {
    if (node == nullptr) {
        return;
    }
    if (node->left != nullptr)
        DelAll(node->left);
    if (node->right != nullptr)
        DelAll(node->right);
    delete node;
    node = nullptr;
}

Tree::Tree(const Tree& copyroot) {
    root = nullptr;
    root = CopyTree(root, copyroot.root);
}

Tree& Tree::operator=(const Tree& copyroot) {
    if (&copyroot != this) {
        Clear();
        root = CopyTree(root, copyroot.root);
    }
    return *this;
}


bool Tree::IsEmpty() const {
    if (root == nullptr)
        return true;
    else
        return false;
}
