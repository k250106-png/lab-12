#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter number of movie categories: ");
    scanf("%d", &n);
    int *ratings = (int*) malloc(n * sizeof(int));

    if (ratings == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("\nEnter rating count for each category:\n");
    for (int i = 0; i < n; i++) {
        printf("Category %d ratings: ", i);
        scanf("%d", &ratings[i]);
    }
    int total = 0;
    int maxIndex = 0;

    for (int i = 0; i < n; i++) {
        total += ratings[i];

        if (ratings[i] > ratings[maxIndex]) {
            maxIndex = i;
        }
    }

    float average = (float)total / n;

    printf("\n----- MOVIE RATINGS REPORT -----\n");
    printf("Total Ratings: %d\n", total);
    printf("Average Ratings per Category: %.2f\n", average);
    printf("Category with Highest Ratings: %d (Rating = %d)\n",
            maxIndex, ratings[maxIndex]);
    int updateIndex, newRating;
    printf("\nEnter category index to update: ");
    scanf("%d", &updateIndex);

    if (updateIndex >= 0 && updateIndex < n) {
        printf("Enter new rating value: ");
        scanf("%d", &newRating);
        ratings[updateIndex] = newRating;
        printf("Rating updated successfully!\n");
    } else {
        printf("Invalid index! Update skipped.\n");
    }
    printf("\nUpdated Ratings:\n");
    for (int i = 0; i < n; i++) {
        printf("Category %d: %d\n", i, ratings[i]);
    }
    free(ratings);

    return 0;
}
