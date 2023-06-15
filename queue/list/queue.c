#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int queue_push(Queue *q, const int x) {
    Node *new = calloc(1, sizeof(Node));
    new->info = x;
    if (q->head == NULL) {
        q->head = new;
    }
    else {
        q->tail->next = new;
    }
    q->tail = new;
    return 0;
}

int queue_pop(Queue *queue, int *info) {
    if (queue->head == NULL)
        return 1;

    *info = queue->head->info;

    Node *head = queue->head;
    queue->head = head->next;
    free(head);

    if (queue->head == NULL)
        queue->tail = NULL;

    return 0;
}

void queue_print(const Queue *queue) {
    if (queue->head == NULL)
        return;

    Node *node = queue->head;
    while (node != NULL) {
        printf("%d ", node->info);
        node = node->next;
    }
    printf("\n");
}