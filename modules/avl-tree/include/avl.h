// Copyright 2019 Denis Yakovlev

#ifndef MODULES_AVL_TREE_INCLUDE_AVL_H_
#define MODULES_AVL_TREE_INCLUDE_AVL_H_

using key = int64_t;

key GetRandomKey(int64_t nBegin, int64_t nEnd);

struct CNode {
    key m_nData;
    CNode* m_pLeft;
    CNode* m_pRight;
    int m_nHeight;
};
class CAvl {
 private:
    void MakeEmpty(CNode* t);
    CNode* Insert(const key& x, CNode* t);
    CNode* SingleRightRotate(CNode* t);
    CNode* SingleLeftRotate(CNode* t);
    CNode* DoubleLeftRotate(CNode* t);
    CNode* DoubleRightRotate(CNode* t);
    CNode* FindMin(CNode* t);
    CNode* FindMax(CNode* t);
    CNode* Remove(const key& x, CNode* t);
    int Height(CNode* t);
    CNode* m_pRoot;
 public:
    CAvl();
    key Find(const key& x);
    void Insert(const key& x);
    void Remove(const key& x);
    key GetRoot() const;
};

#endif  // MODULES_AVL_TREE_INCLUDE_AVL_H_
