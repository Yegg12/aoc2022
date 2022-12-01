#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>



int calculate() {
    FILE *fp = fopen("../textfiles/day1input.txt", "r+");
    int calories = 0;
    int sumcalories = 0;
    int newline = 0;
    int fmax = 0;
    int smax = 0;
    int tmax = 0;
    int full = 0;
    int i = 0;
    
    if(!fp) {
        printf("Failed to open file!");
        return EXIT_FAILURE;
    }

    while((newline = fgetc(fp)) != EOF) {
        if(newline == '\n') i++;
        else {
            i = 0;
            calories *= 10;
            calories += newline - '0';
        }

        if(i == 1) {
            sumcalories += calories;
            calories = 0;
        }
        else if(i == 2) {
            if(fmax < sumcalories) {
                tmax = smax;
                smax = fmax;
                fmax = sumcalories;
            }
            sumcalories = 0;
        }
    }

    full = fmax+smax+tmax;

    return full;
}

int main() {
    printf("%d", calculate());

    return EXIT_SUCCESS;
}