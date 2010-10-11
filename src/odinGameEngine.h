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
 * State of a single board location
 *-----------------------------------------------------------------------------*/
enum odinMatrixState {FREE,A_OWNS,B_OWNS};

/*-----------------------------------------------------------------------------
 *  Mode of play. 
 *-----------------------------------------------------------------------------*/
enum odinGameMode {DEMO,SINGLE,DOUBLE};

/*-----------------------------------------------------------------------------
 *  Game state
 *-----------------------------------------------------------------------------*/
enum odinGameState {NEW,A,B,AWIN,BWIN};

/*-----------------------------------------------------------------------------
 *  Constants
 *-----------------------------------------------------------------------------*/
enum odinGameDimensions {GAMEORDER = 5, GAMELINES = 20, GAMECOLS = 50};

/*-----------------------------------------------------------------------------
 *  moves
 *-----------------------------------------------------------------------------*/
enum odinGameMoves {NOTHING,UP,DOWN,LEFT,RIGHT};

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
