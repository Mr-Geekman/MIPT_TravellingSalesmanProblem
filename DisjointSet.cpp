// Реализация системы непересекающихся множеств

#include <vector>
#include "DisjointSet.hpp"

DisjointSet::DisjointSet(int size) {
    parents.resize(size);
    rank.resize(size, 0);
    for(int i = 0; i < parents.size(); ++i) {
        parents[i] = i;
    }
}
void DisjointSet::union_sets(int first_vertex, int second_vertex) {
    if((first_vertex = find(first_vertex)) == (second_vertex = find(second_vertex))) {
        return;
    }
    if(rank[first_vertex] < rank[second_vertex]) {
        parents[first_vertex] = second_vertex;
    } else {
        parents[second_vertex] = first_vertex;
        if(rank[first_vertex] == rank[second_vertex]) {
            ++rank[first_vertex];
        }
    }
}
int DisjointSet::find(int vertex) {
    if(vertex == parents[vertex]) {
        return vertex;
    } else {
        int value = find(parents[vertex]);
        parents[vertex] = value;
        return value;
    }
}