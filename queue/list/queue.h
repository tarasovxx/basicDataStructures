#ifndef AISD2023_QUEUE_H
#define AISD2023_QUEUE_H

typedef struct Node {
    int info;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head, *tail;
} Queue;

Queue *queue_create();

void queue_destroy(Queue *);

int queue_push(Queue *, const int);

int queue_pop(Queue *, int *);

void queue_print(const Queue *);

#endif
