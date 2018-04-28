// Объявление класса, строящего минимальное остовное дерево

#pragma once

#include "CArcWeightedGraph.hpp"

class MSTBoruvka {
public:
    explicit MSTBoruvka(CArcWeightedGraph& graph);
    CArcWeightedGraph get_tree() const;
private:
    // Получившийся граф - это дерево
    CArcWeightedGraph tree;
};