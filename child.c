#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *data = malloc((argc - 1) * sizeof(int)); // Allocate only for input data
    if (!data) {
        perror("Memory allocation failed");
        return 1;
    }

    printf("\nArgc: %d", argc);
    for (int i = 1; i < argc; i++) {
        data[i - 1] = atoi(argv[i]); // Skip argv[0]
    }

    // Printing Elements in Reverse
    printf("\nPrinting Elements in Reverse:");
    for (int i = argc - 1; i > 0; i--) {
        printf(" %d", data[i - 1]);
    }
    printf("\n\nEXCEV task Completed\n");

    free(data); // Free allocated memory
    return 0;
}

