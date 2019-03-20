#include <stdio.h>

#include "defs.h"
#include "helper.h"
/*

Parts of this code was hugely influenced by my CSE220 - Systems Programming Class,
specifically my second programming assignment.

Shoutout to: Ethan Blanton

To add on, Tests file and Makefile templete was taken from my CSE307 - Software in Practice Class,

Shoutout to: Carl Alphonce

Finish condition : If we cant generate a random new box
*/

int main(int argsc, char *argsv[])
{
    // Setup grid
    Box grid[GRID_SIZE][GRID_SIZE];
    populateGrid(grid);
    grid[0][0].val = 2;
    grid[1][0].val = 1;
    grid[2][0].val = 3;
    grid[3][0].val = 4;
    moveLeft(grid);
    displayGrid(grid);
    return 0;
}