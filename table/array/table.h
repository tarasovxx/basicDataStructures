#ifndef AISD2023_TABLE_H
#define AISD2023_TABLE_H

enum TableErrors {
    OK,
    DUPLICATE_KEY,
    KEY_NOT_FOUND,
    TABLE_OVERFLOW
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
    KeySpace *ks;
    int msize;
    int csize;
} Table;

int table_find(const Table *, const int);

int table_insert(Table *, const int, const char *);

int table_delete(Table *, const int);

void table_garbage_collector(Table *);

#endif //AISD2023_TABLE_H
