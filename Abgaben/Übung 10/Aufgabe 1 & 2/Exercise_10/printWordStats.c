/*
    getWordLength
	printWordStats

	Author: Marco Prescher
	Created on: 04.02.2021
*/

#include <stdio.h>
#include "printWordStats.h"


#define FALSE 0
#define TRUE (!(FALSE))

#define STRINGMEM 512

// forward declarations ---------------------------------------------------------------------------------------------------------
static int getWordLength(const char text[], int pos);
// ------------------------------------------------------------------------------------------------------------------------------

// function definitions ---------------------------------------------------------------------------------------------------------
static int getWordLength(const char text[], int pos) {
    int i = 0;
    int wordFound = FALSE;

    while (((pos + i) < STRINGMEM) && wordFound == FALSE) {
        char currChar = text[pos + i];
        if (currChar == ',' || currChar == '.' || currChar == ' ' || currChar == '?' || currChar == '\000') {
            wordFound = TRUE;
        }
        else {
            i++;
        }
    }

    return i;
}

int printWordStats(const char text[], int occs[]) {
    printf("\nInput string: \"%s\"\n\n", text);

    int wordLength = 0;
    int i = 0;
    while (i < STRINGMEM) {
        wordLength = getWordLength(text, i);
        occs[wordLength]++;
        if (wordLength != 0) {
            i += wordLength;
        }
        else {
            i++;
        }
    }

    for (int i = 1; i < STRINGMEM; i++) {
        if (occs[i] != 0) {
            printf("Length of word: %d \t-> \t%d\n", i, occs[i]);
        }
    }

    return 0;
}
// ------------------------------------------------------------------------------------------------------------------------------