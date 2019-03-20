#include <stdio.h>
#include <stdbool.h>
#include "defs.h"

typedef struct Box
{
    unsigned int val; // 0 val = no value

} Box;

//Adds one box value to another and deletes "val"
void addTo(Box val, Box addTo);

//Moves grid to the left
void moveLeft(Box grid[GRID_SIZE][GRID_SIZE]);

//Moves grid to the right
void moveRight(Box grid[GRID_SIZE][GRID_SIZE]);

//Moves grid Up
void moveUp(Box grid[GRID_SIZE][GRID_SIZE]);

//Moves grid Down
void moveDown(Box grid[GRID_SIZE][GRID_SIZE]);

// Calculates largest number in grid
int highScore(Box grid[GRID_SIZE][GRID_SIZE]);

// Populates all cells with empty boxes.
void populateGrid(Box grid[GRID_SIZE][GRID_SIZE]);

// Displays Grid to the terminal
void displayGrid(Box grid[GRID_SIZE][GRID_SIZE]);

/* Moves elements to the left in all arrays in grid
    You have to call this GRID_SIZE - 1 times.
    because if we have [0,0,0,4] first call will do [0,0,4,0] Second will do [0,4,0,0] Third will do [4,0,0,0]
*/

void leftShiftArray(Box grid[GRID_SIZE][GRID_SIZE]);