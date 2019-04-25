// Copyright 2019 Timakin Nikita

#include <vector>

#include "../include/rb_tree.h"

Node::Node(int _value, Node *_left, Node *_right, Node *_parent, bool _color) :
           value(_value), left(_left), right(_right),
           parent(_parent), color(_color) {}

Node::Node(const Node& node) : value(node.value), left(node.left),
           right(node.right), parent(node.parent), color(node.color) {}

Node& Node::operator=(const Node& node) {
    value = node.value;
    left = node.left;
    right = node.right;
    parent = node.parent;
    color = node.color;

    return *this;
}

bool Node::operator==(const Node& node) {
    if (value == node.value && left == node.left && right == node.right
        && parent == node.parent && color == node.color)
        return true;

    return false;
}

bool Node::operator!=(const Node& node) {
    return !(*this == node);
}

std::ostream& operator<<(std::ostream& out, const Node& node) {
    out << "Node(" << node.value << ", " << node.color << ")";
    return out;
}

RBTree::RBTree() : NIL(new Node{}), root(NIL), current(NIL),
                   nodes_number(0), counter(0) {}

RBTree::RBTree(Node *node) : NIL(new Node{}), root(node), current(NIL),
                             nodes_number(1), counter(0) {
        root->left = NIL;
        root->right = NIL;
        root->parent = NIL;
    }

RBTree::RBTree(const std::vector<int>& vec) :
               NIL(new Node{}), root(NIL), current(NIL),
               nodes_number(0), counter(0) {
    for (int value : vec) {
        Node *node = new Node{value};
        Insert(node);
    }
}

Node* RBTree::GetRoot() const {
    return root;
}

Node* RBTree::GetCurrent() const {
    return current;
}

unsigned RBTree::GetNodesNumber() const {
    return nodes_number;
}

bool RBTree::Find(const int value) {
    current = root;

    while (current != NIL) {
        if (value == current->value)
            return true;
        else if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    return false;
}

void RBTree::Insert(Node *node) {
    if (Find(node->value))
        throw "This item is already in the tree";

    Node *y = NIL;
    Node *x = root;

    while (x != NIL) {
        y = x;
        if (node->value < x->value)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;

    if (y == NIL)
        root = node;
    else if (node->value < y->value)
        y->left = node;
    else
        y->right = node;

    node->left = NIL;
    node->right = NIL;
    node->color = RED;

    insert_fixup(node);

    nodes_number++;
}

void RBTree::Remove(const int value) {
    if (!Find(value))
        throw "There is no that value in the tree";

    Node *z = current;
    Node *y = z;
    Node *x;

    bool y_original_color = y->color;

    if (z->left == NIL) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == NIL) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;

        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == BLACK)
        remove_fixup(x);

    nodes_number--;
}

void RBTree::Begin() {
    while (!stack.empty())
        stack.pop();

    counter = 0;
    current = root;

    while (current->left != NIL) {
        stack.push(current);
        current = current->left;
    }
    stack.push(current);
}

bool RBTree::End() const {
    return (counter == nodes_number);
}

void RBTree::Next() {
    if (!stack.empty())
        stack.pop();

    if (current->right != NIL) {
        current = current->right;

        while (current->left != NIL) {
            stack.push(current);
            current = current->left;
        }
        stack.push(current);
    } else if (!stack.empty()) {
        current = stack.top();
    }

    counter++;
}

void RBTree::insert_fixup(Node *node) {
    while (node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            Node *y = node->parent->parent->right;

            if (y->color == RED) {
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    left_rotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                right_rotate(node->parent->parent);
            }
        } else {
            Node *y = node->parent->parent->left;

            if (y->color == RED) {
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    right_rotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                left_rotate(node->parent->parent);
            }
        }
    }

    root->color = BLACK;
}

void RBTree::transplant(Node *u, Node *v) {
    if (u->parent == NIL)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    v->parent = u->parent;
}

void RBTree::remove_fixup(Node *node) {
    while (node != root && node->color == BLACK) {
        if (node == node->parent->left) {
            Node *w = node->parent->right;

            if (w->color == RED) {
                w->color = BLACK;
                node->parent->color = RED;
                left_rotate(node->parent);
                w = node->parent->right;
            }

            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                node = node->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(w);
                    w = node->parent->right;
                }
                w->color = node->parent->color;
                node->parent->color = BLACK;
                w->right->color = BLACK;
                left_rotate(node->parent);
                node = root;
            }
        } else {
            Node *w = node->parent->left;

            if (w->color == RED) {
                w->color = BLACK;
                node->parent->color = RED;
                right_rotate(node->parent);
                w = node->parent->left;
            }

            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                node = node->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(w);
                    w = node->parent->left;
                }
                w->color = node->parent->color;
                node->parent->color = BLACK;
                w->left->color = BLACK;
                right_rotate(node->parent);
                node = root;
            }
        }
    }

    node->color = BLACK;
}

Node* RBTree::minimum(Node * const node) {
    current = node;

    while (current->left != NIL)
        current = current->left;

    return current;
}

void RBTree::left_rotate(Node *x) {
    Node *y = x->right;
    x->right = y->left;

    if (y->left != NIL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NIL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void RBTree::right_rotate(Node *x) {
    Node *y = x->left;
    x->left = y->right;

    if (y->right != NIL)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == NIL)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;
}
