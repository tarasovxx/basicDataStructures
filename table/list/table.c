#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"


KeySpace *table_find(const Table * t, const int key) {
    KeySpace *ptr = t->first;
    while (ptr) {
        if (ptr->key == key)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

int table_insert(Table * t, const int key, const char * info) {
    if (table_find(t, key) != NULL) {
        return DUPLICATE_KEY;
    }
    KeySpace *new = calloc(1, sizeof(KeySpace));
    new->key = key;
    new->data = calloc(1, sizeof(Item));
    new->data->info = strdup(info);

    new->next = t->first;
    t->first = new;
    return OK;
}

int table_delete(Table * t, const int key) {
    KeySpace *ptr = t->first, *ptr_prev = NULL;
    while (ptr && ptr->key != key) {
        ptr_prev = ptr;
        ptr= ptr->next;
    }
    if (ptr == NULL) {
        return KEY_NOT_FOUND;
    }
    if (ptr == t->first) {
        t->first = ptr->next;
    }
    else {
        ptr_prev->next = ptr->next;
    }
    free(ptr->data->info);
    free(ptr->data);
    free(ptr);
    return OK;
}

