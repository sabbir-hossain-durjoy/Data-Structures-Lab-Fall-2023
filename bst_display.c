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

void inorder(struct Tree* t) {
    if (t == NULL) return;
    inorder(t->left);
    printf("%d ", t->key);
    inorder(t->right);
}

void preorder(struct Tree* t) {
    if (t == NULL) return;
    printf("%d ", t->key);
    preorder(t->left);
    preorder(t->right);
}

void postorder(struct Tree* t) {
    if (t == NULL) return;
    postorder(t->left);
    postorder(t->right);
    printf("%d ", t->key);
}

int main() {
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    struct Tree* root = NULL;
    for (int i = 0; i < 7; i++) root = insert(root, a[i]);
    inorder(root); printf("\n");
    preorder(root); printf("\n");
    postorder(root);
    return 0;
}
