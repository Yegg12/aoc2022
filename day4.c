#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//#define TEST
#define FINAL

//#define CHAL2

typedef struct {
    int min;
    int max;
} range;

int insideRange(range rangeA, range rangeB) {
    if(rangeA.min <= rangeB.min && rangeA.max >= rangeB.max 
    || rangeA.min >= rangeB.min && rangeA.max <= rangeB.max
    #ifdef CHAL2
    || rangeA.min <= rangeB.min && rangeA.max >= rangeB.min
    || rangeA.min <= rangeB.max && rangeA.max >= rangeB.max
    #endif
    ) {
        return 1;
    }
    else return 0;
}

int findNum(FILE *fp) {
    int a = 0;
    int c;

    while(1) {
        c = fgetc(fp);
        if( c != '-' && 
            c != ',' && 
            c != '\n' && 
            c != EOF) {
        a *= 10;
        a += c - '0';
        } else break;
    }

    return a;
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
        rangeA.min = findNum(fp);
        rangeA.max = findNum(fp);

        rangeB.min = findNum(fp);
        rangeB.max = findNum(fp);

        if(rangeA.min && rangeB.max != 0) {} else break;

        if(insideRange(rangeA, rangeB) == 1) i++;

        rangeA.min = 0, rangeA.max = 0;
        rangeB.min = 0, rangeB.max = 0;
    }

    printf("%d", i);

    return 0;
}