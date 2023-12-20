#include <stdio.h>
#include "../headers/graph.h"
#include "debug.h"

void checkVisited(Graph *graph) {
    printf("checkVisited\n");
    for (int i = 0; i < graph->vertexCount; i++) {
        printf("%d ", graph->Vertices[i]->visited);
    }
    printf("\n");
}

void checkAdjacencyMatrix(Graph *graph) {
    printf("checkAdjacencyMatrix:\n");
    for (int i = 0; i < graph->vertexCount; i++) {
        for (int j = 0; j < graph->vertexCount; j++) {
            printf("%.1lf ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}