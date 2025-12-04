#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int containsDigit(char *str) {
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            return 1;
        }
        str++;
    }
    return 0;  
}

int main() {
    int n;
    char temp[200];
    char **users;   

    printf("Enter number of usernames: ");
    scanf("%d", &n);
    getchar();  
    users = (char**) malloc(n * sizeof(char*));

    if (users == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter usernames:\n");
    for (int i = 0; i < n; i++) {
        printf("Username %d: ", i + 1);
        fgets(temp, sizeof(temp), stdin);

        temp[strcspn(temp, "\n")] = '\0';  
        users[i] = (char*) malloc(strlen(temp) + 1);
        strcpy(users[i], temp);
    }

    printf("\nValid Usernames (Alphabetic Only):\n");
    for (int i = 0; i < n; i++) {
        if (!containsDigit(users[i])) {
            printf("%s\n", users[i]);
        }
    }

  
    for (int i = 0; i < n; i++) {
        free(users[i]);  
    }
    free(users);         

    return 0;
}
