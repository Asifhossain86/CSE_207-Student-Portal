#include "admin_operations.h"
#include <string.h>

void admin_login() {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter admin username: ");
    scanf("%s", username);
    printf("Enter admin password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "adminpass") == 0) {
        printf("Admin login successful!\n");
    } else {
        printf("Invalid admin credentials.\n");
    }
}

void add_student(FILE *file) {
    struct Student newStudent;

    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student id: ");
    scanf("%s", newStudent.id);
    printf("Enter student CGPA: ");
    scanf("%f", &newStudent.cgpa);

    // Write student data to the file
    fprintf(file, "%s %s %.2f\n", newStudent.name, newStudent.id, newStudent.cgpa);
    printf("Student added successfully!\n");
}

void remove_student(FILE *file, const char *id) {
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening temporary file!\n");
        return;
    }

    char buffer[MAX_NAME_LENGTH + MAX_ID_LENGTH + 10]; // 10 for CGPA and newline
    struct Student currentStudent;

    rewind(file); // Move file pointer to the beginning

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "%s %s %f", currentStudent.name, currentStudent.id, &currentStudent.cgpa);
        if (strcmp(currentStudent.id, id) != 0) {
            fprintf(tempFile, "%s %s %.2f\n", currentStudent.name, currentStudent.id, currentStudent.cgpa);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    printf("Student removed successfully!\n");
}

void add_faculty(FILE *file) {
    struct Faculty newFaculty;

    printf("Enter faculty name: ");
    scanf("%s", newFaculty.name);
    printf("Enter faculty id: ");
    scanf("%s", newFaculty.id);
    printf("Enter course: ");
    scanf("%s", newFaculty.course);

    // Write faculty data to the file
    fprintf(file, "%s %s %s\n", newFaculty.name, newFaculty.id, newFaculty.course);
    printf("Faculty added successfully!\n");
}

void remove_faculty(FILE *file, const char *id) {
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening temporary file!\n");
        return;
    }

    char buffer[MAX_NAME_LENGTH + MAX_ID_LENGTH + MAX_NAME_LENGTH + 3]; // 3 for spaces and newline
    struct Faculty currentFaculty;

    rewind(file); // Move file pointer to the beginning

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "%s %s %s", currentFaculty.name, currentFaculty.id, currentFaculty.course);
        if (strcmp(currentFaculty.id, id) != 0) {
            fprintf(tempFile, "%s %s %s\n", currentFaculty.name, currentFaculty.id, currentFaculty.course);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("faculty.txt");
    rename("temp.txt", "faculty.txt");

    printf("Faculty removed successfully!\n");
}

