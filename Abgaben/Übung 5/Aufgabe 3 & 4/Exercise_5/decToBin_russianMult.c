/*
	decToBin
	and
	russianPeasantMultiplication

	Author: Marco Prescher
	Created on: 02.12.2020
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
	int test_convertDecimalToBinary = 1;
	int test_russianPeasantMultiplication = 0;

	// convert Decimal to Binary ----------------------------------------------------------
	#pragma region convertDecimalToBinary
	if (test_convertDecimalToBinary) {
		printf("\n#### decToBin ###############################################");

		// test 1 -> value: 0 --------------------
		convertDecimalToBinary(0);

		// test 2 -> value: 33 -------------------
		convertDecimalToBinary(33);

		// test 3 -> value: -10 ------------------
		convertDecimalToBinary(-10);

		printf("\n-------------------------------------------------");
	}
	#pragma endregion
	
	// russian peasant multiplication -----------------------------------------------------
	#pragma region russianPeasantMultiplication
	if (test_russianPeasantMultiplication) {
		printf("\n#### russianMul #############################################");

		// test 1 -> values: 3, 8 ----------------
		russianPeasantMultiplication(3, 8);

		// test 2 -> values: -4, 0 ---------------
		russianPeasantMultiplication(-4, 0);

		// test 3 -> values: 0, 8 ----------------
		russianPeasantMultiplication(0, 8);

		// test 4 -> values: 10, 1 ---------------
		russianPeasantMultiplication(10, 1);

		printf("\n-------------------------------------------------");
	}
	#pragma endregion
	
	// alternativ
	#pragma region getMissingNumber
	// getMissingNumber -------------------------------------------------------------------
	// int values[] = { 0,1,3,4,5 };
	// int valueCount = sizeof values / sizeof *values;
	// int missingNumber = getMissingNumber(valueCount, values, missingNumber);
	#pragma endregion

	// just to make it more beautiful -----------------------------------------------------
	printf("\n\n");
	// ------------------------------------------------------------------------------------

	return 0;
}

int convertDecimalToBinary(int decNumber) {
	printf("\n-------------------------------------------------");
	printf("\ndecNumber: %d", decNumber);

	if (decNumber == 0) {
		printf("\ndecNumber == 0");
		printf("\nBinary of decNumber is = 0");
	} else {
		printf("\ndecNumber != 0");

		// prepare binary array
		int binaryValues[64] = { 0 };

		int isPositiv = 0;
		if (decNumber >= 0) {
			printf("\ndecNumber >= 0 --> decNumber is Positive");
			isPositiv = 1;
		} else {
			printf("\ndecNumber < 0 --> decNumber is Negative");
			decNumber *= (-1);
		}

		// convert ------------------------------------------------------------------------
		printf("\n\nconverting decNumber to binary...");
		int i = 0;
		for (i = 0; decNumber > 0; i++) {
			binaryValues[i] = decNumber % 2;
			decNumber = decNumber / 2;
		}
		printf("\nconverting finished\n");

		if (isPositiv) {
			printf("\nBinary of decNumber is = ");
		} else {
			printf("\nBinary of decNumber is = -");
		}

		// print binary numbers in the right order ----------------------------------------
		for (i = i - 1; i >= 0; i--) {
			printf("%d", binaryValues[i]);
		}
	}

	return 0;
}

int russianPeasantMultiplication(int multiplier, int multiplicand) {
	printf("\n-------------------------------------------------");
	printf("\nmultiplier: %d, multiplicand: %d\n", multiplier, multiplicand);

	int result = 0;

	if (multiplier > 0 && multiplicand > 0) {
		printf("\nmultiplier > 0 && multiplicand > 0");

		printf("\ncalculating...");
		while (multiplier >= 1) {
			if ((multiplier % 2) != 0) {
				result += multiplicand;
			}

			multiplier /= 2;
			multiplicand += multiplicand;
		}
		printf("\nfinished");
	} else {
		printf("\nmultiplier, multiplicand or both <= 0");
	}

	printf("\n\nresult: %d", result);
	return result;
}


// alternativ
int getMissingNumber(int valueCount, int values[]) {
	int sumOfIndexes = 0;
	int sumOfValues = 0;

	for (int i = 0; i < valueCount; i++) {
		sumOfIndexes += i;
		sumOfValues += values[i];
	}

	return (sumOfIndexes + valueCount) - sumOfValues;
}