#ifndef AISD2023_STACK_H
#define AISD2023_STACK_H

typedef struct Node {
    int x;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

int stack_push(Stack *, int);

int stack_pop(Stack *, int *);

void stack_destroy(Stack *);

Stack *stack_create();


#endif //AISD2023_STACK_H
