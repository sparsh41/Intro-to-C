#include <stdio.h>

// Takes an integer and sets it to 0
void setToZero(int *n);

// reurn product of the valuesthe pointers are pointing to
double productPointers(double *p1, double *p2);

// swap pointers
void swapPointers(int *a_ptr, int *b_ptr);

int main(){
    int luck = 100;
    
    // Access
    printf("%d\n", luck);
    
    //Modify
    luck += 10;
    
    // Print address of variable
    printf("The address of luck is %p\n", &luck); // %p id for pointer
    
    // Create a pointer variable
    // <data_type> * pointer_name
    int *luck_ptr = &luck;
    
    // Access the data thepointer is pointing to
    // * - dereferencing operator
    printf("Dereference luck_ptr %d\n", *luck_ptr);
    
    // Modify the data through the pointer
    *luck_ptr = 300;
    printf("The value of luck after modification: %d\n", luck);
    
    // Passing by reference
    setToZero(&luck);
    printf("The value of luck after setting to 0: %d\n", luck);
    
    // New values
    double d1 = 2.4;
    double d2 = 6.43;
    printf("The product of %.2f and %.2f is %lf\n", d1, d2, productPointers(&d1, &d2));
    
    int a = 10, b = -10;
    int *a_ptr = &a, *b_ptr = &b;
    printf("a is %d and b is %d\n", *a_ptr, *b_ptr);
    swapPointers(a_ptr, b_ptr);
    printf("After swapping, a is %d and b is %d\n", *a_ptr, *b_ptr);
    
    
    return 0;
}


void setToZero(int *n){
    *n = 0;
}


double productPointers(double *p1, double *p2){
    return *p1 * *p2;
}


void swapPointers(int *a_ptr, int *b_ptr){
    int temp = *a_ptr;
    *a_ptr = *b_ptr;
    *b_ptr = temp;
}