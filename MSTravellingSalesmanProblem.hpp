// Объявление класса, решающего задачу коммивояжера при помощи минимального остовного дерева

#pragma once

#include <vector>
#include <cmath>
#include "CArcWeightedGraph.hpp"
#include "MSTBoruvka.hpp"
#include "CListWeightedGraph.hpp"

class MSTTravellingSalesmanProblem {
public:
    explicit MSTTravellingSalesmanProblem(std::vector<std::pair<double, double>>& points);
    double get_distance() const;
private:
    double distance;
};