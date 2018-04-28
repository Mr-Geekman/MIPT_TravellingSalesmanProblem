// Объявление класса, решающего задачу коммивояжера при помощи полного перебора

#pragma once

#include <vector>

class TravellingSalesmanProblem {
public:
    explicit TravellingSalesmanProblem(std::vector<std::pair<double, double>>& points);
    double get_distance() const;
private:
    void generate_path(std::vector<std::pair<double, double>>& points, std::vector<bool>& used, std::vector<int>& path);
    double compute_distance(std::vector<std::pair<double, double>>& points, std::vector<int>& path) const;
    double distance;
};