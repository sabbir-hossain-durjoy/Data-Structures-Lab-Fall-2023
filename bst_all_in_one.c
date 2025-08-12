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

struct Tree* minNode(struct Tree* t) {
    while (t && t->left) t = t->left;
    return t;
}

struct Tree* deleteKey(struct Tree* t, int k) {
    if (t == NULL) return NULL;
    if (k < t->key) t->left = deleteKey(t->left, k);
    else if (k > t->key) t->right = deleteKey(t->right, k);
    else {
        if (t->left == NULL) { struct Tree* r = t->right; free(t); return r; }
        if (t->right == NULL) { struct Tree* l = t->left; free(t); return l; }
        struct Tree* s = minNode(t->right);
        t->key = s->key;
        t->right = deleteKey(t->right, s->key);
    }
    return t;
}

void inorder(struct Tree* t) {
    if (t == NULL) return;
    inorder(t->left);
    printf("%d ", t->key);
    inorder(t->right);
}

int main() {
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    struct Tree* root = NULL;
    for (int i = 0; i < 7; i++) root = insert(root, a[i]);
    inorder(root); printf("\n");
    root = deleteKey(root, 30);
    inorder(root);
    return 0;
}
