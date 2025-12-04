#include <stdio.h>
#include <stdlib.h>   // For malloc() and free()

int main() {
    int n;
    printf("Enter number of book categories: ");
    scanf("%d", &n);

    // 1. Dynamic memory allocation
    int *stock = (int*) malloc(n * sizeof(int));

    if (stock == NULL) {   // Check if memory allocated
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 2. Input stock for each category
    printf("\nEnter stock for each category:\n");
    for (int i = 0; i < n; i++) {
        printf("Category %d stock: ", i);
        scanf("%d", &stock[i]);
    }

    // 3. Calculations
    int total = 0;
    int minIndex = 0;

    for (int i = 0; i < n; i++) {
        total += stock[i];

        if (stock[i] < stock[minIndex]) {
            minIndex = i;
        }
    }

    float average = (float)total / n;

    printf("\n----- STOCK REPORT -----\n");
    printf("Total Stock: %d\n", total);
    printf("Average Stock: %.2f\n", average);
    printf("Category with lowest stock: %d\n", minIndex);

    // 4. Update stock
    int updateIndex, newStock;
    printf("\nEnter category index to update: ");
    scanf("%d", &updateIndex);

    if (updateIndex >= 0 && updateIndex < n) {
        printf("Enter new stock value: ");
        scanf("%d", &newStock);
        stock[updateIndex] = newStock;
        printf("Stock updated successfully!\n");
    } else {
        printf("Invalid category index!\n");
    }

    // Print updated stocks
    printf("\nUpdated Stock List:\n");
    for (int i = 0; i < n; i++) {
        printf("Category %d: %d\n", i, stock[i]);
    }

    // 5. Free memory
    free(stock);

    return 0;
}
