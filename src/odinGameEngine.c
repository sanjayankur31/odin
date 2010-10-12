/*
 * =====================================================================================
 *
 *       Filename:  odinGameEngine.c
 *
 *    Description:  the main game engine
 *
 *        Version:  1.0
 *        Created:  27/09/10 14:17:29
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

#include	"odinGameEngine.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinMakeMove
 *  Description:  Processes the user input and updates the structure
 * =====================================================================================
 */
gint
odinMakeMove (struct odinBoard *odinPtr)
{
    
    switch (odinPtr->move) {
        case KEY_UP:	
            break;

        case KEY_DOWN:	
            break;

        case KEY_RIGHT:	
            break;

        case KEY_LEFT:	
            break;

        default:	
            break;
    }				/* -----  end switch  ----- */

    return 0;
}		/* -----  end of function odinMakeMove  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinDrawStatusWin
 *  Description:  Draw the Status Window
 *                  - args:
 *                      struct odinBoard odin : the data structure
 *
 *                  - returns : gint
 *                      0 if successful
 *                      non zero otherwise
 *                      
 * =====================================================================================
 */
gint
odinDrawStatusWin (struct odinBoard odin)
{
    gchar dummyString[50];
    sprintf(dummyString,"Player A: %d",odin.scoreA);
    switch(odin.state)
    {
        case A:
        case NEW:
            wattron(odin.statusWin,COLOR_PAIR(1));
            mvwprintw(odin.statusWin,1,1,dummyString);
            mvwprintw(odin.statusWin,3,1,"> Player A's turn");
            wattroff(odin.statusWin,COLOR_PAIR(1));

            sprintf(dummyString,"Player B: %d",odin.scoreB);
            wattron(odin.statusWin,COLOR_PAIR(2));
            mvwprintw(odin.statusWin,1,50 - 1 - strlen(dummyString),"%s",dummyString);
            wattroff(odin.statusWin,COLOR_PAIR(2));

            break;
        case B:
            wattron(odin.statusWin,COLOR_PAIR(1));
            mvwprintw(odin.statusWin,1,1,dummyString);
            wattroff(odin.statusWin,COLOR_PAIR(1));

            sprintf(dummyString,"Player B: %d",odin.scoreB);
            wattron(odin.statusWin,COLOR_PAIR(2));
            mvwprintw(odin.statusWin,1,50 - 1 - strlen(dummyString),dummyString);
            mvwprintw(odin.statusWin,3,1,"> Player B's turn");
            wattroff(odin.statusWin,COLOR_PAIR(2));
            break;
        case AWIN:
            wattron(odin.statusWin,COLOR_PAIR(1));
            mvwprintw(odin.statusWin,1,(50 - strlen("_ WINS"))/2,"A WINS");
            wattroff(odin.statusWin,COLOR_PAIR(1));
            break;
        case BWIN:
            wattron(odin.statusWin,COLOR_PAIR(2));
            mvwprintw(odin.statusWin,1,(50 - strlen("_ WINS"))/2,"A WINS");
            wattroff(odin.statusWin,COLOR_PAIR(2));
            break;
    }
    return 0;
}		/* -----  end of function odinDrawStatusWin  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinDrawBoxes
 *  Description:  Draw up the boxes. This first checks the status of the box and
 *                accordingly colours them boxes
 * =====================================================================================
 */
gint
odinDrawBoxes (struct odinBoard odin )
{
    int i,j;
    init_pair(1,COLOR_RED,-1);
    init_pair(2,COLOR_GREEN,-1);
    
    for ( i = 0; i < GAMEORDER; i += 1 ) 
    {
        for ( j = 0; j < GAMEORDER; j += 1 ) 
        {
            
            if (odin.locations[i][j].state == A_OWNS ) 
            {
                wattron(odin.locations[i][j].win,COLOR_PAIR(1));
                box(odin.locations[i][j].win,0,0);
                wattroff(odin.locations[i][j].win,COLOR_PAIR(1));
                
            }
            else if(odin.locations[i][j].state == B_OWNS)
            {
                wattron(odin.locations[i][j].win,COLOR_PAIR(2));
                box(odin.locations[i][j].win,0,0);
                wattroff(odin.locations[i][j].win,COLOR_PAIR(2));
                
            }
            else
            {
                box(odin.locations[i][j].win,0,0);
            
            }

        }
    }
    return 0;
}		/* -----  end of function odinDrawBoxes  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinDrawBoard
 *  Description:  This method will create the updated board.
 *                  - args: 
 *                      struct odinBoard odin : the structure containing data
 *
 *                  - returns : gint
 *                      0 on success, non zero otherwise
 * =====================================================================================
 */
gint
odinDrawBoard (struct odinBoard odin)
{
    int i,j;
    odinDrawStatusWin(odin);
    odinDrawBoxes(odin);
    wrefresh(odin.mainWin);
    return 0;
}		/* -----  end of function odinDrawBoard  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinGameEngine
 *  Description:  The main game engine
 * =====================================================================================
 */
gint
odinGameEngine ()
{
    struct odinBoard odin;
    gint i,j;
    /* :TODO:11/10/10 19:32:21:FranciscoD: write a function to calculate these values */
    gint constantValues[5][5] = {{24,30,45,56,97},{45,21,76,0,9},{1,2,5,6,7},{5,54,43,32,21},{54,9,65,3,21}}; 

    /*-----------------------------------------------------------------------------
     *  initialize my board
     *-----------------------------------------------------------------------------*/
    odin.state = NEW;
    odin.scoreA = 0;
    odin.scoreB = 0;
    odin.move = 0;
    odin.emptyPositions = GAMEORDER * GAMEORDER;
    odin.currentPositionRow = 0;
    odin.currentPositionCol = 0;

    odin.mainWin = newwin(GAMELINES + 6,GAMECOLS + 2,(LINES - GAMELINES)/2, (COLS - GAMECOLS)/2);
    box(odin.mainWin,0,0);
    odin.statusWin = derwin(odin.mainWin,4,GAMECOLS,GAMELINES +1,1);
    
    for ( i = 0; i < GAMEORDER; i += 1 ) 
    {
        for ( j = 0; j < GAMEORDER; j += 1 ) 
        {
            odin.locations[i][j].win = derwin(odin.mainWin,4,10,(4*i)+1,(10*j)+1);

            if (odin.locations[i][j].win == NULL ) 
            {
                g_error("Error allocating window\nExiting");
            }
            odin.locations[i][j].value = 0;
            odin.locations[i][j].state = 0;
        }
    }

    
    while (odin.state != AWIN && odin.state != BWIN ) 
    {
        odinDrawBoard(odin);

        cbreak();
        noecho();
        odin.move = wgetch(odin.mainWin);
        odinMakeMove(&odin);
        echo();
        nocbreak();

        /*  temporary fix  */
        break; 
    }


    return 0;

}		/* -----  end of function odinGameEngine  ----- */
