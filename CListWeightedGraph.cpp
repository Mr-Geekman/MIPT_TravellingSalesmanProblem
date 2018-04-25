// Реализация класса графа, как списка смежности

#include <iostream>
#include <vector>
#include <stack>
#include "CListWeightedGraph.hpp"

CListWeightedGraph::CListWeightedGraph() = default;
CListWeightedGraph::CListWeightedGraph(unsigned long int size) {
    adjacency_list.resize(size);
}
CListWeightedGraph::CListWeightedGraph(const CListWeightedGraph* from): CListWeightedGraph(from->size()) {
    this->adjacency_list = from->adjacency_list;
}
CListWeightedGraph::CListWeightedGraph(const CArcWeightedGraph& from) : CListWeightedGraph(from.size()){
    for(auto edge: from) {
        add_edge(edge.from, edge.to, edge.weight);
    }
}
void CListWeightedGraph::add_edge(int from, int to, double weight) {
    adjacency_list[from].emplace_back(std::make_pair(to, weight));
}
std::vector<int> CListWeightedGraph::dfs(int start_vertex) const {
    std::vector<int> path;
    std::vector<bool> visited(size(), false);
    std::stack<int> dfs_stack;
    dfs_stack.push(start_vertex);
    visited[start_vertex] = true;
    while(!dfs_stack.empty()) {
        int current_vertex = dfs_stack.top();
        dfs_stack.pop();
        path.push_back(current_vertex);
        for(int i = 0; i < adjacency_list[current_vertex].size(); ++i) {
            if(!visited[adjacency_list[current_vertex][i].first]) {
                dfs_stack.push(adjacency_list[current_vertex][i].first);
                visited[adjacency_list[current_vertex][i].first] = true;
            }
        }
    }
    return path;
}
unsigned long int CListWeightedGraph::size() const {
    return adjacency_list.size();
}
std::vector<std::pair<int, double>>::const_iterator CListWeightedGraph::adjacent_begin(int vertex) const {
    return adjacency_list[vertex].cbegin();
}
std::vector<std::pair<int, double>>::const_iterator CListWeightedGraph::adjacent_end(int vertex) const {
    return adjacency_list[vertex].cend();
}