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


#include	"odinMiniMax.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  opp
 *  Description:  return th opposite of the current player
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
 * =====================================================================================
 */
struct odinRetStructure
odinMiniMax (struct odinPosition position, gint odinDepth, gint odinPlayer, struct odinBoard odin)
{
    gint odinBestValue,odinNewValue;
    gint x, y;
    struct odinRetStructure odinReturn ;
    odinReturn.position.node = NULL;
    odinReturn.value = 0;
    x = y = 0;

    if(odinDeepEnough(position, odinDepth, odin))
    {
        odinReturn.position.node = NULL;
        /*  rubbish  */
        odinReturn.position.x = odinReturn.position.y = 26;
        odinReturn.value = odinGetStatic();
        return odinReturn;
    }

    /*-----------------------------------------------------------------------------
     *  need to pass the address of odinPosition since move gen will generate 
     *  children as successors
     *-----------------------------------------------------------------------------*/
    if(odinMoveGen(&position,odinPlayer) == NULL)
            return odinReturn;

    /*-----------------------------------------------------------------------------
     *  least value of static is 1
     *-----------------------------------------------------------------------------*/
    odinBestValue = 1;

    odinSibling = g_node_first_child(position.node);

    while(odinSibling != NULL)
    {
        odinReturn = odinMiniMax(odinSibling, odinDepth +1, opp(odinPlayer));
        odinNewVal = odinReturn.value;

        if(odinNewVal > odinBestValue)
        {
            odinBestValue = odinNewValue;
            odinBestPath =  odinReturn.node;
        }

        odinSibling = g_node_next_sibling(position.node);
    }

    return odinReturn;

}		/* -----  end of function odinMiniMax  ----- */
