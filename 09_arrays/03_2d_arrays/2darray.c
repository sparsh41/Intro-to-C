#include <stdio.h>

#define ROW 4
#define COL 4

void print(int rows, int cols, const int arr[rows][cols]);
void setRow(int rows, int cols, int arr[rows][cols], int row_num, int val);
void setCol(int rows, int cols, int arr[rows][cols], int col_num, int val);
int total(int rows, int cols, const int arr[rows][cols]);
int totalPerim(int rows, int cols, const int arr[rows][cols]);

int main(int argc, char *argv[]){
    // Create and initialize a 2D array of integers
    int arr[ROW][COL] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {3, 4, 5, 6}
    };
    
    // Access an element
    printf("The value in position (2,1) of the array is %d\n", arr[0][1]);
    printf("The value in position (3,3) of the array is %d\n", arr[2][2]);
    
    // Change the value of an element
    arr[1][1] = 0;
    
    // Print an array
    puts("The array is:");
    print(ROW, COL, arr);
    
    // Set the second row with 99s
    setRow(ROW, COL, arr, 0, 66);
    setCol(ROW, COL, arr, 2, 99);
    puts("The new array is:");
    print(ROW, COL, arr);
    
    // Find and print the sum of the values of the arrays
    printf("The sum is %d\n", total(ROW, COL, arr));

    // Find and print the sum of he elements in the perimeter in the array
    printf("The sum of the perimeter elements is %d\n", totalPerim(ROW, COL, arr));
    
    
    return 0;
}


void print(int rows, int cols, const int arr[rows][cols]){
    // Iterate through row
    for (int i = 0; i < rows; i++){
        // Iterate through column
        for (int j = 0; j < cols; j++){
            printf("%4d", arr[i][j]);
        }
        puts("");
    }
    puts("");
}


void setRow(int rows, int cols, int arr[rows][cols], int row_num, int val){
    for (int j = 0; j < cols; j++){
        arr[row_num][j] = val;
    };
}


void setCol(int rows, int cols, int arr[rows][cols], int col_num, int val){
    for (int j = 0; j < rows; j++){
        arr[j][col_num] = val;
    };
}


int total(int rows, int cols, const int arr[rows][cols]){
    int sum = 0;
    for (int i = 0; i < rows; i++){
        // Iterate through column
        for (int j = 0; j < cols; j++){
            sum += arr[i][j];
        }
    }
    return sum;
}

int totalPerim(int rows, int cols, const int arr[rows][cols]){
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        if ((i == 0) || (i == rows - 1)){
            for (int j = 0; j < cols; j++){
                sum += arr[i][j];
            }
        }
        else{
            sum += arr[i][0];
            sum += arr[i][cols - 1];
        }
    };
    return sum;
}