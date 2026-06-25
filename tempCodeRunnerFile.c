#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *fp = fopen("students.txt", "a");
    struct Student s;

    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student added successfully!\n");
}

void displayStudents() {
    FILE *fp = fopen("students.txt", "r");
    struct Student s;

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("\nID: %d\nName: %s\nMarks: %.2f\n", s.id, s.name, s.marks);
    }

    fclose(fp);
}

void searchStudent() 
    FILE *fp = fopen("students.txt", "r");
    struct Student s;
    int id, found = 0;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == i
            printf("\nFound!\nID: %d\nName: %s\nMarks: %.2f\n", s.id, s.name, s.marks);
            found = 1;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    fclose(fp);
}

void deleteStudent() {
    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct Student s;
    int id, found = 0;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id != id) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("Student deleted successfully!\n");
    else
        printf("Student not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Record Manager ---\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Delete Student\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}