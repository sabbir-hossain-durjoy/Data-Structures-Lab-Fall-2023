#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *next; };
int main() {
    struct Node *a = malloc(sizeof(struct Node));
    struct Node *b = malloc(sizeof(struct Node));
    a->data = 1; a->next = b;
    b->data = 2; b->next = NULL;
    int count = 0;
    struct Node *t = a;
    while (t) { count++; t = t->next; }
    printf("Count: %d", count);
}
