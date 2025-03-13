/*
    This function prints a description based on the given temperature
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototypes
void temperatureDescription(double temp);
void checkRange(int num);
int largest(int num1, int num2, int num3);
void divide(int n1, int n2);
void printRand();

int main(){
    srand(time(0));
    /*
    double temp;
    int number;
    int n1;
    int n2;
    int n3;
    
    printf("Enter your current temperature: ");
    scanf("%lf", &temp);
    temperatureDescription(temp);
    
    printf("Enter a number: ");
    scanf("%d", &number);
    checkRange(number);
    
    
    printf("Enter three numbers: ");
    scanf("%d%d%d", &n1, &n2, &n3);
    printf("The largest number is %d\n", largest(n1, n2, n3));

    divide(12,6);*/

    printRand();
    
    return 0;
}

void temperatureDescription(double temp){
    if (temp > 101) {
        puts("High Fever");
    }
    else if (temp > 99) {
        puts("Low Fever");
    }
    else if (temp > 97) {
        puts("Normal");
    }
    else {
        puts("Low Temperature");
    }
}

// Checks whether a given number is in the range [0,10]
void checkRange(int num){
    if ((num >= 0) && (num <= 10)){
        puts("The number is between 0 and 10.");
        if (num % 2 == 0){
            puts("The number is even.");
        }
        else {
            puts("The number is not even.");
        }
    }
    else {
        puts("The number is not in the range");
    }
}


// Taks three integers and returns the largest
int largest(int num1, int num2, int num3){
    if ((num1 < num2) && (num2 < num3))
    {
        return num3;
    }
    else if ((num1 > num2) && (num1 > num3))
    {
        return num1;
    }
    else if ((num1 == num2) || (num2 == num3) || (num1 == num3)){
        puts("There are at least two numbers that equal one another.");
    }
    else {
        return num2;
    }
}

// Checks if the first number is divisible by the second or second-3, but not both.
void divide(int n1, int n2){
    // ^ : Exclusive or (One is true but not both)
    if ((n1 % n2 == 0) ^ (n1 % (n2-3) == 0)){
        puts("Yes");
    }
    else{
        puts("No");
    }
}


void printRand(){
    for (int i = 0; i <= 50; i++){
        printf("%d, ", rand() % (27+3+1) - 7);
    }
}