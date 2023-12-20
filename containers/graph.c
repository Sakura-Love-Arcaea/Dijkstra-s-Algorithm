#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack.h"
#include "../headers/queue.h"
#include "../headers/graph.h"
#include "../debug/debug.h"

Graph *createGraph() {
    Graph* graph = (Graph *) malloc(sizeof(Graph));
    graph->vertexCount = 0;
    graph->Vertices = (Vertex **) malloc(sizeof(Vertex *) * GRAPH_SIZE_MAX);
    graph->adjacencyMatrix = (double **) malloc(sizeof(double *) * GRAPH_SIZE_MAX);
    for (int i = 0; i < GRAPH_SIZE_MAX; i++) {
        graph->adjacencyMatrix[i] = (double*) malloc(sizeof(double) * GRAPH_SIZE_MAX);
        for (int j = 0; j < GRAPH_SIZE_MAX; j++) {
            graph->adjacencyMatrix[i][j] = DEFAULT;
        }
    }
    return graph;
}

void addVertex(Graph *graph, char label) {
    Vertex *vertex = (Vertex *) malloc(sizeof(Vertex));
    vertex->label = label;
    vertex->visited = UNVISITED;
    graph->Vertices[graph->vertexCount++] = vertex;
}
char getLabel(Graph *graph, int VertexIndex) {
    return graph->Vertices[VertexIndex]->label;
}
void reset(Graph *graph) {
    for (int i = 0; i < graph->vertexCount; i++) {
        graph->Vertices[i]->visited = UNVISITED;
    }
}
void addEdge(Graph *graph, int start, int end, double weight) {
    graph->adjacencyMatrix[start][end] = weight;
    graph->adjacencyMatrix[end][start] = weight;
}
void displayVertex(Graph *graph, int VertexIndex) {
    printf("%c ", getLabel(graph, VertexIndex));
}
double getEdge(Graph *graph, int start, int end) {
    return graph->adjacencyMatrix[start][end];
}

void displayEdge(Graph *graph, int start, int end) {
    double weight = graph->adjacencyMatrix[start][end];
    printf("%c --", getLabel(graph, start));
    if (weight == -1) {
        printf("X");
    } else {
        printf("%.2lf", getEdge(graph, start, end));
    }
    printf("--> %c\n", getLabel(graph, end));
}
int getUnvisitedVertex(Graph *graph, int VertexIndex) {
    for (int i = 0; i < graph->vertexCount; i++) {
        if (graph->adjacencyMatrix[VertexIndex][i] >= 0 && graph->Vertices[i]->visited == UNVISITED) {
            return i;
        }
    }
    return -1;
}

void depthFirstTraversal(Graph *graph, int startFrom) {
    graph->Vertices[startFrom]->visited = VISITED;
    displayVertex(graph, startFrom);
    Stack *stack = createStack();
    push(stack, startFrom);

    while(!StackIsEmpty(stack)) {
        for (;;) {
            int currentVertex = peek(stack);
            int getChild = getUnvisitedVertex(graph, currentVertex);
            if (getChild == -1) {
                pop(stack);
                break;
            }
            displayVertex(graph, getChild);
            push(stack, getChild);
            graph->Vertices[getChild]->visited = VISITED;
        }
    }
    printf("\n");
    reset(graph);
}

void breadthFirstTraversal(Graph *graph, int startFrom) {
    graph->Vertices[startFrom]->visited = VISITED;
    displayVertex(graph, startFrom);
    Queue *queue = createQueue();
    enqueue(queue, startFrom);
    while (!QueueIsEmpty(queue)) {
        for(;;) {
            int currentVertex = front(queue);
            int getChild = getUnvisitedVertex(graph, currentVertex);
            if (getChild == -1) {
                dequeue(queue);
                break;
            }
            displayVertex(graph, getChild);
            enqueue(queue, getChild);
            graph->Vertices[getChild]->visited = VISITED;
        }
    }
    printf("\n");
    reset(graph);
}