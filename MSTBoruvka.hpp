// Объявление класса, строящего минимальное остовное дерево

#pragma once

class MSTBoruvka {
public:
    explicit MSTBoruvka(CArcWeightedGraph& graph);
    CArcWeightedGraph get_tree() const;
private:
    // Получившийся граф - это дерево
    CArcWeightedGraph tree;
};