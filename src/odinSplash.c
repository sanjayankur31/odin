/*
 * =====================================================================================
 *
 *       Filename:  odinSplash.c
 *
 *    Description:  The odin splash method and other utils
 *
 *        Version:  1.0
 *        Created:  24/08/10 09:46:55
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

#include "odinSplash.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinSplash
 *  Description:  Displays the odin Splash "image"
 *                  - args : NONE
 *
 *                  - returns int
 *                      0 if all Ok
 *                      non zero otherwise
 *                      
 * =====================================================================================
 */
int
odinSplash()
{
    /* Declarations */
    WINDOW *odinSplashWindow;
    const int odinSplashLines = 15;
    const int odinSplashCols = 60;
    const char *odinSplashMessage[] = {"ODIN", "========", "A simple zero-sum game", "GPLv3+","Mini project for VII semester", "Dept. of CS&E", "MIT Manipal", "Copyright Saumya Singh, Amitabh Anand, Ankur Sinha 2010"};



    /** Do the work **/
    /* get a new window */
    odinSplashWindow = newwin(odinSplashLines,odinSplashCols,(LINES - odinSplashLines)/2,(COLS - odinSplashCols)/2);

    /* make a border around it */
    box(odinSplashWindow,0,0);
    mvwprintw(odinSplashWindow,3,(odinSplashCols - strlen(odinSplashMessage[0]))/2,"%s",odinSplashMessage[0]);
    mvwprintw(odinSplashWindow,4,(odinSplashCols - strlen(odinSplashMessage[1]))/2,"%s",odinSplashMessage[1]);
    mvwprintw(odinSplashWindow,5,(odinSplashCols - strlen(odinSplashMessage[2]))/2,"%s",odinSplashMessage[2]);
    mvwprintw(odinSplashWindow,6,(odinSplashCols - strlen(odinSplashMessage[3]))/2,"%s",odinSplashMessage[3]);
    mvwprintw(odinSplashWindow,8,(odinSplashCols - strlen(odinSplashMessage[4]))/2,"%s",odinSplashMessage[4]);
    mvwprintw(odinSplashWindow,9,(odinSplashCols - strlen(odinSplashMessage[5]))/2,"%s",odinSplashMessage[5]);
    mvwprintw(odinSplashWindow,10,(odinSplashCols - strlen(odinSplashMessage[6]))/2,"%s",odinSplashMessage[6]);
    mvwprintw(odinSplashWindow,odinSplashLines -2,(odinSplashCols - strlen(odinSplashMessage[7]))/2,"%s",odinSplashMessage[7]);
    wrefresh(odinSplashWindow);


    sleep(2);
	return 0;
}


