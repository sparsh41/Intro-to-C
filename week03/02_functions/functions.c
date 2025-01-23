/*
    introduction to functions in C

    You cannot create a function inside another function
*/

#include <stdio.h>

// Function format
// <return type> <function name> (<arguments (parameters, inputs)>){}

// The function doesn't take any arguments and doesn't return any value
void print_course(void) {
    printf("You are in COP%d\n", 2271);
}

void draw_circle(void) {
    printf("   * * \n");
    printf(" *     *\n");
    printf(" *     *\n");
    printf("   * *\n");
}

// Draw a caret
void draw_caret() {
    printf("   / \\ \n");
    printf("  /   \\ \n");
    printf(" /     \\ \n");

}

// Draw a line
void draw_line() {
    printf("/_______\\ \n");
}

// Draw a triangle
void draw_triangle() {
    draw_caret();
    draw_line();
}

void draw_stick_figure() {
    draw_circle();
    draw_triangle();
    draw_caret();
}

int main() {
    // Call the functions
    //print_course();
    //draw_circle();
    //draw_triangle();
    //draw_caret();

    draw_stick_figure();

    return 0;
}