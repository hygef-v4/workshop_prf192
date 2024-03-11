#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
                                // array of name string 
void addStudent(char students[MAX_STUDENTS][MAX_NAME_LENGTH] , int *count); 
void removeStudent(char students[MAX_STUDENTS][MAX_NAME_LENGTH], int *count);
void searchStudent(char students[MAX_STUDENTS][MAX_NAME_LENGTH], int count);
void printList(char students[MAX_STUDENTS][MAX_NAME_LENGTH], int count);
void removeExtraBlanks(char *string);

int main() {
    char students[MAX_STUDENTS][MAX_NAME_LENGTH];
    int count = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1- Add a student\n");
        printf("2- Remove a student\n");
        printf("3- Search a student\n");
        printf("4- Print the list in ascending order\n");
        printf("5- Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        //clear input buffer

        switch(choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                removeStudent(students, &count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printList(students, count);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent(char students[MAX_STUDENTS][MAX_NAME_LENGTH], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. The list is full.\n");
        return;
    }

    printf("Enter student name: ");
    fgets(students[*count], MAX_NAME_LENGTH, stdin);

    // Remove extra blanks
    removeExtraBlanks(students[*count]);

    // Convert to uppercase
    for (int i = 0; students[*count][i]; i++) {
        students[*count][i] = toupper(students[*count][i]);
    }
    strtok(students[*count], "\n"); // Remove newline character

    (*count)++;
    printf("Student added successfully.\n");
}

void removeStudent(char students[MAX_STUDENTS][MAX_NAME_LENGTH], int *count) {
    if (*count == 0) {
        printf("No students to remove.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the student to remove: ");
    fgets(name, MAX_NAME_LENGTH, stdin);

    // Remove extra blanks
    removeExtraBlanks(name);

    // Convert to uppercase
    for (int i = 0; name[i]; i++) {
        name[i] = toupper(name[i]);
    }
    strtok(name, "\n"); // Remove newline character

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(students[i], name) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                strcpy(students[j], students[j + 1]);
            }
            (*count)--;
            printf("Student removed successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

void searchStudent(char students[MAX_STUDENTS][MAX_NAME_LENGTH], int count) {
    if (count == 0) {
        printf("No students to search.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the student to search: ");
    fgets(name, MAX_NAME_LENGTH, stdin);

    // Remove extra blanks
    removeExtraBlanks(name);

    // Convert to uppercase
    for (int i = 0; name[i]; i++) {
        name[i] = toupper(name[i]);
    }
    strtok(name, "\n"); // Remove newline character

    int found = 0;
    for (int i = 0; i < count; i++) {
         //compare names 
        if (strcmp(students[i], name) == 0) {
            found = 1;
            printf("Student found at number %d.\n", i+1);
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

void printList(char students[MAX_STUDENTS][MAX_NAME_LENGTH], int count) {
    if (count == 0) {
        printf("No students to print.\n");
        return;
    }

    // Sort the names in ascending order 
    // bubble sort 
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(students[j], students[j + 1]) > 0) {
                char temp[MAX_NAME_LENGTH];
                // swap string 
                strcpy(temp, students[j]);
                strcpy(students[j], students[j + 1]);
                strcpy(students[j + 1], temp);
            }
        }
    }

    printf("List of students in ascending order:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, students[i]);
    }
}

void removeExtraBlanks(char *string) {
    int i,j;
    int len = strlen(string);
    for(i=0; i<len; i++){
   if(string[0]==' '){
      for(i=0; i<(len-1); i++)
      string[i] = string[i+1];
      string[i] = '\0';
      len--;
      i = -1;
      continue;
   }
   if(string[i]==' ' && string[i+1]==' '){
      for(j=i; j<(len-1); j++){
         string[j] = string[j+1];
      }
      string[j] = '\0';
      len--;
      i--;
   }
}
}
