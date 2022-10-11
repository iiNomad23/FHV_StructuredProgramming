/*
	summation
	summationExtension1
	summationExtension2
	getMaximum
	seriesExpansionExponentialFunc
	approximateCalcSquareRoot

	Author: Marco Prescher
	Created on: 16.12.2020
*/

#include <stdio.h>

#define NR_OF_VALUES_5 5
#define NR_OF_VALUES_1 1
#define NR_OF_VALUES_0 0

#define FALSE 0
#define TRUE (!(FALSE))

// forward declaration ---------------------------------------------------------------------------------------------------------
int testSummation(char* testcase, int expectedResult, int* errCnt, int upperLimit);
int summation(int upperLimit);

int testSummationExtension1(char* testcase, int expectedResult, int* errCnt, int upperLimit);
int summationExtension1(int upperLimit);

int testSummationExtension2(char* testcase, int expectedResult, int* errCnt, int lowerLimit, int upperLimit);
int summationExtension2(int lowerLimit, int upperLimit);

int testGetMaximum(char* testcase, int expectedResult, int* errCnt, int values[], int valueCount);
int getMaximum(int values[], int valueCount);

int testSeriesExpansionExponentialFunc(char* testcase, float expectedResult, int* errCnt, float z, int n);
float seriesExpansionExponentialFunc(float z, int n);

int testApproximateCalcSquareRoot(char* testcase, float expectedResult, int* errCnt, float precision, int square);
float approximateCalcSquareRoot(float precision, int square);
// -----------------------------------------------------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
	int test_summation = 1;
	int test_summationExtension1 = 0;
	int test_summationExtension2 = 0;
	int test_getMaximum = 0;
	int test_seriesExpansionExponentialFunc = 0;
	int test_approximateCalcSquareRoot = 0;

	int success = TRUE;
	int errCnt = 0;

	if (test_summation) {
		printf("\n\n#### summation ############################################################################\n\n");

		// test 1 ----------------
		success = testSummation("Testcase_1", 10, &errCnt, 4) && success;

		// test 2 ----------------
		success = testSummation("Testcase_2", 0, &errCnt, 0) && success;

		// test 3 ----------------
		success = testSummation("Testcase_3", 1, &errCnt, 1) && success;

		// test 4 ----------------
		success = testSummation("Testcase_4", 3, &errCnt, 2) && success;
	}

	if (test_summationExtension1) {
		printf("\n\n#### summationExtension1 ##################################################################\n\n");

		// test 1 ----------------
		success = testSummationExtension1("Testcase_1", 20, &errCnt, 8) && success;

		// test 2 ----------------
		success = testSummationExtension1("Testcase_2", 0, &errCnt, 0) && success;

		// test 3 ----------------
		success = testSummationExtension1("Testcase_3", 0, &errCnt, 1) && success;

		// test 4 ----------------
		success = testSummationExtension1("Testcase_4", 2, &errCnt, 2) && success;
	}

	if (test_summationExtension2) {
		printf("\n\n#### summationExtension2 ##################################################################\n\n");

		// test 1 ----------------
		success = testSummationExtension2("Testcase_1", 18, &errCnt, 5, 7) && success;

		// test 2 ----------------
		success = testSummationExtension2("Testcase_2", 13, &errCnt, -5, 7) && success;

		// test 3 ----------------
		success = testSummationExtension2("Testcase_3", -6, &errCnt, -3, -1) && success;

		// test 4 ----------------
		success = testSummationExtension2("Testcase_4", 0, &errCnt, 5, 1) && success;

		// test 5 ----------------
		success = testSummationExtension2("Testcase_5", 0, &errCnt, 0, 0) && success;
	}

	if (test_getMaximum) {
		printf("\n\n#### getMaximum ###########################################################################\n\n");

		// test 1 ----------------
		{
			int values[] = { 3, 5, 10, 2, 1 };
			success = testGetMaximum("Testcase_1", 10, &errCnt, values, NR_OF_VALUES_5) && success;
		}
		// test 2 ----------------
		{
			int values[] = { -10, -1, -4, -9, -57 };
			success = testGetMaximum("Testcase_2", -1, &errCnt, values, NR_OF_VALUES_5) && success;
		}
		// test 3 ----------------
		{
			int values[] = { 5 };
			success = testGetMaximum("Testcase_3", 5, &errCnt, values, NR_OF_VALUES_1) && success;
		}
		// test 4 ----------------
		{
			success = testGetMaximum("Testcase_4", 0, &errCnt, NULL, NR_OF_VALUES_0) && success;
		}
	}

	if (test_seriesExpansionExponentialFunc) {
		printf("\n\n#### seriesExpansionExponentialFunc #######################################################\n\n");

		// test 1 ----------------
		success = testSeriesExpansionExponentialFunc("Testcase_1", 113.118057, &errCnt, 5.00, 7) && success;
		
		// test 2 ----------------
		success = testSeriesExpansionExponentialFunc("Testcase_2", 0.000000, &errCnt, 1.00, 0) && success;

		// test 3 ----------------
		success = testSeriesExpansionExponentialFunc("Testcase_3", 2161.260742, &errCnt, 22.45, 4) && success;

		// test 4 ----------------
		success = testSeriesExpansionExponentialFunc("Testcase_4", 1.000000, &errCnt, 0.00, 10) && success;

		// test 5 ----------------
		success = testSeriesExpansionExponentialFunc("Testcase_5", 0.367879, &errCnt, -1.00, 10) && success;
	}

	if (test_approximateCalcSquareRoot) {
		printf("\n\n#### approximateCalcSquareRoot ############################################################\n\n");

		// test 1 ----------------
		success = testApproximateCalcSquareRoot("Testcase_1", 2.236068, &errCnt, 0.00002, 5) && success;

		// test 2 ----------------
		success = testApproximateCalcSquareRoot("Testcase_2", 0.000000, &errCnt, -0.00002, 2) && success;

		// test 3 ----------------
		success = testApproximateCalcSquareRoot("Testcase_3", 0.000000, &errCnt, 0.000002, 0) && success;

		// test 4 ----------------
		success = testApproximateCalcSquareRoot("Testcase_4", 11.224972, &errCnt, 0.0001, 126) && success;

		// test 5 ----------------
		success = testApproximateCalcSquareRoot("Testcase_5", 11.225193, &errCnt, 1, 126) && success;
	}

	printf("\n\n\nTest finished with %d error(s)", (success == TRUE ? 0 : errCnt));

	// just to make it more beautiful ------------------------------------------------------------------------------------------
	printf("\n###########################################################################################\n\n");
	// -------------------------------------------------------------------------------------------------------------------------

	return 0;
}

int testSummation(char* testcase, int expectedResult, int *errCnt, int upperLimit) {
	int success = TRUE;
	printf("\nexpectedResult: %d\n", expectedResult);

	int result = summation(upperLimit);
	if (result != expectedResult) {
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
int summation(int upperLimit) {
	printf("\nupperLimit: %d\n", upperLimit);

	printf("\ncalculating result...");
	int result = 0;
	for (int i = 1; i <= upperLimit; i++) {
		result += i;
	}
	printf("\nfinished\n");

	printf("\nresult: %d", result);
	return result;
}

int testSummationExtension1(char* testcase, int expectedResult, int* errCnt, int upperLimit) {
	int success = TRUE;
	printf("\nexpectedResult: %d\n", expectedResult);

	int result = summationExtension1(upperLimit);
	if (result != expectedResult) {
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
int summationExtension1(int upperLimit) {
	printf("\nupperLimit: %d\n", upperLimit);

	printf("\ncalculating result...");
	int result = 0;
	for (int i = 2; i <= upperLimit; i++) {
		if ((i % 2) == 0) {
			result += i;
		}
	}
	printf("\nfinished\n");

	printf("\nresult: %d", result);
	return result;
}

int testSummationExtension2(char* testcase, int expectedResult, int* errCnt, int lowerLimit, int upperLimit) {
	int success = TRUE;
	printf("\nexpectedResult: %d\n", expectedResult);

	int result = summationExtension2(lowerLimit, upperLimit);
	if (result != expectedResult) {
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
int summationExtension2(int lowerLimit, int upperLimit) {
	printf("\nlowerLimit: %d, upperLimit: %d\n", lowerLimit, upperLimit);

	printf("\ncalculating result...");
	int result = 0;
	for (int i = lowerLimit; i <= upperLimit; i++) {
		result += i;
	}
	printf("\nfinished\n");

	printf("\nresult: %d", result);
	return result;
}

int testGetMaximum(char* testcase, int expectedResult, int* errCnt, int values[], int valueCount) {
	int success = TRUE;
	printf("\nexpectedResult: %d\n", expectedResult);

	int result = getMaximum(values, valueCount);
	if (result != expectedResult) {
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
int getMaximum(int values[], int valueCount) {
	printf("\nvalueCount: %d\n", valueCount);

	int max = 0;
	if (valueCount > 0) {
		max = values[0];

		printf("\nsearching max...");
		for (int i = 1; i < valueCount; i++) {
			int currVal = values[i];

			if (max < currVal) {
				max = currVal;
			}
		}
		printf("\nfinished\n");
	}
	else {
		printf("\narray is empty!");
	}
	
	printf("\nmax: %d", max);
	return max;
}

int testSeriesExpansionExponentialFunc(char* testcase, float expectedResult, int* errCnt, float z, int n) {
	int success = TRUE;
	printf("\nexpectedResult: %f\n", expectedResult);

	float result = seriesExpansionExponentialFunc(z, n);
	if (result < (expectedResult - 0.000001) || result > (expectedResult + 0.000001)) {
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
float seriesExpansionExponentialFunc(float z, int n) {
	printf("\nz: %f, n: %d\n", z, n);

	float result = 0;
	if (n > 0) {
		int faculty = 1;
		float expo = 1;

		printf("\ncalculating expo...");
		int i = 0;
		while (i < n) {
			result += (expo / faculty);

			i++;

			faculty = faculty * i;
			expo = expo * z;
		}
		printf("\nfinished\n");
	}
	else {
		printf("\nn <= 0!\n");
	}

	printf("\nresult: %f", result);
	return result;
}

int testApproximateCalcSquareRoot(char* testcase, float expectedResult, int* errCnt, float precision, int square) {
	int success = TRUE;
	printf("\nexpectedResult: %f\n", expectedResult);

	float result = approximateCalcSquareRoot(precision, square);
	if (result < (expectedResult - 0.000001) || result >(expectedResult + 0.000001)) {
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
float approximateCalcSquareRoot(float precision, int square) {
	printf("\nprecision: %f, square: %d\n", precision, square);

	float valueN = 0.0;
	if (square > 0 && precision > 0) {
		valueN = square / 2; // first approximation -> divided by two

		float valueNPlusOne = 0.0;
		float deviation = precision + 1;

		printf("\nget accuracy...!");
		// iterate until accuracy is achieved
		for (int n = 1; deviation > precision; n++) {
			valueNPlusOne = valueN;
			valueN = (valueN + square / valueNPlusOne) / 2; // value_n = 0.5 * (value_n + square / value_o); --> creates a warning
			
			deviation = (valueN - valueNPlusOne);

			// abs -> |deviation|
			if (deviation < 0) {
				deviation = deviation * -1;
			}
		}
		printf("\naccuracy achieved!\n");
	}
	else {
		printf("\nsquare or precision <= 0!\n");
	}


	printf("\nresult: %f", valueN);
	return valueN;
}