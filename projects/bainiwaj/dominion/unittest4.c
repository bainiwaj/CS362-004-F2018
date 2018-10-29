/* 
 *  * * Jaspal Bainiwal
 *   * * I am using the testCoinsUpdate template from assignment 3 assistance(2).
 *    * *I am testing the fullDeckCount function in this test. 
 *     *
 *      * */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
int myAssertFunction(int x, int y);

int main() {
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int call;
	int checker;
	int counter = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	printf("TESTING fullDeckCount():\n");
	printf("Test if deck count for copper is the expected amount during the start of the game for player 1\n");
	
	call = fullDeckCount(0, copper, &G);
	checker = myAssertFunction(call, 7);
	if (checker == 1)
	{
		counter++;
	}
	printf("Test if deck count for estate is the expected amount during the start of the game for player 1\n");

	call = fullDeckCount(0, estate, &G);
	checker = myAssertFunction(call, 3);
	if (checker == 1)
	{
		counter++;
	}
	printf("Test if deck count with cards in players hand is the expected amount\n");
	G.handCount[0] = 5;
	for (i = 0; i < 5; i++)
	{
		G.hand[0][i] = copper;
	}
	call = fullDeckCount(0, copper, &G);
	checker = myAssertFunction(call, 8);
	if (checker == 1)
	{
		counter++;
	}
	printf("Test if discard pile is correct by comparing the expected count amount for a card\n");
	G.discardCount[0] = 5;
	for (i = 0; i < 5; i++)
	{
		G.discard[0][i] = copper;
	}
	call = fullDeckCount(0, copper, &G);
	checker = myAssertFunction(call, 13);
	if (checker == 1)
	{
		counter++;
	}
	if (counter == 4)
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
