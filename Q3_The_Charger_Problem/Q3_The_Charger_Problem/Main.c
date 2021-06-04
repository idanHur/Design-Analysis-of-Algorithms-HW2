#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Func.h"
int main() {
	int* profit;
	int* weights;
	int** tTable;
	char** sTable;
	int** xTable;
	int totalWeight;
	int n;
	initForAllArguments_Ap_Once(&profit,&weights,&tTable,&sTable,&totalWeight,&n);
	initZeroFor_S_Table(sTable, totalWeight, n);

	int userPick;
	do {
		printf("\n\nfor the charger problem\nPlease enter\n0 --->  -for product appear once\n1---> for product appear multiple times\nother number ---> for Exit\n\n");
		scanf("%d", &userPick);
		switch (userPick) {
			case 0:
				fillTablesAppearOnce(profit, weights, tTable, sTable, totalWeight, n);
				outPut(profit, weights, tTable, sTable, totalWeight, n);
				printf("------------------------------------------------------\n");
				break;
			case 1:
				initFor_X_Table(&xTable,totalWeight,n);
				fillTableWithRepetition(profit, weights,tTable, xTable, sTable,totalWeight, n);
				outPutFor_WithRepetition(profit,weights,tTable,xTable,sTable,totalWeight,n);
				printf("------------------------------------------------------\n");
		}

	} while (userPick == 0 || userPick == 1);

	

}
