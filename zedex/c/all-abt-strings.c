#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

int main() {
    // Case 1: char name[50];
    char name[MAX_NAME_LENGTH];
    strncpy(name, "John Doe", MAX_NAME_LENGTH - 1);
    name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null terminator
    printf("Name (char name[50]): %s\n", name);

    // Case 2: char *name;
    char *dynamicName = (char *)malloc((MAX_NAME_LENGTH + 1) * sizeof(char));
    strncpy(dynamicName, "Jane Smith", MAX_NAME_LENGTH);
    dynamicName[MAX_NAME_LENGTH] = '\0'; // Ensure null terminator
    printf("Name (char *name): %s\n", dynamicName);
    free(dynamicName);

    // Case 3: char *names[];
    const char *names[] = {"Alice", "Bob", "Charlie"};
    printf("Names (char *names[]):\n");
    for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
        printf("- %s\n", names[i]);
    }

    // Case 4: char **names;
    int numNames = 3;
    char **stringArray = (char **)malloc(numNames * sizeof(char *));
    if (stringArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    stringArray[0] = (char *)malloc((MAX_NAME_LENGTH + 1) * sizeof(char));
    stringArray[1] = (char *)malloc((MAX_NAME_LENGTH + 1) * sizeof(char));
    stringArray[2] = (char *)malloc((MAX_NAME_LENGTH + 1) * sizeof(char));

    strncpy(stringArray[0], "David", MAX_NAME_LENGTH);
    strncpy(stringArray[1], "Emily", MAX_NAME_LENGTH);
    strncpy(stringArray[2], "Frank", MAX_NAME_LENGTH);

    // Ensure null termination for each string
    stringArray[0][MAX_NAME_LENGTH] = '\0';
    stringArray[1][MAX_NAME_LENGTH] = '\0';
    stringArray[2][MAX_NAME_LENGTH] = '\0';

    printf("Names (char **names):\n");
    for (int i = 0; i < numNames; i++) {
        printf("- %s\n", stringArray[i]);
        free(stringArray[i]); // Free each string allocated
    }

    free(stringArray); // Free allocated memory for string pointers

    return 0;
}

