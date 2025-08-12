#include <stdio.h>

int main() {
    int stack[5];
    int top = -1;
    int x;

    top++; stack[top] = 10;
    top++; stack[top] = 20;
    top++; stack[top] = 30;

    x = stack[top]; top--; printf("%d\n", x);
    x = stack[top]; top--; printf("%d\n", x);

    return 0;
}
