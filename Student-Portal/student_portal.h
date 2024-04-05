
#ifndef STUDENT_PORTAL_H
#define STUDENT_PORTAL_H

#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void student_signup(FILE *file);
void faculty_signup(FILE *file);
int student_login(FILE *file, char *id, char *password);
int faculty_login(FILE *file, char *id, char *password);

#endif /* STUDENT_PORTAL_H */
