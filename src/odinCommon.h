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

#include <stdio.h>

/* defining an easy debug message print function 
 * http://www.delorie.com/gnu/docs/gcc/cpp_17.html
 */
#define dbg(format, ...) 										\
	do {												\
		if(debug) 										\
			printf("[DEBUG] %s: (%d) : "format"\n", __func__ , __LINE__ , ## __VA_ARGS__);	\
	}while(0)

