#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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


void randomTestCard() {
    printf("RANDOM TESTING Adventurer Card\n");
    int kingdomCards[10] = {council_room, mine, remodel, smithy, village, adventurer, sea_hag, minion, cutpurse, gardens};
    struct gameState currentGameState, beginningGameState;
    srand(time(0));

    int i;
    for (i=0; i < 200; i++) {
        int randNum = rand();
        initializeGame(2, kingdomCards, randNum, &currentGameState);
        memcpy(&beginningGameState, &currentGameState, sizeof(struct gameState));

        int bonus = 0;
        int adventurerCardEffect = cardEffect(adventurer, 0, 0, 0, &currentGameState, 0, &bonus);
        printf("\tTest if adventurer card effect returns 0:\n");
        assertTrue(adventurerCardEffect, 0);

        int beginningTreasures = 0;
        int i;
        for (i = 0; i < beginningGameState.handCount[0]; i++) {
            if (beginningGameState.hand[0][i] == copper || beginningGameState.hand[0][i] == silver ||
                beginningGameState.hand[0][i] == gold) {
                beginningTreasures++;
            }
        }

        int currentTreasures = 0;
        for (i = 0; i < currentGameState.handCount[0]; i++) {
            if (currentGameState.hand[0][i] == copper || currentGameState.hand[0][i] == silver ||
                currentGameState.hand[0][i] == gold) {
                currentTreasures++;
            }
        }

        printf("\tTest treasure increases by 2 after adventurer:\n");
        assertTrue(beginningTreasures + 2, currentTreasures);

        printf("\tTest kingdom cards supply count remains the same:\n");
        for (i = 0; i < 10; i++) {
            assertTrue(currentGameState.supplyCount[kingdomCards[i]], beginningGameState.supplyCount[kingdomCards[i]]);
        }

        printf("\tTest victory cards supply count remains the same:\n");
        assertTrue(currentGameState.supplyCount[province], beginningGameState.supplyCount[province]);
        assertTrue(currentGameState.supplyCount[duchy], beginningGameState.supplyCount[duchy]);
        assertTrue(currentGameState.supplyCount[estate], beginningGameState.supplyCount[estate]);

        printf("\tTest treasure cards supply count remains the same:\n");
        assertTrue(currentGameState.supplyCount[copper], beginningGameState.supplyCount[copper]);
        assertTrue(currentGameState.supplyCount[silver], beginningGameState.supplyCount[silver]);
        assertTrue(currentGameState.supplyCount[gold], beginningGameState.supplyCount[gold]);

        printf("\tTest other player state not changing:\n");
        assertTrue(currentGameState.deckCount[1], beginningGameState.deckCount[1]);
        assertTrue(currentGameState.handCount[1], beginningGameState.handCount[1]);
    }
}

int main(int argc, char *argv[]) {
    randomTestCard();
    return 0;
}
