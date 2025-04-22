#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 1000

void getString(char *str);
void getString2(char *str);
void getString3(char *str);
bool hasSpaces(const char *str);
// TODO
/*
 Hello, 5 -> HelloHelloHelloHelloHello
*/

void makeDuplicates(char *str, int n);


// TODO 
// Check whether the given string is valid
/*
Has at least one upper and one lower case
Has at least one digit
Has no spaces or tabs
Has {*, $, % , &}
The length is not less than 8
*/
bool checkString(char *str);


int main(void) {
    char str1[SIZE];
    char str2[SIZE];
    char str3[SIZE];
    char str4[SIZE];
    
    getString3(str1);
    getString2(str2);
    
    printf("The first string is \"%s\"\n", str1);
    printf("The second string is \"%s\"\n", str2);
    
    // Copy one string into another
    strcpy(str1, str2);
    printf("The first string is \"%s\"\n", str1);
    printf("The second string is \"%s\"\n", str2);
    
    // Add one string to the other
    strcat(str1, str2);
    printf("The first string is \"%s\"\n", str1);
    printf("The second string is \"%s\"\n", str2);
    
    // Make Duplicates
    getString2(str3);
    makeDuplicates(str3, 5);

    // Check password
    getString2(str4);
    bool password_ready = checkString(str4);
    if (password_ready == 1){
        puts("Accepted!");
    }
    else {
        puts("Does not meet requirements");
    }
    return 0;
}

void getString(char *str) {
    puts("Enter a string: ");
    scanf("%s", str);
}

void getString2(char *str) {
    puts("Enter a string: ");
    fgets(str, SIZE - 1, stdin); // stdin - standard input (keyboard)
    // Remove the ending \n
    int last_character = strlen(str) - 1; // index of the last character
    str[last_character] = '\0';
}

void getString3(char *str) {
    puts("Enter a string: ");
    int i = 0;
    char c = getchar(); // getchar scans one character
    while (i < SIZE - 1 && c != '\n') {
        str[i] = c;
        i++;
        c = getchar();
    }
    str[i] = '\0';
}

bool hasSpaces(const char *str) {
    
    // Check does the string have spaces
    if (strchr(str, ' ') == 0) {
        puts("No spaces");
        return false;
    }
    else {
        puts("There is a space");
        return true;
    }
}

void makeDuplicates(char *str, int n){
    char new_str[SIZE*5];
    for (int i = 0; i < n; i++){
        strcat(new_str,str);
    }
    puts(new_str);
}


bool checkString(char *str){
    bool upper = 0;
    bool lower = 0;
    bool digit = 0;
    bool spaces = 0;
    bool special_char = 0;

    for (int i = 0; i < strlen(str); i++){
        if ((str[i] >= 'A') && (str[i] <= 'Z')){
            upper = true;
        }
        if ((str[i] >= 'a') && (str[i] <= 'z')){
            lower = true;
        }
        if ((str[i] >= '0') && (str[i] <= '9')){
            digit = true;
        }
    }
    if (hasSpaces(str) == 0){
        spaces = true;
    }
    // {*, $, % , &}
    if (strchr(str, '*') != 0){
        special_char = 1;
    }
    if (strchr(str, '$') != 0){
        special_char = 1;
    }
    if (strchr(str, '%') != 0){
        special_char = 1;
    }
    if (strchr(str, '&') != 0){
        special_char = 1;
    }

    /*
    if (upper == 1){
        puts("upper");
    }
    if (lower == 1){
        puts("lower");
    }
    if (digit == 1){
        puts("digit");
    }
    if (spaces == 1){
        puts("spaces");
    }
    if (special_char == 1){
        puts("special");
    }
    if (strlen(str) >= 8){
        puts("length");
    }
    */

    if (lower && upper && digit && spaces && special_char && (strlen(str) >= 8)){
        return true;
    }
    return false;
}