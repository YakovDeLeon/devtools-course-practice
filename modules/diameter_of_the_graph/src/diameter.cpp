// Copyright 2019 Korobeinikov Aleksey

#include <queue>
#include <limits>
#include <algorithm>
#include <vector>
#include <iostream>

#include "include/diameter.h"

Graph::Graph(matrix && vv, int _n) noexcept : v_(std::move(vv)), count_(_n) {}

Graph::Graph():count_(10) {
    v_.resize(count_);
    for (int i = 0; i < count_; ++i) {
        v_[i].resize(count_);
        for (int j = 0; j < count_; ++j) v_[i][j] = 0;
    }
}

void Graph::FindShortestPath() {
    for (int i = 0; i < count_; ++i) {
        for (int j = 0; j < count_; ++j) {
            if (i != j && ((v_[i][j] == 0) || (v_[i][j] == -1)))
                v_[i][j] = std::numeric_limits<signed int>::max()/2;
        }
    }
    for (int k = 0; k < count_; ++k)
        for (int i = 0; i < count_; ++i)
            for (int j = 0; j < count_; ++j)
                v_[i][j] = std::min(v_[i][j], v_[i][k] + v_[k][j]);
}

void Graph::PrintDistance() {
    for (int i = 0; i < count_; ++i) {
        for (int j = 0; j < count_; ++j)
            std::cout << v_[i][j] << " ";
        std::cout << '\n';
    }
}

int Graph::DiameterOfGraph() {
    FindShortestPath();
    int ans = -2;
    for (int i = 0; i < count_; ++i)
        for (int j = 0; j < count_; ++j) {
            ans = std::max(ans, v_[i][j]);
        }
    return ans;
}

Graph::Graph(const Graph& g): count_(g.count_) {
    v_.resize(count_);
    for (int i = 0; i < count_; ++i)
        for (unsigned int j = 0; j < g.v_[i].size(); ++j)
            v_[i].push_back(g.v_[i][j]);
}

Graph& Graph::operator=(const Graph& g) {
    count_ = g.count_;
    v_ = g.v_;
    return *this;
}
