

#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "populateRecords.h"
#include "patient.h"
#include "employee.h"

#define NUM_RECORDS 20

int menu();
void quit();
void sizeofStructs();

int main()
{
    struct person person[NUM_RECORDS];
	char rc = 0;


    // populating the array person with data of patients and employees
    populateRecords(person, NUM_RECORDS);

    int option;
    int exit = 0;
    while(exit == 0) {
        option = menu();
        switch(option) {
            case 0:
                quit();
                break;
            case 1:
                printEmployees(person, NUM_RECORDS);
                break;
            case 2:
                printPatients(person, NUM_RECORDS);
                break;
            case 3:
                searchPatient(person, NUM_RECORDS);
                break;
            case 4:
                printEmployeesSummary(person, NUM_RECORDS);
                break;
            case 5:
                printPatientSummary(person, NUM_RECORDS);
                break;
            case 6:
                sizeofStructs();
                break;
        }
    }

    return 0;
}

int menu() {
    int option;
    int flag = 0;

    while(flag == 0) {
        printf("MENU\n");
        printf("1. Print all employees\n");
        printf("2. Print all patients\n");
        printf("3. Search patient using Family Name\n");
        printf("4. Summary of Employees Data\n");
        printf("5. Summary of Patients data\n");
        printf("6. Size of structures (PersonRec, PatientRec and EmployeeRec)\n");
        printf("0. Quit\n");

        printf("\n");
        printf("Enter an option: ");
        scanf("%u", &option);

        if(option < 0 || option > 6) {
            printf("Enter a valid option\n");
        }
        else {
            flag = 1;
        }
    }
    return option;
}

void sizeofStructs() {
    int pSize = sizeof(struct person);
    int eSize = sizeof(struct employee);
    int paSize = sizeof(struct patient);
    printf("\n");
    printf("Size of structures\n");
    printf("Size of PersonRrec = %d\n", pSize);
    printf("Size of EmployeeRrec = %d\n", eSize);
    printf("Size of of Patient Rrec = %d\n", paSize);
    printf("\n");
}

void quit() {
    printf("You are about to quit. Would you like to proceed? (y/n)?\n");
    char proceed[10];
    scanf("%s", proceed);
    if(strcmp(proceed, "y") == 0) {
        exit(0);
    }
    else if(strcmp(proceed, "n") == 0) {
    }
    else {
        printf("That is not an option\n");
    }
}
