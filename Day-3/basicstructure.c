// create a structure variable and store the values in it and print the values of the structure variable
#include <stdio.h>
struct Person
{
    char name[50];
    int citizen_id;
    int age;
    float salary;
} person1;
int main()
{
    printf("Enter the name of the person: ");
    scanf("%s", person1.name);
    printf("Enter the citizen ID of the person: ");
    scanf("%d", &person1.citizen_id);
    printf("Enter the age of the person: ");
    scanf("%d", &person1.age);
    printf("Enter the salary of the person: ");
    scanf("%f", &person1.salary);
    printf("Name: %s\n", person1.name);
    printf("Citizen ID: %d\n", person1.citizen_id);
    printf("Age: %d\n", person1.age);
    printf("Salary: %.2f\n", person1.salary);
    return 0;
}