#ifndef AISD2023_DEQUE_H
#define AISD2023_DEQUE_H

typedef struct {
    int head, tail;
    int size, capacity;
    int *array;
} Deque;

Deque *deque_create(const int);

void deque_destroy(Deque *);

int deque_push_front(Deque *, const int);

int deque_push_back(Deque *, const int);

int deque_pop_front(Deque *, int *);

int deque_pop_back(Deque *, int *);

void deque_print(const Deque *);

#endif //AISD2023_DEQUE_H
