#pragma once

void initForAllArguments_Ap_Once(int** profit, int** weights, int*** tTable, char*** sTable, int* totalWeight, int* n);
void initZeroFor_S_Table(char **sTable, int totalWeight, int n);
void fillTablesAppearOnce(const int* profit, const int* weights, int** tTable, char** sTable, int totalWeight, int n);
void outPut(const int* profit, const int* weights, int** tTable, char** sTable, int totalWeight, int n);

void initFor_X_Table(int*** xTable, int totalWeight, int n);
void fillTableWithRepetition(const int* profit, const int* weights, int** tTable, int** xTable, char** sTable, int totalWeight, int n);
void outPutFor_WithRepetition(const int* profit, const int* weights, int** tTable, int** xTable, char** sTable, int totalWeight, int n);