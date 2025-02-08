#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

Book* addBook(Book* books, int* totalBooks, char* title, char* author, int id) {
    Book* temp = realloc(books, (*totalBooks + 1) * sizeof(Book));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return books;
    }
    books = temp;
    
    books[*totalBooks].id = id;
    strncpy(books[*totalBooks].title, title, 99);
    strncpy(books[*totalBooks].author, author, 99);
    books[*totalBooks].isAvailable = 1;
    books[*totalBooks].issuedTo = 0;
    
    (*totalBooks)++;
    return books;
}

void removeBook(Book* books, int* totalBooks, int id) {
    int found = 0;
    for (int i = 0; i < *totalBooks; i++) {
        if (books[i].id == id) {
            found = 1;
            for (int j = i; j < *totalBooks - 1; j++) {
                books[j] = books[j + 1];
            }
            (*totalBooks)--;
            break;
        }
    }
    if (!found) {
        printf("Book not found!\n");
    }
}

void displayBooks(Book* books, int totalBooks) {
    printf("\nLibrary Catalog:\n");
    printf("ID\tTitle\tAuthor\tStatus\n");
    printf("--------------------------------\n");
    
    for (int i = 0; i < totalBooks; i++) {
        printf("%d\t%s\t%s\t%s\n", 
            books[i].id, 
            books[i].title, 
            books[i].author, 
            books[i].isAvailable ? "Available" : "Issued"
        );
    }
}

Book* searchBooks(Book* books, int totalBooks, char* query, int* results) {
    Book* found = NULL;
    *results = 0;
    
    for (int i = 0; i < totalBooks; i++) {
        if (strstr(books[i].title, query) || strstr(books[i].author, query)) {
            found = realloc(found, (*results + 1) * sizeof(Book));
            found[*results] = books[i];
            (*results)++;
        }
    }
    return found;
}

void saveBooks(Book* books, int totalBooks) {
    FILE* file = fopen("data/books.dat", "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    fwrite(&totalBooks, sizeof(int), 1, file);
    fwrite(books, sizeof(Book), totalBooks, file);
    fclose(file);
}

Book* loadBooks(int* totalBooks) {
    FILE* file = fopen("data/books.dat", "rb");
    if (file == NULL) {
        *totalBooks = 0;
        return NULL;
    }
    
    fread(totalBooks, sizeof(int), 1, file);
    Book* books = malloc(*totalBooks * sizeof(Book));
    fread(books, sizeof(Book), *totalBooks, file);
    fclose(file);
    return books;
}
