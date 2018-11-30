/*
*Jaspal Bainiwal
* This is test for my adventurer card using random technique.
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int myAssertFunction(int x, int y);
int myGreaterAssert(int x, int y);
int testRand(int x);

int main() {
	srand(time(NULL));
	int counter = 0;
	int testGenerated = 100;
	int totalTest = testGenerated * 5;
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
	int max = 1;
	int min = 0;
	int checker;
	int counter = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G, testG;
	testG.whoseTurn = rand() % (max + 1 - min) + min;
	int thisPlayer = testG.whoseTurn;
	int i;
	int card;
	int treasure_counter = 0;
	int difference;
	int difference2;
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("TESTING adventurer card randomly round: %d\n", x);
	printf("Testing adventurer card draws atleast one treasurer card for player %d\n", (thisPlayer + 1));
	for (i = 0; i < testG.handCount[thisPlayer]; i++)
	{
		card = testG.hand[thisPlayer][i];
		/*using same if statement from dominion.c adventurer function*/
		if (card == copper || card == silver || card == gold)
		{
			treasure_counter++;
		}
	}
	difference = treasure_counter;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	treasure_counter = 0;
	for (i = 0; i < testG.handCount[thisPlayer]; i++)
	{
		card = testG.hand[thisPlayer][i];
		/*using same if statement from dominion.c adventurer function*/
		if (card == copper || card == silver || card == gold)
		{
			treasure_counter++;
		}
	}
	difference = treasure_counter - difference;
	checker = myGreaterAssert(difference, 0);
	if (checker == 1)
	{
		counter++;
	}

	if (thisPlayer == 1) {
		thisPlayer = 0;
	}
	else {
		thisPlayer = 1;
	}
	printf("Testing adventurer card draws atleast one treasurer card for player %d\n", (thisPlayer + 1));
	testG.whoseTurn = thisPlayer;
	treasure_counter = 0;
	difference = 0;
	for (i = 0; i < testG.handCount[thisPlayer]; i++)
	{
		card = testG.hand[thisPlayer][i];
		/*using same if statement from dominion.c adventurer function*/
		if (card == copper || card == silver || card == gold)
		{
			treasure_counter++;
		}
	}
	difference = treasure_counter;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	treasure_counter = 0;
	for (i = 0; i < testG.handCount[thisPlayer]; i++)
	{
		card = testG.hand[thisPlayer][i];
		/*using same if statement from dominion.c adventurer function*/
		if (card == copper || card == silver || card == gold)
		{
			treasure_counter++;
		}
	}
	difference = treasure_counter - difference;
	checker = myGreaterAssert(difference, 0);
	if (checker == 1)
	{
		counter++;
	}
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.whoseTurn = rand() % (max + 1 - min) + min;
	thisPlayer = testG.whoseTurn;
	printf("Testing adventurer card draws exactly two treasurer cards for player %d\n", (thisPlayer + 1));
	difference = 0;
	treasure_counter = 0;
	for (i = 0; i < testG.handCount[thisPlayer]; i++)
	{
		card = testG.hand[thisPlayer][i];
		/*using same if statement from dominion.c adventurer function*/
		if (card == copper || card == silver || card == gold)
		{
			treasure_counter++;
		}
	}
	difference = treasure_counter;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	treasure_counter = 0;
	for (i = 0; i < testG.handCount[thisPlayer]; i++)
	{
		card = testG.hand[thisPlayer][i];
		/*using same if statement from dominion.c adventurer function*/
		if (card == copper || card == silver || card == gold)
		{
			treasure_counter++;
		}
	}
	difference = treasure_counter - difference;
	printf("Expected output = 2 actual output = %d\n", difference);
	checker = myAssertFunction(treasure_counter, 2);
	if (checker == 1)
	{
		counter++;
	}
	if (testG.whoseTurn == 1) {
		thisPlayer = 0;
	}
	else {
		thisPlayer = 1;
	}
	printf("Testing adventurer card draws exactly two treasurer cards for player %d\n", (thisPlayer + 1));
	testG.whoseTurn = thisPlayer;
	treasure_counter = 0;
	for (i = 0; i < testG.handCount[thisPlayer]; i++)
	{
		card = testG.hand[thisPlayer][i];
		/*using same if statement from dominion.c adventurer function*/
		if (card == copper || card == silver || card == gold)
		{
			treasure_counter++;
		}
	}
	difference = treasure_counter;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	treasure_counter = 0;
	for (i = 0; i < testG.handCount[thisPlayer]; i++)
	{
		card = testG.hand[thisPlayer][i];
		/*using same if statement from dominion.c adventurer function*/
		if (card == copper || card == silver || card == gold)
		{
			treasure_counter++;
		}
	}
	difference = treasure_counter - difference;
	printf("Expected output = 2 actual output = %d\n", difference);
	checker = myAssertFunction(treasure_counter, 2);
	if (checker == 1)
	{
		counter++;
	}
	printf("Testing adventurer card does change deck count for player %d\n", (thisPlayer + 1));
	difference = testG.deckCount[thisPlayer];
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	difference2 = testG.deckCount[thisPlayer];
	checker = myGreaterAssert((difference - difference2), 0);
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
