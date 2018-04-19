// Реализация класса, генериющего нормально распределенные точки

#include <vector>
#include <cmath>
#include <random>
#include <ctime>
#include "PointsGenerator.hpp"


PointsGenerator::PointsGenerator(int n) {
    generate_points(n);
}
void PointsGenerator::generate_points(int n) {
    points = {};
    // Создаем генератор случайных чисел
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0); // Может ли тут получиться 0?
    for(int i = 0; i < n; ++i) {
        double radius = dis(gen);
        double phi = dis(gen);
        double temp_1 = std::cos(2 * M_PI * phi);
        double temp_2 = sqrt(-2 * std::log(radius));
        double x = temp_1 * temp_2;
        double y = sqrt(1 - temp_1 * temp_1) * temp_2;
        points.emplace_back(std::make_pair(x, y));
    }
}
std::vector<std::pair<double, double>> PointsGenerator::get_points() const {
    return points;
}