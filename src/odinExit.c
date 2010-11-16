/*
 * =====================================================================================
 *
 *       Filename:  odinExitWindow.c
 *
 *    Description:  code for my exit confirmation box
 *
 *        Version:  1.0
 *        Created:  18/10/10 15:54:22
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


#include	"odinExit.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinExitWindow
 *  Description:  My exit window
 *                  
 *                  - args : 
 *                  struct odinBoard odin 
 *                      needed to clear the screen using werase etc.
 *
 *                  - returns : gint
 *                      1 if NO
 *                      0 if YES
 *
 * =====================================================================================
 */
gint
odinExit (struct odinBoard odin)
{
    WINDOW *odinExitWindow;
    gint rval = 0;

    gchar *odinExitGreet[] = {"Exit?", "=============" };
    gchar *odinExitOptions[] = {"YES", "NO ", 0 };
    gchar *odinExitMessages[] = {"Quit game", "Go back and continue",0};

    rval = odinMenusGeneric(&odinExitWindow, odinExitGreet, odinExitOptions, odinExitMessages);
    /*-----------------------------------------------------------------------------
     *  reset terminal to game mode
     *-----------------------------------------------------------------------------*/
    cbreak();
    noecho();

    return rval;

}		/* -----  end of function odinExitWindow  ----- */
