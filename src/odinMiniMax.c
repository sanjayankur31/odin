/*
 * =====================================================================================
 *
 *       Filename:  odinMiniMax.c
 *
 *    Description:  Implementation of the minimax algorithm for the AI
 *
 *        Version:  1.0
 *        Created:  23/10/10 14:09:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ankur Sinha (FranciscoD), sanjay DOT ankur AT gmail DOT com
 *        Company:  
 *
 * =====================================================================================
 * 
 * Copyright 2010 Ankur Sinha 
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


#include	"odinMiniMax.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinMoveGen
 *  Description:  Fill up the odinSibling array with empty locations and return the 
 *                number of empty locations. Remember to remove the current position 
 *                from the list.
 * =====================================================================================
 */
gint
odinMoveGen (struct odinPosition position, gint odinPlayer, struct odinPosition odinSibling[], struct odinBoard *odin)
{
    gint count = 0;
    gint i,j;

    odin->locations[position.x][position.y].state = CONSIDERED;

    for ( i = 0; i < GAMEORDER; i += 1 ) 
    {
        for ( j = 0; j < GAMEORDER; j += 1 ) 
        {
            if(odin->locations[i][j].state == FREE)
            {
                odinSibling[count].x = i;
                odinSibling[count++].y = j;
            }
        }
    }


    return count;
}		/* -----  end of function odinMoveGen  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinGetStatic
 *  Description:  Mark the current location as "CONSIDERED" and recalculate the static
 *                values for all the locations, then return the current location's 
 *                static value.
 *
 *                TODO: will this screw up the minimax concept? At a glance, NO, but
 *                I'll have to give it a closer look.
 *
 * =====================================================================================
 */
gint
odinGetStatic (struct odinPosition position,gint odinPlayer, struct odinBoard *odin)
{
    if(odin->locations[position.x][position.y].state == FREE)
        odin->locations[position.x][position.y].state = CONSIDERED;

    odinStatic(odin);

    return odin->locations[position.x][position.y].value;
}		/* -----  end of function odinGetStatic  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinDeepEnough
 *  Description:  I'm letting it generate nodes until it can, for example, if the depth
 *                  is 1, I'll let it generate 24 more levels
 *
 *                  - args : 
 *                      - struct odinPosition position
 *                      - gint odinDepth
 *                      - struct odinBoard odin
 *
 *                  - return : gboolean
 *                      TRUE and FALSE as needed
 * =====================================================================================
 */
gboolean
odinDeepEnough (gint odinDepth, struct odinBoard odin)
{
    if (odinDepth + odin.emptyPositions < 25)
        return FALSE;

    return TRUE;
}		/* -----  end of function odinDeepEnough  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  opp
 *  Description:  return th opposite of the current player
 *
 *                  - args : 
 *                      - gint player : current player
 *
 *                  - return : gint
 *                      - A or B
 * =====================================================================================
 */
gint
opp (gint player )
{
    if(player == A)
        return B;

    return A;
}		/* -----  end of function opp  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinMiniMax
 *  Description:  Implementation of the MiniMax algorithm
 *                  
 *                  - args : 
 *                      GNode *odinPosition : current position
 *                      gint odinDepth : current depth
 *                      gint odinPlayer : the player whose turn it is to calculate
 *                      struct odinBoard odin : required for deep enough
 *
 *                  - returns : struct odinRetStructure
 *                      : containing the resultant structure
 * =====================================================================================
 */
struct odinRetStructure
odinMiniMax (struct odinPosition position, gint odinDepth, gint odinPlayer, struct odinBoard *odin)
{
    gint odinBestValue,odinNewVal,i = 0;
    struct odinPosition odinBestPath;
    struct odinPosition odinSibling[25];
    struct odinRetStructure odinReturn;
    odinReturn.value = 0;

    if(odinDeepEnough(odinDepth, *odin))
    {
        /*  rubbish  */
        odinReturn.position.x = position.x;
        odinReturn.position.y = position.y;
        /*  returns the current positions static value */
        odinReturn.value = odinGetStatic(position, odinPlayer, odin);
        return odinReturn;
    }

    /*-----------------------------------------------------------------------------
     *  odinPosition is passed and the odinSibling array is filled with empty positions 
     *-----------------------------------------------------------------------------*/
    if(odinMoveGen(position,odinPlayer,odinSibling, odin) == 0)
            return odinReturn;

    /*-----------------------------------------------------------------------------
     * it's player B, so the static will return -ve values, we need the smallest 
     *-----------------------------------------------------------------------------*/
    odinBestValue = 1;

    /*-----------------------------------------------------------------------------
     *  remember to make the last entry of the array 26,26
     *-----------------------------------------------------------------------------*/
    while(odinSibling[i].x != 26 && odinSibling[i].y != 26)
    {
        odinReturn = odinMiniMax(odinSibling[i], odinDepth +1, opp(odinPlayer),odin);
        odinNewVal = odinReturn.value;

        if(odinNewVal < odinBestValue)
        {
            odinBestValue = odinNewVal;
            odinBestPath =  odinReturn.position;
        }

        i++;
    }

    return odinReturn;

}		/* -----  end of function odinMiniMax  ----- */
