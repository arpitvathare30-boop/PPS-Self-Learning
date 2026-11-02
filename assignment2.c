#include <stdio.h>

int main() {
    int rollNo;
    char name[50];

    /* STEP 1: WRITE DATA TO A FILE */
    FILE *file = fopen("student.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &rollNo);
    printf("Enter Name: ");
    scanf("%49s", name);

    fprintf(file, "Roll Number: %d\nName: %s\n", rollNo, name);
    fclose(file);
    printf("Data successfully written to 'student.txt'!\n\n");

    /* STEP 2: READ DATA BACK FROM THE FILE */
    file = fopen("student.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("--- Reading from student.txt ---\n");
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
    return 0;
}
