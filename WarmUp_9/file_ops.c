#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    // File init, for reading and writing
    const char *filename = "filename.txt";
    FILE *fr = fopen(filename, "r");
    FILE *fw = fopen(filename, "w");

    // handle empty file
    if (fr == NULL) {
        perror("Error opening file for reading");
        return EXIT_FAILURE;
    }

    // Writing to file
    fprintf(fw, "Hello World!\n");
    fclose(fw);

    // Reading from file
    char line[100];  // Assuming lines are no longer than 100 characters
    while (fgets(line, sizeof(line), fr) != NULL) {
        printf("%s", line);
    }
    return EXIT_SUCCESS;
}