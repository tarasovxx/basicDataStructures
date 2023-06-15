#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int queue_push(Queue *q, int x) {
    if (q->size == q->capacity) {
        return 1;
    }
    q->array[q->tail] = x;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
    return 0;
}

int queue_pop(Queue *q, int * x) {
    if (q->size == 0)
        return 0;
    *x = q->array[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->size--;
    return 1;
}

Queue *queue_create(const int capacity) {
    Queue *queue = calloc(1, sizeof(Queue));
    queue->capacity = capacity;
    queue->array = calloc(capacity, sizeof(int));
    return queue;
}

void queue_destroy(Queue *q) {
    free(q->array);
    free(q);
}
