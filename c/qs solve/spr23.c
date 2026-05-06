#include <stdio.h>
#include <stdlib.h>

// Define a structure for Employee
struct Employee {
    int id;
    char name[50];
    float salary;
    int scores[12];
};

int main() {
    int N;
    printf("Enter the number of employees: ");
    scanf("%d", &N);
int sum [N];
    // Declare an array of Employee structures
    struct Employee employees[N];

    // Take input for each employee
    for (int i = 0; i < N; i++) {
         sum[i] = 0;
        printf("Enter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        printf("Enter performance scores for the last 12 months:\n");
        for (int j = 0; j < 12; j++) {
            printf("Month %d: ", j + 1);
            scanf("%d", &employees[i].scores[j]);
            sum[i] += employees[i].scores[j];
        }


        
    }

    // Calculate average performance scores and check eligibility for increment
    printf("\nEligibility for increment:\n");
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < 12; j++) {
            sum += employees[i].scores[j];
        }
        float average = sum / 12.0;
        if (average > 80) {
            printf("Employee with id=%d is eligible for increment.\n", employees[i].id);
        } else {
            printf("Employee with id=%d is not eligible for increment.\n", employees[i].id);
        }
    }

    return 0;
}