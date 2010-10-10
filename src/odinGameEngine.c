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
 *         Name:  odinDrawBoard
 *  Description:  This method will create the updated board.
 *                  - args:
 *                
 *
 *                returns : gint
 *                  - 0 on success, non zero otherwise
 * =====================================================================================
 */
gint
odinDrawBoard ()
{
    WINDOW *odinGameMatrix;
    WINDOW *odinGamePositions[5][5];
    gint odinGameMatrixLines = 20;
    gint odinGameMatrixCols = 50;
    gint i,j;

    odinGameMatrix = newwin(odinGameMatrixLines,odinGameMatrixCols,(LINES - odinGameMatrixLines)/2,(COLS - odinGameMatrixCols)/2);
 
    if(odinGameMatrix == NULL)
    {
        printf("ERROR :( :(");
        return -1;
    }

/*     box(odinGameMatrix,0,0);
 */

    for( i  = 0; i< 5; i++)
    {
        for(j = 0; j< 5; j++)
        {
            odinGamePositions[i][j] = derwin(odinGameMatrix,4, 10,i*4, j*10);
            if(odinGamePositions[i][j] == NULL)
            {
                printf("MEOW!!");
                return -1;
            }
            box(odinGamePositions[i][j],0,0);
        }

    }

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
    int i,j;


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


    odinDrawBoard ();
    return 0;

}		/* -----  end of function odinGameEngine  ----- */
