/*
	string_len
	string_cmp
	string_toUpperCase
	string_copy
	string_subStr
	string_revert

	Author: Marco Prescher
	Created on: 18.01.2021
*/

#include <stdio.h>
#include "stringfunc.h"


#define FALSE 0
#define TRUE (!(FALSE))

int string_len(const char str[]) {
	int length = 0;

	int i = 0;
	while (str[i] != '\0') {
		length++;
		i++;
	}

	return length;
}
int string_cmp(const char str1[], const char str2[]) {
	int str1Len = string_len(str1);
	int str2Len = string_len(str2);

	int compareLen = str1Len < str2Len ? str1Len : str2Len;

	int sameStringValid = TRUE;

	int value = 0;
	if (str1Len < str2Len) {
		value = -1;
	}
	else if (str1Len > str2Len) {
		value = 1;
	}

	int i = 0;
	while ((i < compareLen) && (sameStringValid == TRUE)) {
		if (str1[i] != str2[i]) {
			if (str1[i] < str2[i]) {
				value = -1;
			}
			else if (str1[i] > str2[i]) {
				value = 1;
			}

			sameStringValid = FALSE;
		}
		else {
			i++;
		}
	}

	return value;
}
void string_toUpperCase(char str[]) {
	int strLen = string_len(str);

	for (int i = 0; i < strLen; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 'a' + 'A';
		}
	}
}
void string_copy(char destStr[], const char srcStr[]) {
	int strLen = string_len(srcStr);

	for (int i = 0; i < strLen; i++) {
		destStr[i] = srcStr[i];
	}

	destStr[strLen] = '\0';
}
int string_subStr(char destStr[], const char srcStr[], int startOffs, int endOffs) {
	int srcStrLen = string_len(srcStr);
	int destStrLen = 1;

	if (startOffs >= 0 && endOffs >= 0) {
		int deltaOffs = endOffs - startOffs;

		if (deltaOffs >= 0) {
			if (startOffs <= srcStrLen && endOffs <= srcStrLen) {
				// copy subString of srcStr
				int i = startOffs;
				int j = 0;
				while (i <= endOffs) {
					destStr[j] = srcStr[i];
					i++;
					j++;
				}

				destStr[endOffs + 1] = '\0';
				destStrLen = deltaOffs + 1;
			}
			else {
				destStrLen = -1;
				printf("\nendOff exceeds string length!");
			}
		}
		else {
			destStrLen = -1;
			printf("\nstartOff must be <= endOff!");
		}
	}
	else {
		destStrLen = -1;
		printf("\nstartOff and endOff must be >= 0!");
	}
	

	return destStrLen;
}
int string_revert(char str[]) {
	int strLen = string_len(str);

	int reverFinished = FALSE;
	int i = 0; 
	int j = strLen - 1;
	while ((i < strLen) && !reverFinished) {
		if (i < j) {
			char temp = str[i];
			str[i] = str[j];
			str[j] = temp;

			i++;
			j--;
		}
		else {
			reverFinished = TRUE;
		}
	}

	return 0;
}