#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* values;
	int size;
} *Array;

typedef void(*FillFunc)(int**, int, int);
int** allocateMatrix(int, int, FillFunc);
void fillMatrixMan(int**, int, int);
void fillMatrixRnd(int**, int, int);
void printMatrix(int**, int, int);
Array checkRows(int** matrix, int rows, int cols, int rIndex, int cIndex, Array eIndexes);
void pflush();

int main() {
	int rows, cols;
	printf("Inserisci il numero di righe della matrice: ");
	scanf("%d", &rows);
	printf("Inserisci il numero di colonne della matrice: ");
	scanf("%d", &cols);
	pflush();
	printf("Vuoi riempire la matrice manualmente? [s/n] ");
	char fMethod = getchar();
	int** matrix = fMethod == 's' ? allocateMatrix(rows, cols, fillMatrixMan) : allocateMatrix(rows, cols, fillMatrixRnd);
	printMatrix(matrix, rows, cols);
	Array arr = (Array)malloc(sizeof(Array));
	arr->size = 0;
	arr->values = NULL;
	Array eIndexes = checkRows(matrix, rows, cols, 0, 0, arr, 0);
	if (eIndexes == NULL || !eIndexes->size)
		printf("Non ci sono righe successive uguali");
	else {
		printf("Le righe successive uguali sono:\n");
		for (int i = 0; i < eIndexes->size; i += 2)
			printf("%d e %d; ", eIndexes->values[i] + 1, eIndexes->values[i + 1] + 1);
	}
	pflush();
	getchar();
	return 0;
}

Array checkRows(int** matrix, int rows, int cols, int rIndex, int cIndex, Array eIndexes) {
	if (cIndex > cols - 1) {
		rIndex++;
		cIndex = 0;
	}
	if (rIndex >= rows - 1)
		return eIndexes;
	if (matrix[rIndex][cIndex] != matrix[rIndex + 1][cIndex])
		cIndex = cols;
	if (matrix[rIndex][cIndex] == matrix[rIndex + 1][cIndex] && cIndex == cols-1)
	{
		eIndexes->size += 2;
		eIndexes->values = (int*)realloc(eIndexes->values, eIndexes->size * sizeof(int));
		eIndexes->values[eIndexes->size - 2] = rIndex;
		eIndexes->values[eIndexes->size - 1] = rIndex + 1;
	}
	checkRows(matrix, rows, cols, rIndex, cIndex + 1, eIndexes);
}

void printMatrix(int** matrix, int rows, int cols) {
	printf("La matrice e':\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			printf("%4d", matrix[i][j]);
		printf("\n");
	}
}

int** allocateMatrix(int rows, int cols, FillFunc f) {
	int** matrix = (int*)malloc(sizeof(int) * rows);
	for (int i = 0; i < rows; i++)
		matrix[i] = (int*)malloc(sizeof(int) * cols);
	if (f) f(matrix, rows, cols);
	return matrix;
}

void fillMatrixMan(int** matrix, int rows, int cols) {
	int n = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			printf("Inserisci l'elemento alla riga %d e colonna %d: ", i + 1, j + 1);
			scanf("%d", &n);
			matrix[i][j] = n;
		}
}

void fillMatrixRnd(int** matrix, int rows, int cols) {
	srand(time(NULL));
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = rand() % 100;
	return matrix;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}