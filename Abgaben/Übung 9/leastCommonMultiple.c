/*
	leastCommonMultiple (LCM)
	greatestCommonDivisor (GCD)
	abs
	
	Author: Marco Prescher
	Created on: 18.01.2021
*/

#include <stdio.h>
#include "leastCommonMultiple.h"

// forward declarations ---------------------------------------------------------------------------------------------------------
static int abs(int num);
static int GCD(int num1, int num2);
// ------------------------------------------------------------------------------------------------------------------------------

// function definitions ---------------------------------------------------------------------------------------------------------
static int abs(int num) {
	if (num < 0) {
		num = num * (-1);
	}

	return num;
}
static int GCD(int num1, int num2) {
	int temp = 0;

	if (num1 != 0 && num2 != 0) {
		if (num1 < 0) {
			num1 = abs(num1);
		}
		if (num2 < 0) {
			num2 = abs(num2);
		}

		do
		{
			temp = num1 % num2;
			num1 = num2;
			num2 = temp;
		} while (temp != 0);
	}
	else {
		num1 = num1 == 0 ? num2 : num1;
	}

	return num1;
}

int LCM(int num1, int num2) {
	printf("\nInput numbers: %d, %d\n", num1, num2);

	int LCM = 0;
	if (num1 != 0 && num2 != 0) {
		if (num1 < 0) {
			num1 = abs(num1);
		}
		if (num2 < 0) {
			num2 = abs(num2);
		}

		LCM = num1 * num2 / GCD(num1, num2);
	}

	printf("\nLeastCommonMultiple: %d\n", LCM);
	return LCM;
}
// ------------------------------------------------------------------------------------------------------------------------------