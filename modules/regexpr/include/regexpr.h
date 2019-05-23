// Copyright 2019 Zhivaev Artem

#ifndef MODULES_REGEXPR_INCLUDE_REGEXPR_H_
#define MODULES_REGEXPR_INCLUDE_REGEXPR_H_

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <set>
#include <utility>
#include <array>
#include <iostream>

#include "include/nfa.h"

class RegExpr {
 public:
    explicit RegExpr(const std::string &seq);
    virtual ~RegExpr();

    std::pair<int, int> Match(const std::string &str) const;

    struct Atom {
        enum Modif {
            kNone,
            kKleen,
            kQMark,
        } mod_;
        bool isGroup_;
        std::vector<std::set<char>> values_;
        bool operator == (const Atom &at) const;
    };

 protected:
    NFAState *root_;

    static const std::array<char, 62> kAlphabet;

    static std::vector<Atom> GeneratePatt(const std::string &seq);
    static NFAState *GenerateState(const std::vector<Atom> &patt);
    static bool ValidCheck(const std::string &seq);

    static Atom ParseBrackets(const std::string &seq, size_t *pos);
    static Atom ParseParenthesis(const std::string &seq, size_t *pos);

    friend class RegExprT;
};

class RegExprT : public RegExpr {
 public:
    explicit RegExprT(const std::string &seq) : RegExpr(seq) {}
    virtual ~RegExprT() {}

    using RegExpr::Atom;
    using RegExpr::GeneratePatt;
    using RegExpr::ValidCheck;
    using RegExpr::ParseBrackets;
    using RegExpr::ParseParenthesis;
    using RegExpr::root_;
    using RegExpr::kAlphabet;
};

#endif  // MODULES_REGEXPR_INCLUDE_REGEXPR_H_

