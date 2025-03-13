/*
    Use a sentinel-controlled loop to add and average grades
    Sentinel-controlled loops use a sentinel value to control when to end the loop
*/


#include <stdio.h>

// Prototypes
double sumStudentGradesSentinel();
double avgStudentGradesSentinel();
double getGrade();
void forLoop();

int main(){
    // printf("%.2lf \n", sumStudentGradesSentinel());
    //printf("%.2lf \n", avgStudentGradesSentinel());
    forLoop();
    
    
    return 0;
}


double sumStudentGradesSentinel(){
    double grade = 0;
    double total_grade = 0;
    
    while (grade != -1) { // -1 is the sentinel value
        // Get the grade
        printf("Enter the grade (-1 to exit): ");
        scanf("%lf", &grade);
        if (grade == -1){
            break;
        }
        total_grade += grade;
    }
    
    
    return total_grade;
}


double avgStudentGradesSentinel(){
    double grade;
    double total_grade = 0;
    int count = 0;
    
    while (grade != -1) { // -1 is the sentinel value
        // Get the grade
        grade = getGrade();
        
        // Don't count -1
        if (grade == -1){
            break;
        }
        total_grade += grade;
        count ++;
    }
    
    // Don't divide by 0
    if (count == 0) {
        puts("No grades were entered");
        return 0; 
    }
    return (total_grade/count);
}

double getGrade(){
    // Return only grades in the range [-1, 100]
    double grade;
    
    // do while iteration statment
    do {
        printf("Enter the grade (-1 when done): ");
        scanf("%lf", &grade);
        
        if ((-1 > grade) || (grade > 100)){
            puts("INCORRECT GRADE! Try again.");
        }
    } while ((-1 > grade) || (grade > 100));
    
    return grade;   
}

void forLoop(){
    // Use a for loop to print the values from 15 to 45
    for (int i = 15; i <= 45; i+=5) {
        printf("%d ", i);
    }

    printf("\n\n");
    for (int i = 100; i >= 2; i-=2) {
        printf("%d ", i);
    }
    printf("\n");
}