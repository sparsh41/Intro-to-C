#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// symbolic constant
#define ARRSIZE 200
#define SIZE 11

void printArray(int *arr, int size);
void initWithRandom(int *arr, int size, int left, int right);

int main(){
    srand(time(0));
    
    // Create an array of 200 integers
    int array[ARRSIZE];
    
    // Initialize the first element with 999
    array[0] = 999;
    
    // Initialize the last element wiht 111
    array[199] = 111;
    
    // Print the first and last elements of the array
    printf("First: %d, Last %d\n", array[0], array[199]);
    
    // Initialize an array with a loop
    for (int i = 0; i < ARRSIZE; i++) {
        array[i] = i;
    }
    
    // Reinitialize an array with values from 10 - 200
    int array2[20];
    for (int i = 0; i < 20; i++) {
        array2[i] = (i + 1) * 10;
    }
    
    // Reiniialize with random numbers from -20 to 20
    int array3[20];
    for (int i = 0; i < 20; i++) {
        array3[i] = rand() % 41 - 20;
    }
    
    
    // Print an array
    printArray(array, ARRSIZE);  
    
    
    // Print another array
    printArray(array2, 20);
    
    
    // Print  array3
    printArray(array3, 20);

    // Initialize and print
    int array4[ARRSIZE];
    initWithRandom(array4, ARRSIZE, -100, 100);
    printArray(array4, ARRSIZE);

    int c[] = {-45, 6, 0, 72, 1543};
    printf("The sum of the first and third elements is: %d\n", c[0] + c[2]);
    
    return 0;
}

// Functions with arrays
void printArray(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i == size - 1){
            printf(" %d", arr[i]);
            break;
        }
        printf(" %d,", arr[i]);
    }
    printf("]\n");  
}

// Initialize an array with random nmubers
void initWithRandom(int *arr, int size, int left, int right){
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (right - left) + left;
    }
}