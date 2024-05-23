/*C Program to read and print the n employee details using structure and dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>
/*structure to hold the details of an employee*/
typedef struct employee
{
    int empId;
    char Name[100];
    char Designation[100];
    char Dept[10];

}employee_t;
/* Read the employee details using scanf*/
void readData(int n, employee_t* s)
{
    for (int i = 0; i < n; ++i) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &(s[i].empId));
        printf("Name: ");
        scanf("%s", s[i].Name);
        printf("Designation: ");
        scanf("%s", s[i].Designation);
        printf("Department: ");
        scanf("%s", s[i].Dept);
    }

}
/* Function to print the employee details*/
void display(int n, employee_t * s)
{
    for (int i = 0; i < n; ++i) {
        printf("\nDetails of employee %d:\n", i + 1);
        printf("Employee ID: %d\n", s[i].empId);
        printf("Name: %s\n", s[i].Name);
        printf("Designation: %s\n", s[i].Designation);
        printf("Department: %s\n", s[i].Dept);
    }    
}

/*----------Main Program--------*/
int main()

{
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Allocate memory dynamically for n employees
    employee_t* employees = (employee_t*)malloc(n * sizeof(employee_t));
    if (employees == NULL) {
        printf("Memory allocation failed.\n");
	return 1;
    }

    // Read employee details
    readData(n, employees);

    // Display employee details
    display(n, employees);

    // Free the allocated memory
    free(employees);

    return 0;
}
