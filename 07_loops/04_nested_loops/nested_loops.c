#include <stdio.h>
#include <stdbool.h>

void printTrangleTopLefStars(int size);
void printTriangleBottomLeftNumbers(int size);
void printTriangleTopLeftNumbers(int size);


int main(){
    int n = 0;
    
    // Scan a positive integer
    
    do {
        printf("Enter a positive integer: ");
        scanf("%d", &n);
    } while (n <= 0);

    printTrangleTopLefStars(n);

    printTriangleBottomLeftNumbers(n);

    printTriangleTopLeftNumbers(n);
    
}

/*
    5
*****
****
***
**
*

*/


void printTrangleTopLefStars(int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i; j++){
            printf("%c", '*');
        }
        puts(""); // new line after print
    }
}

void printTriangleBottomLeftNumbers(int size){

    for (int i = 0; i < size; i++){
        for (int j = size; j >= size - i; j--){
            printf("%d", j);
        }
        puts("");
    }
}

void printTriangleTopLeftNumbers(int size){

    for (int i = 0; i <= size; i++){
        for (int j = 1; j <= size - i; j++){
            printf("%d", j);
        }
        puts("");
    }
}