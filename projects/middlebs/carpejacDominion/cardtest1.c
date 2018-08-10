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


void testSmithyCard() {
    printf("TESTING Smithy Card\n");
    int kingdomCards[10] = {council_room, mine, remodel, smithy, village, adventurer, sea_hag, minion, cutpurse, gardens};
    struct gameState currentGameState, beginningGameState;

    initializeGame(2, kingdomCards, 5, &currentGameState);
    memcpy(&beginningGameState, &currentGameState, sizeof(struct gameState));

    int bonus = 0;
    int smithyCardEffect = cardEffect(smithy, 0, 0, 0, &currentGameState, 0, &bonus);
    printf("\tTest if smithy card effect returns 0:\n");
    assertTrue(smithyCardEffect, 0);

    printf("\tTest deck count decreases by 3 after smithy is played:\n");
    assertTrue(currentGameState.deckCount[0], beginningGameState.deckCount[0]-3);

    printf("\tTest hand count has 2 more cards after smithy is played:\n");
    assertTrue(currentGameState.handCount[0], beginningGameState.handCount[0]+2);

    printf("\tTest kingdom cards supply count remains the same:\n");
    int i;
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

int main(int argc, char *argv[]) {
    testSmithyCard();
    return 0;
}
