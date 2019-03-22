#include <stdio.h>
#include <stdbool.h>
#include "defs.h"

typedef struct Box
{
    unsigned int val; // 0 val = no value

} Box;

void addTo(Box val, Box addTo)
{
}

void leftShiftArray(Box grid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++)
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
                        printf("next val %d\n", nextVal);
                        grid[x][y].val = nextVal;
                        grid[x + 1][y].val = 0;
                    }
                }
            }
        }
    }
}

void moveLeft(Box grid[GRID_SIZE][GRID_SIZE])
{
    leftShiftArray(grid);
    // We will scan left to right and merge the left most rows
    for (int y = 0; y < GRID_SIZE; y++) //Row
    {
        for (int x = 0; x < GRID_SIZE; x++) // Col
        {
        }
    }
}

void moveRight(Box grid[GRID_SIZE][GRID_SIZE])
{
}

void moveUp(Box grid[GRID_SIZE][GRID_SIZE])
{
}

void moveDown(Box grid[GRID_SIZE][GRID_SIZE])
{
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
                if (grid[rX][rY].val == 0)
                {
                    grid[rX][rY].val = rVal;
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
                printf("[   ]");
            }
            else
            {
                printf("[ %u ]", grid[x][y].val);
            }
        }
        printf("\n");
    }
}
