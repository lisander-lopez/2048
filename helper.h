#include <stdio.h>
#include <stdbool.h>
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

// Adds random number 2 or 4 and adds to the grid, if cannot add, return false and game has ended

bool addRandom(Box **grid);
//Adds one box value to another and deletes "val"
void addTo(Box **grid, int x, int y, Direction d);

//Moves grid to the left
bool moveLeft(Box **grid);

//Moves grid to the right
bool moveRight(Box **grid);

//Moves grid Up
bool moveUp(Box **grid);

//Moves grid Down
bool moveDown(Box **grid);

// Calculates largest number in grid
int highScore(Box **grid);

// Populates all cells with empty boxes.
Box **populateGrid(Game g);

/* Displays Grid to the terminal 
 * AND calculates the highest score (Since we iterate
 * to print out the grid might aswell calculate 
 * the highest score on the grid)
*/
void displayGrid(Game g);

/* Moves elements to the left in all arrays in grid
    You have to call this GRID_SIZE - 1 times.
    because if we have [0,0,0,4] first call will do [0,0,4,0] Second will do [0,4,0,0] Third will do [4,0,0,0]
*/
void leftShiftArray(Box **grid);

void rightShiftArray(Box **grid);
void upShiftArray(Box **grid);
void downShiftArray(Box **grid);
