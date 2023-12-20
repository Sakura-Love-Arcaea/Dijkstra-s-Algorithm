#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#define GRAPH_SIZE_MAX 15
#define DEFAULT -1;
#define VISITED 1
#define UNVISITED 0
struct Vertex {
    char label;
    int visited;
};

typedef struct Vertex Vertex;

struct Graph {
    Vertex **Vertices;
    double **adjacencyMatrix;
    int vertexCount;
};

typedef struct Graph Graph;

Graph* createGraph();
void addVertex(Graph *graph, char label);
char getLabel(Graph *graph, int VertexIndex);
void reset(Graph *graph);
void addEdge(Graph *graph, int start, int end, double weight);
void displayVertex(Graph *graph, int VertexIndex);
double getEdge(Graph *graph, int start, int end);
void displayEdge(Graph *graph, int start, int end);
int getUnvisitedVertex(Graph *graph, int VertexIndex);

void depthFirstTraversal(Graph *graph, int startFrom);
void breadthFirstTraversal(Graph *graph, int startFrom);
#endif //GRAPH_GRAPH_H
