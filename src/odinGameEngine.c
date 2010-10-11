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
 *         Name:  odinGetMove
 *  Description:  This method gets the move from the user depending on arrow key 
 *                movements
 *                  - args: none
 *                      
 *                  returns: gint 
 *                      - the key pressed
 *                      - -1 on error
 * =====================================================================================
 */
gint
odinGetMove ( )
{

    return BWIN;
}		/* -----  end of function odinGetMove  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinDrawBoard
 *  Description:  This method will create the updated board.
 *                  - args: 
 *                      gint odinState: player one/player two
 *                      gint odinScoreA: score of A
 *                      gint odinScoreB: score of B
 *                
 *
 *                returns : gint
 *                  - 0 on success, non zero otherwise
 * =====================================================================================
 */
gint
odinDrawBoard (gint odinState,gint odinScoreA, gint odinScoreB)
{
    WINDOW *odinGameMatrix;
    WINDOW *odinGamePositions[5][5];
    WINDOW *odinStatusBar;
    gint odinGameMatrixLines = GAMELINES + 5; // 5 for status bar
    gint odinGameMatrixCols = GAMECOLS;
    gint i,j;
    gchar dummyString[50];

    odinGameMatrix = newwin(odinGameMatrixLines + 2,odinGameMatrixCols + 4,(LINES - odinGameMatrixLines)/2,(COLS - odinGameMatrixCols)/2);
 
    if(odinGameMatrix == NULL)
    {
        g_error("Error allocating memory to the Game Matrix window");
    }

    for( i  = 0; i< GAMEORDER; i++)
    {
        for(j = 0; j< GAMEORDER; j++)
        {
            odinGamePositions[i][j] = derwin(odinGameMatrix,4, 10,i*4 +1, j*10 + 2);
            if(odinGamePositions[i][j] == NULL)
            {
                g_error("Some error in the matrix");
            }
            box(odinGamePositions[i][j],0,0);
        }

    }

    odinStatusBar = derwin(odinGameMatrix,4,50,22,2);

    sprintf(dummyString,"Player A: %d",odinScoreA);
    switch(odinState)
    {
        case A:
        case NEW:
            wstandout(odinStatusBar);
            mvwprintw(odinStatusBar,1,1,dummyString);
            wstandend(odinStatusBar);
            sprintf(dummyString,"Player B: %d",odinScoreB);
            mvwprintw(odinStatusBar,1,50 - 1 - strlen(dummyString),"%s",dummyString);
            mvwprintw(odinStatusBar,3,1,"> Player A's turn");
            break;
        case B:
            mvwprintw(odinStatusBar,1,1,dummyString);
            wstandout(odinStatusBar);
            sprintf(dummyString,"Player B: %d",odinScoreB);
            mvwprintw(odinStatusBar,1,50 - 1 - strlen(dummyString),dummyString);
            wstandend(odinStatusBar);
            mvwprintw(odinStatusBar,3,1,"> Player A's turn");
            break;
        case AWIN:
            mvwprintw(odinStatusBar,1,(50 - strlen("_ WINS"))/2,"A WINS");
            break;
        case BWIN:
            mvwprintw(odinStatusBar,1,(50 - strlen("_ WINS"))/2,"A WINS");
            break;
    }

    box(odinGameMatrix,0,0);
    wrefresh(odinGameMatrix);
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
    struct odinGameBoard **boardState;
    gint i,j;
    gint odinGameState = NEW;
    gint odinMove = NOTHING;


    boardState = malloc(5* sizeof(struct odinGameBoard *));

    if(boardState == NULL)
    {
        g_error("Error allocating memory to boardState");
    }

    for(i = 0; i< 5; i++)
    {
        boardState[i] = malloc(5 * sizeof(struct odinGameBoard));
        if(boardState[i] == NULL)
        {
            g_error("Error allocating memory to boardState[i]");
        }

        /*-----------------------------------------------------------------------------
         *  Initialize to all of it to zero
         *-----------------------------------------------------------------------------*/
        memset(boardState[i],0,(5* sizeof(struct odinGameBoard)));
    }

    
    while (odinGameState != AWIN && odinGameState != BWIN ) 
    {
        odinMove = odinGetMove();
        odinDrawBoard (odinGameState,45,54);
    }

    return 0;

}		/* -----  end of function odinGameEngine  ----- */
