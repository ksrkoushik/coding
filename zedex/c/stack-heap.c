#include <stdio.h>
#include <stdlib.h>

void demonstrateMemory() {
    int stackVar = 42; // Variable stored on the stack
    int *heapVar = (int *)malloc(sizeof(int)); // Memory allocated on the heap

    if (heapVar == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    *heapVar = 100; // Assigning a value to the heap-allocated memory

    printf("Stack variable value: %d\n", stackVar);
    printf("Heap variable value: %d\n", *heapVar);

    free(heapVar); // Freeing the allocated heap memory
}

int main() {
    demonstrateMemory();

    // Check for memory leaks using Valgrind
    // Run the program with Valgrind: valgrind ./your_program_name
    // Valgrind should report whether all allocated memory was properly freed.
    
    return 0;
}

