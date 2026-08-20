#include<stdio.h>

struct Address {
    char street[50];
    char city[50];
    char state[50];
    int zip;
};

struct student {
    char name[50];
    int roll_no;
    float cgp;
    struct Address addr; // Nested structure
} stu[100];

int main(){
    int i, n;
    printf("Enter the number of students to enter: ");
    scanf("%d", &n);

    for (i = 0 ; i < n ; i++){
        printf("\n Enter the details of student %d ", i + 1);
        printf("\n Enter name : ");
        scanf("%s", stu[i].name);   
        printf(" Enter roll number : ");
        scanf("%d", &stu[i].roll_no);
        printf(" Enter CGPA : ");
        scanf("%f", &stu[i].cgp);
        
        // Input for nested structure
        printf(" Enter street address : ");
        scanf("%s", stu[i].addr.street);
        printf(" Enter city : ");
        scanf("%s", stu[i].addr.city);
        printf(" Enter state : ");
        scanf("%s", stu[i].addr.state);
        printf(" Enter zip code : ");
        scanf("%d", &stu[i].addr.zip);
    }

    printf("\n\n Student Information : \n");
    for (i = 0 ; i < n ; i++){
        printf("\n Details of student %d ", i + 1);
        printf("\n Name : %s", stu[i].name);
        printf("\n Roll number : %d", stu[i].roll_no);
        printf("\n CGPA : %.2f", stu[i].cgp);
        
        // Output for nested structure
        printf("\n Address: %s, %s, %s - %d", stu[i].addr.street, stu[i].addr.city, stu[i].addr.state, stu[i].addr.zip);
        printf("\n");
    }
}