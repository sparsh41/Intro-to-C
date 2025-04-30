#include <stdio.h>

typedef struct {
    char first_name[30];
    char last_name[30];
    int credit_hours_completed;
    float gpa;
} Student;

int main(){

    Student st1 = {"John", "Doe", 24, 3.547};

    printf("First Name: %s\n", st1.first_name);
    printf("Last Name: %s\n", st1.last_name);
    printf("Credit Hours: %d\n", st1.credit_hours_completed);
    printf("GPA: %.3f\n", st1.gpa);

    return 0;
}