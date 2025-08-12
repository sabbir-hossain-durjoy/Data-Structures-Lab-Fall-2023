#include <stdio.h>
#include <stdlib.h>

struct Tree { int key; struct Tree* left; struct Tree* right; };

struct Tree* newNode(int k) {
    struct Tree* n = (struct Tree*)malloc(sizeof(struct Tree));
    n->key = k; n->left = NULL; n->right = NULL;
    return n;
}

struct Tree* insert(struct Tree* t, int k) {
    if (t == NULL) return newNode(k);
    if (k < t->key) t->left = insert(t->left, k);
    else if (k > t->key) t->right = insert(t->right, k);
    return t;
}

struct Tree* search(struct Tree* t, int k) {
    if (t == NULL || t->key == k) return t;
    if (k < t->key) return search(t->left, k);
    else return search(t->right, k);
}

int main() {
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    struct Tree* root = NULL;
    for (int i = 0; i < 7; i++) root = insert(root, a[i]);
    if (search(root, 60)) printf("Found\n"); else printf("Not found\n");
    return 0;
}
