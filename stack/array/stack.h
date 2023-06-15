#ifndef AISD2023_STACK_H
#define AISD2023_STACK_H

typedef struct Stack {
    int top, capacity;
    int *info;
} Stack;

int stack_push(Stack *, int);

int stack_pop(Stack *, int *);

void stack_destroy(Stack *);

Stack *stack_create(const int );

#endif //AISD2023_STACK_H
