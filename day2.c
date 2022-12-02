#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

const int lose_lut[] = {2, 3, 1};
const int win_lut[] = {1, 2, 3};

int rounds1() {
    FILE *fp = fopen("../textfiles/day2input.txt", "r");
    int roundwin = 0;
    int sumwonrounds = 0;
    int endoffile = 0;

    int opponentchar = 0;
    int playerchar = 0;

    if(!fp) {
        printf("Failed to open file!");
        return EXIT_FAILURE;
    }

    while(endoffile != EOF) {
        opponentchar = fgetc(fp) - '@';
        fgetc(fp);
        playerchar = fgetc(fp) - 'W';
        endoffile = fgetc(fp);

        if(opponentchar == 1 && playerchar == 2 || 
        opponentchar == 2 && playerchar == 3 || 
        opponentchar == 3 && playerchar == 1) {
            roundwin = 6;
        }
        else if(opponentchar == playerchar) {
            roundwin = 3;
        }
        else {
            roundwin = 0;
        }
        sumwonrounds += roundwin + playerchar;
    }

    fclose(fp);
    return sumwonrounds;
}

int rounds2() {
    FILE *fp = fopen("../textfiles/day2input.txt", "r");
    int roundwin = 0;
    int sumwonrounds = 0;
    int endoffile = 0;

    int opponentchar = 0;
    int playerchar = 0;

    if(!fp) {
        printf("Failed to open file!");
        return EXIT_FAILURE;
    }

    while(endoffile != EOF) {
        opponentchar = fgetc(fp) - '@';
        fgetc(fp);
        playerchar = fgetc(fp) - 'W';
        endoffile = fgetc(fp);

        if(playerchar == 1) {
            roundwin = 0;
            playerchar = lose_lut[opponentchar%3];
        }
        else if(playerchar == 2) {
            roundwin = 3;
            playerchar = opponentchar;
        }
        else if(playerchar == 3) {
            roundwin = 6;
            playerchar = win_lut[opponentchar%3];
        }
        sumwonrounds += roundwin + playerchar;
    }

    fclose(fp);
    return sumwonrounds;
}

int main() {
    printf("%d", rounds2());

    return 0;
}