#ifndef BOOK_H
#define BOOK_H
typedef struct {
    int id;
    char title[100];
    char author[100];
    int isAvailable;
    int issuedTo;  // Member ID, 0 if not issued
} Book;

Book* addBook(Book* books, int* totalBooks, char* title, char* author, int id);
void removeBook(Book* books, int* totalBooks, int id);
void displayBooks(Book* books, int totalBooks);
Book* searchBooks(Book* books, int totalBooks, char* query, int* results);
void saveBooks(Book* books, int totalBooks);
Book* loadBooks(int* totalBooks);

#endif
