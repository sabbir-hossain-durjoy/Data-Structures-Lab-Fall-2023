#include <stdio.h>
struct Student { char name[20]; int roll; };
int main() {
    struct Student s = {"Sabbir Hossain", 10};
    printf("Name: %s\nRoll: %d\n", s.name, s.roll);
    return 0;
}
