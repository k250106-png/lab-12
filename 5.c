#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int category(char c) {
    if (c >= 'A' && c <= 'Z') return 1;
    if (c >= 'a' && c <= 'z') return 2;
    if (c >= '0' && c <= '9') return 3;
    return 4;
}

int main() {
    int n;
    char temp[200];
    char *pattern;
    char **pass;
    int *scores;

    printf("Enter number of participants: ");
    scanf("%d", &n);
    getchar();

    printf("Enter password pattern: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';

    pattern = (char*) malloc(strlen(temp) + 1);
    strcpy(pattern, temp);

    pass = (char**) malloc(n * sizeof(char*));
    scores = (int*) malloc(n * sizeof(int));

    int plen = strlen(pattern);

    for (int i = 0; i < n; i++) {
        printf("Password %d: ", i + 1);
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0';

        pass[i] = (char*) malloc(strlen(temp) + 1);
        strcpy(pass[i], temp);

        int len = strlen(pass[i]);
        int minLen = plen < len ? plen : len;
        int match = 0;

        for (int j = 0; j < minLen; j++) {
            if (category(pattern[j]) == category(pass[i][j]))
                match++;
        }

        scores[i] = (match * 100) / plen;
    }

    int best = 0;
    for (int i = 1; i < n; i++)
        if (scores[i] > scores[best])
            best = i;

    printf("\nResults:\n");
    for (int i = 0; i < n; i++)
        printf("%s -> %d%% similarity\n", pass[i], scores[i]);

    printf("\nBest Match: %s (%d%%)\n", pass[best], scores[best]);

    free(pattern);
    for (int i = 0; i < n; i++)
        free(pass[i]);
    free(pass);
    free(scores);

    return 0;
}
