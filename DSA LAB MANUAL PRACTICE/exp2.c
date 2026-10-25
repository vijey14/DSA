#include<stdio.h>
#include<stdlib.h>

struct Employee
{
    int emp_id;
    char name[50];
    float b_salary;

};


int main(){
    struct Employee *ptr;
    float hra, da, grossSalary;

    ptr = malloc(sizeof(struct Employee));

    if(ptr == NULL){
        printf("Memory allocation failed");
        return;
    }

    printf("Enter employee id: ");
    scanf("%d", &ptr->emp_id);

    printf("Enter name: ");
    scanf("%s", &ptr->name);

    printf("Enter the basic salary: ");
    scanf("%f", &ptr->b_salary);

    hra = ptr -> b_salary * 20 / 100;
    da = ptr -> b_salary * 10 / 100;
    
    grossSalary = ptr->b_salary + hra + da;

    printf("\nEmployee Details\n");
    printf("Employee ID: %d\n", ptr->emp_id);
    printf("Employee Name: %s\n", ptr->name);
    printf("Basic Salary: %.2f\n", ptr->b_salary);
    printf("HRA: %.2f\n", hra);
    printf("DA: %.2f\n", da);
    printf("Gross Salary: %.2f\n", grossSalary);

    free(ptr);

    return 0;

}