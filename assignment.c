#include <stdio.h>
#include <stdlib.h>
#include <string.h>

                     /*******        HungkqHe190895      *******/
                            /*  Requirement: users.txt  */
            
/*  login information 
    username: hunghihi
    password: 123456 */

// information of user
typedef struct { 
    char username[30];
    char password[30];
} User;

//features
void clear_console();
void wait_for_keypress();
int login();

//main functions
void create_user();
void read_users();
void update_user();
void delete_user();
void delete_all_users();

//check functions
int check_username_exists(const char *username);
int isFileEmpty(FILE *file); 

int main() {
    clear_console();
    //login menu
    printf("\t\t\t\t LOGIN MENU \t\t\t\t\n");
    do {                      
        login();
    } while(!login());
    clear_console();
    // menu
    while(1) {
        clear_console();
        int choice, check;
        printf("\n\t\t\t\t*** User Password Management Menu ***\n");
        printf("1. Create User\n");
        printf("2. Read Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Delete All Users\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        //check valid input
        do {
            printf("Enter an integer (1 to 6): ");
            check = scanf("%d", &choice); // return 1 if scanf successfully

            while (check != 1) {
                fflush(stdin);  // clear the input buffer
                printf("Input must be an integer (1 to 6): ");
                check = scanf("%d", &choice);
            }

        } while (!check);

    printf("You entered: %d\n", choice);
        
        
        switch(choice) {
            case 1:
                clear_console();
                create_user();
                wait_for_keypress();
                break;
            case 2:
                clear_console();
                read_users();
                wait_for_keypress();
                break;
            case 3:
                clear_console();
                update_user();
                wait_for_keypress();
                break;
            case 4:
                clear_console();
                delete_user();
                wait_for_keypress();
                break;
            case 5:
                clear_console();
                delete_all_users();
                wait_for_keypress();
                break;
            case 6:
                clear_console();
                printf("Existing program!!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
            
        }
    }
    //fclose(fp);

    return 0;
}

void clear_console() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void wait_for_keypress() {
    printf("Press any key to continue...\n");
    int c;
    fflush(stdin); // clear input buffer
    getchar();
}

void create_user() {
    
    User user;
    printf("Enter username: ");
    scanf("%s", user.username);
    printf("Enter password: ");
    scanf("%s", user.password);

    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    fprintf(file, "%s %s\n", user.username, user.password);
    fclose(file);
    
    
}

void read_users() {
    FILE *file = fopen("users.txt", "r"); 
    char username[30];
    char password[30];

    if (file == NULL) {   //check if file not exist 
        printf("Unable to open file.\n");
        return;
    }

    if (isFileEmpty(file)) {   //check empty
        printf("File is empty.\n");
        fclose(file);

    }
    // Reset the file pointer to begin
    rewind(file);
        // read username and password line by line 
    while (fscanf(file, "%s %s\n", username, password) != EOF) {
        printf("Username: %s || Password: %s\n", username, password);
    }

    fclose(file);
}

void update_user() {
    char old_username[30];
    User new_user;  //struct
    FILE *check = fopen("users.txt", "r");
   
    if (isFileEmpty(check)) {
        printf("File is empty.\n");
        return;
    }
   
    fclose(check);
    // Reset the file pointer to begin
    rewind(check);
    printf("Enter the username of the user you want to update: ");
    scanf("%s", old_username);
        // check username existence
    if (!check_username_exists(old_username)) { 
        printf("Username not found!\n");
        return;
    }
    //reset username and password
    printf("Enter new username: ");
    scanf("%s", new_user.username);
    printf("Enter new password: ");
    scanf("%s", new_user.password);

    FILE *file = fopen("users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char username[30];
    char password[30];

    if (file == NULL || temp == NULL) {
        printf("Unable to open file.\n");
        return;
    }
     //update new user name, password to temp.txt
    while (fscanf(file, "%s %s\n", username, password) != EOF) {\
        if (strcmp(username, old_username) == 0) {
            fprintf(temp, "%s %s\n", new_user.username, new_user.password);
        } else {
            fprintf(temp, "%s %s\n", username, password);
        }
    }

    fclose(file);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt", "users.txt"); // rename file
}

void delete_user() {
    char username[30]; //username to delete
    FILE *check = fopen("users.txt", "r");
   
    if (isFileEmpty(check)) {
        printf("File is empty.\n");
        return;
    }
   
    fclose(check);
    // Reset the file pointer to begin
    rewind(check);

    printf("Enter the username of the user you want to delete: ");
    scanf("%s", username);
    //check exist 
    if (!check_username_exists(username)) {
        printf("Username not found!\n");
        return;
    }

    FILE *file = fopen("users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char current_username[30];
    char password[30];

    if (file == NULL || temp == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    while (fscanf(file, "%s %s\n", current_username, password) != EOF) {
        if (strcmp(current_username, username) != 0) {
            fprintf(temp, "%s %s\n", current_username, password);
        } //only write username doesn't match the username u want to delete
    }

    fclose(file);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt", "users.txt");  //rename file 
    printf("Delete successfully!!\n");
}

void delete_all_users() {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }
    fclose(file);
    printf("All users have been deleted.\n");
}

int check_username_exists(const char *username) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }
    char current_username[30];
    char password[30];

    while (fscanf(file, "%s %s\n", current_username, password) != EOF) {
        if (strcmp(current_username, username) == 0) {
            fclose(file);
            return 1; // Username found
        }
    }

    fclose(file);
}

int isFileEmpty(FILE *file) {
    fseek(file, 0, SEEK_END);
    //if file is empty
    if (ftell(file) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int login()
{   
    // default login
    const char* real_username = "hunghihi";
    const char* real_password = "123456";
    char name[20];
    char password[10];

    printf("Enter username: ");
    scanf("%s",name);
    printf("Enter password: ");
    scanf("%s",password);
    // login check
    if (strcmp(name, real_username) == 0 && strcmp(password, real_password) == 0)
    {
        printf("Access granted\n");
        return 1;
    }
    
    printf("Access denied\n");
    return 0;
        
}