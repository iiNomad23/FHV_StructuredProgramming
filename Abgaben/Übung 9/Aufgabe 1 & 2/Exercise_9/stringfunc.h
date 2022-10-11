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

#pragma once

int string_len(const char str[]);
int string_cmp(const char str1[], const char str2[]);
void string_toUpperCase(char str[]);
void string_copy(char destStr[], const char srcStr[]);
int string_subStr(char destStr[], const char srcStr[], int startOffs, int endOffs);
int string_revert(char str[]);