#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *next; };
int main() {
    struct Node *n1 = malloc(sizeof(struct Node));
    n1->data = 1; n1->next = NULL;
    struct Node *end = malloc(sizeof(struct Node));
    end->data = 2; end->next = NULL;
    n1->next = end;
    struct Node *t = n1;
    while (t) { printf("%d ", t->data); t = t->next; }
}
