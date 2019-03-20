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

void moveLeft(Box grid[GRID_SIZE][GRID_SIZE])
{
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
    for (int x = 0; x < GRID_SIZE; x++)
    {
        for (int y = 0; y < GRID_SIZE; y++)
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