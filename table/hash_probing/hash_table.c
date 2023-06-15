#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

int table_find(const Table * t, const int key) {
    int i = hash_int(key) % t->msize, n = 0;
    while (n < t->msize && t->ks[i].busy) {
        if (t->ks[i].key == key) return i;
        i = (i + 1) % t->msize;
        ++n;
    }
    return -1;
}

int table_insert(Table * t, const int key, const char * info) {
    int stat = table_find(t, key);
    if (stat > 0)
        return DUPLICATE_KEY;
    int j = hash_int(key) % t->msize, n = 0;
    while (n < t->msize && t->ks[j].busy) {
        j = (j + 1) % t->msize;
        ++n;
    }
    if (n == t->msize) {
        return TABLE_OVERFLOW;
    }
    t->ks[j].busy = 1;
    t->ks[j].key = key;
    t->ks[j].data = calloc(1, sizeof(Item));
    t->ks[j].data->info = strdup(info);
    return OK;
}

int table_delete(Table * t, const int key) {
    int i = table_find(t, key);
    if (i < 0)
        return KEY_NOT_FOUND;
    t->ks[i].busy = 0;
    free(t->ks[i].data->info);
    free(t->ks[i].data);
    return OK;
}

int rehash(Table *t) {
    int new_msize = t->msize * 2;    // Увеличение размера таблицы в два раза
    KeySpace *new_ks = calloc(new_msize, sizeof(KeySpace));
    if (new_ks == NULL) {
        return MEMORY_ERROR;     // Обработка ошибки при выделении памяти
    }

    // Перехеширование элементов
    for (int i = 0; i < t->msize; i++) {
        if (t->ks[i].busy) {
            int hash = t->ks[i].key % new_msize;     // Новый хеш-код
            while (new_ks[hash].busy) {
                hash = (hash + 1) % new_msize;     // Обработка коллизий методом линейного пробирования
                t->collisions++;     // Увеличение счетчика коллизий
            }
            new_ks[hash] = t->ks[i];     // Перемещение элемента в новую таблицу
        }
    }

    free(t->ks);     // Освобождение старой памяти
    t->ks = new_ks;     // Обновление указателя на новую таблицу
    t->msize = new_msize;     // Обновление размера таблицы

    return OK;
}
