#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

long long hash_int(int key) {
    long long int hash = INT_MAX;
    for (int i = 0; i < sizeof(key); ++i) {
        hash = 37 * hash + ((key >> 8 * i) & 0xff);
    }
}

long long hash_string(char *key) {
    long long int h = INT_MAX;
    for (int i = 0; i < strlen(key); ++i) {
        h = h * 37 + key[i];
    }
    return h;
}