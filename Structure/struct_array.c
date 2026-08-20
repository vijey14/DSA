#include<stdio.h>
struct student{
    char name[50];
    int roll_no;
    float cgp;
}stu[100];


int main(){
    int i, n;
    printf("Enter the number of student to enter: ");
    scanf("%d", &n);

    for (i = 0 ; i < n ; i++){
        printf("\n Enter the detail of %d student ", i + 1);
        printf("\n Enter name : ");
        scanf("%s", stu[i].name);   
        printf(" Enter roll number : ");
        scanf("%d", &stu[i].roll_no);
        printf(" Enter CGPA : ");
        scanf("%f", &stu[i].cgp);
    }

    printf("\n\n Student Information : \n");
    for (i = 0 ; i < n ; i++){
        printf("\n Detail of %d student ", i + 1);
        printf("\n Name : %s", stu[i].name);
        printf("\n Roll number : %d", stu[i].roll_no);
        printf("\n CGPA : %.2f", stu[i].cgp);
        printf("\n");
    }
}


