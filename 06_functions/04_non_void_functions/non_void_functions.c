/*
    Practice with non-void functions
*/

#include <stdio.h>

// Function Prototypes
// The function named getFive which returns an integer and takes no arguments
int getFive();

// Function named printCourse which returns nothing and takes one integer argument
void printCourse(int course_number);

// The function that takes an integer and describes the weather
void describeWeather(int temp);

// The function that converts the given number of miles to kilometers
double milesToKilometers(double miles);

// The function that converts the given number of kilometers to miles
double kmsToMiles(double kms);

int main(){
    int var;

    // Call the getFive function
    var = getFive();
    printf("var is %d\n", var);

    // Call printCourse
    printCourse(2271);

    // Test describeWeather
    int temperature;
    printf("Enter a temperature: ");
    scanf("%d", &temperature);
    describeWeather(temperature);

    // Call covert
    double dist;
    printf("Enter the number of miles: ");
    scanf("%lf", &dist);
    printf("%lf miles is %lf kilometers.\n", dist, milesToKilometers(dist));

    printf("Enter the number of kilometers: ");
    scanf("%lf", &dist);
    printf("%lf kilometers is %lf miles.\n", dist, kmsToMiles(dist));

    return 0;
}

// getFive implemetation
int getFive(){
    int five = 5;

    return five;
}

void printCourse(int course_number){

    printf("You are in COP%d. \n", course_number);
}

void describeWeather(int temp){
    // if statement
    if (temp >= 70){
        puts("HOT");
    }
    else {
        puts("COLD");
    }

}

// Conversion implementation
double milesToKilometers(double miles){

    return miles*1.60934;
}

double kmsToMiles(double kms){
    return kms / 1.60934;
}