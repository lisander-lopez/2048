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
