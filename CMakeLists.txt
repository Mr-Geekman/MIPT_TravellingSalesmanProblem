cmake_minimum_required(VERSION 3.8)
project(2_A)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CArcWeightedGraph.hpp CArcWeightedGraph.cpp
        DisjointSet.hpp DisjointSet.cpp
        MSTBoruvka.hpp MSTBoruvka.cpp
        CListWeightedGraph.hpp CListWeightedGraph.cpp
        MSTravellingSalesmanProblem.hpp MSTTravellingSalesmanProblem.cpp
        TravellingSalesmanProblem.hpp TravellingSalesmanProblem.cpp
        PointsGenerator.hpp PointsGenerator.cpp
        Tester.hpp Tester.cpp)
add_executable(2_A ${SOURCE_FILES})