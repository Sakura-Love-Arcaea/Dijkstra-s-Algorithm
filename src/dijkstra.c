#include <stdio.h>
#include <stdlib.h>
#include "../headers/dijkstra.h"
#include "../headers/stack.h"
#include "../headers/queue.h"
#define INF 100000.0

int *getAdjacentVerticesList(Graph *graph, int VertexIndex) {
    int* list = (int *) malloc(sizeof(int) * graph->vertexCount);
    for (int i = 0; i < graph->vertexCount; i++) {
        list[i] = -1;
    }
    int listIndex = 0;
    for (int i = 0; i < graph->vertexCount; i++) {
        if (graph->adjacencyMatrix[VertexIndex][i] > 0) {
            list[listIndex++] = i;
        }
    }
    return list;
}



Table dijkstra(Graph *graph, int start, int end) {
    int vCount = graph->vertexCount;
    int visitCount = 0;
    struct Row *table = (struct Row *) malloc(sizeof(struct Row) * vCount);
    for (int i = 0; i < vCount; i++) {
        table[i].vertex = i;
        table[i].distantFromStart = INF;
        table[i].previous = -1;
    }

    table[start].distantFromStart = 0;

    while (visitCount != vCount) {
        //choose min distant vertex
        int currentVertex;
        double min = INF;
        for (int i = 0; i < vCount; i++) {
            if (graph->Vertices[i]->visited == VISITED) continue;
            if (table[i].distantFromStart < min) {
                min = table[i].distantFromStart;
                currentVertex = i;
            }
        }
        graph->Vertices[currentVertex]->visited = VISITED; // 標記visited
        visitCount++;
        int *AdjacentVerticesList = getAdjacentVerticesList(graph, currentVertex);
        for (int i = 0; AdjacentVerticesList[i] != -1; i++) { // 尋找相鄰未訪問的， 更新他的距離
            int adjacent = AdjacentVerticesList[i];
            if (graph->Vertices[adjacent]->visited == VISITED) continue;
            double newDistant = table[currentVertex].distantFromStart + getEdge(graph, currentVertex, adjacent);
            if (newDistant < table[adjacent].distantFromStart) {
                table[adjacent].distantFromStart = newDistant;
                table[adjacent].previous = currentVertex;
            }
        }
    }

    return table;
}