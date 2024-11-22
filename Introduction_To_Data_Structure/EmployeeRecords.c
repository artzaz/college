#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_EMPLOYEES 100

typedef struct {
    char lastName[50];
    char firstName[50];
    float gradePointIndex;
} StudentRecord;

typedef struct {
    char lastName[50];
    char firstName[50];
    float salary;
} EmployeeRecord;

void applyRaise(StudentRecord students[], int numStudents, EmployeeRecord employees[], int numEmployees) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].gradePointIndex > 3.0) {
            for (int j = 0; j < numEmployees; j++) {
                if (strcmp(students[i].lastName, employees[j].lastName) == 0 &&
                    strcmp(students[i].firstName, employees[j].firstName) == 0) {

                    employees[j].salary *= 1.10;
                    break; 
                }
            }
        }
    }
}

int main() {

    StudentRecord students[MAX_STUDENTS] = {
        {"Smith", "John", 3.5},
        {"Doe", "Jane", 2.8},
        {"Brown", "Alice", 3.9}
    };
    int numStudents = 3;

    EmployeeRecord employees[MAX_EMPLOYEES] = {
        {"Smith", "John", 50000.0},
        {"Doe", "Jane", 60000.0},
        {"Brown", "Alice", 55000.0}
    };
    int numEmployees = 3;

    applyRaise(students, numStudents, employees, numEmployees);

    printf("Updated Employee Records:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Name: %s %s, Salary: %.2f\n", employees[i].firstName, employees[i].lastName, employees[i].salary);
    }

    return 0;
}
