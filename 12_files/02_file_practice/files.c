#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main(int argc, char argv[]){

    if (argc != 3){
        puts("Incorrect Call");
        return 0;
    }


    FILE *file = fopen(argv[1], "w");

    if (file == NULL){
        return 1;
    }

    int n = atoi(argv[2]);

    int i = 0;
    while (i < n) {
        fprintf(file, "%s", argv[1]);
        i++;
    }
    
    fclose(file);    

    return 0;
}