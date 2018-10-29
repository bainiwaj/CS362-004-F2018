/* 
 * * Jaspal Bainiwal
 * * I am using the testCoinsUpdate template from assignment 3 assistance(2), and
 * cardtest4 template.
 * *I am testing the great hall card in this test. 
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
	int checker;
	int counter = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G, testG;
	int thisPlayer = testG.whoseTurn;
	int difference; 
	int difference2;
	int difference3;
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("TESTING Great Hall:\n");
	printf("Testing card increases actions for player 1\n");
	difference = testG.numActions;
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
	difference2 = testG.numActions;
	difference3 = difference2 - difference;
	checker = myAssertFunction(difference3, 1);
	if (checker == 1)
	{
		counter++;
	}
	printf("Testing card increases actions for player 2\n");
	testG.whoseTurn = 1;
	thisPlayer = testG.whoseTurn;
	difference = testG.numActions;
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
	difference2 = testG.numActions;
	difference3 = difference2 - difference;
	checker = myAssertFunction(difference3, 1);
	if (checker == 1)
	{
		counter++;
	}
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("Testing card has no change on hand count for player 1\n");
	difference = testG.handCount[thisPlayer];
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
	difference2 = testG.handCount[thisPlayer];
	checker = myAssertFunction(difference, difference2);
	if (checker == 1) 
	{
		counter++;
	}
	printf("Testing card has no change on hand count for player 2\n");
	testG.whoseTurn = 1;
	thisPlayer = testG.whoseTurn;
	difference = testG.handCount[thisPlayer];
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
	difference2 = testG.handCount[thisPlayer];
	checker = myAssertFunction(difference, difference2);
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
