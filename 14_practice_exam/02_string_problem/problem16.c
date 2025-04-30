#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STR_LENGTH 20

void encodeString(char *str);

int main(){
    
    char input[STR_LENGTH];

    
    printf("Enter a string: ");
    fgets(input, STR_LENGTH, stdin);
    
    encodeString(input);
    printf("Encoded string: %s", input);
    
    return 0;
}


void encodeString(char *str){
    for (int i = 0; i < strlen(str); i++){
        if (islower(str[i])){
            if (str[i] == 'y' || str[i] == 'z'){
                str[i] -= 24;
            }
            else{
                str[i] += 2;
            }
        }
    }
}
