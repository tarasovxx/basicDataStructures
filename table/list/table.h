#ifndef AISD2023_TABLE_H
#define AISD2023_TABLE_H

enum TableErrors {
    OK,
    DUPLICATE_KEY,
    KEY_NOT_FOUND,
};

typedef struct Item {
    char *info;
} Item;

typedef struct KeySpace {
    int key;
    Item *data;
    struct KeySpace *next;
} KeySpace;

typedef struct Table {
    KeySpace *first;
} Table;

KeySpace *table_find(const Table *, const int);

int table_insert(Table *, const int, const char *);

int table_delete(Table *, const int);

#endif //AISD2023_TABLE_H
