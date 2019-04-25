// Copyright 2019 Konnov Sergey

#ifndef MODULES_TREE_INCLUDE_TREE_H_
#define MODULES_TREE_INCLUDE_TREE_H_

class Tree {
 private:
    struct Node {
        int data;
        int count;
        Node* left, * right;
        Node();
    };  // single tree node
    Node* root;  // root of the tree
    Node* AddNode(Node* node, int data, int count = 1);
    Node* DelNode(Node* node, int data);
    Node* CopyTree(Node* node, Node* copyroot);
    int SearchNode(Node* node, int data);
    void DelAll(Node* node);
 public:
    Tree();  // default constructor
    Tree(const Tree& t);  // copy constructor
    bool IsEmpty() const;  // check whether the tree is empty
    ~Tree();
    void Add(int data);  // add element
    void Del(int data);  // delete element
    int Search(int data);  // search element
    Tree& operator=(const Tree& t);  // assignment operator
    void Clear();  // clear tree
};


#endif  // MODULES_TREE_INCLUDE_TREE_H_
