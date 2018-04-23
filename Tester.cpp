// Реализация класса, тестирующего решения задачи коммивояжера

#include <iostream>
#include <vector>
#include "PointsGenerator.hpp"
#include "MSTravellingSalesmanProblem.hpp"
#include "TravellingSalesmanProblem.hpp"
#include "Tester.hpp"

Tester::Tester(int from, int to, int num_of_repetitions) {
    this->from = from;
    this->to = to;
    for(int i = from; i <= to; ++i) {
        test_with_points(i, num_of_repetitions);
    }
}
std::vector<double> Tester::get_average_factors() const {
    return average_factors;
}
std::vector<double> Tester::get_standart_factor_deviations() const {
    return standart_factor_deviations;
}
void Tester::draw_statistics() const {
    for(int i = from; i <= to; ++i) {
        std::cout.fixed;
        std::cout.precision(4);
        std::cout << i << ": " << "average factor = " << average_factors[i - from] << " standart deviation = " << standart_factor_deviations[i - from] << std::endl;
    }
}
void Tester::test_with_points(int num_of_points, int num_of_repetitions) {
    PointsGenerator gen(num_of_points);
    std::vector<double> factors(num_of_repetitions);
    double sum_factors = 0;
    for(int i = 0; i < num_of_repetitions; ++i) {
        auto points = gen.get_points();
        gen.generate_points(num_of_points);
        MSTTravellingSalesmanProblem MST_solution(points);
        TravellingSalesmanProblem brute_solution(points);
        factors[i] = MST_solution.get_distance() / brute_solution.get_distance();
        sum_factors += factors[i];
    }
    average_factors.push_back(sum_factors / num_of_repetitions);
    // Рассчитаем стандартное отклонение
    double average_difference = sum_factors / num_of_repetitions;
    double standart_deviation = 0;
    for(auto value: factors) {
        standart_deviation += pow(value - average_difference, 2);
    }
    standart_deviation = sqrt(standart_deviation / num_of_repetitions);
    standart_factor_deviations.push_back(standart_deviation);
}