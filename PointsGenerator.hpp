// Объявление класса, генериющего нормально распределенные точки

#pragma once

#include <vector>
#include <cmath>
#include <random>

class PointsGenerator {
public:
    explicit PointsGenerator(int n);
    void generate_points(int n);
    std::vector<std::pair<double, double>> get_points() const;
private:
    // сохраняет последний сгенерированный набор точек
    std::vector<std::pair<double, double>> points;
};