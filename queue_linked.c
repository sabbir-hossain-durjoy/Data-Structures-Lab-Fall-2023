#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    struct Node* n;
    int x;

    n = (struct Node*)malloc(sizeof(struct Node));
    n->data = 10; n->next = NULL;
    front = rear = n;

    n = (struct Node*)malloc(sizeof(struct Node));
    n->data = 20; n->next = NULL;
    rear->next = n; rear = n;

    x = front->data; n = front; front = front->next; if (!front) rear = NULL; free(n); printf("%d\n", x);
    x = front->data; n = front; front = front->next; if (!front) rear = NULL; free(n); printf("%d\n", x);

    return 0;
}
