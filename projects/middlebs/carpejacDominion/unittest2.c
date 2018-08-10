#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void assertTrue(int a, int b) {
    if (a == b) {
        printf("\tPassed Test\n\n");
    } else {
        printf("\tFailed Test\n\n");
    }
}


void testIsGameOver() {
    printf("TESTING isGameOver()\n");
    int kingdomCards[10] = {council_room, mine, remodel, smithy, village, adventurer, sea_hag, minion, cutpurse, gardens};
    struct gameState testGameState1;

    initializeGame(2, kingdomCards, 5, &testGameState1);

    printf("\tgame has just started and is not over:\n");
    assertTrue(isGameOver(&testGameState1), 0);

    testGameState1.supplyCount[province] = 0;

    printf("\tprovinces are empty and game is over:\n");
    assertTrue(isGameOver(&testGameState1), 1);

    struct gameState testGameState2;
    initializeGame(2, kingdomCards, 5, &testGameState2);

    printf("\t0 supply piles are empty and game is not over:\n");
    assertTrue(isGameOver(&testGameState2), 0);

    testGameState2.supplyCount[curse] = 0;
    testGameState2.supplyCount[copper] = 0;

    printf("\t2 supply piles are empty and game is not over:\n");
    assertTrue(isGameOver(&testGameState2), 0);

    testGameState2.supplyCount[silver] = 0;

    printf("\t3 supply piles are empty and game is over:\n");
    assertTrue(isGameOver(&testGameState2), 1);
}

int main(int argc, char *argv[]) {
    testIsGameOver();
    return 0;
}