#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

KeySpace *table_find(const Table * t, const int key) {
    int j = hash_int(key) % t->msize;
    for (KeySpace *ptr = t->ks[j]; ptr; ptr = ptr->next) {
        if (ptr->key == key)
            return ptr;
    }
    return NULL;
}

int table_insert(Table * t, const int key, const char * info) {
    if (table_find(t, key) != NULL)
        return DUPLICATE_KEY;
    KeySpace *new = calloc(1, sizeof(KeySpace));
    new->data = calloc(1, sizeof(Item));
    new->key = key;
    new->data->info = strdup(info);

    int j = hash_int(key) % t->msize;
    new->next = t->ks[j];
    t->ks[j] = new;
    return OK;
}


int table_delete(Table * table, const int  key) {
    int i = hash_int(key) % table->msize;
    KeySpace *ptr = table->ks[i], *ptr_prev;
    while (ptr != NULL && ptr->key != key) {
        ptr_prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
        return KEY_NOT_FOUND;

    if (ptr == table->ks[i])
        table->ks[i] = table->ks[i]->next;
    else
        ptr_prev->next = ptr->next;

    free(ptr->data->info);
    free(ptr->data);
    free(ptr);

    return OK;
}
