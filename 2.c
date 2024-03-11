#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define MAX_EMPLOYEES 100       // extra 1 for null terminator 
#define MAX_CODE_LENGTH 9
#define MAX_NAME_LENGTH 21

typedef struct {       // information 
    char code[MAX_CODE_LENGTH];
    char name[MAX_NAME_LENGTH];
    int salary;
    int allowance;
} Employee;

int menu() {
    int choice;
    
    printf("1- Add a new employee\n");
    printf("2- Search for an employee by name\n");
    printf("3- Remove an employee\n");
    printf("4- Print the list in descending order\n");
    printf("5- Quit\n");
    
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    fflush(stdin);
    return choice;
}

void addEmployee(Employee employees[], int *n) {
    if (*n == MAX_EMPLOYEES) {
        printf("\nSorry! The list is full!\n");
        return;
    }

    printf("\nEnter Employee Information:\n");
    printf("Employee Code(max 8): ");
    scanf(" %8s", employees[*n].code); // max 8 characters
    printf("Employee Name: ");
    scanf(" %20[^\n]", employees[*n].name); // max 20 characters
    printf("Employee Salary (VND): ");
    scanf("%d", &employees[*n].salary);
    printf("Employee Allowance (VND): ");
    scanf("%d", &employees[*n].allowance);

    (*n)++;
    printf("\nEmployee added successfully!\n");
}

void printEmployee(Employee emp) {
    printf("Code: %s\n", emp.code);
    printf("Name: %s\n", emp.name);
    printf("Salary: %d VND\n", emp.salary);
    printf("Allowance: %d VND\n", emp.allowance);
}

void searchEmployeeByName(Employee employees[], int n) {
    char searchName[MAX_NAME_LENGTH];
    printf("\nEnter the name of the employee you want to find: ");
    scanf(" %20[^\n]", searchName);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcasecmp(employees[i].name, searchName) == 0) { // Case-insensitive comparison
            printf("\nEmployee found:\n");
            printEmployee(employees[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee not found!\n");
    }
}

void removeEmployee(Employee employees[], int *n) {
    char removeCode[MAX_CODE_LENGTH];
    printf("\nEnter the code of the employee you want to remove: ");
    scanf(" %8s", removeCode);

    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (strcmp(employees[i].code, removeCode) == 0) {
            for (int j = i; j < *n - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*n)--;
            found = 1;
            printf("\nEmployee removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee not found!\n");
    }
}

void printEmployeesDescending(Employee employees[], int n) {
    // Sort the array of employees in descending order based on salary + allowance
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int total1 = employees[j].salary + employees[j].allowance;
            int total2 = employees[j + 1].salary + employees[j + 1].allowance;
            if (total1 < total2) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }

    printf("\nEmployees in descending order based on salary + allowance:\n");
    for (int i = 0; i < n; i++) {
        printEmployee(employees[i]);
        printf("\n");
    }
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;
    int choice;

    do {
        choice = menu();
        switch (choice) {
            case 1:
                addEmployee(employees, &numEmployees);
                break;
            case 2:
                if (numEmployees > 0) {
                    searchEmployeeByName(employees, numEmployees);
                } else {
                    printf("\nNo employees to search!\n");
                }
                break;
            case 3:
                if (numEmployees > 0) {
                    removeEmployee(employees, &numEmployees);
                } else {
                    printf("\nNo employees to remove!\n");
                }
                break;
            case 4:
                if (numEmployees > 0) {
                    printEmployeesDescending(employees, numEmployees);
                } else {
                    printf("\nNo employees to print!\n");
                }
                break;
            case 5:
                printf("\nExisting!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
