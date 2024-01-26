#include "helpers.h"

#include <CUnit/Basic.h>
#include <stdlib.h>

void test_max() {
    CU_ASSERT_EQUAL(max(-1, 1), 1);
    CU_ASSERT_EQUAL(max(-6, -5), -5);
    CU_ASSERT_EQUAL(max(0, 10), 10);
    CU_ASSERT_EQUAL(max(1, 1), 1);
}