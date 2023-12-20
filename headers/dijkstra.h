#ifndef DIJKSTRAALGORITHM_DIJKSTRA_H
#define DIJKSTRAALGORITHM_DIJKSTRA_H
#include "graph.h"
struct Row {
    int vertex;
    double distantFromStart;
    int previous;
};
typedef struct Row * Table;

Table dijkstra(Graph *graph, int start, int end);
#endif //DIJKSTRAALGORITHM_DIJKSTRA_H
