/*
    The program calculates the roots of a quadratic equation 
    
    ax^2 + bx + c = 0
*/


#include <stdio.h> 
#include <math.h>

// Function Prototypes
double countDiscriminant(int a, int b, int c);
void printRoots(int a, int b, int c);



int main(){
    int a;
    int b;
    int c;

    printf("Enter the coefficients a, b, and c: ");
    scanf("%d%d%d", &a, &b, &c);

    printf("Solution(s) to the quadratic equation %dx^2 + %dx + %d = 0 are:\n", a, b, c);
    printRoots(a, b, c);
    
    return 0;
}

/*********************/
double countDiscriminant(int a, int b, int c){
    // b^2 - 4ac
    return (b * b) - (4 * a * c);
}


/*********************/
void printRoots(int a, int b, int c){
    int disc = countDiscriminant(a, b, c);
    if (disc < 0){
        puts("No real roots");
    }
    else if (disc == 0){
        // -b/2a
        double x = (-b) / (2*a);
        printf("%lf\n", x);
    }
    else {
        // -b +- sqrt(disc) / (2*a)
        double x1 = (-b + sqrt(disc)) / (2*a);
        double x2 = (-b - sqrt(disc)) / (2*a);
        printf("%lf and %lf\n", x1, x2);
    }
}