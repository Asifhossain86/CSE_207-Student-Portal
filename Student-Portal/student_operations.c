
/*#include "student_operations.h"
#include <string.h>

void view_student_profile(FILE *file, const char *id) {
    char buffer[MAX_NAME_LENGTH + MAX_ID_LENGTH + 14];
    struct Student currentStudent;

    rewind(file);

    while (fscanf(file, "%s %s %f", currentStudent.name, currentStudent.id, &currentStudent.cgpa) != EOF) {
        if (strcmp(currentStudent.id, id) == 0) {
            printf("Name: %s\n", currentStudent.name);
            printf("ID: %s\n", currentStudent.id);
            printf("CGPA: %.2f\n", currentStudent.cgpa);
            if (strcmp(currentStudent.courses[0], "") != 0) {
                printf("Courses:\n");
                for (int i = 0; i < 4; ++i) {
                    if (strcmp(currentStudent.courses[i], "") != 0) {
                        printf("- %s\n", currentStudent.courses[i]);
                    }
                }
            } else {
                printf("No courses yet.\n");
            }
            return;
        }
    }

    printf("Student not found!\n");
}

void add_course(FILE *file, const char *id) {
    char buffer[MAX_NAME_LENGTH + MAX_ID_LENGTH + 14]; // 14 for CGPA, spaces, and newline
    struct Student currentStudent;

    rewind(file); // Move file pointer to the beginning

    while (fscanf(file, "%s %s %f", currentStudent.name, currentStudent.id, &currentStudent.cgpa) != EOF) {
        if (strcmp(currentStudent.id, id) == 0) {
            printf("Enter course to add: ");
            char newCourse[MAX_COURSE_LENGTH];
            scanf("%s", newCourse);
            for (int i = 0; i < 4; ++i) {
                if (strcmp(currentStudent.courses[i], "") == 0) {
                    strcpy(currentStudent.courses[i], newCourse);
                    printf("Course added successfully!\n");
                    break;
                }
            }
            fseek(file, -1 * (strlen(currentStudent.name) + strlen(currentStudent.id) + 14), SEEK_CUR);
            fprintf(file, "%s %s %.2f", currentStudent.name, currentStudent.id, currentStudent.cgpa);
            for (int i = 0; i < 4; ++i) {
                fprintf(file, " %s", currentStudent.courses[i]);
            }
            fprintf(file, "\n");
            return;
        }
    }

    printf("Student not found!\n");
}

void remove_course(FILE *file, const char *id) {
    char buffer[MAX_NAME_LENGTH + MAX_ID_LENGTH + 14]; // 14 for CGPA, spaces, and newline
    struct Student currentStudent;

    rewind(file); // Move file pointer to the beginning

    while (fscanf(file, "%s %s %f", currentStudent.name, currentStudent.id, &currentStudent.cgpa) != EOF) {
        if (strcmp(currentStudent.id, id) == 0) {
            printf("Enter course to remove: ");
            char courseToRemove[MAX_COURSE_LENGTH];
            scanf("%s", courseToRemove);
            for (int i = 0; i < 4; ++i) {
                if (strcmp(currentStudent.courses[i], courseToRemove) == 0) {
                    strcpy(currentStudent.courses[i], "");
                    printf("Course removed successfully!\n");
                    break;
                }
            }
            fseek(file, -1 * (strlen(currentStudent.name) + strlen(currentStudent.id) + 14), SEEK_CUR);
            fprintf(file, "%s %s %.2f", currentStudent.name, currentStudent.id, currentStudent.cgpa);
            for (int i = 0; i < 4; ++i) {
                fprintf(file, " %s", currentStudent.courses[i]);
            }
            fprintf(file, "\n");
            return;
        }
    }

    printf("Student not found!\n");
}/*
#include "student_operations.h"
#include <string.h>

void view_student_profile(FILE *file, const char *id) {
    struct Student student;

    rewind(file); // Move file pointer to the beginning

    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (strcmp(student.id, id) == 0) {
            printf("Name: %s\n", student.name);
            printf("ID: %s\n", student.id);
            printf("CGPA: %.2f\n", student.cgpa);
            if (strcmp(student.courses[0], "") != 0) {
                printf("Courses:\n");
                for (int i = 0; i < 4; ++i) {
                    if (strcmp(student.courses[i], "") != 0) {
                        printf("- %s\n", student.courses[i]);
                    }
                }
            } else {
                printf("No courses yet.\n");
            }
            return;
        }
    }

    printf("Student not found!\n");
}

void add_course(FILE *file, const char *id) {
    struct Student student;

    rewind(file); // Move file pointer to the beginning

    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (strcmp(student.id, id) == 0) {
            printf("Enter course to add: ");
            char newCourse[MAX_COURSE_LENGTH];
            scanf("%s", newCourse);
            for (int i = 0; i < 4; ++i) {
                if (strcmp(student.courses[i], "") == 0) {
                    strcpy(student.courses[i], newCourse);
                    printf("Course added successfully!\n");
                    fseek(file, -sizeof(struct Student), SEEK_CUR);
                    fwrite(&student, sizeof(struct Student), 1, file);
                    return;
                }
            }
            printf("Maximum courses limit reached!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

void remove_course(FILE *file, const char *id) {
    struct Student student;

    rewind(file); // Move file pointer to the beginning

    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (strcmp(student.id, id) == 0) {
            printf("Enter course to remove: ");
            char courseToRemove[MAX_COURSE_LENGTH];
            scanf("%s", courseToRemove);
            for (int i = 0; i < 4; ++i) {
                if (strcmp(student.courses[i], courseToRemove) == 0) {
                    strcpy(student.courses[i], "");
                    printf("Course removed successfully!\n");
                    fseek(file, -sizeof(struct Student), SEEK_CUR);
                    fwrite(&student, sizeof(struct Student), 1, file);
                    return;
                }
            }
            printf("Course not found!\n");
            return;
        }
    }

    printf("Student not found!\n");
}
/**/
#include "student_operations.h"
#include <string.h>

void view_student_profile(FILE *file, const char *id) {
    struct Student student;

    rewind(file); // Move file pointer to the beginning

    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (strcmp(student.id, id) == 0) {
            printf("Name: %s\n", student.name);
            printf("ID: %s\n", student.id);
            printf("CGPA: %.2f\n", student.cgpa);
            if (strcmp(student.courses[0], "") != 0) {
                printf("Courses:\n");
                for (int i = 0; i < 4; ++i) {
                    if (strcmp(student.courses[i], "") != 0) {
                        printf("- %s\n", student.courses[i]);
                    }
                }
            } else {
                printf("No courses yet.\n");
            }
            return;
        }
    }

    printf("Student not found!\n");
}

void add_course(FILE *file, const char *id) {
    struct Student student;

    rewind(file); // Move file pointer to the beginning

    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (strcmp(student.id, id) == 0) {
            printf("Enter course to add: ");
            char newCourse[MAX_COURSE_LENGTH];
            scanf("%s", newCourse);
            for (int i = 0; i < 4; ++i) {
                if (strcmp(student.courses[i], "") == 0) {
                    strcpy(student.courses[i], newCourse);
                    printf("Course added successfully!\n");
                    fseek(file, -sizeof(struct Student), SEEK_CUR);
                    fwrite(&student, sizeof(struct Student), 1, file);
                    return;
                }
            }
            printf("Maximum courses limit reached!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

void remove_course(FILE *file, const char *id) {
    struct Student student;

    rewind(file); // Move file pointer to the beginning

    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (strcmp(student.id, id) == 0) {
            printf("Enter course to remove: ");
            char courseToRemove[MAX_COURSE_LENGTH];
            scanf("%s", courseToRemove);
            for (int i = 0; i < 4; ++i) {
                if (strcmp(student.courses[i], courseToRemove) == 0) {
                    strcpy(student.courses[i], "");
                    printf("Course removed successfully!\n");
                    fseek(file, -sizeof(struct Student), SEEK_CUR);
                    fwrite(&student, sizeof(struct Student), 1, file);
                    return;
                }
            }
            printf("Course not found!\n");
            return;
        }
    }

    printf("Student not found!\n");
}


