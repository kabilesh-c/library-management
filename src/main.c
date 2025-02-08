#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "member.h"

void displayMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add New Book\n");
    printf("2. Remove Book\n");
    printf("3. Search Books\n");
    printf("4. Display All Books\n");
    printf("5. Add New Member\n");
    printf("6. Display Members\n");
    printf("7. Issue Book\n");
    printf("8. Return Book\n");
    printf("9. Save and Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Book* books = NULL;
    Member* members = NULL;
    int totalBooks = 0;
    int totalMembers = 0;
    int choice;
    char title[100], author[100], name[100], email[100], query[100];
    int id;
    
    // Load existing data
    books = loadBooks(&totalBooks);
    members = loadMembers(&totalMembers);
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline
        
        switch (choice) {
            case 1: // Add New Book
                printf("Enter book title: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = 0;
                
                printf("Enter author name: ");
                fgets(author, 100, stdin);
                author[strcspn(author, "\n")] = 0;
                
                books = addBook(books, &totalBooks, title, author, totalBooks + 1);
                break;
                
            case 2: // Remove Book
                printf("Enter book ID to remove: ");
                scanf("%d", &id);
                removeBook(books, &totalBooks, id);
                break;
                
            case 3: // Search Books
                printf("Enter search query: ");
                fgets(query, 100, stdin);
                query[strcspn(query, "\n")] = 0;
                
                int results;
                Book* found = searchBooks(books, totalBooks, query, &results);
                if (results > 0) {
                    printf("\nFound %d books:\n", results);
                    displayBooks(found, results);
                    free(found);
                } else {
                    printf("No books found!\n");
                }
                break;
                
            case 4: // Display All Books
                displayBooks(books, totalBooks);
                break;
                
            case 5: // Add New Member
                printf("Enter member name: ");
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0;
                
                printf("Enter member email: ");
                fgets(email, 100, stdin);
                email[strcspn(email, "\n")] = 0;
                
                members = addMember(members, &totalMembers, name, email, totalMembers + 1);
                break;
                
            case 6: // Display Members
                displayMembers(members, totalMembers);
                break;
                
            case 7: // Issue Book
                printf("Enter book ID: ");
                scanf("%d", &id);
                int memberID;
                printf("Enter member ID: ");
                scanf("%d", &memberID);
                
                // Add book issuing logic here
                break;
                
            case 8: // Return Book
                printf("Enter book ID: ");
                scanf("%d", &id);
                
                // Add book return logic here
                break;
                
            case 9: // Save and Exit
                saveBooks(books, totalBooks);
                saveMembers(members, totalMembers);
                free(books);
                free(members);
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}

