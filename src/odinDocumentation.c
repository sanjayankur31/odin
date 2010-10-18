/*
 * =====================================================================================
 *
 *       Filename:  odinDocumentation.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/09/10 14:50:07
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


#include	"odinDocumentation.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinDocumentation
 *  Description:  This method displays the documentation for the project
 *
 *                  - args : NONE
 *
 *                  - returns : gint
 *                      0 if OK
 *                      NONZERO if something went wrong
 * =====================================================================================
 */
gint
odinDocumentation ( )
{
    WINDOW *odinNewGameWindow;

    gchar *odinNewGameGreet[] = {"Controls", "=============" };
    gchar *odinNewGameOptions[] = {" a | LeftArrow ", " d | RightArrow", " w |  UpArrow  ", " s | DownArrow ","q", 0 };
    gchar *odinNewGameMessages[] = {"Move Left", "Move Right", "Move Up", "Move Down","Quit",0};
    gint odinMenuSelect;

    odinMenuSelect = odinMenusGeneric(&odinNewGameWindow, odinNewGameGreet, odinNewGameOptions, odinNewGameMessages);

    return 0;
}		/* -----  end of function odinDocumentation  ----- */
