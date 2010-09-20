/*
 * =====================================================================================
 *
 *       Filename:  odinMainMenu.c
 *
 *    Description: holds code for displaying of the main application menu 
 *
 *        Version:  1.0
 *        Created:  28/08/10 00:06:28
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


#include	"odinMainMenu.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinMenuDraw
 *  Description:  This method does the actual drawing. It is needed to implement the 
 *                highlighting.
 *
 *                  - Args:
 *                      char *options[] : options array.
 *                      WINDOW *odinMainMenuWindow : the window to draw on.
 *                      int odinMainMenuCols : number of columns in new window.
 *                      int odinCurrentHighlight : the option currently highlighted.
 *                      int odinStartRow : Begin printing from this row.
 *
 *                  - Returns: int
 *                      0 if all OK.
 *                      non zero otherwise.
 *
 * =====================================================================================
 */
void
odinMenuDraw (char *options[], char *optionMessages[] , WINDOW *odinMainMenuWindow,int odinMainMenuCols, int odinCurrentHighlight ,int odinStartRow)
{
    /*  Declarations  */
    int odinCurrentRow = 0;
    char **odinOptionsPtr;
    char *odinTextPtr;
    char *odinMessagePtr;
    int i;

    odinOptionsPtr = options;
    while(*odinOptionsPtr)
    {
        /*  Make the current one BOLD */
        if(odinCurrentRow == odinCurrentHighlight)
            wattron(odinMainMenuWindow, A_STANDOUT);

        odinTextPtr = options[odinCurrentRow];
        mvwprintw(odinMainMenuWindow,odinCurrentRow + odinStartRow,(odinMainMenuCols - strlen(odinTextPtr))/2, "%s",odinTextPtr);

        /*  switch off the attribute  */
        if(odinCurrentRow == odinCurrentHighlight)
            wattroff(odinMainMenuWindow, A_STANDOUT);

        /*  print the description  */
        /* TODO : position the message properly */
        if(odinCurrentRow == odinCurrentHighlight)
        {
            odinMessagePtr = optionMessages[odinCurrentRow];
            for ( i = 2; i < odinMainMenuCols -1; i++)
            {
                
                mvwaddch(odinMainMenuWindow,odinStartRow +8, i, ' ');
            }
            mvwprintw(odinMainMenuWindow,odinStartRow + 8, 2, "%c %s",'>', odinMessagePtr);
        }
        
        odinCurrentRow++;
        odinOptionsPtr++;
    }

    wrefresh(odinMainMenuWindow);
}		/* -----  end of function odinMenuDraw  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinMainMenu
 *  Description:  Displays the main menu to the user and permits the user to select an 
 *                  option
 *
 *                  -args: NONE
 *
 *                  - returns: int
 *                      the index of selected option
 *                      -ve on error
 *
 * =====================================================================================
 */
int
odinMainMenu ()
{
    /*  Declarations  */
    /* Main menu 
     *
     * Key board used to select.
     * We aren't including mouse support just yet
     *
     * New game
     * Controls/Docs
     * Options ?
     * Quit
     */
    char *odinMainMenuGreet[] = {"Main Menu", "=============" };
    char *odinMainMenuOptions[] = {"1.New Game", "2.Controls\\Documentation", "3.Options", "4.Quit", 0 };
    char *odinOptionMessages[] = {"Start a new game", "See the program documentation", "Configure the options", "Quit the game",0};

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

    odinOptions = odinMainMenuOptions;

    odinMainMenuWindow = newwin(odinMainMenuLines,odinMainMenuCols,(LINES - odinMainMenuLines)/2,(COLS - odinMainMenuCols)/2);
    box(odinMainMenuWindow,0,0);

    mvwprintw(odinMainMenuWindow,3,(odinMainMenuCols - strlen(odinMainMenuGreet[0]))/2, "%s",odinMainMenuGreet[0]);
    mvwprintw(odinMainMenuWindow,4,(odinMainMenuCols - strlen(odinMainMenuGreet[1]))/2, "%s",odinMainMenuGreet[1]);

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
        odinMenuDraw(odinMainMenuOptions, odinOptionMessages , odinMainMenuWindow, odinMainMenuCols, odinOptionSelected, odinStartRow );

        /*  Get keypress, remember, we use wgetch because we're not in stdscr anymore  */
        odinKey = wgetch(odinMainMenuWindow);
    }
    keypad(odinMainMenuWindow,FALSE);
    nocbreak();
    echo();

    if(odinKey == 'q')
        odinOptionSelected = 3;


    return(odinOptionSelected +1);

}		/* -----  end of function odinMainMenu  ----- */

