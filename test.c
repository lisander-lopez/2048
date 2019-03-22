#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CUnit.h"
#include "Basic.h"
#include "helper.h"

void testBoardEquality(Box grid[GRID_SIZE][GRID_SIZE]);

/* Test Left with the number on an edge
    [][][][]            [][][][]
    [2][][2][] ----->  [4][][][]
    [][][][]           [][][][]
    [][][][]           [][][][]

*/
void testMoveLeft0(void)
{
    Box grid[GRID_SIZE][GRID_SIZE];
    populateGrid(grid);
    grid[0][1].val = 2;
    grid[2][1].val = 2;
    moveLeft(grid);
    CU_ASSERT_TRUE(grid[0][1].val == 4);
}
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

void testEmptyPopulate(void)
{
    Box grid[GRID_SIZE][GRID_SIZE];
    populateGrid(grid);
    bool empty = true;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            Box b = grid[i][j];
            if (b.val != 0)
            {
                empty = false;
            }
        }
    }
    CU_ASSERT_TRUE(empty);
}
void testBoardEquality(Box grid[GRID_SIZE][GRID_SIZE])
{

    //CU_ASSERT_EQUAL(retVal, expected);
}

// Checks if random value was added to the box and makes sure value is either 2 or 4
void testRandomAdder0()
{
    Box grid[GRID_SIZE][GRID_SIZE];
    populateGrid(grid);
    bool add = addRandom(grid);
    int valCount = 0;
    for (int y = 0; y < GRID_SIZE; y++)
    {
        for (int x = 0; x < GRID_SIZE; x++)
        {
            if (grid[x][y].val == 2 || grid[x][y].val == 4)
            { // If its a zero Box
                valCount++;
            }
        }
    }
    CU_ASSERT_TRUE(add && (valCount == 1));
}

// Checks winning state that a full box cannot be added a random value to
void testRandomAdder1()
{
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
        (NULL == CU_add_test(pSuite, "test08", testMultipleOps)) ||
        (NULL == CU_add_test(pSuite, "test08", testEmptyPopulate)) ||
        (NULL == CU_add_test(pSuite, "test08", testRandomAdder0)) ||
        (NULL == CU_add_test(pSuite, "test08", testRandomAdder1)))
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
