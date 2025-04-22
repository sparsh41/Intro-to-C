#include <stdio.h>

int main(int argc, char *argv[]){

    // Create a pointer to a file structure
    FILE *file = NULL;

    // Open the file - fopen(<name>, <action>)cretes the fie and returns the pointer to FILE
    file = fopen("out.txt", "w");

    // Check whether the ile was opened
    if (file == NULL) {
        puts("File not opened");
        return 1;
    }

    // Write into the file
    int i = 1;
    while (i <= 100) {
        fprintf(file, "%d", i++);
        if (i != 101){
            fprintf(file, "\n");
        }
    }
    

    // Close the file
    fclose(file);

    return 0;
}