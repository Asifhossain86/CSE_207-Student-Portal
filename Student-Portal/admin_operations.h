
#ifndef ADMIN_OPERATIONS_H
#define ADMIN_OPERATIONS_H

#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct Student {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    float cgpa;
};

struct Faculty {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    char course[MAX_NAME_LENGTH];
};

void admin_login();
void add_student(FILE *file);
void remove_student(FILE *file, const char *id);
void add_faculty(FILE *file);
void remove_faculty(FILE *file, const char *id);

#endif /* ADMIN_OPERATIONS_H */
