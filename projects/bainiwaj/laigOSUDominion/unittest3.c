/* 
 * * Jaspal Bainiwal
 * * I am using the testCoinsUpdate template from assignment 3 assistance(2).
 * *I am testing the supplyCount function in this test.
 * */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
int myAssertFunction(int x, int y);

int main() {
	int seed = 1000;
	int numPlayer = 2;
	int call;
	int checker;
	int counter = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	

	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	printf("TESTING supplyCount():\n");
	
	printf("Test if supply for kingdom cards was set up correctly for two player game\n");
	call = supplyCount(adventurer, &G);
	checker = myAssertFunction(call, 10);
	if (checker == 1)
	{
		counter++;
	}

	printf("Test if supplyCount is initialized with correct amount of victory cards for two players\n");
	call = supplyCount(province, &G);
	checker = myAssertFunction(call, 8);
	if (checker == 1)
	{
		counter++;
	}

	printf("Test if correct supply of curse cards are set up based on two player game\n");
	call = supplyCount(curse, &G);
	checker = myAssertFunction(call, 10);
	if (checker == 1)
	{
		counter++;
	}


	if (counter == 3)
	{
		printf("All tests passed!\n");
	}
	else
	{
		printf("Not all tests passed!\n");
	}
	return 0;
}
/*Wrote my own assert function because the helpful hint suggested that
 * the built in assert might crash the program*/
int myAssertFunction(int x, int y)
{
	if (x != y)
	{
		printf("TEST FAILED\n");
		return 0;
	}
	else
	{
		printf("TEST SUCCESSFULLY COMPLETED\n");
		return 1;
	}
}	
