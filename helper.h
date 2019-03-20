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