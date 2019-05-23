// Copyright 2019 Zhivaev Artem

#ifndef MODULES_REGEXPR_INCLUDE_NFA_H_
#define MODULES_REGEXPR_INCLUDE_NFA_H_

#include <set>
#include <vector>


class NFAState {
 public:
    NFAState();
    virtual ~NFAState();

    int Match(const char *ch) const;

 protected:
    void AddCharNext(char ch);
    void AddCharsLoop(std::set<char> s);

    NFAState *next_;
    NFAState *loop_;

    std::set<char> nChars_;
    std::set<char> lChars_;
    int throughLvl_ = 0;
    bool isFinal_;

    int TryDoTrans(const NFAState *node, const char *ch, int count) const;

    friend class RegExpr;
    friend class NFAStateT;
};

class NFAStateT : public NFAState {
 public:
    NFAStateT() : NFAState() {}
    virtual ~NFAStateT() {}

    using NFAState::next_;
    using NFAState::loop_;
    using NFAState::nChars_;
    using NFAState::lChars_;
    using NFAState::throughLvl_;
    using NFAState::isFinal_;
    using NFAState::TryDoTrans;
    using NFAState::AddCharNext;
    using NFAState::AddCharsLoop;
};


#endif  // MODULES_REGEXPR_INCLUDE_NFA_H_

