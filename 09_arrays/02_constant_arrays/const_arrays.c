#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// Print the doubled values of the given array
void printDoubledArray(const int *arr, int size);

// Searching in arrays (linear search)
int firstZero(const int *arr, int size);
int lastZero(const int *arr, int size);

// Return 1 if there are an even number of zeros and return 0 if there are an odd number of zeros or no zeros
int hasEvenZeros(const int *arr, int size);
int findNthZero(const int *arr, int size, int n);


int main(){
    
    srand(time(0));
    
    int a[SIZE];
    for (int i = 0; i < SIZE; i++){
        a[i] = rand() % 11;
    }
    
    printDoubledArray(a, SIZE);
    
    int first_zero = firstZero(a, SIZE);
    int last_zero = lastZero(a, SIZE);
    int even_zeros = hasEvenZeros(a, SIZE);
    int nth_zero = findNthZero(a, SIZE, 2);

    if ((first_zero == last_zero) && (first_zero != -1)){
        printf("The index of the zero is %d.\n", first_zero);
    }
    else if (first_zero == -1){
        puts("There are no zeros in the array.");
    }
    else {
        printf("The first zero is in the index is %d and the index of the last zero is %d.\n", first_zero, last_zero);
    }
    if (first_zero != -1){
        if (even_zeros == 0){
            puts("There are an even number of zeros in the array.");
        }
        else {
            puts("There are an odd number of zeros in the array.");
        }
    }
    
    return 0;
}


void printDoubledArray(const int *arr, int size){
    puts("The doubled array is: ");
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i == size - 1){
            printf("%d", arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
    }
    printf("]\n");
    puts("");
}


int firstZero(const int *arr, int size){
    for (int i = 0; i < size; i++){
        if (arr[i] == 0){
            return i;
        }
    }
    // no zero
    return -1;
}


int lastZero(const int *arr, int size){
    for (int i = size - 1; i >= 0; i--){
        if (arr[i] == 0){
            return i;
        }
    }
    // no zero
    return -1;
}


int hasEvenZeros(const int *arr, int size){
    int num_zeros = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] == 0){
            num_zeros ++;
        }
    }
    if (num_zeros == 0){
        return 0;
    }
    return num_zeros % 2;
}


int findNthZero(const int *arr, int size, int n){
    int num_zeros = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] == 0){
            num_zeros ++;
        }
        if (num_zeros == n){
            return i;
        }
    }
    return -1;
}