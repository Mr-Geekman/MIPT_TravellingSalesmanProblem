// Реализация класса, решающего задачу коммивояжера при помощи минимального остовного дерева

#include <vector>
#include <cmath>
#include "CArcWeightedGraph.hpp"
#include "MSTBoruvka.hpp"
#include "CListWeightedGraph.hpp"
#include "MSTravellingSalesmanProblem.hpp"

MSTTravellingSalesmanProblem::MSTTravellingSalesmanProblem(std::vector<std::pair<double, double>>& points) {
    distance = 0;
    CArcWeightedGraph graph(points.size());
    for(int i = 0; i < points.size(); ++i) {
        for(int j = 0; j < points.size(); ++j) {
            if(i == j) {
                continue;
            }
            // Добавляем в граф ребро с весом, равным расстоянию между 2 точками на плоскости
            graph.add_edge(i, j, std::hypot(points[i].first - points[j].first, points[i].second - points[j].second));
        }
    }
    MSTBoruvka MST(graph);
    CArcWeightedGraph a = MST.get_tree();
    CListWeightedGraph tree(MST.get_tree());
    // Выполняем DFS и он возвращает нам последовательность обхода точек
    std::vector<int> path = tree.dfs(0); // Тщательно проверить код у этой штуки
    // Выполняем подсчет длины всего пути
    path.push_back(path[0]);
    for(int i = 0; i < path.size() - 1; ++i) {
        distance += hypot(points[path[i]].first - points[path[i + 1]].first, points[path[i]].second - points[path[i + 1]].second);
    }
}
double MSTTravellingSalesmanProblem::get_distance() const {
    return distance;
}