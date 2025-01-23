/*
    The program converts the given numer of seconds to minutes, hours, and seconds

    Ex: 65 seconds --> 0 hours, 1 minute, 5 seconds
*/

#include <stdio.h>

int main(){
    int seconds;

    // Get the number of seconds
    puts("Enter the number of seconds:");
    scanf("%d", &seconds);
    printf("%d seconds is ", seconds);

    int minutes = seconds/60;
    int hours = minutes/60;

    minutes = minutes%60;
    seconds = seconds%60;

    // Print the result
    printf("%d hours, %d minutes, and %d seconds.\n", hours, minutes, seconds);
    return 0;
}