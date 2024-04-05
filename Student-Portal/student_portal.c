#include "student_portal.h"
#include <string.h>

void student_signup(FILE *file) {
    struct User newUser;

    printf("Enter your name: ");
    scanf("%s", newUser.name);

    printf("Enter your student id: ");
    scanf("%s", newUser.id);

    printf("Enter your password: ");
    scanf("%s", newUser.password);

    // Write user data to the file
    fprintf(file, "%s %s %s\n", newUser.name, newUser.id, newUser.password);
    printf("Student registration successful!\n");
}

void faculty_signup(FILE *file) {
    struct User newUser;

    printf("Enter your name: ");
    scanf("%s", newUser.name);

    printf("Enter your faculty id: ");
    scanf("%s", newUser.id);

    printf("Enter your password: ");
    scanf("%s", newUser.password);

    // Write user data to the file
    fprintf(file, "%s %s %s\n", newUser.name, newUser.id, newUser.password);
    printf("Faculty registration successful!\n");
}

int student_login(FILE *file, char *id, char *password) {
    char buffer[MAX_NAME_LENGTH + MAX_ID_LENGTH + MAX_PASSWORD_LENGTH + 3]; // 3 for spaces and newline
    struct User currentUser;

    rewind(file); // Move file pointer to the beginning

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "%s %s %s", currentUser.name, currentUser.id, currentUser.password);
        if (strcmp(currentUser.id, id) == 0 && strcmp(currentUser.password, password) == 0) {
            printf("Student login successful! Welcome, %s\n", currentUser.name);
            return 1;
        }
    }

    printf("Invalid student id or password. Please try again.\n");
    return 0;
}

int faculty_login(FILE *file, char *id, char *password) {
    char buffer[MAX_NAME_LENGTH + MAX_ID_LENGTH + MAX_PASSWORD_LENGTH + 3]; // 3 for spaces and newline
    struct User currentUser;

    rewind(file); // Move file pointer to the beginning

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "%s %s %s", currentUser.name, currentUser.id, currentUser.password);
        if (strcmp(currentUser.id, id) == 0 && strcmp(currentUser.password, password) == 0) {
            printf("Faculty login successful! Welcome, %s\n", currentUser.name);
            return 1;
        }
    }

    printf("Invalid faculty id or password. Please try again.\n");
    return 0;
}

