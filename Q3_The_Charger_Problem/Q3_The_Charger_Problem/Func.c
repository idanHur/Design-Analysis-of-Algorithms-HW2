#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Func.h"

void initForAllArguments_Ap_Once(int** profit, int** weights, int*** tTable, char*** sTable, int* totalWeight, int* n) {
	printf("please add n (number of product) --->  ");
	scanf("%d", n);
	printf("please add Total Weight  --->  ");
	scanf("%d", totalWeight);
	*profit = (int*)calloc((*n + 1), sizeof(int));
	*weights = (int*)calloc((*n + 1), sizeof(int));
	for (int i = 1; i <= *n; i++) {
		printf("please add profit for product %d  --->  ", i);
		scanf("%d", (*profit + i));
		printf("please add weight for product %d  --->  ", i);
		scanf("%d", (*weights + i));
	}
	*tTable = (int**)malloc((*n + 1) * sizeof(int*));
	*sTable = (char**)malloc((*n + 1) * sizeof(char*));
	for (int i = 0; i <= *n; i++) {
		tTable[0][i] = calloc((*totalWeight + 1), sizeof(int));
		sTable[0][i] = calloc((*totalWeight + 1), sizeof(char));
	}
}
void initZeroFor_S_Table(char **sTable, int totalWeight, int n) {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= totalWeight; j++)
			if (i == 0 || j == 0)
				sTable[i][j] = '0';
}
void fillTablesAppearOnce(const int* profit, const int* weights, int** tTable, char** sTable, int totalWeight, int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= totalWeight; j++) {
			if (weights[i] > j || (tTable[i - 1][j - weights[i]] + profit[i]) <= tTable[i - 1][j]) {
				tTable[i][j] = tTable[i - 1][j];
				sTable[i][j] = 'N';
			}
			else {
				tTable[i][j] = tTable[i - 1][j - weights[i]] + profit[i];
				sTable[i][j] = 'Y';
			}
		}
	}
}
void outPut(const int* profit, const int* weights, int** tTable, char** sTable, int totalWeight, int n) {
	//tTable
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= totalWeight + 1; j++) {
			if (i == 0 && j == 0)
				printf(" T ");
			else if (i == 0)
				printf(" %d ", j - 1);
			else if (j == 0)
				printf(" %d ", i - 1);
			else {
				printf(" %d ", tTable[i - 1][j - 1]);
			}
		}
		printf("\n");
	}
	printf("\n\n");

	//sTable
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= totalWeight + 1; j++) {
			if (i == 0 && j == 0)
				printf(" S ");
			else if (i == 0)
				printf(" %d ", j - 1);
			else if (j == 0)
				printf(" %d ", i - 1);
			else {
				printf(" %c ", sTable[i - 1][j - 1]);
			}
		}
		printf("\n");
	}
	//total price
	printf("\n\n");
	printf("Optimal Total Profit ---> %d \n\n",tTable[n][totalWeight]);
}


void initFor_X_Table(int*** xTable, int totalWeight, int n) {
	*xTable = (int**)malloc((n + 1) * sizeof(int*));
	for (int i = 0; i <= n; i++) {
		xTable[0][i] = calloc((totalWeight + 1), sizeof(int));
	}
}
void fillTableWithRepetition(const int* profit, const int* weights, int** tTable, int** xTable, char** sTable, int totalWeight, int n) {
	int max = 0;
	int x_i = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= totalWeight; j++) {
			for (int k = 0; weights[i] != 0 && k <= (j / weights[i]); k++) {      
				if (max < (tTable[i - 1][j - (weights[i] * k)] + k * profit[i])) {
					max = tTable[i - 1][j - (weights[i] * k)] + k * profit[i];
					x_i = k;
				}
			}
			if (max == 0)  //weight == 0 ,not need to happend product w=0 
				tTable[i][j] = tTable[i - 1][j];
			else
				tTable[i][j] = max;
			xTable[i][j] = x_i;
			if (x_i == 0)
				sTable[i][j] = 'N';
			else
				sTable[i][j] = 'Y';
			max = 0;
			x_i = 0;
		}
	}
}
void outPutFor_WithRepetition(const int* profit, const int* weights, int** tTable, int** xTable, char** sTable, int totalWeight, int n) {
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= totalWeight + 1; j++) {
			if (i == 0 && j == 0)
				printf(" X ");
			else if (i == 0)
				printf(" %d ", j - 1);
			else if (j == 0)
				printf(" %d ", i - 1);
			else {
				printf(" %d ", xTable[i - 1][j - 1]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
	outPut(profit, weights, tTable, sTable, totalWeight, n);
}