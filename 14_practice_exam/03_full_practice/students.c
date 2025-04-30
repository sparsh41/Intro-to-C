#include <stdio.h>
#include <string.h>

#define SUBJECTS 3

typedef struct
{
    char name[30];
    int roll_number;
    int marks[SUBJECTS][2];
    double average;
} Student;

// Prototypes
Student inputData(void);
void printAverage(Student *roster, int size);
void printLongestName(Student *roster, int size);
double calcSubjectAverage(Student *roster, int size, int subject);


int main(){
    int N;
    
    // Number of Students
    printf("Enter number of students: ");
    scanf("%d", &N);
    Student roster[N];
    puts("\n");
    
    // Input data into students
    for (int i = 1; i <= N; i++){
        printf("Enter details for student %d\n", i);
        roster[i-1] = inputData();
        puts("");
    }
    
    // Find Student Averages
    puts("\nStudent Averages:");
    printAverage(roster, N);
    puts("");
    
    // Find Longest Name
    printLongestName(roster, N);
    puts("");

    // Find Subject Averages
    printf("\nSubject Averages: \n");
    for (int i = 1; i <= SUBJECTS; i++){
        printf("Subject %d: %.2f\n", i, calcSubjectAverage(roster, N, i));
    }
    puts("");

    // Write into file
    FILE *file = NULL;

    file = fopen("students.txt", "w");
    if (file == NULL){
        puts("File could not be opened.");
        return 1;
    }

    for (int i = 0; i < N; i++){
        fprintf(file, "%s, %d, %d, %d, %d, %.2f", 
            roster[i].name, 
            roster[i].roll_number, 
            roster[i].marks[0][1], roster[i].marks[1][1], roster[i].marks[2][1], 
            roster[i].average);
        if (i != N-1){
            fprintf(file, "\n");
        }
    }

    printf("\nRecords written to students.txt\n");
    fclose(file);

    // Read records from file
    file = NULL;
    file = fopen("students.txt", "r");
    if (file == NULL){
        puts("File could not be opened.");
        return 1;
    }
    printf("Reading from file:\n");
    char student[150];
    while (!feof(file))
    {
        fgets(student, 149, file);
        printf("%s", student);
    }
    puts("");
    
    return 0;
}

Student inputData(void){
    
    Student st;

    while (getchar() != '\n');
    
    printf("Name: ");
    char name[30];
    fgets(name, 29, stdin);
    strcpy(st.name, name);
    st.name[strlen(st.name) - 1] = '\0';
    
    printf("Roll No: ");
    int n;
    scanf("%d", &n);
    st.roll_number = n;
    
    printf("Marks (%d subjects): ", SUBJECTS);
    int marks[SUBJECTS][2] = 
    {
        {1, 0},
        {2, 0},
        {3, 0},
    };
    int sum = 0;
    scanf("%d%d%d", &marks[0][1], &marks[1][1], &marks[2][1]);
    for (int i = 0; i < SUBJECTS; i++){
        for (int j = 0; j < 2; j++){
        st.marks[i][j] = marks[i][j];
    }
    sum += marks[i][1];
}

    st.average = ((double)sum)/3.0;

    return st;
}

void printAverage(Student *roster, int size){
    for (int i = 0; i < size; i++){
        printf("%s (%d): %.2f\n", roster[i].name, roster[i].roll_number, roster[i].average);
    }
}

void printLongestName(Student *roster, int size){
    char max_name[30];
    strcpy(max_name, roster[0].name);
    
    for (int i = 1; i < size; i++){
        if (strlen(roster[i].name) > strlen(max_name)){
            strcpy(max_name, roster[i].name);
        }
    }
    
    printf("Student with longest name: %s", max_name);
}

double calcSubjectAverage(Student *roster, int size, int subject){
    int sum = 0;

    for (int i = 0; i < size; i++){
        sum += roster[i].marks[subject - 1][1];
    }

    return (double)sum / size;
}