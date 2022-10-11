/*
	leastCommonMultiple (LCM)
	modularization

	Author: Marco Prescher
	Created on: 18.01.2021
*/

#include <stdio.h>
#include "stringfunc.h"
#include "leastCommonMultiple.h"


#define FALSE 0
#define TRUE (!(FALSE))

#define STRINGMEM 512

// forward declarations ---------------------------------------------------------------------------------------------------------

// leastCommonMultiple ---------------
int testLCM(char testcase[], int expectedResult, int* errCnt, int num1, int num2);

// modularization --------------------
int testModularization(int* errCnt);

int testStringLen(char testcase[], int expectedResult, int* errCnt, const char str[]);
int testStringCmp(char testcase[], int expectedResult, int* errCnt, const char str1[], const char str2[]);
int testStringToUpperCase(char testcase[], char expectedResult[], int* errCnt, char str[]);
int testStringCopy(char testcase[], char expectedResult[], int* errCnt, char destStr[], const char srcStr[]);
int testStringSubStr(char testcase[], char expectedResult[], int* errCnt, char destStr[], const char srcStr[], int startOffs, int endOffs);
int testStringRevert(char testcase[], char expectedResult[], int* errCnt, char str[]);
// ------------------------------------------------------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
	int test_LCM = TRUE;
	int test_modularization = TRUE;

	int success = TRUE;
	int errCnt = 0;

	if (test_LCM) {
		printf("\n\n#### leastCommonMultiple (LCM) ###################################################################\n\n");

		// test 1 ----------------
		success = testLCM("Testcase_1", 10, &errCnt, 10, 10) && success;
		// test 2 ----------------
		success = testLCM("Testcase_2", 20, &errCnt, 10, 4) && success;
		// test 3 ----------------
		success = testLCM("Testcase_3", 1020, &errCnt, 170, -60) && success;
		// test 4 ----------------
		success = testLCM("Testcase_4", 0, &errCnt, 23, 0) && success;
	}
	if (test_modularization) {
		printf("\n\n#### modularization ##############################################################################\n\n");

		success = testModularization(&errCnt) && success;
	}

	printf("\n\n\nTest finished with %d error(s)", (success == TRUE ? 0 : errCnt));

	// just to make it more beautiful -------------------------------------------------------------------------------------------
	printf("\n##################################################################################################\n\n");
	// --------------------------------------------------------------------------------------------------------------------------

	return 0;
}

// function definitions ---------------------------------------------------------------------------------------------------------

// leastCommonMultiple ---------------
int testLCM(char testcase[], int expectedResult, int* errCnt, int num1, int num2) {
	int success = TRUE;
	printf("\nexpectedResult: %d\n", expectedResult);

	int result = LCM(num1, num2);
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

// modularization --------------------
int testModularization(int* errCnt) {
	int test_stringLen = TRUE;
	int test_stringCmp = TRUE;

	// we need to test "string_len" and "string_cmp" to test these functions
	int validToTest = test_stringLen && test_stringCmp;

	int test_stringToUpperCase = TRUE && validToTest;
	int test_stringCopy = TRUE && validToTest;
	int test_stringSubStr = TRUE && validToTest;
	int test_stringRevert = TRUE && validToTest;

	int success = TRUE;

	if (test_stringLen) {
		printf("\n++++ stringLen +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

		// test 1 ----------------
		success = testStringLen("Testcase_1", 14, errCnt, "TestThisLength") && success;
		// test 2 ----------------
		success = testStringLen("Testcase_2", 0, errCnt, "") && success;
		// test 3 ----------------
		success = testStringLen("Testcase_3", 1, errCnt, "1") && success;
	}

	// below we need the "string_len" function. so we have to be sure that the test of that function was successful!
	if (success) {
		if (test_stringCmp) {
			printf("\n++++ stringCmp +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

			// test 1 ----------------
			{
				const char str1[] = "TestString";
				const char str2[] = "TestString";
				success = testStringCmp("Testcase_1", 0, errCnt, str1, str2) && success;
			}
			// test 2 ----------------
			{
				const char str1[] = "Test";
				const char str2[] = "Tasten";
				success = testStringCmp("Testcase_2", 1, errCnt, str1, str2) && success;
			}
			// test 3 ----------------
			{
				const char str1[] = "Tast";
				const char str2[] = "Testen";
				success = testStringCmp("Testcase_3", -1, errCnt, str1, str2) && success;
			}
			// test 4 ----------------
			{
				const char str1[] = "Test";
				const char str2[] = "TestString";
				success = testStringCmp("Testcase_4", -1, errCnt, str1, str2) && success;
			}
			// test 5 ----------------
			{
				const char str1[] = "TestString";
				const char str2[] = "Test";
				success = testStringCmp("Testcase_5", 1, errCnt, str1, str2) && success;
			}
			// test 6 ----------------
			{
				const char str1[] = "A";
				const char str2[] = "B";
				success = testStringCmp("Testcase_6", -1, errCnt, str1, str2) && success;
			}
			// test 7 ----------------
			{
				const char str1[] = "B";
				const char str2[] = "A";
				success = testStringCmp("Testcase_7", 1, errCnt, str1, str2) && success;
			}
			// test 8 ----------------
			{
				const char str1[] = "";
				const char str2[] = "";
				success = testStringCmp("Testcase_8", 0, errCnt, str1, str2) && success;
			}
		}

		// same like with the "string_len" function we have to be sure that the "string_cmp" function test was successful!
		if (success) {
			if (test_stringToUpperCase) {
				printf("\n++++ stringToUpperCase +++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

				// test 1 ----------------
				{
					char str[] = "TestString";
					success = testStringToUpperCase("Testcase_1", "TESTSTRING", errCnt, str) && success;
				}
				// test 2 ----------------
				{
					char str[] = "";
					success = testStringToUpperCase("Testcase_2", "", errCnt, str) && success;
				}
				// test 3 ----------------
				{
					char str[] = "56asd";
					success = testStringToUpperCase("Testcase_3", "56ASD", errCnt, str) && success;
				}
				// test 4 ----------------
				{
					char str[] = " ";
					success = testStringToUpperCase("Testcase_4", " ", errCnt, str) && success;
				}
			}
			if (test_stringCopy) {
				printf("\n++++ stringCopy ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

				// test 1 ----------------
				{
					char destStr[STRINGMEM] = "";
					const char srcStr[] = "TestString";
					success = testStringCopy("Testcase_1", srcStr, errCnt, destStr, srcStr) && success;
				}
				// test 2 ----------------
				{
					char destStr[STRINGMEM] = "";
					const char srcStr[] = "42 Hahaa";
					success = testStringCopy("Testcase_2", srcStr, errCnt, destStr, srcStr) && success;
				}
				// test 3 ----------------
				{
					char destStr[STRINGMEM] = "";
					const char srcStr[] = "  ";
					success = testStringCopy("Testcase_3", srcStr, errCnt, destStr, srcStr) && success;
				}
				// test 4 ----------------
				{
					char destStr[STRINGMEM] = "";
					const char srcStr[] = "";
					success = testStringCopy("Testcase_4", srcStr, errCnt, destStr, srcStr) && success;
				}
			}
			if (test_stringSubStr) {
				printf("\n++++ stringSubStr ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

				// test 1 ----------------
				{
					char destStr[STRINGMEM] = "";
					const char srcStr[] = "TestString";

					success = testStringSubStr("Testcase_1", "stSt", errCnt, destStr, srcStr, 2, 5) && success;
				}
				// test 2 ----------------
				{
					char destStr[STRINGMEM] = "";
					const char srcStr[] = "TestString";

					success = testStringSubStr("Testcase_2", "TestString", errCnt, destStr, srcStr, 0, 9) && success;
				}
				// test 3 ----------------
				{
					char destStr[STRINGMEM] = "";
					const char srcStr[] = "TestString";

					success = testStringSubStr("Testcase_3", "", errCnt, destStr, srcStr, 0, 15) && success;
				}
				// test 4 ----------------
				{
					char destStr[STRINGMEM] = "";
					const char srcStr[] = "TestString";

					success = testStringSubStr("Testcase_4", "", errCnt, destStr, srcStr, -3, 9) && success;
				}
				// test 5 ----------------
				{
					char destStr[STRINGMEM] = "";
					const char srcStr[] = "TestString";

					success = testStringSubStr("Testcase_5", "", errCnt, destStr, srcStr, 6, 3) && success;
				}
				// test 6 ----------------
				{
					char destStr[STRINGMEM] = "";
					const char srcStr[] = "TestString";

					success = testStringSubStr("Testcase_6", "T", errCnt, destStr, srcStr, 0, 0) && success;
				}
				// test 7 ----------------
				{
					char destStr[STRINGMEM] = "";
					const char srcStr[] = "TestString";

					success = testStringSubStr("Testcase_7", "t", errCnt, destStr, srcStr, 5, 5) && success;
				}
			}
			if (test_stringRevert) {
				printf("\n++++ stringRevert ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

				// test 1 ----------------
				{
					char revertStr[] = "RevertThisString";
					success = testStringRevert("Testcase_1", "gnirtSsihTtreveR", errCnt, revertStr) && success;
				}
				// test 2 ----------------
				{
					char revertStr[] = "Revert  This  String";
					success = testStringRevert("Testcase_2", "gnirtS  sihT  treveR", errCnt, revertStr) && success;
				}
				// test 3 ----------------
				{
					char revertStr[] = "username: xdorphine56";
					success = testStringRevert("Testcase_3", "65enihprodx :emanresu", errCnt, revertStr) && success;
				}
				// test 4 ----------------
				{
					char revertStr[] = "";
					success = testStringRevert("Testcase_4", "", errCnt, revertStr) && success;
				}
				// test 5 ----------------
				{
					char revertStr[] = "  ";
					success = testStringRevert("Testcase_5", "  ", errCnt, revertStr) && success;
				}
			}
		}
		else {
			printf("\n\n !!!! \"string_cmp\" test failed... please investigate this !!!!\n");
		}
	}
	else {
		printf("\n\n !!!! \"string_len\" test failed... please investigate this !!!!\n");
	}

	return success;
}

int testStringLen(char testcase[], int expectedResult, int* errCnt, const char str[]) {
	int success = TRUE;
	printf("\nexpectedResult: %d\n", expectedResult);
	printf("\ninput string: \"%s\"", str);

	// get string_len --------------------------------
	int result = string_len(str);
	printf("\nlength of string: %d", result);

	// check result ----------------------------------
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
int testStringCmp(char testcase[], int expectedResult, int* errCnt, const char str1[], const char str2[]) {
	int success = TRUE;
	printf("\nexpectedResult: %d\n", expectedResult);

	// print inputs ----------------------------------
	printf("\ninput strings: \"%s\", ", str1);
	printf("\"%s\"", str2);

	// get string_cmp value -------------------------- 
	int result = string_cmp(str1, str2);
	printf("\ncmp result: %d", result);

	// check result ----------------------------------
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
int testStringToUpperCase(char testcase[], char expectedResult[], int* errCnt, char str[]) {
	int success = TRUE;
	printf("\nexpectedResult: \"%s\"\n", expectedResult);

	// print inputs ----------------------------------
	printf("\ninput string: \"%s\"", str);

	// exec string_toUpperCase -----------------------
	string_toUpperCase(str);
	printf("\ntoUpper string: \"%s\"", str);

	// check result ----------------------------------
	if (string_cmp(expectedResult, str)) {
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
int testStringCopy(char testcase[], char expectedResult[], int* errCnt, char destStr[], const char srcStr[]) {
	int success = TRUE;
	printf("\nexpectedResult: \"%s\"\n", expectedResult);

	// print inputs ----------------------------------
	printf("\ninput string: \"%s\"", srcStr);

	// exec string_copy ------------------------------
	string_copy(destStr, srcStr);
	printf("\ncopied string: \"%s\"", destStr);

	// check result ----------------------------------
	if (string_cmp(expectedResult, destStr)) {
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
int testStringSubStr(char testcase[], char expectedResult[], int* errCnt, char destStr[], const char srcStr[], int startOffs, int endOffs) {
	int success = TRUE;
	printf("\nexpectedResult: %s\n", expectedResult);

	// print inputs ----------------------------------
	printf("\ninput string: \"%s\"", srcStr);
	printf("\nstartOffs: %d\nendOffs: %d\n", startOffs, endOffs);

	// get string_subStr -----------------------------
	int result = string_subStr(destStr, srcStr, startOffs, endOffs);
	printf("\nsub string: \"%s\"", destStr);

	// check result ----------------------------------
	int destStrLen = string_len(destStr);
	if ((result > 0 && destStrLen != result) || string_cmp(destStr, expectedResult)) {
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
int testStringRevert(char testcase[], char expectedResult[], int* errCnt, char str[]) {
	int success = TRUE;
	printf("\nexpectedResult: \"%s\"\n", expectedResult);

	// print inputs ----------------------------------
	int strLen = string_len(str);
	printf("\ninput string: \"%s\"", str);

	// exec string_revert ----------------------------
	string_revert(str);
	printf("\nreverted string: \"%s\"", str);

	// check result ----------------------------------
	if (string_cmp(expectedResult, str)) {
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