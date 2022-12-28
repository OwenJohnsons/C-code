/**
 * @file assignment5a.c
 * @brief  Bones of code for MAP55613 Assignment 5a
 * 	Write functions that you can pass to qsort that will order an array of struct Coords.
 * @author Owen A. Johnson
 * @version 1.0 
 * @date 2022-12-23
 */
#include <stdio.h>
#include <stdlib.h>
#include "coord.h"

int main(int argc, char *argv[])
{
	Coord X[10] = { {'A',4,2}
		, {'B',1,3}
		, {'C', 8,4}
		, {'D', 2,8}
		, {'E', 6,1}
		, {'F', 2,3}
		, {'G', 5,2}
		, {'H', 1,9}
		, {'I', 6,2}
		, {'J', 4,1}
	};

	//
	// Declare "sorter" to be a function pointer (which we can pass to qsort)
	// We will set this equal to one of the sorting functions you have written
	// in coord.c
	//


	printf("Enter 0 to sort by x coordinate first, or 1 to sort by y coordinate\n");
	
	//
	// Process the number entered and then use that choice to set the 
	// function pointer "sorter" above
	//


	//
	// Call qsort on X. Pass in the function pointer "sorter" you set above
	//



	/*
	 * Print result to screen
	 */

	for (int i = 0; i < 10; i++) {
		printf("%c:\t(%d,%d)\n", X[i].c, X[i].x, X[i].y);	
	}
	printf("\n");

	return 0;
}
