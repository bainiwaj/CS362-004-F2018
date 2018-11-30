/* 
 * * Jaspal Bainiwal
 * * I am using the testCoinsUpdate template from assignment 3 assistance(2), and
 * cardtest4 template.
 * *I am testing the adventurer card in this test. 
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
	int i;
	int card;
	int treasure_counter = 0;
	int difference; 
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("TESTING adventurer:\n");
	printf("Testing adventurer card draws atleast one treasurer card for player 1\n");
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
	printf("Testing adventurer card draws atleast one treasurer card for player 2\n");
	testG.whoseTurn = 1;
	thisPlayer = testG.whoseTurn;
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
	printf("Testing adventurer card draws exactly two treasurer cards for player 1\n");
	thisPlayer = testG.whoseTurn;
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
	checker = myAssertFunction(difference, 2);
	if (checker == 1)
	{
		counter++;
	}
	printf("Testing adventurer card draws exactly two treasurer cards for player 2\n");
	testG.whoseTurn = 1;
	thisPlayer = testG.whoseTurn;
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
