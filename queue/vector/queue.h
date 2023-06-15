#ifndef AISD2023_QUEUE_H
#define AISD2023_QUEUE_H

typedef struct Queue {
    int head, tail;
    int size, capacity;
    int *array;
} Queue;

int queue_push(Queue *, int );

int queue_pop(Queue *, int *);

Queue *queue_create(const int);

void queue_destroy(Queue *);


#endif //AISD2023_QUEUE_H
