// Реализация класса, тестирующего решения задачи коммивояжера

#pragma once

#include <iostream>
#include <vector>
#include "PointsGenerator.hpp"
#include "MSTravellingSalesmanProblem.hpp"
#include "TravellingSalesmanProblem.hpp"


class Tester {
public:
    Tester(int from, int to, int num_of_repetitions);
    void draw_statistics() const;
private:
    void test_with_points(int num_of_points, int num_of_repetitions);
    int from;
    int to;
    std::vector<double> average_factors;
    std::vector<double> standart_factor_deviations;
};