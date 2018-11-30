/* 
 * * Jaspal Bainiwal
 * * I am using the testCoinsUpdate template from assignment 3 assistance(2), and
 * cardtest4 template.
 * *I am testing the smithy card in this test. 
 *
 * */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
int myAssertFunction(int x, int y);
int myGreaterAssert(int x, int y);

int main() {
	int seed = 1000;
	int numPlayer = 2;
	int call;
	int checker;
	int counter = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G, testG;
	int thisPlayer = testG.whoseTurn;
	int discard;
	
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("TESTING Smithy:\n");
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("Testing smithy card draws atleast one card for player\n");
	call = testG.handCount[thisPlayer];
	checker = myGreaterAssert(call, 5);
	if (checker == 1)
	{
		counter++;
	}
	printf("Testing smithy card draws atleast two card for player\n");
	call = testG.handCount[thisPlayer];
	checker = myGreaterAssert(call, 6);
	if (checker == 1)
	{
		counter++;
	}
	printf("Testing smithy card draws three cards then discards one\n");
	call = testG.handCount[thisPlayer];
	checker = myAssertFunction(call, 7);
	if (checker == 1)
	{
		counter++;
	}
	printf("Testing smithy discards one card\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	discard = testG.handCount[thisPlayer];
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	call = testG.handCount[thisPlayer];
	discard = call - discard;
	checker = myAssertFunction(discard, 3);
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
 * the built in assert might crash the program*/
int myAssertFunction(int x, int y)
{
	if (x != y || x < y)
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

int myGreaterAssert(int x, int y)
{
	if (x < y)
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
