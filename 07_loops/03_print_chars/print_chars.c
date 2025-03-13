#include <stdio.h>

int main(){
    // Get the uppercase character
    char input;

    do  {
    printf("Enter an uppercase character: ");
    scanf(" %c", &input);
    } while ((input < 'A') || (input > 'Z'));
    
    // get a positive integer
    int num;
    do {
        printf("Enter a posiive number: ");
        scanf("%d", &num);
    } while (num <= 0);
    
    // get a second character which is either * or # and print the pattern C**CC**C...
    char input2;
    do {
        printf("Enter either a * or #: ");
        scanf(" %c", &input2);
    } while ((input2 != '*') && (input2 != '#'));
    
    /*
    // Print the scanned char the integer number of times - use a for loop
    for (int i = 0; i < num; i++){
        printf("%c", input);
    }*/
    
    // Print the advanced pattern
    for (int i = 0; i < num; i++){
        if (i % 2 == 0){
            printf("%c%c", input, input2);
        }
        else{
            printf("%c%c", input2, input);
        }
    }
    puts("");
    return 0;
}