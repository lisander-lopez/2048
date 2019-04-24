#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ncurses.h>
#include "defs.h"

typedef struct Box
{
    unsigned int val; // 0 val = no value

} Box;

typedef struct Game
{
    int high;
    Box **grid;
} Game;

typedef enum
{
    HORIZONTAL,
    VERTICAL
} Direction;

bool addRandom(Box **grid);

void addTo(Box **grid, int x, int y, Direction d) // Last parameter c == L add from right c == R add from left, c== U c == D same conecept.
{
    if (d == HORIZONTAL)
    {
        int num = grid[x + 1][y].val;
        grid[x][y].val += num;
        grid[x + 1][y].val = 0;
    }
    if (d == VERTICAL)
    {
        int num = grid[x][y + 1].val;
        grid[x][y].val += num;
        grid[x][y + 1].val = 0;
    }
}

void leftShiftArray(Box **grid)
{
    for (int i = 0; i < GRID_SIZE; i++) // Inefficient but we have to run this nested loops Grid_size - 1 times to ensure everything was shifted left
    {
        for (int y = 0; y < GRID_SIZE; y++)
        {
            for (int x = 0; x < GRID_SIZE; x++) // LOOP TO GRID_SIZE - 1
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

void rightShiftArray(Box **grid)
{
    for (int i = 0; i < GRID_SIZE; i++) // Inefficient but we have to run this nested loops Grid_size - 1 times to ensure everything was shifted left
    {
        for (int y = 0; y < GRID_SIZE; y++) // Each Row
        {
            for (int x = GRID_SIZE - 1; x >= 0; x--) // Each number in row (col) LOOP UNTIL x>0 not >=
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
void upShiftArray(Box **grid)
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
void downShiftArray(Box **grid)
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

bool moveLeft(Box **grid)
{
    leftShiftArray(grid);
    // We will scan left to right and merge the left most rows
    for (int y = 0; y < GRID_SIZE; y++) //Row
    {
        for (int x = 0; x < GRID_SIZE - 1; x++) // Col - We are checking x and x + 1 so we will loop until SIZE-1
        {
            // if the value at the current box equals the value next to the box add them together
            if (grid[x][y].val == grid[x + 1][y].val)
            {
                addTo(grid, x, y, HORIZONTAL);
                x++;
            }
        }
    }
    leftShiftArray(grid);   // There will be 0's in place of the adding so we will shift the array.
    return addRandom(grid); // Adds random number to grid and returns if was successful
}

bool moveRight(Box **grid)
{
    rightShiftArray(grid);
    // We will scan right to left and merge the right most rows
    for (int y = 0; y < GRID_SIZE; y++) //Row
    {
        for (int x = 0; x < GRID_SIZE - 1; x++) // Col
        {
            // if the value at the current box equals the value next to the box add them together
            if (grid[x][y].val == grid[x + 1][y].val)
            {
                addTo(grid, x, y, HORIZONTAL);
                x++;
            }
        }
    }
    rightShiftArray(grid);  // There will be 0's in place of the adding so we will shift the array.
    return addRandom(grid); // Adds random number to grid and returns if was successful
}

bool moveUp(Box **grid)
{
    upShiftArray(grid);
    // We will scan right to left and merge the right most rows
    for (int x = 0; x < GRID_SIZE; x++) //Row
    {
        for (int y = 0; y < GRID_SIZE - 1; y++) // Col
        {
            // if the value at the current box equals the value next to the box add them together
            if (grid[x][y].val == grid[x][y + 1].val)
            {
                addTo(grid, x, y, VERTICAL);
                //printf();
                y++;
            }
        }
    }
    upShiftArray(grid);     // There will be 0's in place of the adding so we will shift the array.
    return addRandom(grid); // Adds random number to grid and returns if was successful
}

bool moveDown(Box **grid)
{
    downShiftArray(grid);
    // We will scan right to left and merge the right most rows
    for (int x = 0; x < GRID_SIZE; x++) //Row
    {
        for (int y = 0; y < GRID_SIZE - 1; y++) // Col
        {
            // if the value at the current box equals the value next to the box add them together
            if (grid[x][y].val == grid[x][y + 1].val)
            {
                addTo(grid, x, y, VERTICAL);
                //printf();
                y++;
            }
        }
    }
    downShiftArray(grid);   // There will be 0's in place of the adding so we will shift the array.
    return addRandom(grid); // Adds random number to grid and returns if was successful
}

int highScore(Box **grid)
{
    return 0;
}

Box **populateGrid(Box **grid)
{
    grid = calloc(GRID_SIZE, sizeof(Box) * GRID_SIZE);
    for (int i = 0; i < GRID_SIZE; i++)
    {
        grid[i] = malloc(sizeof(Box) * GRID_SIZE);
    }
    addRandom(grid);
    return grid;
}

bool addRandom(Box **grid)
{
    // Equation int rVal = 2 + 2 *(rand() %2);
    int rVal = (rand() % 2) ? 2 : 4;
    int rX = rand() % GRID_SIZE; // Generates random X val,
    int rY = rand() % GRID_SIZE; // Generates random Y val,
    bool retVal = false;
    move(0, 0);
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

void displayGrid(Box **grid)
{
    for (int y = 0; y < GRID_SIZE; y++)
    {
        for (int x = 0; x < GRID_SIZE; x++)
        {
            if (grid[x][y].val == 0)
            { // If its a zero Box
                move(y, x);
                refresh();
                printf("[ %3c ]", ' ');
            }
            else
            {
                move(y, x);
                refresh();
                printf("[ %4u ]", grid[x][y].val);
            }
        }
        printf("\n");
    }
}
