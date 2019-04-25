// Copyright 2019 Korobeinikov Aleksey

#ifndef MODULES_DIAMETER_OF_THE_GRAPH_INCLUDE_DIAMETER_H_
#define MODULES_DIAMETER_OF_THE_GRAPH_INCLUDE_DIAMETER_H_

#include <vector>

using matrix = std::vector<std::vector<int>>;

class Graph {
 private:
    matrix v_;
    int count_;  // count of vertex
 public:
    Graph();
    Graph(matrix && v, int _n) noexcept;
    Graph(const Graph& g);
    Graph& operator=(const Graph& g);
    int DiameterOfGraph();
    void PrintDistance();
 private:
    void FindShortestPath();
};
#endif  // MODULES_DIAMETER_OF_THE_GRAPH_INCLUDE_DIAMETER_H_
