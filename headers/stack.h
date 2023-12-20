#ifndef GRAPH_STACK_H
#define GRAPH_STACK_H
#define STACK_SIZE_MAX 255
struct Stack {
    int *array;
    int top;
};

typedef struct Stack Stack;

Stack* createStack();
void push(Stack *stack, int data);
int pop(Stack *stack);
int peek(Stack *stack);
int StackIsEmpty(Stack *stack);

#endif //GRAPH_STACK_H
