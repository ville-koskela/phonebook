#include "list.h"
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <string.h>

void test_createPhoneNumber(void) {
    PhoneNumber *phone = createPhoneNumber("1234567890");
    CU_ASSERT_PTR_NOT_NULL(phone);
    CU_ASSERT_STRING_EQUAL(phone->number, "1234567890");
}
