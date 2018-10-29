/* 
 * * Jaspal Bainiwal
 * * I am using the testCoinsUpdate template from assignment 3 assistance(2).
 * *I am testing the scoreFor function in this test.
 */

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
	printf("TESTING scoreFor():\n");
	printf("Testing if player 1 starts off with hand score of zero\n");
	G.handCount[0] = 0;
	call = scoreFor(0, &G);
	checker = myAssertFunction(call, 0);
	if (checker == 1)
	{
		counter++;
	}
	printf("Testing if player 1 hand has correct score when handcout is 2\n");
	G.handCount[0] = 2;
	G.hand[0][0] = province;
	G.hand[0][1] = great_hall;
	call = scoreFor(0, &G);
	checker = myAssertFunction(call, 7);
	if (checker == 1)
	{
		counter++;
	}
	printf("Testing if player 2 hand has correct score with handcount 1\n");
	G.handCount[1] = 1;
	G.hand[1][0] = great_hall;
	call = scoreFor(1, &G);
	checker = myAssertFunction(call, 1);
	if (checker == 1)
	{
		counter++;
	}
	printf("Testing if player 1 starts off with discard pile score of zero\n");
	G.handCount[0] = 0;
	G.discardCount[0] = 0;
	call = scoreFor(0, &G);
	checker = myAssertFunction(call, 0);
	if (checker == 1)
	{
		counter++;
	}
	printf("Testing if player 2 starts off with discard pile score of zero\n");
	G.handCount[1] = 0;
	G.discardCount[1] = 0;
	call = scoreFor(1, &G);
	checker = myAssertFunction(call, 0);
	if (checker == 1)
	{
		counter++;
	}
	printf("Testing if player 1 DISCARD AND DECK score is the expected amount\n");
	G.handCount[0] = 0;
	G.discardCount[0] = 1;
	G.discard[0][0] = province;
	G.deck[0][0] = province;
	call = scoreFor(0, &G);
	checker = myAssertFunction(call, 12);
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
