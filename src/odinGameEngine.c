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
    sprintf(dummyString,"Player A: %3d",odin.scoreA);
    switch(odin.state)
    {
        case A:
        case NEW:
            wattron(odin.statusWin,COLOR_PAIR(1));
            mvwprintw(odin.statusWin,1,1,dummyString);
            mvwprintw(odin.statusWin,3,1,"> Player A's turn.");
            wattroff(odin.statusWin,COLOR_PAIR(1));

            sprintf(dummyString,"Player B: %3d",odin.scoreB);
            wattron(odin.statusWin,COLOR_PAIR(2));
            mvwprintw(odin.statusWin,1,50 - 1 - strlen(dummyString),"%s",dummyString);
            wattroff(odin.statusWin,COLOR_PAIR(2));
            break;
        case B:
            wattron(odin.statusWin,COLOR_PAIR(1));
            mvwprintw(odin.statusWin,1,1,dummyString);
            wattroff(odin.statusWin,COLOR_PAIR(1));

            sprintf(dummyString,"Player B: %3d",odin.scoreB);
            wattron(odin.statusWin,COLOR_PAIR(2));
            mvwprintw(odin.statusWin,1,50 - 1 - strlen(dummyString),dummyString);
            mvwprintw(odin.statusWin,3,1,"> Player B's turn.");
            wattroff(odin.statusWin,COLOR_PAIR(2));
            break;
        case AWIN:
            wattron(odin.statusWin,COLOR_PAIR(1));
            mvwprintw(odin.statusWin,1,(50 - strlen("_ WINS"))/2,"A WINS");
            mvwprintw(odin.statusWin,3,1,"> Congratulations Player A! You have won!");
            wattroff(odin.statusWin,COLOR_PAIR(1));
            break;
        case BWIN:
            wattron(odin.statusWin,COLOR_PAIR(2));
            mvwprintw(odin.statusWin,1,(50 - strlen("_ WINS"))/2,"B WINS");
            mvwprintw(odin.statusWin,3,1,"> Congratulations Player B! You have won!");
            wattroff(odin.statusWin,COLOR_PAIR(2));
            break;
    }
    wnoutrefresh(odin.statusWin);
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
    init_pair(3,COLOR_CYAN,-1);
    
    for ( i = 0; i < GAMEORDER; i += 1 ) 
    {
        for ( j = 0; j < GAMEORDER; j += 1 ) 
        {
            /* :TODO:12/10/10 22:05:18:FranciscoD: I can probably write this better */
            if (odin.locations[i][j].state == A_OWNS ) 
            {
                if(odin.currentPositionRow == i && odin.currentPositionCol == j)
                {
                    wattron(odin.locations[i][j].win,COLOR_PAIR(3));
                    box(odin.locations[i][j].win,0,0);
                    wattroff(odin.locations[i][j].win,COLOR_PAIR(3));
                }
                else
                {
                    wattron(odin.locations[i][j].win,COLOR_PAIR(1));
                    box(odin.locations[i][j].win,0,0);
                    wattroff(odin.locations[i][j].win,COLOR_PAIR(1));
                }
                wattron(odin.locations[i][j].win,COLOR_PAIR(1));
                mvwprintw(odin.locations[i][j].win,2,2,"$A$%+d$",odin.locations[i][j].value);
                wattroff(odin.locations[i][j].win,COLOR_PAIR(1));
                
            }
            else if(odin.locations[i][j].state == B_OWNS)
            {
                if(odin.currentPositionRow == i && odin.currentPositionCol == j)
                {
                    wattron(odin.locations[i][j].win,COLOR_PAIR(3));
                    box(odin.locations[i][j].win,0,0);
                    wattroff(odin.locations[i][j].win,COLOR_PAIR(3));
                }
                else
                {
                    wattron(odin.locations[i][j].win,COLOR_PAIR(2));
                    box(odin.locations[i][j].win,0,0);
                    wattroff(odin.locations[i][j].win,COLOR_PAIR(2));
                }
                wattron(odin.locations[i][j].win,COLOR_PAIR(2));
                mvwprintw(odin.locations[i][j].win,2,2,"$B$%+d$",odin.locations[i][j].value);
                wattroff(odin.locations[i][j].win,COLOR_PAIR(2));
                
            }
            else
            {
                if(odin.currentPositionRow == i && odin.currentPositionCol == j)
                {
                    wattron(odin.locations[i][j].win,COLOR_PAIR(3));
                    box(odin.locations[i][j].win,0,0);
                    mvwprintw(odin.locations[i][j].win,2,2,"$_$%+d$",odin.locations[i][j].value);
                    wattroff(odin.locations[i][j].win,COLOR_PAIR(3));
                }
                else 
                {
                    box(odin.locations[i][j].win,0,0);
                    mvwprintw(odin.locations[i][j].win,2,2,"$_$%+d$",odin.locations[i][j].value);
                }
            
            }

            /*  remember that you need to refresh each window separately before anything works! */
            wnoutrefresh(odin.locations[i][j].win);
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
    doupdate();
    return 0;
}		/* -----  end of function odinDrawBoard  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinMakeMove
 *  Description:  Analyse the conquered position and update the state.
 *                Remember, as per the rules, no cascading effect.
 * =====================================================================================
 */
gint
odinMakeMove (struct odinBoard *odin)
{

    /*  check the other locations and update */
    if(odin->state == A ) 
    {
        /* first change ownership of paradropped location */
        odin->locations[odin->currentPositionRow][odin->currentPositionCol].state = A_OWNS;
        odin->scoreA += 1;
        odin->emptyPositions -= 1;
        if(odin->currentPositionRow < 4 && odin->locations[odin->currentPositionRow +1][odin->currentPositionCol].state == B_OWNS)
        {
            odin->locations[odin->currentPositionRow +1][odin->currentPositionCol].state = A_OWNS;
            odin->scoreA += 1;
            odin->scoreB -= 1;
        }
        if(odin->currentPositionRow > 0 && odin->locations[odin->currentPositionRow -1][odin->currentPositionCol].state == B_OWNS)
        {
            odin->locations[odin->currentPositionRow -1][odin->currentPositionCol].state = A_OWNS;
            odin->scoreA += 1;
            odin->scoreB -= 1;
        }
        if(odin->currentPositionCol < 4 && odin->locations[odin->currentPositionRow][odin->currentPositionCol +1].state == B_OWNS)
        {
            odin->locations[odin->currentPositionRow][odin->currentPositionCol +1].state = A_OWNS;
            odin->scoreA += 1;
            odin->scoreB -= 1;
        }
        if(odin->currentPositionCol > 0 && odin->locations[odin->currentPositionRow][odin->currentPositionCol -1].state == B_OWNS)
        {
            odin->locations[odin->currentPositionRow][odin->currentPositionCol -1].state = A_OWNS;
            odin->scoreA += 1;
            odin->scoreB -= 1;
        }
        if(odin->emptyPositions == 0)
        {
            if(odin->scoreA > odin->scoreB)
            {
                odin->state = AWIN;
            }
            else 
            {
                odin->state = BWIN;
            }
        }
        else
        {
            odin->state = B;
        }
        return 0;
    }
    else if(odin->state == B) 
    {
        /* first change ownership of paradropped location */
        odin->locations[odin->currentPositionRow][odin->currentPositionCol].state = B_OWNS;
        odin->scoreB += 1;
        odin->emptyPositions -= 1;
        if(odin->currentPositionRow < 4 && odin->locations[odin->currentPositionRow +1][odin->currentPositionCol].state == A_OWNS)
        {
            odin->locations[odin->currentPositionRow +1][odin->currentPositionCol].state = B_OWNS;
            odin->scoreB += 1;
            odin->scoreA -= 1;
        }
        if(odin->currentPositionRow > 0 && odin->locations[odin->currentPositionRow -1][odin->currentPositionCol].state == A_OWNS)
        {
            odin->locations[odin->currentPositionRow -1][odin->currentPositionCol].state = B_OWNS;
            odin->scoreB += 1;
            odin->scoreA -= 1;
        }
        if(odin->currentPositionCol < 4 && odin->locations[odin->currentPositionRow][odin->currentPositionCol +1].state == A_OWNS)
        {
            odin->locations[odin->currentPositionRow][odin->currentPositionCol +1].state = B_OWNS;
            odin->scoreB += 1;
            odin->scoreA -= 1;
        }
        if(odin->currentPositionCol > 0 && odin->locations[odin->currentPositionRow][odin->currentPositionCol -1].state == A_OWNS)
        {
            odin->locations[odin->currentPositionRow][odin->currentPositionCol -1].state = B_OWNS;
            odin->scoreB += 1;
            odin->scoreA -= 1;
        }
        if(odin->emptyPositions == 0)
        {
            if(odin->scoreA < odin->scoreB)
            {
                odin->state = BWIN;
            }
            else
            { 
                odin->state = AWIN;
            }
        }
        else
        {
            odin->state = A;
        }
    }
    return 0;
}		/* -----  end of function odinMakeMove  ----- */

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
    gint move;

    /*-----------------------------------------------------------------------------
     *  initialize my board
     *-----------------------------------------------------------------------------*/
    odin.state = NEW;
    odin.scoreA = 0;
    odin.scoreB = 0;
    odin.move = 0;
    odin.emptyPositions = GAMEORDER * GAMEORDER;
    /*  place it on the extreme start of the matrix */
    odin.currentPositionRow = 0;
    odin.currentPositionCol = 0;

    odin.mainWin = newwin(GAMELINES + 6,GAMECOLS + 2,(LINES - GAMELINES)/2, (COLS - GAMECOLS)/2);
    box(odin.mainWin,0,0);
    keypad(odin.mainWin,TRUE);
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
            odin.locations[i][j].state = FREE;
        }
    }

    /*  change the state and begin!! */
    odin.state = A;
    odinStatic(&odin);
    odinDrawBoard(odin);
    while (odin.state != AWIN && odin.state != BWIN ) 
    {
        /*  let him walk around the park and see */
        while(1)
        {
            cbreak();
            noecho();
            move = wgetch(odin.mainWin);
            echo();
            nocbreak();

            /* :TODO:12/10/10 23:12:59:FranciscoD: use switch later? */
            if(((move == '\n' || move == 'c') && odin.locations[odin.currentPositionRow][odin.currentPositionCol].state == FREE) || move == 'q')
                break;
            else if(move == KEY_UP || move == 'w')
            {
                if (odin.currentPositionRow == 0 ) {
                    odin.currentPositionRow = 4;
                }
                else {
                    odin.currentPositionRow -= 1;
                }
            }
            else if(move == KEY_DOWN || move == 's')
            {
                if (odin.currentPositionRow == 4 ) {
                    odin.currentPositionRow = 0;
                }
                else {
                    odin.currentPositionRow += 1;
                }
            }
            else if(move == KEY_RIGHT || move == 'd')
            {
                if (odin.currentPositionCol == 4 ) {
                    odin.currentPositionCol = 0;
                }
                else {
                    odin.currentPositionCol += 1;
                }
            }
            else if(move == KEY_LEFT || move == 'a')
            {
                if (odin.currentPositionCol == 0 ) {
                    odin.currentPositionCol = 4;
                }
                else {
                    odin.currentPositionCol -= 1;
                }
            }

            odinDrawBoard(odin);
        }

        /*  q to quit at anytime */
        if(move == 'q')
            break;
        /* :TODO:12/10/10 23:53:40:FranciscoD: Add an exit confirmation box */
        else
        {
            /* :TODO:13/10/10 00:05:38:FranciscoD: You might just be able to merge this entire thing into a method? */
            odinMakeMove(&odin);
            odinStatic(&odin);
            odinDrawBoard(odin);
        }

    }


    return 0;

}		/* -----  end of function odinGameEngine  ----- */
