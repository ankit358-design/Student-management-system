#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold student information
struct Student {
    int roll_number;
    char name[50];
    float marks;
};

// Global array to store student records (for simplicity)
// In a real-world application, dynamic allocation or file handling would be used.
struct Student students[100];
int student_count = 0; // Tracks the number of students currently stored

// Function to add a new student
void add_student() {
    if (student_count < 100) {
        printf("Enter Roll Number: ");
        scanf("%d", &students[student_count].roll_number);
        printf("Enter Name: ");
        scanf("%s", students[student_count].name); // Use %s for string input
        printf("Enter Marks: ");
        scanf("%f", &students[student_count].marks);
        student_count++;
        printf("Student added successfully.\n");
    } else {
        printf("Maximum student limit reached.\n");
    }
}

// Function to display all student records
void display_students() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < student_count; i++) {
        printf("Roll Number: %d, Name: %s, Marks: %.2f\n",
               students[i].roll_number, students[i].name, students[i].marks);
    }
    printf("-----------------------\n");
}

// Function to search for a student by roll number
void search_student() {
    int roll_to_find;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll_to_find);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll_to_find) {
            printf("Student Found:\n");
            printf("Roll Number: %d, Name: %s, Marks: %.2f\n",
                   students[i].roll_number, students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll_to_find);
}

// Function to delete a student by roll number
void delete_student() {
    int roll_to_delete;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll_to_delete);

    int found_index = -1;
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll_to_delete) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        // Shift elements to the left to fill the gap
        for (int i = found_index; i < student_count - 1; i++) {
            students[i] = students[i + 1];
        }
        student_count--;
        printf("Student with Roll Number %d deleted successfully.\n", roll_to_delete);
    } else {
        printf("Student with Roll Number %d not found.\n", roll_to_delete);
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Delete Student by Roll Number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                delete_student();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}