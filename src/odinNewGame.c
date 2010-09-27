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

    int odinMenuSelect = odinMenusGeneric(&odinNewGameWindow, odinNewGameGreet, odinNewGameOptions, odinNewGameMessages);

    /* use a switch later */
    odinGameEngine ();


    return 0;
}		/* -----  end of function odinNewGame  ----- */
