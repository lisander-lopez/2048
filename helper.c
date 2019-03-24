#include <stdio.h>
#include <stdbool.h>
#include <ncurses.h>
#include "defs.h"

typedef struct Box
{
    unsigned int val; // 0 val = no value

} Box;

void displayGrid(Box grid[GRID_SIZE][GRID_SIZE]);

bool addRandom(Box grid[GRID_SIZE][GRID_SIZE]);
void addTo(Box grid[GRID_SIZE][GRID_SIZE], int x, int y, char c) // Last parameter c == L add from right c == R add from left, c== U c == D same conecept.
{
    if (c == 'H')
    {
        int num = grid[x + 1][y].val;
        grid[x][y].val += num;
        grid[x + 1][y].val = 0;
    }
    if (c == 'V')
    {
        int num = grid[x][y + 1].val;
        grid[x][y].val += num;
        grid[x][y + 1].val = 0;
    }
}

void leftShiftArray(Box grid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++) // Inefficient but we have to run this nested loops Grid_size - 1 times to ensure everything was shifted left
    {
        for (int y = 0; y < GRID_SIZE; y++)
        {
            for (int x = 0; x < GRID_SIZE; x++)
            {
                if (x + 1 >= GRID_SIZE)
                {
                    // Out of bounds
                }
                else
                {
                    if (grid[x][y].val == 0)
                    {
                        int nextVal = grid[x + 1][y].val;
                        //printf("next val %d\n", nextVal);
                        grid[x][y].val = nextVal;
                        grid[x + 1][y].val = 0;
                    }
                }
            }
        }
    }
}

void rightShiftArray(Box grid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++) // Inefficient but we have to run this nested loops Grid_size - 1 times to ensure everything was shifted left
    {
        for (int y = 0; y < GRID_SIZE; y++) // Each Row
        {
            for (int x = GRID_SIZE - 1; x >= 0; x--) // Each number in row (col)
            {
                if (x - 1 < 0)
                {
                    // Out of bounds
                }
                else
                {
                    if (grid[x][y].val == 0)
                    {
                        int nextVal = grid[x - 1][y].val;
                        //printf("next val %d\n", nextVal);
                        grid[x][y].val = nextVal;
                        grid[x - 1][y].val = 0;
                    }
                }
            }
        }
    }
}
void upShiftArray(Box grid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++) // Inefficient but we have to run this nested loops Grid_size - 1 times to ensure everything was shifted
    {
        for (int x = 0; x < GRID_SIZE; x++) // Each col
        {
            for (int y = 0; y < GRID_SIZE; y++) // Each number in col
            {
                if (y + 1 >= GRID_SIZE)
                {
                    // Out of bounds
                }
                else
                {
                    if (grid[x][y].val == 0)
                    {
                        int nextVal = grid[x][y + 1].val;
                        //printf("next val %d\n", nextVal);
                        grid[x][y].val = nextVal;
                        grid[x][y + 1].val = 0;
                    }
                }
            }
        }
    }
}
void downShiftArray(Box grid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++) // Inefficient but we have to run this nested loops Grid_size - 1 times to ensure everything was shifted
    {
        for (int x = 0; x < GRID_SIZE; x++) // Each col
        {
            for (int y = GRID_SIZE - 1; y >= 0; y--) // Each number in col
            {
                if (y - 1 < 0)
                {
                    // Out of bounds
                }
                else
                {
                    if (grid[x][y].val == 0)
                    {
                        int nextVal = grid[x][y - 1].val;
                        //printf("next val %d\n", nextVal);
                        grid[x][y].val = nextVal;
                        grid[x][y - 1].val = 0;
                    }
                }
            }
        }
    }
}

bool moveLeft(Box grid[GRID_SIZE][GRID_SIZE])
{
    leftShiftArray(grid);
    // We will scan left to right and merge the left most rows
    for (int y = 0; y < GRID_SIZE; y++) //Row
    {
        for (int x = 0; x < GRID_SIZE; x++) // Col
        {
            // if the value at the current box equals the value next to the box add them together
            if (grid[x][y].val == grid[x + 1][y].val)
            {
                addTo(grid, x, y, 'H');
                x++;
            }
        }
    }
    leftShiftArray(grid);   // There will be 0's in place of the adding so we will shift the array.
    return addRandom(grid); // Adds random number to grid and returns if was successful
}

bool moveRight(Box grid[GRID_SIZE][GRID_SIZE])
{
    rightShiftArray(grid);
    // We will scan right to left and merge the right most rows
    for (int y = 0; y < GRID_SIZE; y++) //Row
    {
        for (int x = 0; x < GRID_SIZE; x++) // Col
        {
            // if the value at the current box equals the value next to the box add them together
            if (grid[x][y].val == grid[x + 1][y].val)
            {
                addTo(grid, x, y, 'H');
                x++;
            }
        }
    }
    rightShiftArray(grid);  // There will be 0's in place of the adding so we will shift the array.
    return addRandom(grid); // Adds random number to grid and returns if was successful
}

bool moveUp(Box grid[GRID_SIZE][GRID_SIZE])
{
    upShiftArray(grid);
    // We will scan right to left and merge the right most rows
    for (int x = 0; x < GRID_SIZE; x++) //Row
    {
        for (int y = 0; y < GRID_SIZE; y++) // Col
        {
            // if the value at the current box equals the value next to the box add them together
            if (grid[x][y].val == grid[x][y + 1].val)
            {
                addTo(grid, x, y, 'V');
                //printf();
                y++;
            }
        }
    }
    upShiftArray(grid);     // There will be 0's in place of the adding so we will shift the array.
    return addRandom(grid); // Adds random number to grid and returns if was successful
}

bool moveDown(Box grid[GRID_SIZE][GRID_SIZE])
{
    downShiftArray(grid);
    // We will scan right to left and merge the right most rows
    for (int x = 0; x < GRID_SIZE; x++) //Row
    {
        for (int y = 0; y < GRID_SIZE; y++) // Col
        {
            // if the value at the current box equals the value next to the box add them together
            if (grid[x][y].val == grid[x][y + 1].val)
            {
                addTo(grid, x, y, 'V');
                //printf();
                y++;
            }
        }
    }
    downShiftArray(grid);   // There will be 0's in place of the adding so we will shift the array.
    return addRandom(grid); // Adds random number to grid and returns if was successful
}

int highScore(Box grid[GRID_SIZE][GRID_SIZE])
{
}

void populateGrid(Box grid[GRID_SIZE][GRID_SIZE])
{
    for (int x = 0; x < GRID_SIZE; x++)
    {
        for (int y = 0; y < GRID_SIZE; y++)
        {
            grid[x][y].val = 0;
        }
    }
    addRandom(grid);
}

bool addRandom(Box grid[GRID_SIZE][GRID_SIZE])
{
    int rVal = 2 + rand() % (4 + 1 - 2); // Generates random value number 2 - 4, NO.. what if its 3?
    if (rVal == 3)
    {
        int weight = 0 + rand() % (100 + 1 - 0); // GEnerates random number from 0-100
        if (weight < 50)
        { // Round down
            rVal = 2;
        }
        else
        { // Round up
            rVal = 4;
        }
    }
    int rX = 0 + rand() % ((GRID_SIZE - 1) + 1 - 0); // Generates random X val,
    int rY = 0 + rand() % ((GRID_SIZE - 1) + 1 - 0); // Generates random Y val,
    bool retVal = false;
    move(0, 0);
    printf("rX: %d rY: %d rV: %d \n", rX, rY, rVal);
    if (grid[rX][rY].val == 0) // If value at random picked position is 0
    {
        grid[rX][rY].val = rVal;
        retVal = true;
        return retVal;
    }
    else // Else go through each position on the grid and check if random value can be addded
    {
        for (int x = 0; x < GRID_SIZE; x++)
        {
            for (int y = 0; y < GRID_SIZE; y++)
            {
                if (grid[x][y].val == 0)
                {
                    grid[x][y].val = rVal;
                    retVal = true;
                    return retVal;
                }
            }
        }
        return retVal;
    }
}

void displayGrid(Box grid[GRID_SIZE][GRID_SIZE])
{
    for (int y = 0; y < GRID_SIZE; y++)
    {
        for (int x = 0; x < GRID_SIZE; x++)
        {
            if (grid[x][y].val == 0)
            { // If its a zero Box
                move(y, x);
                refresh();
                printf("[   ]");
            }
            else
            {
                move(y, x);
                refresh();
                printf("[ %u ]", grid[x][y].val);
            }
        }
        printf("\n");
    }
}
