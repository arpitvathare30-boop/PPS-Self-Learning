#include <stdio.h>

/* Snippet B - Logical error fixed:
   "marks = 40" ASSIGNS 40 to marks (always true).
   Correct pass check is "marks >= 40" (comparison). */
int main() {
    int marks = 35;
    printf("Checking student result...\n");
    if (marks >= 40) {
        printf("Student has passed!\n");
    } else {
        printf("Student has failed.\n");
    }
    return 0;
}
