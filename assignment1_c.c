#include <stdio.h>

/* Snippet C - Infinite loop fixed:
   count++ made count grow forever, so "count > 0" never became false.
   count-- makes it move toward 0 and the loop ends. */
int main() {
    int count = 5;
    printf("Starting countdown:\n");
    while (count > 0) {
        printf("Count: %d\n", count);
        count--;
    }
    printf("Done!\n");
    return 0;
}
