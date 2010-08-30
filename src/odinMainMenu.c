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
 *         Name:  odinMainMenuDraw
 *  Description:  This method does the actual drawing. It is needed to implement the 
 *                  highlighting
 *
 *                  - Args:
 *                      char *options[] : options array
 *                      WINDOW *odinMainMenuWindow : the window to draw on
 *                      int odinCurrentHighlight : the option currently highlighted
 *                      int 
 *
 *                  - Returns: int
 *                      0 if all OK
 *                      non zero otherwise
 *
 * =====================================================================================
 */
    void
odinMainMenuDraw (char *options[], WINDOW *odinMainMenuWindow, int odinCurrentHighlight )
{
    mvwprintw(odinMainMenuWindow,6,(odinMainMenuCols - strlen(odinMainMenuOptions[2]))/2, "%s",odinMainMenuOptions[2]);
    mvwprintw(odinMainMenuWindow,7,(odinMainMenuCols - strlen(odinMainMenuOptions[3]))/2, "%s",odinMainMenuOptions[3]);
    mvwprintw(odinMainMenuWindow,8,(odinMainMenuCols - strlen(odinMainMenuOptions[4]))/2, "%s",odinMainMenuOptions[4]);
    mvwprintw(odinMainMenuWindow,9,(odinMainMenuCols - strlen(odinMainMenuOptions[5]))/2, "%s",odinMainMenuOptions[5]);

    return 0;
}		/* -----  end of function odinMainMenuDraw  ----- */

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
    const char *odinMainMenuGreet[] = {"Main Menu", "=============" };
    const char *odinMainMenuOptions[] = {"1.New Game", "2.Controls\\Documentation", "3.Options", "4.Quit" };

    WINDOW *odinMainMenuWindow;
    const int odinMainMenuCols  = 40;
    const int odinMainMenuLines = 20;

    /*  mimic high lighting 
     *  range from 2 to 5 (indexes)*/
    static int odinMainMenuOptionSelected = 2;

    odinMainMenuWindow = newwin(odinMainMenuLines,odinMainMenuCols,(LINES - odinMainMenuLines)/2,(COLS - odinMainMenuCols)/2);

    box(odinMainMenuWindow,0,0);
    mvwprintw(odinMainMenuWindow,3,(odinMainMenuCols - strlen(odinMainMenuOptions[0]))/2, "%s",odinMainMenuGreet[0]);
    mvwprintw(odinMainMenuWindow,4,(odinMainMenuCols - strlen(odinMainMenuOptions[1]))/2, "%s",odinMainMenuGreeet[1]);


    wrefresh(odinMainMenuWindow);
    sleep(2);

    return 0;
}		/* -----  end of function odinMainMenu  ----- */

