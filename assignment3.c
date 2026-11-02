#include <stdio.h>

int main() {
    int n = 3;          // Number of students
    int rollNo;
    char name[50];
    float marks;

    /* STEP 1: WRITE MULTIPLE RECORDS TO A FILE */
    FILE *file = fopen("class_records.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    printf("--- Enter Details for %d Students ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &rollNo);

        printf("Enter Name: ");
        scanf("%49s", name);

        printf("Enter Marks: ");
        scanf("%f", &marks);

        fprintf(file, "Roll: %d | Name: %s | Marks: %.2f\n", rollNo, name, marks);
    }

    fclose(file);
    printf("\nAll 3 records successfully written to 'class_records.txt'!\n\n");

    /* STEP 2: READ ALL RECORDS BACK FROM THE FILE */
    file = fopen("class_records.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("--- Reading Records from class_records.txt ---\n");
    char buffer[150];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}
