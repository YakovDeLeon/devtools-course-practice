// Copyright 2019 Denis Yakovlev

#include <algorithm>
#include <random>
#include "include/avl.h"

using std::max;

void CAvl::MakeEmpty(CNode* t) {
    if (t == nullptr) {
        return;
    }
    MakeEmpty(t->m_pLeft);
    MakeEmpty(t->m_pRight);
    delete t;
}

CNode* CAvl::Insert(const key& x, CNode* t) {
    if (t == nullptr) {
        t = new CNode;
        t->m_nData = x;
        t->m_nHeight = 0;
        t->m_pLeft = t->m_pRight = nullptr;
    } else if (x < t->m_nData) {
        t->m_pLeft = Insert(key(x), t->m_pLeft);
        if (Height(t->m_pLeft) - Height(t->m_pRight) == 2) {
            if (x < t->m_pLeft->m_nData) {
                t = SingleRightRotate(t);
            } else {
                t = DoubleRightRotate(t);
            }
        }
    } else if (x > t->m_nData) {
        t->m_pRight = Insert(key(x), t->m_pRight);
        if (Height(t->m_pRight) - Height(t->m_pLeft) == 2) {
            if (x > t->m_pRight->m_nData) {
                t = SingleLeftRotate(t);
            } else {
                t = DoubleLeftRotate(t);
            }
        }
    }

    t->m_nHeight = max(Height(t->m_pLeft), Height(t->m_pRight)) + 1;
    return t;
}

CNode* CAvl::SingleRightRotate(CNode* t) {
    CNode* u = t->m_pLeft;
    t->m_pLeft = u->m_pRight;
    u->m_pRight = t;
    t->m_nHeight = max(Height(t->m_pLeft), Height(t->m_pRight)) + 1;
    u->m_nHeight = max(Height(u->m_pLeft), t->m_nHeight) + 1;
    return u;
}

CNode* CAvl::SingleLeftRotate(CNode* t) {
    CNode* u = t->m_pRight;
    t->m_pRight = u->m_pLeft;
    u->m_pLeft = t;
    t->m_nHeight = max(Height(t->m_pLeft), Height(t->m_pRight)) + 1;
    u->m_nHeight = max(Height(t->m_pRight), t->m_nHeight) + 1;
    return u;
}

CNode* CAvl::DoubleLeftRotate(CNode* t) {
    t->m_pRight = SingleRightRotate(t->m_pRight);
    return SingleLeftRotate(t);
}

CNode* CAvl::DoubleRightRotate(CNode* t) {
    t->m_pLeft = SingleLeftRotate(t->m_pLeft);
    return SingleRightRotate(t);
}

CNode* CAvl::FindMin(CNode* t) {
    if (t == nullptr) {
        return nullptr;
    } else if (t->m_pLeft == nullptr) {
        return t;
    } else {
        return FindMin(t->m_pLeft);
    }
}

CNode* CAvl::FindMax(CNode* t) {
    if (t == nullptr) {
        return nullptr;
    } else if (t->m_pRight == nullptr) {
        return t;
    } else {
        return FindMax(t->m_pRight);
    }
}

CNode* CAvl::Remove(const key& x, CNode* t) {
    CNode* temp;

    if (t == nullptr) {
        //
        // Element not found
        //
        return nullptr;
    } else if (x < t->m_nData) {
        //
        // Searching for element
        //
        t->m_pLeft = Remove(x, t->m_pLeft);
    } else if (x > t->m_nData) {
        t->m_pRight = Remove(x, t->m_pRight);
    } else if (t->m_pLeft && t->m_pRight) {
        //
        // Element found
        // With 2 children
        //
        temp = FindMin(t->m_pRight);
        t->m_nData = temp->m_nData;
        t->m_pRight = Remove(t->m_nData, t->m_pRight);
    } else {
        //
        // With one or zero child
        //
        temp = t;
        if (t->m_pLeft == nullptr) {
            t = t->m_pRight;
        } else if (t->m_pRight == nullptr) {
            t = t->m_pLeft;
        }
        delete temp;
    }
    if (t == nullptr)
        return t;

    t->m_nHeight = max(Height(t->m_pLeft), Height(t->m_pRight)) + 1;

    if (Height(t->m_pLeft) - Height(t->m_pRight) == 2) {
        //
        // If CNode is unbalanced
        // If m_pLeft CNode is deleted, m_pRight case
        //
        if (Height(t->m_pLeft->m_pLeft) - Height(t->m_pLeft->m_pRight) == 1) {
            //
            // m_pRight m_pRight case
            //
            return SingleRightRotate(t);
        } else {
            //
            // m_pRight m_pLeft case
            //
            return DoubleRightRotate(t);
        }
    } else if (Height(t->m_pRight) - Height(t->m_pLeft) == 2) {
        //
        // If m_pRight CNode is deleted, m_pLeft case
        //
        if (Height(t->m_pRight->m_pRight) - Height(t->m_pRight->m_pLeft) == 1) {
            //
            // m_pLeft m_pLeft case
            //
            return SingleLeftRotate(t);
        } else {
            //
            // m_pLeft m_pRight case
            //
            return DoubleLeftRotate(t);
        }
    }
    return t;
}

int CAvl::Height(CNode* t) {
    return (t == nullptr ? -1 : t->m_nHeight);
}

CAvl::CAvl() {
    m_pRoot = nullptr;
}

void CAvl::Insert(const key& x) {
    m_pRoot = Insert(x, m_pRoot);
}

void CAvl::Remove(const key& x) {
    m_pRoot = Remove(x, m_pRoot);
}

key CAvl::Find(const key & x) {
    CNode * t = this->m_pRoot;
    while (t != nullptr) {
        if (x < t->m_nData) {
            t = t->m_pLeft;
        } else if (x > t->m_nData) {
            t = t->m_pRight;
        } else if (x == t->m_nData) {
            return (t->m_nData);
        }
    }
    return key();
}

key CAvl::GetRoot() const {
    if (m_pRoot) {
        return m_pRoot->m_nData;
    } else {
        return key();
    }
}

key GetRandomKey(int64_t nBegin, int64_t nEnd) {
    static std::random_device random_device;
    static std::mt19937 generator(random_device());

    static std::uniform_int_distribution<key> distribution(nBegin, nEnd);

    return distribution(generator);
}
