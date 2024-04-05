#include "faculty_operations.h"
#include <string.h>

void assign_courses(FILE *file, const char *student_id) {
    char buffer[MAX_NAME_LENGTH + MAX_ID_LENGTH + 14]; // 14 for CGPA, spaces, and newline
    struct Student currentStudent;

    rewind(file); // Move file pointer to the beginning

    while (fscanf(file, "%s %s %f", currentStudent.name, currentStudent.id, &currentStudent.cgpa) != EOF) {
        if (strcmp(currentStudent.id, student_id) == 0) {
            printf("Assign courses to student:\n");
            for (int i = 0; i < 4; ++i) {
                printf("Course %d: ", i + 1);
                scanf("%s", currentStudent.courses[i]);
            }
            fseek(file, -1 * (strlen(currentStudent.name) + strlen(currentStudent.id) + 14), SEEK_CUR);
            fprintf(file, "%s %s %.2f", currentStudent.name, currentStudent.id, currentStudent.cgpa);
            for (int i = 0; i < 4; ++i) {
                fprintf(file, " %s", currentStudent.courses[i]);
            }
            fprintf(file, "\n");
            printf("Courses assigned successfully!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

void remove_courses(FILE *file, const char *student_id) {
    char buffer[MAX_NAME_LENGTH + MAX_ID_LENGTH + 14]; // 14 for CGPA, spaces, and newline
    struct Student currentStudent;

    rewind(file); // Move file pointer to the beginning

    while (fscanf(file, "%s %s %f", currentStudent.name, currentStudent.id, &currentStudent.cgpa) != EOF) {
        if (strcmp(currentStudent.id, student_id) == 0) {
            for (int i = 0; i < 4; ++i) {
                strcpy(currentStudent.courses[i], "");
            }
            fseek(file, -1 * (strlen(currentStudent.name) + strlen(currentStudent.id) + 14), SEEK_CUR);
            fprintf(file, "%s %s %.2f", currentStudent.name, currentStudent.id, currentStudent.cgpa);
            for (int i = 0; i < 4; ++i) {
                fprintf(file, " %s", currentStudent.courses[i]);
            }
            fprintf(file, "\n");
            printf("Courses removed successfully!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

