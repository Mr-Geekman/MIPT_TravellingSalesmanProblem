// Реализация класса, решающего задачу коммивояжера при помощи полного перебора

#include <vector>
#include <cmath>
#include "TravellingSalesmanProblem.hpp"

TravellingSalesmanProblem::TravellingSalesmanProblem(std::vector<std::pair<double, double>>& points) {
    distance = INFINITY;
    std::vector<bool> used(points.size(), false);
    std::vector<int> path = {};
    generate_path(points, used, path);
}
void TravellingSalesmanProblem::generate_path(std::vector<std::pair<double, double>>& points, std::vector<bool>& used, std::vector<int>& path) {
    bool flag = false;
    for(int i = 0; i < used.size(); ++i) {
        if(!used[i]) {
            flag = true;
            used[i] = true;
            path.push_back(i);
            generate_path(points, used, path);
            path.pop_back();
            used[i] = false;
        }
    }
    if(!flag) {
        distance = std::min(compute_distance(points, path), distance);
    }
}
double TravellingSalesmanProblem::compute_distance(std::vector<std::pair<double, double>>& points, std::vector<int>& path) const {
    double curr_distance = 0;
    path.push_back(path[0]);
    for(int i = 0; i < path.size() - 1; ++i) {
        curr_distance += hypot(points[path[i]].first - points[path[i + 1]].first, points[path[i]].second - points[path[i + 1]].second);
    }
    path.pop_back();
    return curr_distance;
}
double TravellingSalesmanProblem::get_distance() const {
    return distance;
}