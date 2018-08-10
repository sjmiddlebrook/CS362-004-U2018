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


void testSupplyCount() {
    printf("TESTING supplyCount()\n");
    int kingdomCards[10] = {council_room, mine, remodel, smithy, village, adventurer, sea_hag, minion, cutpurse, gardens};
    struct gameState testGameState1;

    initializeGame(2, kingdomCards, 5, &testGameState1);

    printf("\tcheck initial supply count of gold:\n");
    assertTrue(supplyCount(gold, &testGameState1), 30);

    printf("\tcheck initial supply count of silver:\n");
    assertTrue(supplyCount(silver, &testGameState1), 40);

    printf("\tcheck initial supply count of copper:\n");
    assertTrue(supplyCount(copper, &testGameState1), 46);

    int i;
    // loop all cards to set supply count and test
    for (i = 0; i <= treasure_map; i++) {
        testGameState1.supplyCount[i] = 2;
        printf("\tCheck supply count:\n");
        assertTrue(supplyCount(i, &testGameState1), 2);
    }

}

int main(int argc, char *argv[]) {
    testSupplyCount();
    return 0;
}