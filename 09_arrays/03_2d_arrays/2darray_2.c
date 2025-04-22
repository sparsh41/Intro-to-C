#include <stdio.h>

void print(int rows, int cols, const double arr[rows][cols]);

int main(){
    double arr[5][5];

    int n = 1;
    for (int i = 0; i < 5;i++){
        for (int j = 0; j < 5; j++){
            arr[i][j] = n;
            n++;
        }
    }

    print(5,5,arr);
    
    arr[0][1] = 24;
    arr[2][2] = 43;
    arr[4][4] = 377;
    
    print(5,5,arr);

    return 0;
}


void print(int rows, int cols, const double arr[rows][cols]){
    // Iterate through row
    for (int i = 0; i < rows; i++){
        // Iterate through column
        for (int j = 0; j < cols; j++){
            printf("    %.2f", arr[i][j]);
        }
        puts("");
    }
    puts("");
}