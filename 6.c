#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//information
typedef struct {
    char name[50];
    char address[100];
    int mark;
} Student;

int compare(const void *a, const void *b) {
    return ((Student *)b)->mark - ((Student *)a)->mark; 
    // compare marks between 2 students
}

int main() {
    FILE *fp = fopen("students.txt", "r"); // open students.txt
    Student students[100];
    int i = 0;

    while (fscanf(fp, "%[^;];%[^;];%d\n", students[i].name, students[i].address, &students[i].mark) !=EOF) {   // read from file 
        i++;
    }

    int n = i;
    qsort(students, n, sizeof(Student), compare); // quick sort 

    fp = fopen("students_2.txt", "w");
    for (i = 0; i < n; i++) {   // write to file 
        fprintf(fp, "%s;%s;%d\n", students[i].name, students[i].address, students[i].mark);
    }

    fclose(fp);
    return 0;
}
