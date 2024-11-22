#include <stdio.h>
#include <stdlib.h>

#define NUM_BRANCHES 20
#define NUM_ITEMS 10

int main() {

    double sales[NUM_BRANCHES][NUM_ITEMS] = {0.0};

    int branch, item;
    double sale;

    printf("Enter sales data (branch, item, sales). Enter -1 to finish:\n");
    while (1) {
        printf("Branch (1-20): ");
        scanf("%d", &branch);
        if (branch == -1) break;

        printf("Item (1-10): ");
        scanf("%d", &item);

        printf("Sales (0-99999): ");
        scanf("%lf", &sale);


        if (branch < 1 || branch > NUM_BRANCHES || item < 1 || item > NUM_ITEMS || sale < 0 || sale >= 100000) {
            printf("Invalid input. Try again.\n");
            continue;
        }


        sales[branch - 1][item - 1] += sale;
    }


    printf("\n%-8s", "Branch");
    for (int i = 1; i <= NUM_ITEMS; i++) {
        printf("Item%-6d", i);
    }
    printf("Total\n");


    double item_totals[NUM_ITEMS] = {0.0};
    double branch_totals[NUM_BRANCHES] = {0.0};
    double grand_total = 0.0;


    for (int i = 0; i < NUM_BRANCHES; i++) {
        printf("%-8d", i + 1);
        double branch_total = 0.0;

        for (int j = 0; j < NUM_ITEMS; j++) {
            printf("%-10.2f", sales[i][j]);
            branch_total += sales[i][j];
            item_totals[j] += sales[i][j];
        }

        branch_totals[i] = branch_total;
        grand_total += branch_total;
        printf("%.2f\n", branch_total);
    }


    printf("%-8s", "TOTAL");
    for (int j = 0; j < NUM_ITEMS; j++) {
        printf("%-10.2f", item_totals[j]);
    }
    printf("%.2f\n", grand_total);

    return 0;
}
