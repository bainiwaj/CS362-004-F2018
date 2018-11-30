/*
* Jaspal Bainiwal
* This is the random test for the great hall card.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include<stdlib.h>
#include<time.h>
int myAssertFunction(int x, int y);
int myGreaterAssert(int x, int y);
int testRand(int x);

int main() {
	srand(time(NULL));
	int counter = 0;
	int testGenerated = 100;
	int totalTest = testGenerated * 4;
	int testFailed;
	int testPassed;
	int i;
	for (i = 0; i < testGenerated; i++)
	{
		counter = testRand(i + 1);
		testPassed = testPassed + counter;
	}
	testFailed = totalTest - testPassed;
	printf("Test that passed: %d\nTest that failed: %d\n", testPassed, testFailed);
	return 0;
}

int testRand(int x) {
	int seed = 1000;
	int numPlayer = 2;
	int checker;
	int counter = 0;
	int max = 1;
	int min = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G, testG;
	int thisPlayer;
	int difference;
	int difference2;
	int difference3;
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("TESTING Great Hall randomly %d:\n", x);
	testG.whoseTurn = rand() % (max + 1 - min) + min;
	thisPlayer = testG.whoseTurn;
	printf("Testing card increases actions for player %d\n", (thisPlayer + 1));
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
	testG.whoseTurn = thisPlayer;
	printf("Testing card has no change on hand count for player %d\n", (thisPlayer + 1));
	difference = testG.handCount[thisPlayer];
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
	difference2 = testG.handCount[thisPlayer];
	checker = myAssertFunction(difference, difference2);
	if (checker == 1)
	{
		counter++;
	}
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.whoseTurn = thisPlayer;
	printf("Testing card at random handpos has been discarded for player %d\n", (thisPlayer + 1));
	handpos = rand() % (max + 1 - min) + min;
	difference = testG.hand[thisPlayer][handpos];
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
	difference2 = testG.hand[thisPlayer][handpos];
	checker = myGreaterAssert(difference, difference2);
	if (checker == 1)
	{
		counter++;
	}
	printf("Testing card works after one player turn ends and another player plays same card \n");
	if (thisPlayer == 1) {
		testG.whoseTurn = 0;
	}
	else {
		testG.whoseTurn = 1;
	}
	difference = testG.numActions;
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
	difference2 = testG.numActions;
	difference3 = difference2 - difference;
	checker = myAssertFunction(difference3, 1);
	if (checker == 1)
	{
		counter++;
	}
	return counter;
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
