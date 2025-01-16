/*
    Converts age to minutes
*/

#include <stdio.h>

int main(){

    // initialize variables
    int age;

    // Get input from user
    puts("Enter your age in years:");
    scanf("%d", &age);

    // Convert to minutes
    int age_min = age*365*24*60;

    // Print to console
    printf("\"%d\" years is \"%d\" minutes.\n", age, age_min);

    return 0;
}