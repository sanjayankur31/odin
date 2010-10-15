/*
 * =====================================================================================
 *
 *       Filename:  odinAIStatic.c
 *
 *    Description:  file containing the static evaluation function for use by minimax
 *
 *        Version:  1.0
 *        Created:  14/10/10 22:55:36
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

#include	"odinAIStatic.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  odinStatic
 *  Description:  static function that returns value to be used by minimax.
 *                - number of locations that will captured in total by selecting one
 *
 * :TODO:15/10/10 17:41:18:FranciscoD: Think up a good static function 
 *
 *                  - args: 
 *                      - struct odinBoard *odin : odinGameBoard to be filled with values
 *
 *                  - returns : gint value
 *                      - the static importance of the position
 *                      - non zero otherwise
 * =====================================================================================
 */
gint
odinStatic (struct odinBoard *odin )
{
    gint value = 0;
    gint i,j;

    for ( i = 0; i < GAMEORDER; i += 1 ) 
    {
        for ( j = 0; j < GAMEORDER; j += 1 ) 
        {
            value = 0;
            if(odin->state == A && odin->locations[i][j].state == FREE) 
            {
                value = 1;
                /* first change ownership of paradropped location */
                if(i < 4 && odin->locations[i +1][j].state == B_OWNS)
                {
                    value++;
                }
                if(i > 0 && odin->locations[i -1][j].state == B_OWNS)
                {
                    value++;
                }
                if(j < 4 && odin->locations[i][j +1].state == B_OWNS)
                {
                    value++;
                }
                if(j > 0 && odin->locations[i][j -1].state == B_OWNS)
                {
                    value++;
                }
            }
            else if(odin->state == B && odin->locations[i][j].state == FREE) 
            {
                value = -1;
                if(i < 4 && odin->locations[i +1][j].state == A_OWNS)
                {
                    value--;
                }
                if(i > 0 && odin->locations[i -1][j].state == A_OWNS)
                {
                    value--;
                }
                if(j < 4 && odin->locations[i][j +1].state == A_OWNS)
                {
                    value--;
                }
                if(j > 0 && odin->locations[i][j -1].state == A_OWNS)
                {
                    value--;
                }
            }
            odin->locations[i][j].value = value;
        }

    }
    return 0;
}		/* -----  end of function odinStatic  ----- */

