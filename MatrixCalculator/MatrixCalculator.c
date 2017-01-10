#include <stdio.h>
#include <stdlib.h>

void getUserData(float** matrix, int rows, int cols);
float** createMatrix(int rows, int cols);
float** getSubMatrix(float** matrix, int size, int rIndex, int cIndex);
float determinant(float** matrix, int size);
float cofactor(float** matrix, int size, int rIndex, int cIndex);
float** inverse(float** matrix, int size);
float** matrixMultiplication(float** matrixA, float** matrixB, int rowsA, int colsA, int colsB);
void printMatrix(float** matrix, int rows, int cols);
void destroyMatrix(float** matrix, int rows);

int main() {
	printf("Matrix Calculator\n");
	int rows = 0, cols = 0;
	printf("Inserire il numero di righe della matrice: ");
	scanf("%d", &rows);
	printf("Inserire il numero di colonne della matrice: ");
	scanf("%d", &cols);
	float** matrix = createMatrix(rows, cols);
	getUserData(matrix, rows, cols);
	float** invMatrix = inverse(matrix, rows);
	printMatrix(invMatrix, rows, cols);
	return 0;
}

void getUserData(float** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			printf("Elemento alla riga %d e alla colonna %d: ", i+1, j+1);
			scanf("%f", &matrix[i][j]);
		}			
}

void printMatrix(float** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%5f", matrix[i][j]);
		}
		printf("\n");
	}
}

float** createMatrix(int rows, int cols) {
	float** matrix = malloc(sizeof(float*) * rows);
	for (int i = 0; i < cols; i++)
		matrix[i] = malloc(sizeof(float) * cols);
	return matrix;
}

float** getSubMatrix(float** matrix, int size, int rIndex, int cIndex) {
	float** subMatrix = createMatrix(size -1, size -1);
	int sbI = 0;
	for (int i = 0; i < size; i++) {
		int sbJ = 0;
		if (rIndex == i) continue;				
		for (int j = 0; j < size; j++) {
			if (cIndex == j) continue;		
			subMatrix[sbI][sbJ] = matrix[i][j];
			sbJ++;
		}
		sbI++;
	}
	return subMatrix;
}

float** inverse(float** matrix, int size) {
	float** inverseMatrix = createMatrix(size, size);
	float det = determinant(matrix, size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			inverseMatrix[j][i] = 1/det * cofactor(matrix, size, i, j);
	return inverseMatrix;
}

float cofactor(float** matrix, int size, int rIndex, int cIndex) {
	float** subMatrix = getSubMatrix(matrix, size, rIndex, cIndex);
	int cofactor = (rIndex + cIndex % 2 ? -1 : 1) * determinant(subMatrix, size - 1, size - 1);
	destroyMatrix(subMatrix, size-1);
	return cofactor;
}

float determinant(float** matrix, int size) {
	if (size == 1)
		return matrix[0][0];
	if (size == 2)
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];	
	float det = 0;
	for (int j = 0; j < size; j++) {
		float** subMatrix = getSubMatrix(matrix, size, 0, j);
		det += matrix[0][j] * (j % 2 ? -1 : 1) * determinant(subMatrix, size -1, size -1);
		destroyMatrix(subMatrix, size-1);
	}
	return det;
}

float** scalarMultiplication(float** matrix, int rows, int cols, int scalar) {
	float** mulMatrix = createMatrix(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			mulMatrix[i][j] = scalar*matrix[i][j];
	return mulMatrix;
}

float** matrixMultiplication(float** matrixA, float** matrixB, int rowsA, int colsA, int colsB) {
	float** mulMatrix = createMatrix(rowsA, colsB);
	for (int i = 0; i < rowsA; i++) 
		for (int j = 0; j < colsB; j++) 
			for (int k = 0; k < colsA; k++) 
				mulMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
	return mulMatrix;
}

void destroyMatrix(float** matrix, int rows) {
	for (int i = 0; i < rows; i++)
		free(matrix[i]);
	free(matrix);
}