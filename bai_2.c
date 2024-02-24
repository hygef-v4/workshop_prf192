/*Develop a C-program that helps user managing an 1-D array of real numbers(maximum of 100 elements) ,
with initial number of elements is 0, using the following simple menu:
1- Add a value
2- Search a value
3- Print out the array
4- Print out values in a range
5- Print out the array in ascending order
Others- Quit*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100        // max size of array 

// Function 
void addValue(float array[], int *size);    //using pointer to modify the size value outside function (main function)
void searchValue(float array[], int size);
void printArray(float array[], int size);
void printRange(float array[], int size, float minVal, float maxVal);
void sortAscending(float array[], int size);

int main() 
{
    float array[MAX_SIZE];      // array 
    int size = 0;               // array is empty
    int choice;                 
    float minVal, maxVal;       

    do {
        printf("\nSimple Menu:\n");
        printf("1- Add a value\n");
        printf("2- Search a value\n");
        printf("3- Print out the array\n");
        printf("4- Print out values in a range\n");
        printf("5- Print out the array in ascending order\n");
        printf("Others- Quit\n");
        printf("Enter your choice: ");
        //enter choice 
        scanf("%d", &choice);       

        switch (choice) {
            
            case 1:
                addValue(array, &size);     // pass by reference to size 
                break;
            
            case 2:
                if (size > 0)
                    searchValue(array, size);
                else                            // if size = 0 --> empty
                    printf("Array is empty!\n");
                break;
            
            case 3:
                if (size > 0)
                    printArray(array, size);
                else
                    printf("Array is empty!\n");
                break;
            
            case 4:
                if (size > 0) 
                {
                    printf("Enter min value: ");
                    scanf("%f", &minVal);
                    printf("Enter max value: ");
                    scanf("%f", &maxVal);

                    printRange(array, size, minVal, maxVal);
                } 
                
                else 
                {
                    printf("Array is empty!\n");
                }
                break;
            
            case 5:
                if (size > 0) 
                {
                    sortAscending(array, size);
                } 
                
                else 
                {
                    printf("Array is empty!\n");
                }
                break;
            default:
                printf("Exiting the program...\n");
                break;
        }
    } while (choice >= 1 && choice <= 5);

    return 0;
}

void addValue(float array[], int *size) 
{
    if (*size < MAX_SIZE) 
    {
        printf("Enter the value to add: ");
        scanf("%f", &array[*size]);
        (*size)++;
        printf("Value added successfully.\n");
    } 
    
    else 
    {
        printf("Array is full!\n");
    }
}

void searchValue(float array[], int size) 
{
    // print num of existences of a element 
    float value;
    int count = 0;

    printf("Enter the value to search: ");
    scanf("%f", &value);

    for (int i = 0; i < size; i++) 
    {
        if (array[i] == value)
            count++;
    }

    printf("Value %f found %d time(s) in the array.\n", value, count);
}

void printArray(float array[], int size) 
{   
    // print all elements of array
    printf("Array: ");
    for (int i = 0; i < size; i++) 
    {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

void printRange(float array[], int size, float minVal, float maxVal) 
{   
    // print value between min and max 
    printf("Values in range %.2f to %.2f: ", minVal, maxVal);
    for (int i = 0; i < size; i++) 
    {
        if (array[i] >= minVal && array[i] <= maxVal)
            printf("%.2f ", array[i]);
    }
    printf("\n");
}

void sortAscending(float array[], int size) 
{
    float *tempArray[MAX_SIZE]; // Array of pointers to float
    float temp;
    
    // each pointer to each element of original array 
    for (int i = 0; i < size; i++) 
    {
        tempArray[i] = &array[i];
    }
    
    // Bubble sort the pointers 
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - 1 - i; j++) 
        {
            if (*tempArray[j] > *tempArray[j + 1]) 
            {
                // Swap pointers (address of its destination pointing to)
                float *temp = tempArray[j];
                tempArray[j] = tempArray[j + 1];
                tempArray[j + 1] = temp;
            }
        }
    }
    
    // Print sorted array using original pointers
    printf("Array in ascending order: ");
    for (int i = 0; i < size; i++) 
    {
        printf("%.2f ", *tempArray[i]);
    }
    printf("\n");
}
