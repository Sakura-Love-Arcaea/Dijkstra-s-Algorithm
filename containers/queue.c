#include <stdio.h>
#include <stdlib.h>
#include "../headers/queue.h"

Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->array = (int *) malloc(sizeof(int) * QUEUE_SIZE_MAX);
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    return queue;
}

void enqueue(Queue *queue, int data) {
    queue->array[++queue->rear] = data;
    queue->count++;
}

int dequeue(Queue *queue) {
    queue->count--;
    return queue->array[queue->front++];
}
int front(Queue *queue) {
    return queue->array[queue->front];
}
int QueueIsEmpty(Queue *queue) {
    return queue->count == 0 ? 1 : 0;
}