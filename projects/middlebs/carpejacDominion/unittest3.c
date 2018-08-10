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


void testWhoseTurn() {
    printf("TESTING whoseTurn()\n");
    int kingdomCards[10] = {council_room, mine, remodel, smithy, village, adventurer, sea_hag, minion, cutpurse, gardens};
    struct gameState testGameState1;

    initializeGame(2, kingdomCards, 5, &testGameState1);
    testGameState1.whoseTurn = 0;
    printf("\tcheck first player turn:\n");
    assertTrue(whoseTurn(&testGameState1), 0);

    testGameState1.whoseTurn = 1;
    printf("\tcheck second player turn:\n");
    assertTrue(whoseTurn(&testGameState1), 1);
}

int main(int argc, char *argv[]) {
    testWhoseTurn();
    return 0;
}