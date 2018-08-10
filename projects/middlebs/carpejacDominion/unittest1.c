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


void testGetCost() {
    printf("TESTING getCost()\n");
    printf("\tcurse cost:\n");
    assertTrue(getCost(curse), 0);
    printf("\testate cost:\n");
    assertTrue(getCost(estate), 2);
    printf("\tduchy cost:\n");
    assertTrue(getCost(duchy), 5);
    printf("\tprovince cost:\n");
    assertTrue(getCost(province), 8);
    printf("\tcopper cost:\n");
    assertTrue(getCost(copper), 0);
    printf("\tsilver cost:\n");
    assertTrue(getCost(silver), 3);
    printf("\tgold cost:\n");
    assertTrue(getCost(gold), 6);
    printf("\tadventurer cost:\n");
    assertTrue(getCost(adventurer), 6);
    printf("\tcouncil_room cost:\n");
    assertTrue(getCost(council_room), 5);
    printf("\tfeast cost:\n");
    assertTrue(getCost(feast), 4);
    printf("\tgardens cost:\n");
    assertTrue(getCost(gardens), 4);
    printf("\tmine cost:\n");
    assertTrue(getCost(mine), 5);
    printf("\tremodel cost:\n");
    assertTrue(getCost(remodel), 4);
    printf("\tsmithy cost:\n");
    assertTrue(getCost(smithy), 4);
    printf("\tvillage cost:\n");
    assertTrue(getCost(village), 3);
    printf("\tbaron cost:\n");
    assertTrue(getCost(baron), 4);
    printf("\tgreat_hall cost:\n");
    assertTrue(getCost(great_hall), 3);
    printf("\tminion cost:\n");
    assertTrue(getCost(minion), 5);
    printf("\tsteward cost:\n");
    assertTrue(getCost(steward), 3);
    printf("\ttribute cost:\n");
    assertTrue(getCost(tribute), 5);
    printf("\tambassador cost:\n");
    assertTrue(getCost(ambassador), 3);
    printf("\tcutpurse cost:\n");
    assertTrue(getCost(cutpurse), 4);
    printf("\tembargo cost:\n");
    assertTrue(getCost(embargo), 2);
    printf("\toutpust cost:\n");
    assertTrue(getCost(outpost), 5);
    printf("\tsalvager cost:\n");
    assertTrue(getCost(salvager), 4);
    printf("\tsea_hag cost:\n");
    assertTrue(getCost(sea_hag), 4);
    printf("\ttreasure_map cost:\n");
    assertTrue(getCost(treasure_map), 4);
}

int main(int argc, char *argv[]) {
    testGetCost();
    return 0;
}

