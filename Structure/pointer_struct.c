#include <stdio.h>
struct student {
    char name[20];
    int rollno;
    float cpi;
};
int main()
{
    struct student *studPtr, stud1;
    studPtr = &stud1;
    printf("Enter Name: ");
    scanf("%s", studPtr->name);
    printf("Enter RollNo: ");
    scanf("%d", &studPtr->rollno);
    printf("Enter CPI: ");
    scanf("%f", &studPtr->cpi);
    printf("\nStudent Details:\n");
    printf("Name: %s\n", studPtr->name);
    printf("RollNo: %d", studPtr->rollno);
    printf("\n CPI: %f", studPtr->cpi);
    return 0;
}