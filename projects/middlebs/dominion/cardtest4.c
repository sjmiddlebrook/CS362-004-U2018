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
    printf("TESTING Council Room Card\n");
    int kingdomCards[10] = {council_room, mine, remodel, smithy, village, adventurer, sea_hag, minion, cutpurse, gardens};
    struct gameState currentGameState, beginningGameState;

    initializeGame(2, kingdomCards, 5, &currentGameState);
    memcpy(&beginningGameState, &currentGameState, sizeof(struct gameState));

    int bonus = 0;
    int councilRoomCardEffect = cardEffect(council_room, 0, 0, 0, &currentGameState, 0, &bonus);
    printf("\tTest if council room card effect returns 0:\n");
    assertTrue(councilRoomCardEffect, 0);

    printf("\tTest deck count decreases by 4 after council room is played:\n");
    assertTrue(currentGameState.deckCount[0], beginningGameState.deckCount[0]-4);

    printf("\tTest hand count has 3 more cards after council room is played:\n");
    assertTrue(currentGameState.handCount[0], beginningGameState.handCount[0]+3);

    printf("\tTest buy increases by 1 after council room is played:\n");
    assertTrue(currentGameState.numBuys, beginningGameState.numBuys+1);

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

    printf("\tTest other player hand count increases by 1:\n");
    assertTrue(currentGameState.handCount[1], beginningGameState.handCount[1]+1);

}

int main(int argc, char *argv[]) {
    testAdventurerCard();
    return 0;
}



