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


void randomTestCard() {

}

int main(int argc, char *argv[]) {
    randomTestCard();
    return 0;
}
