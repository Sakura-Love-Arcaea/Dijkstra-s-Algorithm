#include <stdio.h>
#include "./headers/graph.h"
#include "./headers/queue.h"
#include "./headers/stack.h"
#include "headers/dijkstra.h"
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
#define I 8

int main() {
    Graph *graph = createGraph();

    addVertex(graph, 'A');
    addVertex(graph, 'B');
    addVertex(graph, 'C');
    addVertex(graph, 'D');
    addVertex(graph, 'E');
    addVertex(graph, 'F');
    addVertex(graph, 'G');
    addVertex(graph, 'H');
    addVertex(graph, 'I');

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 7, 6, 1);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 8, 6, 6);
    addEdge(graph, 7, 8, 7);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 6, 5, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 5, 3, 14);
    addEdge(graph, 4, 3, 9);
    addEdge(graph, 4, 5, 10);


    int start = 8;
    int end = 3;
    Table table = dijkstra(graph, start, end);

    for (int j = 0; j < graph->vertexCount; j++) {
        printf("%d | %4.2lf | %d\n", table[j].vertex, table[j].distantFromStart, table[j].previous);
    }
    printf("\n");


    int now = table[end].previous;
    Stack *path = createStack();
    while (now != -1) {
        push(path, now);
        now = table[now].previous;
    }
    while (StackIsEmpty(path) != 1) {
        printf("%d -> ", pop(path));
    }
    printf("%d\n", end);
    printf("%.2lf\n", table[end].distantFromStart);

    depthFirstTraversal(graph, 0);
    breadthFirstTraversal(graph, 0);

    return 0;
}
