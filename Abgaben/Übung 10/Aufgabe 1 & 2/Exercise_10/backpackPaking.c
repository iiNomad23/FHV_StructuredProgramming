/*
	backpackPaking

	Author: Marco Prescher
	Created on: 04.02.2021
*/

#include <stdio.h>
#include "backpackPaking.h"


#define FALSE 0
#define TRUE (!(FALSE))

static int getBestAvailableIndex(struct InventoryChunk items[], int structLength) {
	int bestIndex = -1;
	double maxValue = 0;

	for (int i = 0; i < structLength; i++){
		if (items[i].units > 0 && items[i].valuePerUnit > maxValue) {
			maxValue = items[i].valuePerUnit;
			bestIndex = i;
		}
	}

	return bestIndex;
}

double backpackPaking(struct InventoryChunk items[], int structLen, int backpackSize) {
	double sum = 0;

	if (structLen > 0) {
		int bestIndex = 0;
		int backPackFull = FALSE;

		printf("Optimale Bepackung: ");
		while (backpackSize > 0 && !backPackFull) {
			bestIndex = getBestAvailableIndex(items, structLen);
			if (bestIndex < 0) {
				backPackFull = TRUE;
			}
			else {
				items[bestIndex].units--;
				items[bestIndex].unitsUsed++;
				sum += items[bestIndex].valuePerUnit;

				// check if index incremented 
				int bestIndexAfterUnitUsed = getBestAvailableIndex(items, structLen);
				if (bestIndexAfterUnitUsed < 0) {
					backPackFull = TRUE;
				}
				else if (bestIndexAfterUnitUsed != bestIndex) {
					printf("%d x %s, ", items[bestIndex].unitsUsed, items[bestIndex].name);
				}
			}

			backpackSize--;
		}

		printf("%d x %s", items[bestIndex].unitsUsed, items[bestIndex].name);
		printf(" -> %.2f EUR", sum);
	}
	else {
		printf("Backpack is empty!");
	}

	return sum;
}