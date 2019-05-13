#include <stdio.h>
#include <stdbool.h>
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
    // Setup Game and Grid
    Game g;
    g.grid = populateGrid(g);

    srand(time(NULL));   // Init rand seed
    bool running = true; // Not loosing condition
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    //nodelay(stdscr, TRUE);
    //noraw();
    //noecho();
    //Game Loop
    displayGrid(g);
    while (running)
    {
        int c = getch();

        if (c == KEY_LEFT)
        {
            if (!moveLeft(g.grid))
            {
                running = false;
            }
            else
            {
                displayGrid(g);
            }
        }
        if (c == KEY_RIGHT)
        {
            if (!moveRight(g.grid))
            {
                running = false;
            }
            else
            {
                displayGrid(g);
            }
        }
        if (c == KEY_UP)
        {
            if (!moveUp(g.grid))
            {
                running = false;
            }
            else
            {
                displayGrid(g);
            }
        }
        if (c == KEY_DOWN)
        {
            if (!moveDown(g.grid))
            {
                running = false;
            }
            else
            {
                displayGrid(g);
            }
        }
        printf("HIGH SCORE: %d\n", g.high);
    }
    refresh();
    getch();
    erase();
    endwin();
    fflush(stdout);
    return 0;
}