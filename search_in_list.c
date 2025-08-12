#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

int main() {
    struct Node* a = (struct Node*)malloc(sizeof(struct Node));
    struct Node* b = (struct Node*)malloc(sizeof(struct Node));
    struct Node* c = (struct Node*)malloc(sizeof(struct Node));
    int key = 20, pos = 1, found = 0;
    struct Node* t;

    a->data = 10; a->next = b;
    b->data = 20; b->next = c;
    c->data = 30; c->next = NULL;

    t = a;
    while (t) {
        if (t->data == key) { found = 1; break; }
        t = t->next;
        pos++;
    }
    if (found) printf("%d\n", pos);
    else printf("-1\n");
    return 0;
}
