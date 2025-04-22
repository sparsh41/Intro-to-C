#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define MAX_LINE 256

typedef struct {
    char title[SIZE];
    char author[SIZE];
    int num_pages;
    int price;
} Book;


void printBookInfo(const Book *book);
int minPrice(const Book *library, int size);

int main() {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        puts("File could not be opened.");
        return 1;
    }

    Book books[100];
    char line[MAX_LINE];
    int count = 0;

    while (fgets(line, 999, file) && !feof(file)) {
        line[strcspn(line, "\n")] = 0; // Remove trailing newline

        char *token = strtok(line, ",");
        strcpy(books[count].title, token);

        token = strtok(NULL, ",");
        strcpy(books[count].author, token);

        token = strtok(NULL, ",");
        books[count].num_pages = atoi(token);

        token = strtok(NULL, ",");
        books[count].price = atoi(token);

        count++;
    }

    fclose(file);

    for (int i = 0; i < 5; i++) {
        printf("Book# %d\n", i + 1);
        printBookInfo(&books[i]);
    }
    
    int minIndex = minPrice(books, count);
    printf("\nThe book with the minimum price is\n");
    printBookInfo(&books[minIndex]);
    
    return 0;
}

void printBookInfo(const Book *book) {
    printf("-------------------------------------------------------\n");
    printf("Author\t\t%s\n", book->author);
    printf("Title\t\t%s\n", book->title);
    printf("Pages\t\t%d\n", book->num_pages);
    printf("Price\t\t%d\n", book->price);
    printf("-------------------------------------------------------\n");
}

int minPrice(const Book *library, int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (library[i].price < library[minIndex].price) {
            minIndex = i;
        }
    }
    return minIndex;
}