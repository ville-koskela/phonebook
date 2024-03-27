#include "list.h"
#include <stdlib.h>
#include <string.h>

PhoneNumber *createPhoneNumber(char *number) {
    PhoneNumber *newNumber = (PhoneNumber *)malloc(sizeof(PhoneNumber));
    strcpy(newNumber->number, number);
    return newNumber;
}
