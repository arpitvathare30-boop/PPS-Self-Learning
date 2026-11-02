#include <stdio.h>

/* Snippet A - Syntax errors fixed:
   1. Missing semicolon after "int age"
   2. scanf needs the address of the variable: &age */
int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Your age is %d\n", age);
    return 0;
}
