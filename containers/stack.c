#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack.h"

Stack* createStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->array = (int *) malloc(sizeof(int) * STACK_SIZE_MAX);
    stack->top = -1;
    return stack;
}

void push(Stack *stack, int data) {
    stack->array[++stack->top] = data;
}

int pop(Stack *stack) {
    return stack->array[stack->top--];
}
int peek(Stack *stack) {
    return stack->array[stack->top];
}

int StackIsEmpty(Stack *stack) {
    return stack->top == -1 ? 1 : 0;
}





