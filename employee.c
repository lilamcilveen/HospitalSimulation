#include "employee.h"
#include "stdio.h"
#include "struct.h"

void printEmployee(PersonRec person)

{
    char temp[50];
    int pos = person.emp.position;
    long years = person.emp.yearsService;
    long dep = person.emp.department;
    float sal = person.emp.salary;

    float totSal = years * sal;

    char *fName = person.firstName;
    char *sName = person.familyName;

    sprintf(temp, "%s %s", fName, sName);
    printf("%-33s", temp);
    printf("dept: %lu salary: %.2f position: %d years of service: %lu salary to-date: %.2f\n", dep, sal, pos, years, totSal);

}

void printEmployees(PersonRec person[], int numRecords)
{
    printf("\n");
    printf("Hospital Employees\n");

    int i;
    for(i = 0; i < numRecords; i++) {
        if(person[i].emplyeeOrPatient == 0) {
            printEmployee(person[i]);
        }
    }
    printf("\n");
}


void printEmployeesSummary(PersonRec *person, int numRecords)
{
    int count = 0;
    float tSalary;
    float avSalary;
    
    int i;
    for(i = 0; i < numRecords; i++) {
        if(person[i].emplyeeOrPatient == 0) {
            tSalary += person[i].emp.salary;
            count += 1;
        }
    }

    avSalary = tSalary / count;

    printf("\n");
    printf("Employee Summary\n");
    printf("Total number of employees: %d  total salary: %.2f  average salary: %.2f\n", count, tSalary, avSalary);
    printf("\n");
    printf("Summary by position\n");

    int j;
    int k;
    for(k = 0; k < 4; k++) {
        tSalary = 0;
        count = 0;
        for(j = 0; j < numRecords; j++) {
            if(person[j].emplyeeOrPatient == 0 && person[j].emp.position == k) {
                count += 1;
                tSalary += person[j].emp.salary;
            }
        }
        avSalary = tSalary / count;
        printf("position[%d]-employees: %d total salary: %.2f average salary: %.2f\n", k, count, tSalary, avSalary);
    }
    printf("\n");
}

