/*
    Getting the input from the keyboard
*/

#include <stdio.h>

int main(){
    int square_side = 1;
    int square_perimeter = 0;
    int square_area = 0;

    // Write the prompt
    puts("Enter the side of the square");

    // Get input - only conversion factors in scanf function
    // & - address operator
    scanf("%d", &square_side);

    // Do the math
    square_perimeter = 4 * square_side;
    square_area = square_side * square_side;

    // Create the output
    printf("The perimeter of the square with side %d is %d\n", square_side, square_perimeter);

    return 0;
}