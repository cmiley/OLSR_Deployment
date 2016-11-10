// Program Information /////////////////////////////////////////////////////////
/**
 * @file Simulator Functions.c
 *
 * @brief Memory Address Locator and Timer for CS 446 at the Univserity of 
 *        Nevada, Reno
 * 
 * @details This file includes the necessary functions for assignment 2 of the 
 *          CS 446 course simulator.
 *
 * @author Cayler Miley
 *
 * @version 1.01 (14 September 16)
 */

// PRECOMPILER DIRECTIVES //////////////////////////////////////////////////////

#ifndef MEM_FUNC_H
#define MEM_FUNC_H

// HEADER FILES ////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

// GLOBAL CONSTANTS ////////////////////////////////////////////////////////////

 // None

unsigned int AllocateMemory( int totMem );
int timePassed( struct timeval refTime );

#endif // MEM_FUNC_H