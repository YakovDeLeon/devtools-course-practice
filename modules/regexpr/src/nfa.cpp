// Copyright 2019 Zhivaev Artem

#include <set>
#include <algorithm>

#include "include/nfa.h"

NFAState::NFAState()
    : next_(nullptr),
      loop_(nullptr),
      throughLvl_(0),
      isFinal_(false)
{}

NFAState::~NFAState() {
    if (loop_ != nullptr && loop_ != this) {
        auto p = loop_;
        while (p != this) {
            auto tmp = p->next_;
            delete p;
            p = tmp;
        }
    }
}

int NFAState::Match(const char *ch) const {
    return TryDoTrans(this, ch, 0);
}

void NFAState::AddCharNext(char ch) {
    nChars_.insert(ch);
}

void NFAState::AddCharsLoop(std::set<char> chSet) {
    if (loop_ == nullptr) {
        loop_ = this;
        lChars_ = chSet;
    } else if (loop_ == this) {
        loop_ = new NFAState;
        loop_->next_ = this;
        loop_->nChars_ = chSet;
    } else {
        auto tmp = loop_;
        while (tmp->next_ != this) {
            tmp = tmp->next_;
        }
        tmp->next_ = new NFAState;
        tmp->next_->next_ = this;
        tmp->next_->nChars_ = chSet;
    }
}

int NFAState::TryDoTrans(const NFAState *node,
                         const char *ch, int count) const {
    if (ch == nullptr || node == nullptr) {
        throw std::exception();
    }
    if (!node->isFinal_ && *ch == '\0') {
        return -1;
    } else if (node->isFinal_ && *ch == '\0') {
        return count;
    }

    std::set<int> retValues;
    retValues.insert(-1);

    for (auto i : node->lChars_) {
        if (*ch == i) {
            retValues.insert(TryDoTrans(node->loop_, ch + 1, count + 1));
        }
    }

    for (auto i : node->nChars_) {
        if (*ch == i) {
            retValues.insert(TryDoTrans(node->next_, ch + 1, count + 1));
        }
    }

    if (node->throughLvl_ > 0) {
        auto tmp = node;
        for (int i = 0; i < node->throughLvl_; ++i) {
            tmp = tmp->next_;
        }
        retValues.insert(TryDoTrans(tmp, ch, count));
    }

    if (*(retValues.rbegin()) == -1 && node->isFinal_) {
        return count;
    }

    return *(retValues.rbegin());
}

