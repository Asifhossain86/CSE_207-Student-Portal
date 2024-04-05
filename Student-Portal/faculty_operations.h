
#ifndef FACULTY_OPERATIONS_H
#define FACULTY_OPERATIONS_H

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

void assign_courses(FILE *file, const char *student_id);
void remove_courses(FILE *file, const char *student_id);

#endif /* FACULTY_OPERATIONS_H */
