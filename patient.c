

#include "string.h"
#include "stdio.h"
#include "patient.h"

/********************************************************************/
void printPatient(PersonRec person)

{
    char temp[50];
    int dep = person.patient.department;
    long dCost = person.patient.dailyCost;
    int days = person.patient.numDaysInHospital;
    char sev = person.patient.severity;

    int tCost = dCost * days;

    char *fName = person.firstName;
    char *sName = person.familyName;

    sprintf(temp, "%s %s", fName, sName);
    printf("%-33s", temp);
    printf("dept: %d days in hospital: %d severity: %d daily cost: %lu total cost: %d\n", dep, days, sev, dCost, tCost);



}

/********************************************************************/
void printPatients(PersonRec person[], int numRecords)
{
    printf("\n");
    printf("Patient List\n");

    int i;
    for(int i = 0; i < numRecords; i++) {
        if(person[i].emplyeeOrPatient == 1) {
            printPatient(person[i]);
        }
    }
    printf("\n");
}


/********************************************************************/
void printPatientSummary(PersonRec *person, int numRecords)
{
    int count = 0;
    float tCost;
    float avCost;
    float dCost;

    int i;
    for(i = 0; i < numRecords; i++) {
        if(person[i].emplyeeOrPatient == 1) {
            tCost += (person[i].patient.dailyCost * person[i].patient.numDaysInHospital);
            count += 1;
        }
    }

    avCost = tCost / count;

    printf("\n");
    printf("Patient Summary\n");
    printf("Total number of patients: %d total cost to-date: %.2f average cost per patient to-date: %.2f\n", count, tCost, avCost);
    printf("\n");
    printf("Summary by Department\n");
    int j;
    int k;
    for(k = 1; k < 7; k++) {
        count = 0;
        tCost = 0;
        avCost = 0;
        dCost = 0;
        for(j = 0; j < numRecords; j++) {
            if(person[j].emplyeeOrPatient == 1 && person[j].patient.department == k) {
                count += 1;
                tCost += (person[j].patient.dailyCost * person[j].patient.numDaysInHospital);
                dCost += person[j].patient.dailyCost;
            }
        }
        avCost = dCost / count;
        printf("Department[%d]-patients: %d cost to-date: %.2f daily cost: %.2f average daily cost per patient: %.2f\n", k, count, tCost, dCost, avCost);
    }
    printf("\n");
}


/********************************************************************/
void searchPatient(PersonRec person[], int numRecords)
{
    printf("\n");
    int count = 0;
    int flag = 1;
    int i;
    while(flag != 0) {
        printf("Please enter the Patient's family name: ");
        char searchInput[30];
        scanf("%s", searchInput);
        
        for(i = 0; i < numRecords; i++) {
            if (person[i].emplyeeOrPatient == 1 && strcmp(person[i].familyName, searchInput) == 0) {
                printPatient(person[i]);
                count += 1;
            }
        }
        printf("\n");
        flag = 0;
    }
    if(count == 0) {
        printf("No patient was found\n");
        printf("\n");
    }
}
