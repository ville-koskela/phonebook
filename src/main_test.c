#include "state/list_test.h"
#include "state/tree_test.h"
#include "utils/helpers_test.h"
#include <CUnit/Basic.h>

#include <stdarg.h>

int checkSuites(int, ...);
int checkTests(int, ...);

int main() {
    CU_initialize_registry();

    CU_pSuite listSuite = CU_add_suite("List suite", NULL, NULL);
    CU_pSuite treeSuite = CU_add_suite("Tree suite", NULL, NULL);
    CU_pSuite helperSuite = CU_add_suite("Helper suite", NULL, NULL);

    int suites = checkSuites(3, listSuite, treeSuite, helperSuite);

    if (suites) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    int tests = checkTests(
        6,
        CU_add_test(listSuite, "test of createPhoneNumber",
                    test_createPhoneNumber),
        CU_add_test(treeSuite, "test of createNode", test_createNode),
        CU_add_test(treeSuite, "test of insertNode", test_insertNode),
        CU_add_test(treeSuite, "test of searchNode", test_searchNode),
        CU_add_test(treeSuite, "test of deleteNode", test_deleteNode),
        CU_add_test(helperSuite, "test of max", test_max));

    if (tests) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

int checkSuites(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        CU_pSuite suite = va_arg(args, CU_pSuite);
        if (suite == NULL) {
            va_end(args);
            return 1;
        }
    }

    va_end(args);

    return 0;
}

int checkTests(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        CU_pTest test = va_arg(args, CU_pTest);
        if (test == NULL) {
            va_end(args);
            return 1;
        }
    }

    va_end(args);

    return 0;
}