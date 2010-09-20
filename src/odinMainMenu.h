/*
 * =====================================================================================
 *
 *       Filename:  odinMainMenu.h
 *
 *    Description:  header to odinMainMenu.c
 *
 *        Version:  1.0
 *        Created:  28/08/10 00:10:41
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


int debug;

#include "odinCommon.h"

void
odinMenuDraw (char *options[], char *optionMessages[] , WINDOW *odinMainMenuWindow,int odinMainMenuCols, int odinCurrentHighlight ,int odinStartRow);

int
odinMenusGeneric (WINDOW **odinMenusGenericWindow, char **odinMenusGenericGreet, char **odinMenusGenericOptions, char **odinGenericMessages );
