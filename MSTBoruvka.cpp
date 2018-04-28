// Реализация класса, строящего минимальное остовное дерево

#include "MSTBoruvka.hpp"
#include "DisjointSet.hpp"

MSTBoruvka::MSTBoruvka(CArcWeightedGraph& graph) {
    tree = CArcWeightedGraph(graph.size());
    DisjointSet set(graph.size());
    // Выполняем основной цикл пока не получим дерево (учитываем прямые ребра и обратные)
    while(tree.edges_num() < 2 * (graph.size() - 1)) {
        // Вектор с самыми дешевыми ребрами от каждого поддерева до остального графа
        std::vector<Edge> cheapest_edges(graph.size(), Edge());
        // Перебираем все ребра
        for(auto edge: graph) {
            // Пропускаем случай, когда вершины в одном поддереве
            if(set.find(edge.from) == set.find(edge.to)) {
                continue;
            }
            if(edge.weight < cheapest_edges[set.find(edge.to)].weight) {
                cheapest_edges[set.find(edge.to)] = Edge(edge.from, edge.to, edge.weight);
            }
            if(edge.weight < cheapest_edges[set.find(edge.from)].weight) {
                cheapest_edges[set.find(edge.from)] = Edge(edge.from, edge.to, edge.weight);
            }
        }
        // Добавляем все новые ребра в дерево
        for(auto edge: cheapest_edges) {
            // Чтобы не соединить 2 поддерева второй раз
            if(set.find(edge.from) != set.find(edge.to)) {
                // Добавляем 2 ребра, так как граф неориентированный
                tree.add_edge(edge.from, edge.to, edge.weight);
                tree.add_edge(edge.to, edge.from, edge.weight);
                // Объединяем поддеревья
                set.union_sets(edge.from, edge.to);
            }
        }
    }
}
CArcWeightedGraph MSTBoruvka::get_tree() const {
    return tree;
}