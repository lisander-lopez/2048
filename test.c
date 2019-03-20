#include <stdio.h>
#include <stdbool.h>
#include "CUnit.h"
#include "Basic.h"
#include "helper.h"

void testBoardEquality(Box gric[GRID_SIZE][GRID_SIZE]);

/* Test Left with the number on an edge
    [][][][]            [][][][]
    [2][][2][] ----->  [4][][][]
    [][][][]           [][][][]
    [][][][]           [][][][]

*/
void testMoveLeft0(void) {}
/* Test Left with the number NOT on an edge
    [][][][]            [][][][]
    [][2][2][] ----->  [4][][][]
    [][][][]           [][][][]
    [][][][]           [][][][]

*/
void testMoveLeft1(void) {}
/* Test Right with the number NOT on an edge
    [][][][]            [][][][]
    [][2][2][] ----->  [][][][4]
    [][][][]           [][][][]
    [][][][]           [][][][]

*/
void testMoveRight0(void) {}
/* Test Right with the number on an edge
    [][][][]            [][][][]
    [][2][][2] ----->  [][][][4]
    [][][][]           [][][][]
    [][][][]           [][][][]

*/
void testMoveRight1(void) {}
/* Test UP with the number on an edge
    [][2][][]          [][4][2][]
    [][2][2][] ----->  [][][][]
    [][][][]           [][][][]
    [][][][]           [][][][]

*/
void testMoveUp0(void) {}
/* Test Up with the number NOT on an edge
    [][][][]           [][4][][]
    [][2][][] ----->  [][][][]
    [][][][]          [][][][]
    [][2][]           [][][][]

*/
void testMoveUp1(void) {}
/* Test Down with the number on an edge
    [][][][]            [][][][]
    [][][2][] ----->    [][][][]
    [][][][]            [][][][]
    [][][2][]           [][][4][]

*/
void testMoveDown0(void) {}
/* Test Down with the number not on an edge
    [][2][][]           [][][][]
    [][2][][] ----->   [][][][]
    [][2][][]          [][4][][]
    [][2][][]           [][4][][]

*/
void testMoveDown1(void) {}

/* Test Multiple Operatons in the following order, up, right, right, left
    [][][][]           [4][2][][]
    [][2][2][] ----->  [][][][]
    [][2][][]          [][][][]
    [][][][]           [][][][]

*/
void testMultipleOps(void) {}

void testBoardEquality(Box gric[GRID_SIZE][GRID_SIZE])
{
    //CU_ASSERT_EQUAL(retVal, expected);
}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_1", NULL, NULL);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if (
        (NULL == CU_add_test(pSuite, "test00", testMoveLeft0)) ||
        (NULL == CU_add_test(pSuite, "test01", testMoveLeft1)) ||
        (NULL == CU_add_test(pSuite, "test02", testMoveRight0)) ||
        (NULL == CU_add_test(pSuite, "test03", testMoveRight1)) ||
        (NULL == CU_add_test(pSuite, "test04", testMoveUp0)) ||
        (NULL == CU_add_test(pSuite, "test05", testMoveUp1)) ||
        (NULL == CU_add_test(pSuite, "test06", testMoveDown0)) ||
        (NULL == CU_add_test(pSuite, "test07", testMoveDown1)) ||
        (NULL == CU_add_test(pSuite, "test08", testMultipleOps)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    //   CU_basic_show_failures(CU_get_failure_list());
    CU_cleanup_registry();
    return CU_get_error();
}
