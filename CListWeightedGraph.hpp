// Объявление графа, как списка смежности

#pragma once

#include <iostream>
#include <vector>
#include "CArcWeightedGraph.hpp"

class CListWeightedGraph {
public:
    CListWeightedGraph();
    explicit CListWeightedGraph(unsigned long int size);
    explicit CListWeightedGraph(const CListWeightedGraph* from); // МБ тут тоже стоит поменять * на &
    explicit CListWeightedGraph(const CArcWeightedGraph& from);
    void add_edge(int from, int to, double weight);
    std::vector<int> dfs(int start_vertex) const;
    unsigned long int size() const;
    std::vector<std::pair<int, double>>::const_iterator adjacent_begin(int vertex) const;
    std::vector<std::pair<int, double>>::const_iterator adjacent_end(int vertex) const;
private:
    // В first хранится номер вершины, в second - вес ребра
    std::vector<std::vector<std::pair<int, double>>> adjacency_list;
};