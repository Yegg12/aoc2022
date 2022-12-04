#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define FINAL

typedef struct {
    int min;
    int max;
} range;

int insideRange(range rangeA, range rangeB) {
    if(rangeA.min <= rangeB.min && rangeA.max >= rangeB.max 
    || rangeA.min >= rangeB.min && rangeA.max <= rangeB.max
    #ifdef TEST2
    || rangeA.min <= rangeB.min && rangeA.max >= rangeB.min
    || rangeA.min <= rangeB.max && rangeA.max >= rangeB.max
    #endif
    ) {
        return 1;
    }
    else return 0;
}

int main() {
#ifdef FINAL
    FILE *fp = fopen("../textfiles/day4input.txt", "r");
#endif

#ifdef TEST
    FILE *fp = fopen("../textfiles/testinput.txt", "r");
#endif

    if(!fp) {
        printf_s("Could not open file!");
        return EXIT_FAILURE;
    }

    int i = 0;
    int c;
    range rangeA;
    range rangeB;

    rangeA.min = 0, rangeA.max = 0;
    rangeB.min = 0, rangeB.max = 0;

    while(c != EOF) {
        c = 0;

        while(c != '-') {
            c = fgetc(fp);
            if(c != '-') {
            rangeA.min *= 10;
            rangeA.min += c - '0';
            }
        }
        c = 0;

        while(c != ',') {
            c = fgetc(fp);
            if(c != ',') {
            rangeA.max *= 10;
            rangeA.max += c - '0';
            }
        }
        c = 0;

        while(c != '-') {
            c = fgetc(fp);
            if(c != '-') {
            rangeB.min *= 10;
            rangeB.min += c - '0';
            }
        }
        c = 0;

        while(c != '\n' && c != EOF) {
            c = fgetc(fp);
            if(c != '\n' && c != EOF) {
            rangeB.max *= 10;
            rangeB.max += c - '0';
            }
        }

        if(insideRange(rangeA, rangeB) == 1) i++;

        rangeA.min = 0, rangeA.max = 0;
        rangeB.min = 0, rangeB.max = 0;
    }

    printf("%d", i);

    return 0;
}