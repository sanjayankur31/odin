/*
 * =====================================================================================
 *
 *       Filename:  odinMenus.c
 *
 *    Description:  function definitions for drawing and handling the menus
 *
 *        Version:  1.0
 *        Created:  20/09/10 18:55:07
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


#include	"odinMenus.h"

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
odinMenuDraw (char *options[], char *optionMessages[],WINDOW *odinMenuWindow,int odinMainMenuCols, int odinCurrentHighlight ,int odinStartRow)
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
            wattron(odinMenuWindow, A_STANDOUT);

        odinTextPtr = options[odinCurrentRow];
        mvwprintw(odinMenuWindow,odinCurrentRow + odinStartRow,(odinMainMenuCols - strlen(odinTextPtr))/2, "%s",odinTextPtr);

        /*  switch off the attribute  */
        if(odinCurrentRow == odinCurrentHighlight)
            wattroff(odinMenuWindow, A_STANDOUT);

        /*  print the description  */
        /* TODO : position the message properly */
        if(odinCurrentRow == odinCurrentHighlight)
        {
            odinMessagePtr = optionMessages[odinCurrentRow];
            for ( i = 2; i < odinMainMenuCols -1; i++)
            {
                
                mvwaddch(odinMenuWindow,odinStartRow +8, i, ' ');
            }
            mvwprintw(odinMenuWindow,odinStartRow + 8, 2, "%c %s",'>', odinMessagePtr);
        }
        
        odinCurrentRow++;
        odinOptionsPtr++;
    }

    wrefresh(odinMenuWindow);
}		/* -----  end of function odinMenuDraw  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinMenusGeneric
 *  Description:  Displays the main menu to the user and permits the user to select an 
 *                  option
 *
 *                  -args: 
 *                      WINDOW **odinMenusGenericWindow : a window pointer passed from
 *                      parent function
 *
 *                      char **odinMenusGenericGreet : array having Greets
 *
 *                      char ** odinMenusGenericOptions : array having separate selectable
 *                      options
 *
 *                      char **odinGenericMessages : help messages to display
 *
 *                  - returns: int
 *                      the index of selected option
 *                      -ve on error
 *
 * =====================================================================================
 */
int
odinMenusGeneric (WINDOW **odinMenusGenericWindow, char **odinMenusGenericGreet, char **odinMenusGenericOptions, char **odinGenericMessages )
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

    /*  only needed for counting max number of options  */
    char **odinOptions; 

    /*  A new window for this  
     *  At the moment, I'm using a constant size for the menus
     */
    const int odinMenusGenericCols  = 40;
    const int odinMenusGenericLines = 20;

    /*  mimic high lighting 
     *  range from 0 to 3 (indexes)*/
    static int odinOptionSelected = 0;

    /* Variables needed for the highlighting */
    int odinMaxRow = 0;
    int odinKey = 0;
    int odinStartRow = 6;

    odinOptions = odinMenusGenericOptions;

    *odinMenusGenericWindow = newwin(odinMenusGenericLines,odinMenusGenericCols,(LINES - odinMenusGenericLines)/2,(COLS - odinMenusGenericCols)/2);
    box(*odinMenusGenericWindow,0,0);

    mvwprintw(*odinMenusGenericWindow,3,(odinMenusGenericCols - strlen(odinMenusGenericGreet[0]))/2, "%s",odinMenusGenericGreet[0]);
    mvwprintw(*odinMenusGenericWindow,4,(odinMenusGenericCols - strlen(odinMenusGenericGreet[1]))/2, "%s",odinMenusGenericGreet[1]);

    wrefresh(*odinMenusGenericWindow);

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

    keypad(*odinMenusGenericWindow, TRUE);
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
        odinMenuDraw(odinMenusGenericOptions, odinGenericMessages , *odinMenusGenericWindow, odinMenusGenericCols, odinOptionSelected, odinStartRow );

        /*  Get keypress, remember, we use wgetch because we're not in stdscr anymore  */
        odinKey = wgetch(*odinMenusGenericWindow);
    }
    keypad(*odinMenusGenericWindow,FALSE);
    nocbreak();
    echo();

    if(odinKey == 'q')
        odinOptionSelected = 3;


    return(odinOptionSelected +1);

}		/* -----  end of function odinMenusGeneric  ----- */

