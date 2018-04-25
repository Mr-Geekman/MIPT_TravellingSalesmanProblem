// Реализация класса графа, как списка ребер

#include <iostream>
#include <vector>
#include <cmath>
#include "CArcWeightedGraph.hpp"

// Реализация структуры ребра
Edge::Edge(): from(0), to(0), weight(INFINITY) {};
Edge::Edge(int from, int to, double weight): from(from), to(to), weight(weight) {};

CArcWeightedGraph::CArcWeightedGraph() = default;
CArcWeightedGraph::CArcWeightedGraph(int size) {
    graph_size = size;
}
CArcWeightedGraph::CArcWeightedGraph(const CArcWeightedGraph* from): CArcWeightedGraph(from->size()) {
    this->edges = from->edges;
}
void CArcWeightedGraph::add_edge(int from, int to, double weight) {
    edges.emplace_back(Edge(from, to, weight));
}
int CArcWeightedGraph::edges_num() const {
    return edges.size();
}
int CArcWeightedGraph::size() const {
    return graph_size;
}
std::vector<Edge>::const_iterator CArcWeightedGraph::begin() const {
    return edges.cbegin();
}
std::vector<Edge>::const_iterator CArcWeightedGraph::end() const {
    return edges.cend();
}