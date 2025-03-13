#include <stdio.h>

void printChars();

int main(){
    printChars();
    
    return 0;
}

// Print all characters twice except duplicates (ex AA, AB and BA)
void printChars(){
    char outer = 'A';
    while (outer <= 'Z'){
        char inner = outer;
        while (inner <= 'Z') {
            if (outer != inner) {
                printf("%c%c ", outer, inner);
            }
            inner++;
        }
        outer++;
    }
    puts("");
    
}