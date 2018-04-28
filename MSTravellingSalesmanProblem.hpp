// Объявление класса, решающего задачу коммивояжера при помощи минимального остовного дерева

#pragma once

#include <vector>

class MSTTravellingSalesmanProblem {
public:
    explicit MSTTravellingSalesmanProblem(std::vector<std::pair<double, double>>& points);
    double get_distance() const;
private:
    double distance;
};