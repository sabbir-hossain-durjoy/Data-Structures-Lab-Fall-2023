#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *next; };
int main() {
    struct Node *a = malloc(sizeof(struct Node));
    struct Node *b = malloc(sizeof(struct Node));
    struct Node *c = malloc(sizeof(struct Node));
    a->data = 1; a->next = b;
    b->data = 2; b->next = c;
    c->data = 3; c->next = NULL;
    a->next = c;
    free(b);
    struct Node *t = a;
    while (t) { printf("%d ", t->data); t = t->next; }
}
