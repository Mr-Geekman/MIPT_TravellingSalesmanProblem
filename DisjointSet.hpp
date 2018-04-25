// Объявление класса системы непересекающихся множеств

#pragma once

#include <vector>

class DisjointSet {
public:
    explicit DisjointSet(int size);
    void union_sets(int first_vertex, int second_vertex);
    int find(int vertex);
private:
    std::vector<int> parents;
    std::vector<int> rank;
};