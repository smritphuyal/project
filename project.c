#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void addStudent() {
    FILE *fptr;
    fptr = fopen("file.txt", "a"); // Open file in append mode

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char sn[50];
    int ID;

    // get name from user
    printf("Student name: ");
    scanf("%s", sn);

    // get student id from user
    printf("Enter student ID: ");
    scanf("%d", &ID);

    // show details
    fprintf(fptr, "%d %s\n", ID, sn);

    fclose(fptr);

   ask();
   printf("\n");
}

void removeStudent() {
    //opening files
    FILE *fptr, *temp;
    fptr = fopen("file.txt", "r");
    temp = fopen("temp.txt", "w");
//show error msg if file is empty
    if (fptr == NULL || temp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    //asking user for id to remove
    int removeID;
    printf("Enter student ID to remove: ");
    scanf("%d", &removeID);

    int ID;
    char sn[50];

    while (fscanf(fptr, "%d %s", &ID, sn) != EOF) {
        if (ID != removeID) {
            fprintf(temp, "%d %s\n", ID, sn);
        }
    }

    fclose(fptr);
    fclose(temp);

    remove("file.txt");
    rename("temp.txt", "file.txt");


    ask();
     printf("\n");
   
}

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

    int ID;
    char sn[50];

    while (fscanf(fptr, "%d %s", &ID, sn) != EOF) {
        if (ID == searchID) {
            printf("Student found: %d %s\n", ID, sn);
            fclose(fptr);
            return;
        }
    }

    printf("Student not found.\n");
    fclose(fptr);


   ask();
    printf("\n");
}

void showStudent() {
    FILE *fptr;
    fptr = fopen("file.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char info[100];
    while (fgets(info, sizeof(info), fptr) != NULL) {
        printf("%s", info);
    }

    fclose(fptr);


    ask();
     printf("\n");
    
}

void ask(){
    int n;
    printf("Enter 1 to add student, 2 to remove student, 3 to show all student info,  4 to search student and 5 to exit : ");
    scanf("%d", &n);

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

void main() {
   
ask();
//it took 6 hours to write
}
