/*
 * =====================================================================================
 *
 *       Filename:  odinGameEngine.h
 *
 *    Description:  
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

#include "odinCommon.h"

static gint debug;

/*-----------------------------------------------------------------------------
 * This enum is used to specify the state of a single board loacation
 *-----------------------------------------------------------------------------*/
enum odinMatrixState {FREE,A,B};

/*-----------------------------------------------------------------------------
 *  This struct signifies the GameBoard. 
 *  A two dimensional array of this structure will hold my position states
 *  in conjunction with the enum.
 *-----------------------------------------------------------------------------*/
struct odinGameBoard
{
    gint value;
    gint flag;
};

/*-----------------------------------------------------------------------------
 *  Function prototypes : The functions have elaborate comments describing them
 *-----------------------------------------------------------------------------*/
gint
odinDrawBoard ();

gint
odinGameEngine ();
