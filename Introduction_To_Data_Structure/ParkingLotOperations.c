#include <stdio.h>
#include <string.h>

#define MAX_CAPACITY 10
#define MAX_PLATE_LENGTH 20

typedef struct {
    char license[MAX_PLATE_LENGTH];
    int maneuvers;
} Car;

typedef struct {
    Car cars[MAX_CAPACITY];
    int top;
} ParkingLot;


void initializeParkingLot(ParkingLot *lot) {
    lot->top = -1;
}


int isFull(ParkingLot *lot) {
    return lot->top == MAX_CAPACITY - 1;
}


int isEmpty(ParkingLot *lot) {
    return lot->top == -1;
}


int enterParkingLot(ParkingLot *lot, const char *license) {
    if (isFull(lot)) {
        printf("Car %s arrives: No space available.\n", license);
        return 0; 
    }
    lot->top++;
    strcpy(lot->cars[lot->top].license, license);
    lot->cars[lot->top].maneuvers = 0;
    printf("Car %s arrives: Space available.\n", license);
    return 1; 
}


int exitParkingLot(ParkingLot *lot, const char *license) {
    if (isEmpty(lot)) {
        printf("Car %s leaves: Parking lot is empty.\n", license);
        return 0; 
    }

    ParkingLot tempLot;
    initializeParkingLot(&tempLot);

    int found = 0, maneuvers = 0;

    while (!isEmpty(lot)) {
        if (strcmp(lot->cars[lot->top].license, license) == 0) {
            found = 1; 
            maneuvers = lot->cars[lot->top].maneuvers;
            lot->top--;
            break;
        }
        tempLot.cars[++tempLot.top] = lot->cars[lot->top];
        tempLot.cars[tempLot.top].maneuvers++; 
        lot->top--;
    }

   
    while (!isEmpty(&tempLot)) {
        lot->cars[++lot->top] = tempLot.cars[tempLot.top--];
    }

    if (found) {
        printf("Car %s leaves: Maneuvered %d times.\n", license, maneuvers);
        return 1; 
    } else {
        printf("Car %s leaves: Not found in the parking lot.\n", license);
        return 0; 
    }
}

int main() {
    ParkingLot lot;
    initializeParkingLot(&lot);

    char operation;
    char license[MAX_PLATE_LENGTH];

    printf("Enter parking operations (e.g., 'E ABC123' for entry, 'S ABC123' for exit, or 'Q' to quit):\n");
    while (1) {
        scanf(" %c", &operation);
        if (operation == 'Q') {
            break;
        }
        scanf("%s", license);

        if (operation == 'E') {
            enterParkingLot(&lot, license);
        } else if (operation == 'S') {
            exitParkingLot(&lot, license);
        } else {
            printf("Invalid operation. Use 'E' for entry, 'S' for exit, or 'Q' to quit.\n");
        }
    }

    return 0;
}
