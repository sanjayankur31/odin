/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  the main file to odin
 *
 *        Version:  1.0
 *        Created:  24/08/10 09:38:52
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

#include	"main.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  the main method to odin
 *                  - args:
 *                      gint argc : number of command line arguments
 *                      gchar **argv : argument list
 *
 *                  - returns gint
 *                      0 if all goes well
 *                      non zero otherwise
 *                      
 * =====================================================================================
 */
gint 
main(gint argc, gchar **argv){
    /* Initialize the ncurses library */
    initscr();

    /*  invisible cursor  */
    curs_set(0);

    /* display the splash */
    odinSplash();
    refresh();
    
    odinMainMenu();

    /*  invisible cursor  */
    curs_set(1);
    endwin();
	return 0;
}		/* -----  end of function main  ----- */


