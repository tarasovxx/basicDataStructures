#ifndef AISD2023_HASH_TABLE_H
#define AISD2023_HASH_TABLE_H

#include "../hash/hash.h"

enum TableErrors {
    OK,
    DUPLICATE_KEY,
    KEY_NOT_FOUND,
    TABLE_OVERFLOW,
    MEMORY_ERROR
};

typedef struct Item {
    char *info;
} Item;

typedef struct KeySpace {
    int busy;
    int key;
    Item *data;
} KeySpace;

typedef struct Table {
    KeySpace * ks;
    int collisions;
    int msize;
} Table;

int table_find(const Table *, const int);

int table_insert(Table *, const int, const char *);

int table_delete(Table *, const int);

int rehash(Table *);

#endif //AISD2023_HASH_TABLE_H
