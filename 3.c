#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_DRINKS 100
#define MAX_NAME_LENGTH 21 // Including null terminator

// struct to store soft drink data
struct SoftDrink {
    char name[MAX_NAME_LENGTH];
    char make[MAX_NAME_LENGTH];
    int volume;
    int price;
    int duration;
};

// Function prototypes
int menu();
void addSoftDrink(struct SoftDrink[], int*);
void printByMake(const struct SoftDrink[], int, const char[]);
void printByVolumeRange(const struct SoftDrink[], int, int, int);
void printAscendingOrder(const struct SoftDrink[], int);

int main() {
    struct SoftDrink drinks[MAX_DRINKS];
    int numDrinks = 0;
    int choice;

    do {
        choice = menu();

        switch (choice) {
            case 1:
                addSoftDrink(drinks, &numDrinks);
                break;
            case 2: {
                char make[MAX_NAME_LENGTH];
                printf("Enter the make to filter: ");
                scanf("%20s", make);
                printByMake(drinks, numDrinks, make);
                break;
            }
            case 3: {
                int minVol, maxVol;
                printf("Enter the volume range (min max): ");
                scanf("%d %d", &minVol, &maxVol);
                printByVolumeRange(drinks, numDrinks, minVol, maxVol);
                break;
            }
            case 4:
                printAscendingOrder(drinks, numDrinks);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Display menu and get user's choice
int menu() {
    int choice;

    printf("\n====================== MENU ======================\n");
    printf("1. Add a new soft drink\n");
    printf("2. Print items by make\n");
    printf("3. Print items by volume range\n");
    printf("4. Print list in ascending order by volume then price\n");
    printf("5. Quit\n");
    printf("==================================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume newline character

    return choice;
}

// Function to add a new soft drink
void addSoftDrink(struct SoftDrink drinks[], int* numDrinks) {
    if (*numDrinks >= MAX_DRINKS) {
        printf("Sorry, the maximum number of drinks has been reached.\n");
        return;
    }

    struct SoftDrink newDrink;

    printf("Enter drink name: ");
    fgets(newDrink.name, MAX_NAME_LENGTH, stdin);
    newDrink.name[strcspn(newDrink.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter make: ");
    fgets(newDrink.make, MAX_NAME_LENGTH, stdin);
    newDrink.make[strcspn(newDrink.make, "\n")] = '\0'; // Remove trailing newline

    printf("Enter volume (ml): ");
    scanf("%d", &newDrink.volume);

    printf("Enter price (VND): ");
    scanf("%d", &newDrink.price);

    printf("Enter duration (days): ");
    scanf("%d", &newDrink.duration);

    drinks[*numDrinks] = newDrink;
    (*numDrinks)++;
}

// Function to print items by make
void printByMake(const struct SoftDrink drinks[], int numDrinks, const char make[]) {
    int found = 0;

    printf("\nItems with make '%s':\n", make);
    for (int i = 0; i < numDrinks; ++i) {
        if (strcmp(drinks[i].make, make) == 0) {
            printf("Name: %s\n", drinks[i].name);
            printf("Volume: %d ml\n", drinks[i].volume);
            printf("Price: %d VND\n", drinks[i].price);
            printf("Duration: %d days\n", drinks[i].duration);
            found = 1;
        }
    }

    if (!found)
        printf("No items found with make '%s'\n", make);
}

// Function to print items by volume range
void printByVolumeRange(const struct SoftDrink drinks[], int numDrinks, int minVol, int maxVol) {
    int found = 0;

    printf("\nItems with volume between %d ml and %d ml:\n", minVol, maxVol);
    for (int i = 0; i < numDrinks; ++i) {
        if (drinks[i].volume >= minVol && drinks[i].volume <= maxVol) {
            printf("Name: %s\n", drinks[i].name);
            printf("Make: %s\n", drinks[i].make);
            printf("Price: %d VND\n", drinks[i].price);
            printf("Duration: %d days\n", drinks[i].duration);
            printf("\n");
            found = 1;
        }
    }

    if (!found)
        printf("No items found within the specified volume range.\n");
}

//compare two soft drinks for sorting
int compareDrinks(const void* a, const void* b) {
    const struct SoftDrink* drinkA = (const struct SoftDrink*)a;
    const struct SoftDrink* drinkB = (const struct SoftDrink*)b;

    // Compare by volume first, then by price
    if (drinkA->volume != drinkB->volume)
        return drinkA->volume - drinkB->volume;
    else
        return drinkA->price - drinkB->price;
}

// print list in ascending order by volume then price
void printAscendingOrder(const struct SoftDrink drinks[], int numDrinks) {
    if (numDrinks == 0) {
        printf("No drinks to sort.\n");
        return;
    }

    // Make a copy of drinks array for sorting
    struct SoftDrink sortedDrinks[MAX_DRINKS];
    memcpy(sortedDrinks, drinks, numDrinks * sizeof(struct SoftDrink));

    // Sort the array
    qsort(sortedDrinks, numDrinks, sizeof(struct SoftDrink), compareDrinks);

    // Print the sorted list
    printf("\nList in ascending order by volume then price:\n");
    for (int i = 0; i < numDrinks; ++i) {
        printf("Name: %s\n", sortedDrinks[i].name);
        printf("Make: %s\n", sortedDrinks[i].make);
        printf("Volume: %d ml\n", sortedDrinks[i].volume);
        printf("Price: %d VND\n", sortedDrinks[i].price);
        printf("Duration: %d days\n", sortedDrinks[i].duration);
        printf("\n");
    }
}
