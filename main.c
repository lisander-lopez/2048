#include <stdio.h>
#include <ncurses.h>
#include "defs.h"
#include "helper.h"
#include "time.h"

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

    srand(time(NULL));   // Init rand seed
    bool running = true; // Not loosing condition
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    //nodelay(stdscr, TRUE);
    //noraw();
    //noecho();
    //Game Loop
    /*
    while (running)
    {
        int c = getch();

        if (c == KEY_LEFT)
        {
            if (!moveLeft(grid))
            {
                running = false;
            }
            else
            {
                displayGrid(grid);
            }
        }
    }
    */
    grid[0][1].val = 2;
    grid[2][1].val = 2;
    moveLeft(grid);
    displayGrid(grid);
    refresh();
    getch();
    erase();
    endwin();
    fflush(stdout);
    return 0;
}