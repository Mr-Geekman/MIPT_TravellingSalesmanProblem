/*
Приближенное решение метрической неориентированной задачи коммивояжера методом минимального остовного дерева и
сравнение результатов с методом полного перебора.
*/

#include "Tester.hpp"

int main() {
    // tester(m, n, k) значит, что тесты запустятся для количества точек от m до n с числом повторений для каждого количества точек k
    Tester tester(2, 7, 10);
    tester.draw_statistics();
    return 0;
}