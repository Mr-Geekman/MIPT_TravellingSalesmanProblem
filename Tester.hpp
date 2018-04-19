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
    std::vector<double> get_average_differences() const;
    std::vector<double> get_standart_difference_deviations() const;
    void draw_statistics() const;
private:
    void test_with_points(int num_of_points, int num_of_repetitions);
    // Массив средних значений
    int from;
    int to;
    std::vector<double> average_differences;
    // Стандартное отклонение
    std::vector<double> standart_difference_deviations;
    //std::vector<double> MST_standart_deviation;
    //std::vector<double> brute_average_values;
    //std::vector<double> brut_standart_deviation;
};