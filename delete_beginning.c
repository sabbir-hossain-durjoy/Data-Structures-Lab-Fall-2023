#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *next; };
int main() {
    struct Node *n1 = malloc(sizeof(struct Node));
    struct Node *n2 = malloc(sizeof(struct Node));
    n1->data = 1; n1->next = n2;
    n2->data = 2; n2->next = NULL;
    struct Node *temp = n1;
    n1 = n1->next;
    free(temp);
    while (n1) { printf("%d ", n1->data); n1 = n1->next; }
}
