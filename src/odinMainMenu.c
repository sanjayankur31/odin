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
    WINDOW *odinMainMenuWindow;

    int odinSelectedOption = odinMenusGeneric(&odinMainMenuWindow, odinMainMenuGreet, odinMainMenuOptions, odinOptionMessages);

    switch(odinSelectedOption)
    {
        case 1: 
            odinNewGame();
            break;

        case 2: 
            odinDocumentation();
            break;

        case 3: 
            odinOptions();
            break;       
        
        default:
            break;        
    }

    return 0;

}		/* -----  end of function odinMainMenu  ----- */

