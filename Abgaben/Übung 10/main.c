/*
	printWordStats
	backpackPaking

	Author: Marco Prescher
	Created on: 04.02.2021
*/

#include <stdio.h>
#include "printWordStats.h"
#include "backpackPaking.h"


#define FALSE 0
#define TRUE (!(FALSE))

#define STRUCTLEN_0 0
#define STRUCTLEN_4 4
#define STRUCTLEN_6 6

#define STRINGMEM 512

// forward declarations ---------------------------------------------------------------------------------------------------------
int testBackpackPaking(char testcase[], double expectedResult, int* errCnt, struct InventoryChunk items[], int structLength, int backpackSize);
// ------------------------------------------------------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
	int test_printWordStats = TRUE;
	int test_backpackPaking = TRUE;

	int success = TRUE;
	int errCnt = 0;
	if (test_printWordStats) {
		printf("\n\n#### printWordStats ##############################################################################\n\n");
		//TODO:: implement testPrintWordStats function

		// test 1 ----------------
		{
			char text[STRINGMEM] = "Gegeben ist ein Text, der in einem char-Feld mit der maximalen Länge 512 gespeichert wird. Der Text besteht nur aus Buchstaben(’a ’..’z ’ und ’A ’..’Z ’) und den Interpunktionszeichen(’.’, ’, ’ und ’ ? ’).";
			int occs[STRINGMEM] = { 0 };

			printWordStats(text, occs);
			printf("\n***************************************************************");
		}
		// test 2 ----------------
		{
			char text[STRINGMEM] = "";
			int occs[STRINGMEM] = { 0 };

			printWordStats(text, occs);
			printf("\n***************************************************************");
		}
		// test 3 ----------------
		{
			char text[STRINGMEM] = "Optimale Bepackung: 1 x Füllfeder, 3 x Filzstift, 6 x Radiergummi => 11€";
			int occs[STRINGMEM] = { 0 };

			printWordStats(text, occs);
			printf("\n***************************************************************");
		}
		// test 4 ----------------
		{
			char text[STRINGMEM] = ",.,,.,???,,.,use,, , , of punctuation,,";
			int occs[STRINGMEM] = { 0 };

			printWordStats(text, occs);
			printf("\n***************************************************************");
		}
	}
	
	if (test_backpackPaking) {
		printf("\n\n#### backpackPaking ##############################################################################\n\n");

		// test 1 ----------------
		{
			struct InventoryChunk items[] = {
				{"Filzstift", 3, 0, 1},
				{"Fuellfeder", 1, 0, 5},
				{"Radiergummi", 40, 0, 0.5},
				{"Kreide", 100, 0, 0.1}
			};

			success = testBackpackPaking("Testcase_1", 11.00, &errCnt, items, STRUCTLEN_4, 10) && success; 
		}
		// test 2 ----------------
		{
			struct InventoryChunk items[] = { NULL };
			success = testBackpackPaking("Testcase_2", 0.00, &errCnt, items, STRUCTLEN_0, 10) && success;
		}
		// test 3 ----------------
		{
			struct InventoryChunk items[] = {
				{"Filzstift", 3, 0, 1},
				{"Fuellfeder", 1, 0, 5},
				{"Radiergummi", 40, 0, 0.5},
				{"Kreide", 100, 0, 0.1}
			};

			success = testBackpackPaking("Testcase_3", 38.00, &errCnt, items, STRUCTLEN_4, 300) && success;
		}
		// test 4 ----------------
		{
			struct InventoryChunk items[] = {
				{"Filzstift", 3, 0, 1},
				{"Fuellfeder", 1, 0, 5},
				{"Radiergummi", 40, 0, 0.5},
				{"Kreide", 100, 0, 0.1},
				{"Handy", 3, 0, 50},
				{"Dosenbier", 100, 0, 0.5},
			};

			success = testBackpackPaking("Testcase_4", 238.00, &errCnt, items, STRUCTLEN_6, 300) && success;
		}
	}

	printf("\n\n\nTest finished with %d error(s)", (success == TRUE ? 0 : errCnt));

	// just to make it more beautiful -------------------------------------------------------------------------------------------
	printf("\n##################################################################################################\n\n");
	// --------------------------------------------------------------------------------------------------------------------------

	return 0;
}

// function definitions ---------------------------------------------------------------------------------------------------------
int testBackpackPaking(char testcase[], double expectedResult, int* errCnt, struct InventoryChunk items[], int structLength, int backpackSize) {
	int success = TRUE;
	printf("\nexpectedResult: %.2f EUR\n\n", expectedResult);

	// get value of backpack -------------------------
	double result = backpackPaking(items, structLength, backpackSize);

	// check result ----------------------------------
	if (result < (expectedResult - 0.01) || result > (expectedResult + 0.01)) {
		printf("\n\n%s failed!", testcase);

		success = FALSE;
		(*errCnt)++;
	}
	else {
		printf("\n\n%s successful!", testcase);
	}

	printf("\n***************************************************************");

	return success;
}
// ------------------------------------------------------------------------------------------------------------------------------