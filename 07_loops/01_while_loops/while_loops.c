/*
    Introduction to while loops
*/


#include <stdio.h> 
#include <unistd.h> // usleep function
#include <stdlib.h> // rand function 
#include <time.h> // time function

// Function Protoypes
void printHello();
void printNHello(int n);
double fahernheitToCelcius(int temp);
void printTemperatures(int min, int max);
void printNRandom(int n);


int main(){
    srand(time(0));
    /*
    // first function
    printHello();
    
    // second function
    int times;
    printf("\n\n\nEnter the amount of times you want to loop: ");
    scanf("%d", &times);
    printf("\n\n\n");
    printNHello(times);
    
    // third function
    printTemperatures(-100, 100);
    */

    // fourth function
    printNRandom(10);

    return 0;
}

void printHello(){
    // Use an iteration statement (loop)
    
    // 1 - counter
    int i = 1;
    
    // 2 - condition (when to stop iteration)
    while (i <= 100) {
        printf("%d - HELLO!\n", i);
        usleep(10000);
        // 3 - increment (change the counter)
        i++;
    }
    
}


void printNHello(int n){
    while (n > 0) {
        printf("%3d - HELLO!\n", n);
        usleep(10000);
        n--;
    }
}


double fahernheitToCelcius(int temp){
    return ((temp - 32) * 5.0 / 9);
}



void printTemperatures(int min, int max){
    while (min <= max) {
        printf("%+5d - %+.3f\n", min, fahernheitToCelcius(min));
        usleep(10000);
        min++;
    } 
}

void printNRandom(int n){
    while (n > 0){
        printf("%d\n", rand() % 10);
        n--;
    }
}