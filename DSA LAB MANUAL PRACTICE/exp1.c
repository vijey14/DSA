#include <stdio.h>
#include<stdlib.h>

struct student
{
  int reg_no;
  char name[50];
  float mark1, mark2, mark3;
};

int main(){
    struct student s1;
    float total, avg;

    printf("Enter reg_no: ");
    scanf("%d", &s1.reg_no);
    printf("Enter name: ");
    scanf("%s", &s1.name);
    printf("Enter mark1: ");
    scanf("%f", &s1.mark1);
    printf("Enter mark2: ");
    scanf("%f", &s1.mark2);
    printf("Enter mark3: ");
    scanf("%f", &s1.mark3);


    total = s1.mark1 + s1.mark1 + s1.mark3;
    avg = total / 3;

    printf("\nStudent Details\n");
    printf("Register Number: %d\n", s1.reg_no);
    printf("Student Name: %s\n", s1.name);
    printf("Subject 1 Marks: %.2f\n", s1.mark1);
    printf("Subject 2 Marks: %.2f\n", s1.mark2);
    printf("Subject 3 Marks: %.2f\n", s1.mark3);
    printf("Total Marks: %.2f\n", total);
    printf("Average Marks: %.2f\n", avg);

    return 0;
}
