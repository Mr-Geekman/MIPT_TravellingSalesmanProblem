// Реализация класса, решающего задачу коммивояжера при помощи минимального остовного дерева

#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <utility>
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
    CListWeightedGraph tree(MST.get_tree());
    // Находим вершины с нечетными степенями
    std::unordered_map<int, bool> even_degree{}; // bool понадобится при добавлении паросочетания в дерево
    for(int i = 0; i < graph.size(); ++i) {
        auto a = tree.adjacent_end(i) - tree.adjacent_begin(i);
        if((tree.adjacent_end(i) - tree.adjacent_begin(i)) % 2 == 1) {
            even_degree[i] = false;
        }
    }
    // Жадным образом (ответ не точный) находим паросочетание наименьшей стоимости на вершинах even_degree
    std::vector<Edge> edges_for_matching;
    for(auto edge: graph) {
        if(even_degree.find(edge.from) != even_degree.end() && even_degree.find(edge.to) != even_degree.end()) {
            edges_for_matching.push_back(edge);
        }
    }
    std::sort(edges_for_matching.begin(), edges_for_matching.end(), [](Edge first, Edge second){return first.weight < second.weight;});
    for(auto elem: edges_for_matching) {
        if(!even_degree[elem.from] && !even_degree[elem.to]) {
            tree.add_edge(elem.from, elem.to, elem.weight);
            tree.add_edge(elem.to, elem.from, elem.weight);
            even_degree[elem.from] = true;
            even_degree[elem.to] = true;
        }
    }
    // Теперь находим Эйлеров цикл
    std::vector<int> eulerian_cycle{};
    std::stack<int> vertex_stack{};
    std::vector<std::vector<bool>> visited_edges(tree.size(), std::vector<bool>(tree.size(), false));
    vertex_stack.push(0);
    while(!vertex_stack.empty()) {
        int current_vertex = vertex_stack.top();
        for(auto i = tree.adjacent_begin(current_vertex); i != tree.adjacent_end(current_vertex); ++i) {
            if(!visited_edges[current_vertex][(*i).first]) {
                vertex_stack.push((*i).first);
                visited_edges[current_vertex][(*i).first] = true;
                visited_edges[(*i).first][current_vertex] = true;
                break;
            }
        }
        if(current_vertex == vertex_stack.top()) {
            vertex_stack.pop();
            eulerian_cycle.push_back(current_vertex);
        }
    }
    // Преобразовываем Эйлеров цикл в Гамильтонов (пропускаем повторяющиеся вершины)
    std::vector<int> hamiltonian_cycle{};
    std::vector<bool> visited_vertices(tree.size(), false);
    for(auto vertex: eulerian_cycle) {
        if(!visited_vertices[vertex]) {
            hamiltonian_cycle.push_back(vertex);
            visited_vertices[vertex] = true;
        }
    }
    hamiltonian_cycle.push_back(hamiltonian_cycle[0]);
    // Обходим и подсчитываем дистанцию
    for(int i = 0; i < hamiltonian_cycle.size() - 1; ++i) {
        distance += hypot(points[hamiltonian_cycle[i]].first - points[hamiltonian_cycle[i + 1]].first, points[hamiltonian_cycle[i]].second - points[hamiltonian_cycle[i + 1]].second);
    }
}
double MSTTravellingSalesmanProblem::get_distance() const {
    return distance;
}