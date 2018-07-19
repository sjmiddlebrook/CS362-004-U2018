#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


void testAdventurerCard() {
    printf("TESTING Gardens Card\n");
    int kingdomCards[10] = {council_room, mine, remodel, smithy, village, adventurer, sea_hag, minion, cutpurse, gardens};
    struct gameState currentGameState, beginningGameState;

    initializeGame(2, kingdomCards, 5, &currentGameState);
    memcpy(&beginningGameState, &currentGameState, sizeof(struct gameState));

    int bonus = 0;
    int gardensCardEffect = cardEffect(gardens, 0, 0, 0, &currentGameState, 0, &bonus);
    printf("\tTest if adventurer card effect returns -1:\n");
    assertTrue(gardensCardEffect, -1);
}

int main(int argc, char *argv[]) {
    testAdventurerCard();
    return 0;
}



