#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Function checks if the given character is uppercase
bool isUpper(char c);
bool isLower(char c);

bool isAlpha(char c);
bool isAlNum(char c);

char toLower(char c);

void printReversedCase(const char *str);

int main(){
    // Create a character
    char c = '%';
    
    // Create a boolean variable
    const bool isHappy = true;
    
    // Test isUpper
    printf("isUpper('%c') = %d\n", c, isUpper(c));
    printf("isLower('%c') = %d\n", c, isLower(c));
    printf("isAlpha('%c') = %d\n", c, isAlpha(c));
    printf("isAlNum('%c') = %d\n\n", c, isAlNum(c));
    
    
    // Create a string
    char str[] = "HeL10 Th3rE!";
    
    // Print the string
    puts("Printing with printf:");
    printf("%s\n\n", str);
    
    puts("Printing with loop:");
    for (int i = 0; str[i] != '\0'; i++){ // str[i] != '0' -- continue until end of string
        printf("%c", str[i]);
    }
    puts("");
    puts("");
    
    
    puts("Printing with puts:");
    puts(str);
    puts("");
    
    puts("Print the string in lowercase");
    for (int i = 0; str[i] != '\0'; i++){
        putchar(toLower(str[i]));
    }
    puts("");
    

    puts("Print the string in reversed case");
    printReversedCase(str);

    
    return 0;
}


bool isUpper(char c){
    if ((c >= 'A') && (c <= 'Z')){
        return true;
    }
    return false;
}


bool isLower(char c){
    if ((c >= 'a') && (c <= 'z')){
        return true;
    }
    return false;
}


bool isAlpha(char c){
    if (isUpper(c) || isLower(c)){
        return true;
    }
    return false;
}


bool isAlNum(char c){
    if (isAlpha(c) || (c >= '0' && c <= '9')){
        return true;
    }
    return false;
}


char toLower(char c){
    if (isUpper(c)){
        return c + 32;
    }
    return c;
}


void printReversedCase(const char *str){
    for (int i = 0; str[i] != '\0'; i++){
        if (isupper(str[i])){
            tolower(str[i]);
        }
        if (islower(str[i])){
            toupper(str[i]);
        }
    }
    puts(str);
}