#include <stdio.h>
struct student {
    char name[50];
    int age;
    float gpa;  
};
int main(){
    struct student s1;
    printf("Enter name: ");
    scanf("%s", s1.name);
    printf("Enter age: ");
    scanf("%d", &s1.age);
    printf("Enter GPA: ");
    scanf("%f", &s1.gpa);

    printf("\nStudent Information:\n");
    printf("Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("GPA: %.2f\n", s1.gpa);

    return 0;
}