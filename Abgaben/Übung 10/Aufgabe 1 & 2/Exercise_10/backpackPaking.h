/*
	backpackPaking

	Author: Marco Prescher
	Created on: 04.02.2021
*/

#pragma once

extern struct InventoryChunk {
	char name[256];
	int units;
	int unitsUsed;
	double valuePerUnit;
} InventoryChunk;

double backpackPaking(struct InventoryChunk items[], int structLength, int backpackSize);