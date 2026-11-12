#include <stdio.h>

int main(void) {
    int marks;
    char grade;

    printf("Enter marks: ");
    scanf("%d", &marks);

    if (marks < 0 || marks > 100) {
        printf("Invalid marks\n");
        return 0;
    }

    if (marks >= 90) {
        grade = 'A';
    } else if (marks >= 75) {
        grade = 'B';
    } else if (marks >= 60) {
        grade = 'C';
    } else if (marks >= 40) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    printf("Grade: %c\n", grade);

    switch (grade) {
        case 'A': printf("Remark: Excellent\n"); break;
        case 'B': printf("Remark: Very good\n"); break;
        case 'C': printf("Remark: Good\n"); break;
        case 'D': printf("Remark: Pass\n"); break;
        case 'F': printf("Remark: Fail\n"); break;
    }

    return 0;
}