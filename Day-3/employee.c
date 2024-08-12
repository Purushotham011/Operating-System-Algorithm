// create an employee structure with the following members:empname, empid, empdept, empsalary. Create an employee structure variable and store the values in it and print the values of the structure variable
#include <stdio.h>
struct Employee
{
    char empname[50];
    int empid;
    char empdept[50];
    float empsalary;
} emp1[3];
int main()
{
    for (int i = 0; i < 3; i++)
    {
        printf("Enter the name of the employee: ");
        scanf("%s", emp1[i].empname);
        printf("Enter the employee ID of the employee: ");
        scanf("%d", &emp1[i].empid);
        printf("Enter the department of the employee: ");
        scanf("%s", emp1[i].empdept);
        printf("Enter the salary of the employee: ");
        scanf("%f", &emp1[i].empsalary);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s\n", emp1[i].empname);
        printf("Employee ID: %d\n", emp1[i].empid);
        printf("Department: %s\n", emp1[i].empdept);
        printf("Salary: %.2f\n", emp1[i].empsalary);
    }
    return 0;
}