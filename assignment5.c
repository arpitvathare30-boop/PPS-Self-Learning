#include <stdio.h>   // Standard I/O library: printf, scanf, FILE, fopen, fprintf, fgets, fclose

int main() {
    int n = 3;          // Total number of students whose records we will store
    int rollNo;         // Holds one student's roll number (whole number)
    char name[50];      // Holds one student's name (up to 49 characters + '\0')
    float marks;        // Holds one student's marks (decimal number)

    /* ---------- STEP 1: WRITE MULTIPLE RECORDS TO A FILE ---------- */

    // FILE * is a pointer that tracks the file we are working with.
    // fopen() opens "class_records.txt" in "w" (write) mode:
    // it creates the file, or erases the old content if it already exists.
    FILE *file = fopen("class_records.txt", "w");

    // fopen() returns NULL if it fails (e.g. no permission), so always check.
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;       // Exit with a non-zero value to signal an error
    }

    printf("--- Enter Details for %d Students ---\n", n);

    // Loop runs once per student: i = 0, 1, 2
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);   // i + 1 so humans see 1, 2, 3

        printf("Enter Roll Number: ");
        scanf("%d", &rollNo);               // %d reads an int; & gives the variable's address

        printf("Enter Name: ");
        scanf("%49s", name);                // %s reads one word; 49 limits input to avoid overflow

        printf("Enter Marks: ");
        scanf("%f", &marks);                // %f reads a float

        // fprintf works like printf but writes INTO the file instead of the screen.
        // Each call adds one new line; %.2f prints marks with 2 decimals.
        fprintf(file, "Roll: %d | Name: %s | Marks: %.2f\n", rollNo, name, marks);
    }

    // fclose() saves everything and releases the file.
    // Rule: every fopen() must have a matching fclose().
    fclose(file);
    printf("\nAll 3 records successfully written to 'class_records.txt'!\n\n");

    /* ---------- STEP 2: READ ALL RECORDS BACK FROM THE FILE ---------- */

    // Reopen the same file, this time in "r" (read) mode.
    file = fopen("class_records.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("--- Reading Records from class_records.txt ---\n");

    char buffer[150];   // Temporary storage for one line read from the file

    // fgets() reads one line (up to sizeof(buffer)-1 characters) into buffer.
    // At end of file it returns NULL, which stops the loop.
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);   // Line already contains '\n', so no extra one is needed
    }

    fclose(file);       // Close the file again when finished
    return 0;           // 0 = program finished successfully
}
