/******************************************************************************
 *  * * Jaspal Bainiwal
 *   * * I am using the testCoinsUpdate template from assignment 3 assistance(2).
 *    * *I am testing the endTurn function in this test.
 *    ************************************************************************
 *    */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*Wrote my own assert function because the helpful hint suggested that 
 *  * the built in assert might crash the program*/
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
	printf("TESTING endTurn():\n");
	
	printf("gamestate whoseTurn is 0 and after endTurn it should be 1\n");
	endTurn(&G);
	call = G.whoseTurn;
	checker = myAssertFunction(call, 1);
	if (checker == 1)
	{
		counter++;
	}

	printf("If last players turn has ended it should go to player 0\n");
	G.whoseTurn = 1;
	endTurn(&G);
	call = G.whoseTurn;
	checker = myAssertFunction(call, 0);
	if (checker == 1)
	{
		counter++;
	}

	printf("Test if function resets card count\n");
	G.playedCardCount = 3;
	endTurn(&G);
	call = G.playedCardCount;
	checker = myAssertFunction(call, 0);
	if (checker == 1)
	{
		counter++;
	}

	printf("Test if hand count resets after turn ends\n");
	G.whoseTurn = 0;
	G.handCount[0] = 2;
	endTurn(&G);
	call = G.handCount[0];
	checker = myAssertFunction(call, 0);
	if (checker == 1)
	{
		counter++;
	}

	printf("Test if outpost in play resets after turn ends\n");
	G.outpostPlayed = 1;
	endTurn(&G);
	call = G.outpostPlayed;
	checker = myAssertFunction(call, 0);
	if (checker == 1)
	{
		counter++;
	}

	printf("Test if number of buys goes to one\n");
	G.numBuys = 4;
	endTurn(&G);
	call = G.numBuys;
	checker = myAssertFunction(call, 1);
	if (checker == 1)
	{
		counter++;
	}

	if (counter == 6)
	{
		printf("All tests passed!\n");
	}
	else
	{
		printf("Not all tests passed!\n");
	}
	return 0;
}
