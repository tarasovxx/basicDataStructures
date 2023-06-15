#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binaryTree.h"

Node *tree_find(Node * root, int key) {
    if (!root) return NULL;
    Node *ptr = root;
    while (ptr) {
        if (ptr->key == key)
            return ptr;
        if (ptr->key < key)
            ptr = ptr->left;
        else
            ptr = ptr->right;

    }
    return NULL;
}

int tree_insert(Node * root, const int key, const char * info) {
    Node *ptr = root, *parent = NULL;
    while (ptr) {
        parent = ptr;
        if (ptr->key == key)
            return 1;
        if (ptr->key < key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    Node *new = calloc(1, sizeof(Node));
    new->key = key;
    new->info = strdup(info);
    if (parent == NULL)
        root = new;
    else if (parent->key > key)
        parent->left = new;
    else
        parent->right = new;

    return 0;

}

Node *findMin(Node *root) {
    Node *ptr = root;
    while (ptr->left) {
        ptr = ptr->left;
    }
    return ptr;
}

Node *deleteNode(Node * root, const int key) {
    if (root == NULL)
        return NULL;
    if (root->key < key)
        root->left = deleteNode(root->left, key);
    else if (root->key > key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node *tmp = root->right;
            free(root->info);
            free(root);
            root = NULL;
            return tmp;
        }
        else if (root->right == NULL) {
            Node *tmp = root->left;
            free(root->info);
            free(root);
            return tmp;
        }
        else {
            Node *tmp = findMin(root->right);
            free(root->info);
            root->key = tmp->key;
            root->info = strdup(tmp->info);
            root->right = deleteNode(root->right, tmp->key);

        }
        return root;
    }
}

// С дубликатами
/*
Node* deleteNode(Node* root, Node* target) {
    if (root == NULL) {
        return root;
    }
    if (strcmp(target->key, root->key) < 0) {
        root->left = deleteNode(root->left, target);
    }
    else if (strcmp(target->key, root->key) > 0) {
        root->right = deleteNode(root->right, target);
    }
        // В случае если мы нашли искомое, то ещё проверяем соотвествует ли адрес искомомого элменета и удаляемого
    else {
        if (root != target) {
            root->left = deleteNode(root->left, target);
        }
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                free(root->key);
                free(root);
                root = NULL;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                free(root->key);
                free(root);
                root = NULL;
                return temp;
            }
            Node* temp = findMin(root->right);
            free(root->key);
            root->key = strdup(temp->key);
            root->info = temp->info;
            root->right = deleteNode(root->right, temp);
        }
    }
    return root;
}*/

int tree_delete(Tree *tree, const int key)
{
    Node *ptr = tree->root;
    Node *par = NULL;
    while (ptr != NULL)
    {
        if (ptr->key == key)
            break;

        par = ptr;

        if (key < ptr->key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if (ptr == NULL)
        return 1;

    if (ptr->right == NULL)
    {
        if (par == NULL)
            tree->root = ptr->left;
        else if (ptr == par->left)
            par->left = ptr->left;
        else /* ptr == par->right */
            par->right = ptr->left;
    }
    else
    {
        Node *right = ptr->right;
        if (right->left == NULL)
        {
            right->left = ptr->left;

            if (par == NULL)
                tree->root = right;
            else if (ptr == par->left)
                par->left = right;
            else /* ptr = par->right */
                par->right = right;
        }
        else
        {
            Node *succ = right->left;
            while (succ->left != NULL)
            {
                right = succ;
                succ = succ->left;
            }

            right->left = succ->right;
            succ->left = ptr->left;
            succ->right = ptr->right;

            if (par == NULL)
                tree->root = succ;
            else if (ptr == par->left)
                par->left = succ;
            else /* ptr == par->right */
                par->right = succ;
        }
    }

    free(ptr->info);
    free(ptr);

    return 0;
}