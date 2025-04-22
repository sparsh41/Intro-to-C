#include <stdio.h>
#include <string.h>

#define NAME_SIZE 30

// Create a structure
struct Student {
    // Structure members
    char first_name[NAME_SIZE];
    int age;
    // TODO
    // add double GPA;
    double GPA;
};

void printStudentInfo(const struct Student *st);



int main(int argc, char *argv[]) {
    // Create the object of type int and call it a
    int a;

    // Create an object of another type (type Student)
    // Create an object of type struct Student and named it stud1
    struct Student stud1;

    // Initialize the structure members
    strcpy(stud1.first_name, "Nick");
    stud1.age = 19;
    stud1.GPA = 4.0;

    // Print the members of the structure through the function
    printStudentInfo(&stud1);

    // Create a pointer to int
    int b;
    int *b_ptr = &b;
    *b_ptr; // accces to b through a pointer b_ptr

    // Create a pointer to a student structure
    struct Student *stud_ptr = &stud1;

    // Access to the members of the structure through the pointer
    (*stud_ptr).first_name; // access with dereferencing
    stud_ptr->age;          // access with arrow operator

    // Create another student
    struct Student stud2 = {.first_name = "Jack", .age = 20, .GPA = 0.5};

    printStudentInfo(&stud2);


    return 0;
}


void printStudentInfo(const struct Student *st) {
    printf("First name:\t\t%s\n", st->first_name);
    printf("Age:\t\t\t%d\n", st->age);
    printf("GPA: \t\t\t%.1f\n", st->GPA);
}