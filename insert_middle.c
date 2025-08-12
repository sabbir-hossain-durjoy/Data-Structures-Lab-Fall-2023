#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *next; };
int main() {
    struct Node *n1 = malloc(sizeof(struct Node));
    struct Node *n2 = malloc(sizeof(struct Node));
    n1->data = 1; n1->next = n2;
    n2->data = 3; n2->next = NULL;
    struct Node *mid = malloc(sizeof(struct Node));
    mid->data = 2;
    mid->next = n2;
    n1->next = mid;
    struct Node *t = n1;
    while (t) { printf("%d ", t->data); t = t->next; }
}
