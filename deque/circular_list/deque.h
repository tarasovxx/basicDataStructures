#ifndef AISD2023_DEQUE_H
#define AISD2023_DEQUE_H

typedef struct Node {
    int info;
    struct Node *prev, *next;
} Node;

typedef struct {
    Node *head, *tail;
} Deque;

Deque *deque_create();

void deque_destroy(Deque *);

int deque_push_front(Deque *, const int);

int deque_push_back(Deque *, const int);

int deque_pop_front(Deque *, int *);

int deque_pop_back(Deque *, int *);

void deque_print(const Deque *);

#endif //AISD2023_DEQUE_H
