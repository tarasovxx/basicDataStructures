#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int stack_push(Stack *st, int x) {
    Node *new = calloc(1, sizeof(Node));
    new->x = x;
    new->next = st->top;
    st->top = new;
    return 0;
}

int stack_pop(Stack *st, int *info) {
    if (!st->top)
        return 1;
    *info = st->top->x;
    st->top = st->top->next;
    return 0;
}

void stack_destroy(Stack *st) {
    Node *ptr = st->top, *ptr_prev = NULL;
    while (ptr) {
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }
    free(st);
}

Stack *stack_create() {
    return calloc(1, sizeof(Stack));
}
