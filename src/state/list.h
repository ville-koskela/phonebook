#ifndef LIST_H
#define LIST_H

// We will list phone numbers
typedef struct PhoneNumber {
    char number[20];
} PhoneNumber;

typedef struct ListNode {
    struct PhoneNumber *data;
    struct ListNode *next;
} ListNode;

PhoneNumber *createPhoneNumber(char *);

#endif
