#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


int stack_push(Stack * st, int x) {
    if (st->top == st->capacity)
        return 1; // Стэк переполнен
    st->info[st->top++] = x;
    return 0;
}

int stack_pop(Stack * st, int *x) {
    if (st->top != 0) {
        *x = st->info[--st->top];
    }
    else
        return 1; // Стэк пуст
    return 0;
}

void stack_destroy(Stack *st) {
    free(st->info);
    free(st);
}

Stack *stack_create(const int capacity) {
    Stack *st = calloc(1, sizeof(Stack));
    st->capacity = capacity;
    st->info = calloc(capacity, sizeof(int));
    return st;
}

