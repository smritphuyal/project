#include <stdio.h>
#include <stdlib.h>

// Structure to represent a student
typedef struct {
    char name[50];
    int ID;
    int roll;
    char grade;
} Student;

// Function prototypes
void addStudent();
void removeStudent();
void searchStudent();
void showStudent();
void ask();

// Function to add a student to the database
void addStudent() {
    FILE *fptr;
    fptr = fopen("file.txt", "a"); // Open file in append mode

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Student newStudent;

    // Get student details from user
    printf("Student name: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Enter student ID: ");
    scanf("%d", &newStudent.ID);
    printf("Enter student Roll: ");
    scanf("%d", &newStudent.roll);
    printf("Enter student grade: ");
    scanf(" %c", &newStudent.grade); // Added space before %c

    // Write student details to file
    fprintf(fptr, "%d\t%s\t%d\t%c\n", newStudent.ID, newStudent.name, newStudent.roll, newStudent.grade);

    fclose(fptr);
    printf("\n");
    //clears input buffer
    fflush(stdin);
    // Open ask function
    ask();
}

// Function to remove a student from the database
void removeStudent() {
    // Opening files
    FILE *fptr, *temp;
    fptr = fopen("file.txt", "r");
    temp = fopen("temp.txt", "w");

    // Show error message if file is empty
    if (fptr == NULL || temp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Asking user for ID to remove
    int removeID;
    printf("Enter student ID to remove: ");
    scanf("%d", &removeID);

    Student currentStudent;

    while (fscanf(fptr, "%d\t%s\t%d\t%c", &currentStudent.ID, currentStudent.name, &currentStudent.roll, &currentStudent.grade) != EOF) {
        if (currentStudent.ID != removeID) {
            fprintf(temp, "%d\t%s\t%d\t%c\n", currentStudent.ID, currentStudent.name, currentStudent.roll, currentStudent.grade);
        }
    }

    fclose(fptr);
    fclose(temp);

    remove("file.txt");
    rename("temp.txt", "file.txt");
    printf("\n");
    //clears input buffer
    fflush(stdin);
    // Open ask function
    ask();
}

// Function to search for a student in the database
void searchStudent() {
    FILE *fptr;
    fptr = fopen("file.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int searchID;
    printf("Enter student ID to search: ");
    scanf("%d", &searchID);

    Student currentStudent;

    while (fscanf(fptr, "%d\t%s\t%d\t%c", &currentStudent.ID, currentStudent.name, &currentStudent.roll, &currentStudent.grade) != EOF) {
        if (currentStudent.ID == searchID) {
            printf("Student found: %d %s %d %c\n", currentStudent.ID, currentStudent.name, currentStudent.roll, currentStudent.grade);
            fclose(fptr);
            return;
        }
    }

    printf("Student not found.\n");
    fclose(fptr);
    printf("\n");
    
        //clears input buffer 
    fflush(stdin);
    // Call ask function
    ask();
}

// Function to show all students' information
void showStudent() {
    FILE *fptr;
    fptr = fopen("file.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Student currentStudent;

    while (fscanf(fptr, "%d\t%s\t%d\t%c", &currentStudent.ID, currentStudent.name, &currentStudent.roll, &currentStudent.grade) != EOF) {
        printf("ID: %d, Name: %s, Roll: %d, Grade: %c\n", currentStudent.ID, currentStudent.name, currentStudent.roll, currentStudent.grade);
    }

    fclose(fptr);

    printf("\n");
        //clears input buffer 
    fflush(stdin);
    // Call ask function
    ask();
}

// Function to ask the user for options
void ask() {
    int n;
    printf("Enter 1 to add student, 2 to remove student, 3 to show all student info, 4 to search student, and 5 to exit: ");
    scanf("%d", &n);
    printf("\n");
    switch (n) {
        case 1:
            addStudent();
            break;
        case 2:
            removeStudent();
            break;
        case 3:
            showStudent();
            break;
        case 4:
            searchStudent();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid option\n");
            break;
    }
}

// Main function
int main() {
    ask();
    return 0;
}
