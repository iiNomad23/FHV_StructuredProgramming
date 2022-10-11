/*
    primeDecomposition
	searchSubstring
	encodeText

	Author: Marco Prescher
	Created on: 07.01.2021
*/

#include <stdio.h>

// for random numbers -----------
#include<stdlib.h>
#include<time.h>


#define FALSE 0
#define TRUE (!(FALSE))

// forward declarations ---------------------------------------------------------------------------------------------------------
int getLengthOfString(char* str);
int getLengthOfAWordFromString(char* str, int pos);
char* mergeStrings(char* str1, char* str2);
char* compareStrings(char* str1, char* str2);
int random(int min, int max);

// primeDecomposition ----------------------------------------------------------
int primeDecomposition(int number);

// searchSubstring -------------------------------------------------------------
int searchSubstring(char* text, char* pat);
int checkPatternCompletion(char* text, int* pos, char* pat, int patLength);

// encodeText ------------------------------------------------------------------
char* testEncodeText(char* testcase, char* expectedResult, int* errCnt, char* text);
char* encodeText(char* text);

char* extractWordOrDelimiter(char* text, int* i);
int isDelimiter(char* text, int i);
char* extractDelimiter(char* text, int* i);
char* extractWord(char* text, int* i);

char* encodeWordOrDelimiter(char* wordOrDelimiter, int* wordCount);
char* encodeDelimiter(char* wordOrDelimiter);
char* encodeWord(char* wordOrDelimiter, int* wordCount);
// -----------------------------------------------------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
	int test_primeDecomposition = 0;
	int test_searchSubstring = 0;
	int test_encodeText = 1;

	int success = TRUE;
	int errCnt = 0;

	if (test_primeDecomposition) { 
		printf("\n\n#### primeDecomposition ###################################################################\n\n");

		// TODO: tests

		// test 1 ----------------
		primeDecomposition(240);
		// test 2 ----------------
		primeDecomposition(1001);
		// test 3 ----------------
		primeDecomposition(6936);
		// test 4 ----------------
		primeDecomposition(82589933);
		// test 5 ----------------
		primeDecomposition(0);
	}
	if (test_searchSubstring) {
		printf("\n\n#### searchSubstring ######################################################################\n\n");

		// TODO: tests

		// test 1 ----------------
		searchSubstring("Dieses da ist es", "es");
		// test 2 ----------------
		searchSubstring("Dieses da", "");
		// test 3 ----------------
		searchSubstring("Diesseess da ist eeeses es", "es");
		// test 4 ----------------
		searchSubstring("Dieses da ist es", " ");
	}
	if (test_encodeText) {
		printf("\n\n#### encodeText ###########################################################################\n\n");

		// test 1 ----------------
		success = testEncodeText("Testcase_1", "$@$reD%nnaM@%red?tetsaregsua?ist#", &errCnt, "__,,____Der Mann, der ausgerastet ist.");
		// test 2 ----------------
		success = testEncodeText("Testcase_2", "", &errCnt, "");
		// test 3 ----------------
		success = testEncodeText("Testcase_3", "", &errCnt, ". .. , ,, __ _");
		// test 4 ----------------
		success = testEncodeText("Testcase_4", "mieB?402U%dnis%nretsO%alle%tim%med%sserpxethcaN%hcan?Wien%nerhafegtim#", &errCnt, "Beim Bahnhof sind heute alle mit dem Nachtexpress nach Wien mitgefahren.");
	}

	printf("\n\n\nTest finished with %d error(s)", (success == TRUE ? 0 : errCnt));

	// just to make it more beautiful ------------------------------------------------------------------------------------------
	printf("\n###########################################################################################\n\n");
	// -------------------------------------------------------------------------------------------------------------------------

	return 0;
}

// function definitions --------------------------------------------------------------------------------------------------------
int getLengthOfString(char* str) {
	int length = 0;

	int i = 0;
	while (str[i] != '\0') {
		length++;
		i++;
	}

	return length;
}
int getLengthOfAWordFromString(char* str, int pos) {
	int length = 0;

	int i = pos;
	while (!isDelimiter(str, pos)) {
		length++;
		pos++;
		i++;
	}

	return length;
};
char* mergeStrings(char* srcStr, char* appendStr) {
	int srcStrLength = getLengthOfString(srcStr);
	int appendStrLength = getLengthOfString(appendStr);
	int returnStrLength = srcStrLength + appendStrLength + 1;

	char* returnStr = malloc(returnStrLength * sizeof(char)); // allocate memory (heap)
	if (returnStr != NULL) {
		int i = 0;
		int j = 0;

		// copy srcStr
		while (i < srcStrLength) {
			returnStr[i] = srcStr[i];
			i++;
		}
		// copy appendStr
		while (i < (srcStrLength + appendStrLength)) {
			returnStr[i] = appendStr[j];
			i++;
			j++;
		}

		returnStr[returnStrLength - 1] = '\0';
	}

	return returnStr;
}
char* compareStrings(char* str1, char* str2) {
	int str1Length = getLengthOfString(str1);

	int sameString = TRUE;
	for (int i = 0; (i < str1Length) && (sameString == TRUE); i++) {
		if (str1[i] != str2[i]) {
			sameString = FALSE;
		}
	}

	return sameString;
}
int random(int min, int max) {
	int number = min + rand() % (max - min);
	return number;
}


// primeDecomposition ----------------------------------------------------------
int primeDecomposition(int number) {
	printf("\nInput number: %d\n", number);

	int i = 2;
	if (number >= i) {
		printf("\nStart decomposition...\n\n");

		while (i <= number) {
			if ((number % i) == 0) {
				printf("%10d | %d\n", number, i);
				number /= i;
			}
			else {
				i++;
			}
		}

		printf("%10d |\n", number);
		printf("\nDecomposition finished\n");
	}
	else {
		printf("\nThe specified number is too small!");
	}

	printf("\n***************************************************************");
	return 0;
}


// searchSubstring -------------------------------------------------------------
int searchSubstring(char* text, char* pat) {
	printf("\nText: \t\t%s", text);
	printf("\nPattern: \t%s\n", pat);

	int textLength = getLengthOfString(text);
	int patLength = getLengthOfString(pat);

	if (textLength > 0 && patLength > 0 && (textLength - patLength) > 0) {
		printf("\n  -> Positions are: ");

		int i = 0;
		while (i <= (textLength - patLength)) {
			if (text[i] == pat[0]) { 
				// start of pattern found
				int isPatterComplete = checkPatternCompletion(text, &i, pat, patLength);
				if (isPatterComplete) {
					printf("%d  ", i - patLength);
				}
			}
			else {
				i++;
			}
		}
	}
	else {
		printf("\nText or pattern not ok!");
	}

	printf("\n***************************************************************");
	return 0;
}
int checkPatternCompletion(char* text, int* pos, char* pat, int patLength) {
	int patWrong = FALSE;

	(*pos)++;
	int i = 1;
	while (i < patLength && patWrong == FALSE) {
		if (text[(*pos)] != pat[i]) {
			patWrong = TRUE;
		}
		else {
			(*pos)++;
			i++;
		}
	}

	return !patWrong;
}


// encodeText ------------------------------------------------------------------
char* testEncodeText(char* testcase, char* expectedResult, int* errCnt, char* text) {
	int success = TRUE;
	printf("\nexpectedResult: \"%s\"\n", expectedResult);

	char* result = encodeText(text);
	if (!compareStrings(expectedResult, result)) {
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
char* encodeText(char* text) {
	printf("\nstring:\t\t \"%s\"\n", text);

	char* encodedText = "";
	if (text[0] != '\0') {
		int wordCount = 1;

		int i = 0;
		while (text[i] != '\0') {
			char* wordOrDelimiter = extractWordOrDelimiter(text, &i);
			char* encodedWordOrDelimiter = encodeWordOrDelimiter(wordOrDelimiter, &wordCount);

			encodedText = mergeStrings(encodedText, encodedWordOrDelimiter);

			// free allocated memory of 'wordOrDelimiter' again!
			free(wordOrDelimiter);
		}

		printf("encoded string:\t \"%s\"\n", encodedText);
	}
	else {
		printf("\nstring is empty!");
	}

	return encodedText;
}

int isDelimiter(char* text, int i) {
	char currChar = text[i];

	if (currChar == ' ' || currChar == ',' || currChar == '.' || currChar == '_') {
		return 1;
	}
	else {
		return 0;
	}
}

// extractions ----------------------
char* extractWordOrDelimiter(char* text, int* i) {
	char* wordOrDelimiter = "";

	if (text[(*i)] != '\0') {
		if (isDelimiter(text, (*i))) {
			wordOrDelimiter = extractDelimiter(text, i);
		}
		else {
			wordOrDelimiter = extractWord(text, i);
		}
	}

	return wordOrDelimiter;
}
char* extractDelimiter(char* text, int* i) {
	// char del[] = { text[(*i)], '\0' };
	// char* delimiter = "_";

	char* delimiter = malloc(2 * sizeof(char)); // allocate memory (heap)
	if (delimiter != NULL) { 
		delimiter[0] = text[(*i)];
		delimiter[1] = '\0';

		do {
			(*i)++;
		} while ((text[(*i)] != '\0') && (text[(*i)] == delimiter[0]));
	}

	return delimiter;
}
char* extractWord(char* text, int* i) {
	int lengthOfCurrWord = getLengthOfAWordFromString(text, (*i)) + 1;

	char* word = malloc(lengthOfCurrWord * sizeof(char)); // allocate memory (heap)
	if (word != NULL) {
		for (int j = 0; j < lengthOfCurrWord - 1; j++) {
			word[j] = text[(*i)];
			(*i)++;
		}

		word[lengthOfCurrWord - 1] = '\0';
	}

	return word;
}

// encoding -----------------------
char* encodeWordOrDelimiter(char* wordOrDelimiter, int* wordCount) {
	char* encodedSubString = "";
	if (isDelimiter(wordOrDelimiter, 0)) {
		encodedSubString = encodeDelimiter(wordOrDelimiter);
	}
	else {
		encodedSubString = encodeWord(wordOrDelimiter, wordCount);
	}

	return encodedSubString;
}
char* encodeDelimiter(char* wordOrDelimiter) {
	if (wordOrDelimiter[0] == ',') {
		return "@";
	} 
	else if (wordOrDelimiter[0] == '.') {
		return "#";
	}
	else if (wordOrDelimiter[0] == '_') {
		return "$";
	}
	else {
		int rndNumber = random(0, 2);
		char delimiters[] = { '?', '%', '&' };

		char* encodedDelimiter = malloc(2 * sizeof(char)); // allocate memory (heap)
		if (encodedDelimiter != NULL) {
			encodedDelimiter[0] = delimiters[rndNumber];
			encodedDelimiter[1] = '\0';
		}

		return encodedDelimiter;
	}
}
char* encodeWord(char* wordOrDelimiter, int* wordCount) {
	char* encodedWord = "";
	int wordCountExceeded = (*wordCount) >= 5 ? 1 : 0;

	if (wordOrDelimiter[0] == 'h' && compareStrings(wordOrDelimiter, "heute")) {
		encodedWord = wordCountExceeded ? "heute" : "nretsO";
	}
	else if (wordOrDelimiter[0] == 'B' && compareStrings(wordOrDelimiter, "Bahnhof")) {
		encodedWord = wordCountExceeded ? "Bahnhof" : "402U";
	}
	else if (wordOrDelimiter[0] == 'a' && compareStrings(wordOrDelimiter, "alle")) {
		encodedWord = wordCountExceeded ? "alle" : "hci";
	}
	else {
		if (wordCountExceeded) {
			encodedWord = wordOrDelimiter;
		}
		else {
			int lengthOfCurrWord = getLengthOfString(wordOrDelimiter) + 1;

			char* word = malloc(lengthOfCurrWord * sizeof(char)); // allocate memory (heap)
			if (word != NULL) {
				int j = lengthOfCurrWord - 2;
				for (int i = 0; i < lengthOfCurrWord - 1; i++) {
					word[i] = wordOrDelimiter[j];
					j--;
				}

				word[lengthOfCurrWord - 1] = '\0';
			}

			encodedWord = word;
		}
	}

	if (wordCountExceeded) {
		(*wordCount) = 1;
	}
	else {
		(*wordCount)++;
	}
	
	return encodedWord;
}
// -----------------------------------------------------------------------------------------------------------------------------