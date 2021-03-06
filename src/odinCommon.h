/*
 * =====================================================================================
 *
 *       Filename:  odinCommon.h
 *
 *    Description:  common headers to be used in odin
 *
 *        Version:  1.0
 *        Created:  24/08/10 09:46:11
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

#include <unistd.h>
#include <curses.h>
#include <string.h>
#include <stdio.h>
#include <glib.h>

/*-----------------------------------------------------------------------------
 * State of a single board location
 *-----------------------------------------------------------------------------*/
enum odinMatrixState {FREE,CURRENT,A_OWNS,B_OWNS,CONSIDERED};

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
 *  This struct signifies the GameBoard. 
 *  A two dimensional array of this structure will hold my position states
 *  in conjunction with the enum.
 *-----------------------------------------------------------------------------*/
struct oneLocation
{
    WINDOW *win;
    gint value;
    gint state;
};

/*-----------------------------------------------------------------------------
 *  This structure defines the game's current variables
 *-----------------------------------------------------------------------------*/
struct odinBoard
{
    WINDOW *mainWin;
    WINDOW *statusWin;
    struct oneLocation locations[5][5];
    gint scoreA,scoreB;
    gint move; 
    gint state;
    gint emptyPositions;
    gint currentPositionRow;
    gint currentPositionCol;
};

/*-----------------------------------------------------------------------------
 *  to be used in MiniMax
 *-----------------------------------------------------------------------------*/
struct odinPosition
{
    gint x, y;
};

struct odinRetStructure
{
    struct odinPosition position;
    gint value;
};
