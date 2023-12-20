#ifndef GRAPH_QUEUE_H
#define GRAPH_QUEUE_H
#define QUEUE_SIZE_MAX 255

struct Queue {
    int *array;
    int front;
    int rear;
    int count;
};

typedef struct Queue Queue;

Queue *createQueue();
void enqueue(Queue *queue, int data);
int dequeue(Queue *queue);
int front(Queue *queue);
int QueueIsEmpty(Queue *queue);
#endif //GRAPH_QUEUE_H
