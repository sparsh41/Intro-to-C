//Write a C program that produces the following output
/*
    Name
    Course ID
    Student ID
    Student ID - Course ID
*/

#include <stdio.h>

//Main function
int main(){
    //Create variables for course ID and student ID
    int course_ID = 2271;
    int student_ID = 17426;

    //Name
    printf("Name: Sparsh Rangwala\n");

    //Produce output
    printf("Course ID: %d\n", course_ID);
    printf("Student ID: %d\n", student_ID);

    //Print the difference
    printf("Student ID - Course ID: %d\n", student_ID - course_ID);

    return 0;
}