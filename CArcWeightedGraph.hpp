// Объявление графа, как списка ребер

#pragma once

#include <iostream>
#include <vector>

// Объявление структуры ребра
struct Edge {
    Edge();
    Edge(int from, int to, double weight);
    int from;
    int to;
    double weight;
};

class CArcWeightedGraph {
public:
    CArcWeightedGraph();
    explicit CArcWeightedGraph(int size);
    explicit CArcWeightedGraph(const CArcWeightedGraph* from);
    void add_edge(int from, int to, double weight);
    int edges_num() const;
    int size() const;
    std::vector<Edge>::const_iterator begin() const;
    std::vector<Edge>::const_iterator end() const;
private:
    // Храню список ребер графа
    std::vector<Edge> edges;
    int graph_size;
};