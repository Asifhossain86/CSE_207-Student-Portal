#ifndef STUDENT_OPERATIONS_H
#define STUDENT_OPERATIONS_H

#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 20
#define MAX_COURSE_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    float cgpa;
    char courses[4][MAX_COURSE_LENGTH];
};

void view_student_profile(FILE *file, const char *id);
void add_course(FILE *file, const char *id);
void remove_course(FILE *file, const char *id);

#endif /* STUDENT_OPERATIONS_H */
