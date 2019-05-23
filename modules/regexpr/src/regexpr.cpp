// Copyright 2019 Zhivaev Artem

#include <stack>
#include <utility>
#include <string>
#include <algorithm>
#include <array>
#include <vector>

#include "include/regexpr.h"
#include "include/nfa.h"

bool RegExpr::Atom::operator == (const RegExpr::Atom &at) const {
    return mod_ == at.mod_ && isGroup_ == at.isGroup_
           && values_ == at.values_;
}

const std::array<char, 62> RegExpr::kAlphabet = {{
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
}};

RegExpr::RegExpr(const std::string &seq) {
    if (!ValidCheck(seq)) {
        throw std::exception();
    }

    root_ = GenerateState(GeneratePatt(seq));
}

RegExpr::~RegExpr() {
    if (root_ != nullptr) {
        auto p = root_;
        while (p != nullptr) {
            auto tmp = p->next_;
            delete p;
            p = tmp;
        }
    }
}

std::pair<int, int> RegExpr::Match(const std::string &str) const {
    const char *pch = str.c_str();
    auto res = std::make_pair(0, 0);

    while (pch[res.first] != '\0') {
        res.second = res.first + root_->Match(pch + res.first);
        if (res.second >= res.first) {
            return res;
        }
        res.first += 1;
    }

    return {-1, -1};
}

std::vector<RegExpr::Atom> RegExpr::GeneratePatt(const std::string &seq) {
    std::vector<Atom> res;
    size_t pos = 0;

    while (pos < seq.size()) {
        switch (seq[pos]) {
         case '[':
            res.push_back(ParseBrackets(seq, &pos));
            break;
         case '(':
            res.push_back(ParseParenthesis(seq, &pos));
            break;
         case '.':
            {
            Atom at;
            at.isGroup_ = false;
            at.values_.push_back({});
            for (int i = 0; i < 256; ++i) {
                at.values_.at(0).insert('\0' + i);
            }
            switch (seq[pos + 1]) {
             case '*':
                at.mod_ = Atom::kKleen;
                ++pos;
                break;
             case '?':
                at.mod_ = Atom::kQMark;
                ++pos;
                break;
             default:
                at.mod_ = Atom::kNone;
                break;
            }
            res.push_back(at);
            }
            break;
         default:
            {
            if (seq[pos] == '\\' && seq[pos + 1] == '\0') {
                throw std::exception();
            } else if (seq[pos] == '\\' && seq[pos + 1] != '\0') {
                ++pos;
            }
            Atom at;
            at.isGroup_ = false;
            at.values_.push_back({seq[pos]});
            switch (seq[pos + 1]) {
             case '*':
                at.mod_ = Atom::kKleen;
                ++pos;
                break;
             case '?':
                at.mod_ = Atom::kQMark;
                ++pos;
                break;
             default:
                at.mod_ = Atom::kNone;
                break;
            }
            res.push_back(at);
            }
            break;
        }
        ++pos;
    }

    return res;
}

NFAState *RegExpr::GenerateState(const std::vector<Atom> &patt) {
    NFAState *res = new NFAState;
    auto curr = res;

    auto it = patt.begin();

    for (; it != patt.end(); ++it) {
        if (!it->isGroup_) {
            switch (it->mod_) {
             case Atom::kNone:
                curr->next_ = new NFAState;
                for (char ch : it->values_.at(0)) {
                    curr->AddCharNext(ch);
                }
                curr = curr->next_;
                break;
             case Atom::kKleen:
                curr->AddCharsLoop(it->values_.at(0));
                break;
             case Atom::kQMark:
                curr->next_ = new NFAState;
                curr->throughLvl_ = 1;
                for (char ch : it->values_.at(0)) {
                    curr->AddCharNext(ch);
                }
                curr = curr->next_;
                break;
            }
        } else {
            switch (it->mod_) {
             case Atom::kNone:
                for (auto s : it->values_) {
                    curr->next_ = new NFAState;
                    for (char ch : s) {
                        curr->AddCharNext(ch);
                    }
                    curr = curr->next_;
                }
                break;
             case Atom::kKleen:
                for (auto s : it->values_) {
                    curr->AddCharsLoop(s);
                }
                break;
             case Atom::kQMark:
                curr->throughLvl_ = it->values_.size();
                for (auto s : it->values_) {
                    curr->next_ = new NFAState;
                    for (char ch : s) {
                        curr->AddCharNext(ch);
                    }
                    curr = curr->next_;
                }
                break;
            }
        }
    }

    curr->isFinal_ = true;

    return res;
}

bool RegExpr::ValidCheck(const std::string &seq) {
    std::stack<char> par;
    std::stack<char> bra;
    auto it = seq.begin();

    if (seq.back() == '\\') {
        return false;
    }

    for (; it != seq.end(); ++it) {
        if ((*it == '[' && *std::next(it, 1) == ']') ||
            (*it == '(' && *std::next(it, 1) == ')')) {
            return false;
        }
        if (*it == '\\') {
            std::advance(it, 1);
            continue;
        }
        if (*it == '(' && par.empty()) {
            par.push('(');
        } else if (*it == '(' && !par.empty()) {
            return false;
        } else if (*it == ')' && !par.empty()) {
            par.pop();
        } else if (*it == ')' && par.empty()) {
            return false;
        } else if (*it == '[' && bra.empty()) {
            bra.push('[');
        } else if (*it == '[' && !bra.empty()) {
            return false;
        } else if (*it == ']' && !bra.empty()) {
            bra.pop();
        } else if (*it == ']' && bra.empty()) {
            return false;
        }
    }

    return true;
}

RegExpr::Atom RegExpr::ParseBrackets(const std::string &seq, size_t *ppos) {
    size_t &pos = *ppos;
    if (seq[pos] != '[') {
        throw std::exception();
    }
    Atom res;
    res.isGroup_ = false;
    res.values_.push_back({});

    while (seq[++pos] != ']') {
        if (seq[pos + 1] == '-') {
            auto it1 = std::find(kAlphabet.begin(), kAlphabet.end(), seq[pos]);
            pos += 2;
            auto it2 = std::find(kAlphabet.begin(), kAlphabet.end(), seq[pos]);
            std::advance(it2, 1);
            std::for_each(it1, it2, [&res](char ch) {
                res.values_.at(0).insert(ch);
            });
        } else {
            res.values_.at(0).insert(seq[pos]);
        }
    }

    switch (seq[pos + 1]) {
     case '*':
        res.mod_ = Atom::Modif::kKleen;
        ++pos;
        break;
     case '?':
        res.mod_ = Atom::Modif::kQMark;
        ++pos;
        break;
     default:
        res.mod_ = Atom::Modif::kNone;
        break;
    }

    return res;
}

RegExpr::Atom RegExpr::ParseParenthesis(const std::string &seq, size_t *ppos) {
    size_t &pos = *ppos;
    if (seq[pos] != '(') {
        throw std::exception();
    }
    Atom res;
    res.isGroup_ = true;

    while (seq[++pos] != ')') {
        if (seq[pos] == '[') {
            auto tmp = ParseBrackets(seq, ppos);
            res.values_.push_back(tmp.values_.at(0));
            if (seq[pos] != ']') {
                --pos;
            }
        } else if (seq[pos] == '.') {
            res.values_.push_back({});
            for (int i = 1; i < 256; ++i) {
                res.values_.back().insert('0' + i);
            }
        } else {
            if (seq[pos] == '\\' && seq[pos + 1] != '\0') {
                ++pos;
            } else if (seq[pos] == '\\' && seq[pos + 1] == '\0') {
                throw std::exception();
            }
            res.values_.push_back({seq[pos]});
        }
    }

    switch (seq[pos + 1]) {
        case '*':
            res.mod_ = Atom::kKleen;
            ++pos;
            break;
        case '?':
            res.mod_ = Atom::kQMark;
            ++pos;
            break;
        default:
            res.mod_ = Atom::kNone;
            break;
    }

    return res;
}

