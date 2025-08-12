#include <stdio.h>

int main() {
    int q[5];
    int front = 0;
    int rear = -1;
    int x;

    rear++; q[rear] = 1;
    rear++; q[rear] = 2;
    rear++; q[rear] = 3;

    x = q[front]; front++; printf("%d\n", x);
    x = q[front]; front++; printf("%d\n", x);

    return 0;
}
