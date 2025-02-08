#ifndef MEMBER_H
#define MEMBER_H

typedef struct {
    int id;
    char name[100];
    char email[100];
    int booksIssued;
} Member;

Member* addMember(Member* members, int* totalMembers, char* name, char* email, int id);
void displayMembers(Member* members, int totalMembers);
void saveMembers(Member* members, int totalMembers);
Member* loadMembers(int* totalMembers);

#endif