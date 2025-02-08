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

// member.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "member.h"

Member* addMember(Member* members, int* totalMembers, char* name, char* email, int id) {
    Member* temp = realloc(members, (*totalMembers + 1) * sizeof(Member));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return members;
    }
    members = temp;
    
    members[*totalMembers].id = id;
    strncpy(members[*totalMembers].name, name, 99);
    strncpy(members[*totalMembers].email, email, 99);
    members[*totalMembers].booksIssued = 0;
    
    (*totalMembers)++;
    return members;
}

void displayMembers(Member* members, int totalMembers) {
    printf("\nMember List:\n");
    printf("ID\tName\tEmail\tBooks Issued\n");
    printf("--------------------------------\n");
    
    for (int i = 0; i < totalMembers; i++) {
        printf("%d\t%s\t%s\t%d\n", 
            members[i].id, 
            members[i].name, 
            members[i].email,
            members[i].booksIssued
        );
    }
}

void saveMembers(Member* members, int totalMembers) {
    FILE* file = fopen("data/members.dat", "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    fwrite(&totalMembers, sizeof(int), 1, file);
    fwrite(members, sizeof(Member), totalMembers, file);
    fclose(file);
}

Member* loadMembers(int* totalMembers) {
    FILE* file = fopen("data/members.dat", "rb");
    if (file == NULL) {
        *totalMembers = 0;
        return NULL;
    }
    
    fread(totalMembers, sizeof(int), 1, file);
    Member* members = malloc(*totalMembers * sizeof(Member));
    fread(members, sizeof(Member), *totalMembers, file);
    fclose(file);
    return members;
}