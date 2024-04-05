#include <stdio.h>
#include <stdlib.h>
#include "student_portal.h"
#include "admin_operations.h"
#include "student_operations.h"
#include "faculty_operations.h"

int main() {
    FILE *student_file;
    FILE *faculty_file;
    char student_id[MAX_ID_LENGTH];
    char student_password[MAX_PASSWORD_LENGTH];
    char faculty_id[MAX_ID_LENGTH];
    char faculty_password[MAX_PASSWORD_LENGTH];
    int choice;


    student_file = fopen("students.txt", "a+");
    if (student_file == NULL) {
        printf("Error opening student file!\n");
        return 1;
    }


    faculty_file = fopen("faculty.txt", "a+");
    if (faculty_file == NULL) {
        printf("Error opening faculty file!\n");
        return 1;
    }

    do {
        printf("\nMenu:\n");
        printf("1. Student\n");
        printf("2. Faculty\n");
        printf("3. Admin\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nStudent Portal:\n");
                printf("1. Student Sign Up\n");
                printf("2. Student Login\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        student_signup(student_file);
                        break;
                    case 2:
                        printf("Enter your student id: ");
                        scanf("%s", student_id);
                        printf("Enter your password: ");
                        scanf("%s", student_password);
                        student_login(student_file, student_id, student_password);
                        printf("\n");
                        if (student_login(student_file, student_id, student_password)) {
                            printf("1. View Profile\n");
                            printf("2. Add Course\n");
                            printf("3. Remove Course\n");
                            printf("Enter your choice: ");
                            scanf("%d", &choice);
                            switch (choice) {
                                case 1:
                                    view_student_profile(student_file, student_id);
                                    break;
                                case 2:
                                    add_course(student_file, student_id);
                                    break;
                                case 3:
                                    remove_course(student_file, student_id);
                                    break;
                                default:
                                    printf("Invalid choice!\n");
                            }
                        }
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 2:
                printf("\nFaculty Portal:\n");
                printf("1. Faculty Sign Up\n");
                printf("2. Faculty Login\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        faculty_signup(faculty_file);
                        break;
                    case 2:
                        printf("Enter your faculty id: ");
                        scanf("%s", faculty_id);
                        printf("Enter your password: ");
                        scanf("%s", faculty_password);
                        faculty_login(faculty_file, faculty_id, faculty_password);
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 3:
                printf("\nAdmin Panel:\n");
                admin_login();
                printf("1. Add Student\n");
                printf("2. Remove Student\n");
                printf("3. Add Faculty\n");
                printf("4. Remove Faculty\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        add_student(student_file);
                        break;
                    case 2:
                        printf("Enter student id to remove: ");
                        scanf("%s", student_id);
                        remove_student(student_file, student_id);
                        break;
                    case 3:
                        add_faculty(faculty_file);
                        break;
                    case 4:
                        printf("Enter faculty id to remove: ");
                        scanf("%s", faculty_id);
                        remove_faculty(faculty_file, faculty_id);
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    fclose(student_file);
    fclose(faculty_file);
    return 0;
}
