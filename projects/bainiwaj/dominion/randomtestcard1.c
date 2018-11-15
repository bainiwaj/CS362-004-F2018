/*
* Jaspal Bainiwal
* This is the random test for the outpost card.
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
	int handSize;
	int handDiff;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G, testG;
	int difference;
	int difference2;
	int difference3;
	int thisPlayer;
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("TESTING Outpost randomly: %d\n", x);
	testG.whoseTurn = rand() % (max + 1 - min) + min;
	thisPlayer = testG.whoseTurn;
	printf("Testing card increases outpost played for player %d\n", (thisPlayer + 1));
	difference = testG.outpostPlayed;
	cardEffect(outpost, choice1, choice2, choice3, &testG, handpos, &bonus);
	difference2 = testG.outpostPlayed;
	difference3 = difference2 - difference;
	printf("Expect a difference of 1 actual difference output %d\n", difference3);
	checker = myAssertFunction(difference3, 1);
	if (checker == 1)
	{
		counter++;
	}
	if (testG.whoseTurn == 1)
	{
		thisPlayer = 0;
	}
	else
	{
		thisPlayer = 1;
	}
	printf("Testing card increases outpost played for any other player: %d\n", (thisPlayer + 1));
	testG.whoseTurn = thisPlayer;
	difference = testG.outpostPlayed;
	cardEffect(outpost, choice1, choice2, choice3, &testG, handpos, &bonus);
	difference2 = testG.outpostPlayed;
	difference3 = difference2 - difference;
	printf("Expect a difference of 1 actual difference output %d\n", difference3);
	checker = myAssertFunction(difference3, 1);
	if (checker == 1)
	{
		counter++;
	}

	memcpy(&testG, &G, sizeof(struct gameState));
	printf("Testing the bug is still present, where coin amount is being changed %d\n", (thisPlayer + 1));
	testG.whoseTurn = thisPlayer;
	difference = testG.coins;
	handSize = testG.playedCardCount;
	cardEffect(outpost, choice1, choice2, choice3, &testG, handpos, &bonus);
	handDiff = testG.playedCardCount;
	difference2 = testG.coins;
	difference3 = difference2 - difference;
	printf("Expect 5 difference in coins actual coin difference =  %d\n", difference3);
	checker = myAssertFunction(difference3, 5);
	if (checker == 1)
	{
		counter++;
	}
	printf("Checking card has been discard properly for player %d\n", (thisPlayer + 1));
	checker = myGreaterAssert(handDiff, handSize);
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
