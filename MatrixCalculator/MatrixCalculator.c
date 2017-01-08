#include <stdio.h>
#include <stdlib.h>

void getUserData(int** matrix, int rows, int cols);
int** createMatrix(int rows, int cols);
int calDet(int** matrix, int rows, int cols, int index);

int main() {
	printf("Matrix Calculator\n");
	int rows = 0, cols = 0;
	printf("Inserire il numero di righe della matrice: ");
	scanf("%d", &rows);
	printf("Inserire il numero di colonne della matrice: ");
	scanf("%d", &cols);
	int** matrix = createMatrix(rows, cols);
	getUserData(matrix, rows, cols);
	int det = calDet(matrix, rows, cols, 0);
	return 0;
}

void getUserData(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			printf("Elemento alla riga %d e alla colonna %d: ", i+1, j+1);
			scanf("%d", &matrix[i][j]);
		}			
}

int** createMatrix(int rows, int cols) {
	int** matrix = malloc(sizeof(int*) * rows);
	for (int i = 0; i < cols; i++)
		matrix[i] = malloc(sizeof(int) * cols);
	return matrix;
}

int calDet(int** matrix, int rows, int cols, int index) {
	if (rows == 1 && cols == 1)
		return matrix[0];
	if (rows == 2 && cols == 2)
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];	
}