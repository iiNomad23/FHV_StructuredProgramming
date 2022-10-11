/*
	ascii2int
	triangularMatrix
	interestBill
	arithmeticAverage


	Author: Marco Prescher
	Created on: 09.12.2020
*/

#include <stdio.h>

#define NR_OF_VALUES_8 8
#define NR_OF_VALUES_6 6
#define NR_OF_VALUES_1 1
#define NR_OF_VALUES_0 0


int ascii2int(char* chain) {
	printf("\nstring: \"%s\"", chain);

	if (chain[0] != '\0') {
		int number = 0;

		printf("\n\nconverting string to integer...");
		for (int i = 0; chain[i] != '\0'; i++) {
			int currNum = 0;

			switch (chain[i]) {
			case '0':
				currNum = 0;
				break;
			case '1':
				currNum = 1;
				break;
			case '2':
				currNum = 2;
				break;
			case '3':
				currNum = 3;
				break;
			case '4':
				currNum = 4;
				break;
			case '5':
				currNum = 5;
				break;
			case '6':
				currNum = 6;
				break;
			case '7':
				currNum = 7;
				break;
			case '8':
				currNum = 8;
				break;
			case '9':
				currNum = 9;
				break;

			default:
				currNum = -1;
				break;
			}

			// break if number is invalid (no decimal digit)
			if (currNum < 0) {
				break;
			}

			number *= 10;
			number += currNum;
		}
		printf("\nconverting finished\n");

		printf("\ninteger: %d", number);
	}
	else {
		printf("\nstring is empty!");
	}
	
	printf("\n***************************************************************");

	return 0;
}

int triangularMatrix(int number) {
	printf("\nnumber = %d\n", number);

	if (number > 0) {
		int test_while = 1;
		int test_doWhile = 1;
		int test_for = 1;

		if (test_while) {
			printf("\nTest while\n\n");

			int lineBreakNum = 1;
			int printedNumCounter = 0;
			int i = 1;
			while (i < number) {
				printf("%d\t", i);
				printedNumCounter++;

				if ((printedNumCounter % lineBreakNum) == 0) {
					printf("\n");
					lineBreakNum++;
					printedNumCounter = 0;
				}

				i += 2;
			}

			printf("\n\n");
		}

		if (test_doWhile) {
			printf("\nTest doWhile\n\n");

			int lineBreakNum = 1;
			int printedNumCounter = 0;
			int i = 1;

			if (i < number) {
				do {
					printf("%d\t", i);
					printedNumCounter++;

					if ((printedNumCounter % lineBreakNum) == 0) {
						printf("\n");
						lineBreakNum++;
						printedNumCounter = 0;
					}

					i += 2;
				} while (i < number);
			}

			printf("\n\n");
		}

		if (test_for) {
			printf("\nTest for\n\n");

			int lineBreakNum = 1;
			int printedNumCounter = 0;
			for (int i = 1; i < number; i += 2) {
				printf("%d\t", i);
				printedNumCounter++;

				if ((printedNumCounter % lineBreakNum) == 0) {
					printf("\n");
					lineBreakNum++;
					printedNumCounter = 0;
				}
			}

			printf("\n\n");
		}
	}
	else {
		printf("\nnumber must be > 0\n");
	}

	printf("\n***************************************************************");

	return 0;
}

int interestBill(float capital, int fixedRateInPercent, int years) {
	if (years < 0) {
		years = 0;
	}
	if (fixedRateInPercent < 0) {
		fixedRateInPercent = 0;
	}

	printf("\nCapital development for share capital: %.2f EUR\n", capital);
	printf("Fixed rate: %d%, Duration: %d Years\n\n", fixedRateInPercent, years);

	printf("Year \t\tCapital");
	printf("\n----------------------------------------");
	for (int i = 1; i <= years; i++) {
		capital += capital / 100 * fixedRateInPercent;
		printf("\n%d \t\t%.2f EUR\n", i, capital);
	}

	printf("\nYour capital after %d year(s) is %.2f EUR", years, capital);
	printf("\n***************************************************************");

	return 0;
}

int arithmeticAverage(int valueCount, int values[]) {
	printf("\nvalueCount: %d\n", valueCount);

	if (valueCount > 0) {
		int min = values[0];
		int max = values[0];
		int arithAvg = 0;

		printf("\ncalculating min, max and arithmeticAverage...");
		for (int i = 0; i < valueCount; i++) {
			int currVal = values[i];

			if (currVal < min) {
				min = currVal;
			}
			if (currVal > max) {
				max = currVal;
			}

			arithAvg += currVal;
		}
		printf("\nfinished\n");

		printf("\nArithmetic average: %.3f", (float)arithAvg / valueCount);
		printf("\nmin: %d", min);
		printf("\nmax: %d", max);
	}
	else {
		printf("\narray is empty!");
	}
	
	printf("\n***************************************************************");

	return 0;
}


int main(int argc, char* argv[]) {
	int test_ascii2int = 1;
	int test_triangularMatrix = 0;
	int test_interestBill = 0;
	int test_arithmeticAverage = 0;

	if (test_ascii2int) {
		printf("\n\n#### ascii2int ############################################################################\n\n");

		// test 1 ----------------
		ascii2int("213532");
		// test 2 ----------------
		ascii2int("a213532");
		// test 3 ----------------
		ascii2int("213532-");
		// test 4 ----------------
		ascii2int("213 532");
		// test 5 ----------------
		ascii2int("");
	}

	if (test_triangularMatrix) {
		printf("\n\n#### triangularMatrix #####################################################################\n\n");

		// test 1 ----------------
		triangularMatrix(0);
		// test 2 ----------------
		triangularMatrix(1);
		// test 3 ----------------
		triangularMatrix(2);
		// test 4 ----------------
		triangularMatrix(20);
		// test 5 ----------------
		triangularMatrix(15);
		// test 6 ----------------
		triangularMatrix(200);
	}

	if (test_interestBill) {
		printf("\n\n#### interestBill #########################################################################\n\n");

		// test 1 ----------------
		interestBill(1000.00, 5, 10);
		// test 2 ----------------
		interestBill(-1000.00, 2, 5);
		// test 3 ----------------
		interestBill(0.00, 10, 3);
		// test 4 ----------------
		interestBill(666.66, 20, 15);
		// test 5 ----------------
		interestBill(666.66, 0, 0);
	}

	if (test_arithmeticAverage) {
		printf("\n\n#### arithmeticAverage ####################################################################\n\n");

		// test 1 ----------------
		{
			int values[] = { 3, 5, 7, 8, 1, -1, 4, 0 };
			printf("\nvalues: { 3, 5, 7, 8, 1, -1, 4, 0 }");
			arithmeticAverage(NR_OF_VALUES_8, values);
		}
		// test 2 ----------------
		{
			int values[] = { 0, 4, 1, -10, 4, 0 };
			printf("\nvalues: { 0, 4, 1, -10, 4, 0 }");
			arithmeticAverage(NR_OF_VALUES_6, values);
		}
		// test 3 ----------------
		{
			int values[] = { 2 };
			printf("\nvalues: { 2 }");
			arithmeticAverage(NR_OF_VALUES_1, values);
		}
		// test 4 ----------------
		{
			printf("\nvalues: { }");
			arithmeticAverage(NR_OF_VALUES_0, NULL);
		}
		
	}


	// just to make it more beautiful ------------------------------------------------------------------------------------------
	printf("\n###########################################################################################\n\n");
	// -------------------------------------------------------------------------------------------------------------------------

	return 0;
}