#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Use %s <word1> <word2>\n", argv[0]);
        return 0;
    }
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    // Compare two given words
    int result = strcmp(argv[1], argv[2]);

    if (result > 0) {
        printf("%s goes after %s\n", argv[1], argv[2]);
    }
    else if (result < 0) {
        printf("%s goes before %s\n", argv[1], argv[2]);
    }
    else {
        puts("The words are identical");
    }


    return 0;
}
