#ifndef AISD2023_BINARYTREE_H
#define AISD2023_BINARYTREE_H

typedef struct Node {
    int key;
    char *info;
    struct Node *left, *right;
} Node;

Node *tree_find(Node *, int);

int tree_insert(Node *, const int, const char *);

Node *deleteNode(Node *, const int);

int tree_delete(Node *, const int );

#endif //AISD2023_BINARYTREE_H
