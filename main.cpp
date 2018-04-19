#include <iostream>
#include "Tester.hpp"
#include "TravellingSalesmanProblem.hpp"
#include "MSTravellingSalesmanProblem.hpp"

/*
Планы по решению
1) разобраться, почему результат MST бывает лучше результата brute +
2) проверить генерацию точек на "нормальность" и проверить на возможные ошибки реализацию
*/

int main() {
    Tester tester(4, 10, 5);
    tester.draw_statistics();
    return 0;
}