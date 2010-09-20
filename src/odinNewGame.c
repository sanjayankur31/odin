/*
 * =====================================================================================
 *
 *       Filename:  odinNewGame.c
 *
 *    Description:  This file has the functions that handle the "New Game" selection
 *
 *        Version:  1.0
 *        Created:  06/09/10 15:31:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ankur Sinha (FranciscoD), sanjay DOT ankur AT gmail DOT com
 *        Company:  
 *
 * =====================================================================================
 */

/* Copyright 2010 Ankur Sinha 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "odinNewGame.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinNewGame
 *  Description:  Handles the new game sub menu
 *                TODO : can this and the main menu be combined into one? Too much code 
 *                wastage here.
 *
 *                Args : NONE
 *
 *
 *                returns : int
 *                          - odinOptionSelected : selected menu option
 * =====================================================================================
 */
int
odinNewGame ()
{   
    /* Declarations */
    WINDOW *odinNewGameWindow;

    char *odinNewGameGreet[] = {"Game Menu", "=============" };
    char *odinNewGameOptions[] = {"1.Single Player", "2.Two Player", "3.Demo", "4.Back", 0 };
    char *odinNewGameMessages[] = {"Start a single player game", "Start a two player game", "View an AI vs AI demo", "Go back to main menu",0};

    /*  only needed for counting max number of options  */
    char **odinOptions; 

    /*  A new window for this  */
    WINDOW *odinMainMenuWindow;
    const int odinMainMenuCols  = 40;
    const int odinMainMenuLines = 20;

    /*  mimic high lighting 
     *  range from 0 to 3 (indexes)*/
    static int odinOptionSelected = 0;

    /* Variables needed for the highlighting */
    int odinMaxRow = 0;
    int odinKey = 0;
    int odinStartRow = 6;

    odinOptions = odinNewGameOptions;

    odinMainMenuWindow = newwin(odinMainMenuLines,odinMainMenuCols,(LINES - odinMainMenuLines)/2,(COLS - odinMainMenuCols)/2);
    box(odinMainMenuWindow,0,0);

    mvwprintw(odinMainMenuWindow,3,(odinMainMenuCols - strlen(odinNewGameGreet[0]))/2, "%s",odinNewGameGreet[0]);
    mvwprintw(odinMainMenuWindow,4,(odinMainMenuCols - strlen(odinNewGameGreet[1]))/2, "%s",odinNewGameGreet[1]);

    wrefresh(odinMainMenuWindow);

    /*  count the total number of options */
    while(*odinOptions)
    {
        odinMaxRow++;
        odinOptions++;
    }

    /*  I don't think this is needed  */
    if(odinOptionSelected >= odinMaxRow)
    {
        odinOptionSelected = 0;
    }

    keypad(odinMainMenuWindow, TRUE);
    cbreak();
    noecho();
    odinKey = 0;

    while(odinKey != 'q' && odinKey != KEY_ENTER && odinKey != '\n')
    {
        if(odinKey == KEY_UP)
        {
            /* if I'm on the first one, I need to come to the last one, like a circular queue */
            if(odinOptionSelected == 0)
            {
                odinOptionSelected = odinMaxRow -1;
            }
            /*  else just subtract one */
            else
            {
                odinOptionSelected--;
            }
        }


        if(odinKey == KEY_DOWN)
        {
            /* If I'm on the last one, I need to come to the first one, like a circular queue */
            if(odinOptionSelected == (odinMaxRow -1))
            {
                odinOptionSelected = 0;
            }
            /*  else just go to the next one  */
            else 
            {
                odinOptionSelected++;
            }
        }

        /*  Draw with new high light  */
        odinMenuDraw(odinNewGameOptions, odinNewGameMessages , odinMainMenuWindow, odinMainMenuCols, odinOptionSelected, odinStartRow );

        /*  Get keypress, remember, we use wgetch because we're not in stdscr anymore  */
        odinKey = wgetch(odinMainMenuWindow);
    }
    keypad(odinMainMenuWindow,FALSE);
    nocbreak();
    echo();

    if(odinKey == 'q')
        odinOptionSelected = 3;


    return(odinOptionSelected +1);
}		/* -----  end of function odinNewGame  ----- */
