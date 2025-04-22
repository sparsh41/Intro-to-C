#include <stdio.h>

int main(int argc, char *argv[]){

    // Create a pointer to a file structure
    FILE *file = NULL;

    // Open the file - fopen(<name>, <action>)cretes the fie and returns the pointer to FILE
    file = fopen("out.txt", "r");

    // Check whether the file was opened
    if (file == NULL) {
        puts("File not opened");
        return 1;
    }

    // Read from the file
    int i = 1;
    while (!feof(file)) {
        fscanf(file, "%d", &i);
        printf("%d\n", i);
    }
    

    // Close the file
    fclose(file);

    return 0;
}