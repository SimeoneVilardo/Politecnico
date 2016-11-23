#include <stdio.h>

#define N 4

typedef struct { int row; int column; } Index;
typedef struct { Index initIndex; Index finalIndex; } MatrixID;

void initMatrix(int matrix[][N]);
void setUserValues(int *p, int *q);
int printMatrix(int matrix[][N]);
MatrixID getMaxSubMatrix(int matrix[][N], int p, int q);
int printResult(int matrix[][N], MatrixID matrixId, int rows, int cols);
int sumMatrix(int matrix[][N], int i, int j, int p, int q);
void pflush();

int main()
{
	int matrix[N][N] = { {15,4,-21,8}, {-34, -7, -7,4}, {18, 26,9,2}, {-15,-5,3,29} }; // Valori presi dal testo
	//initMatrix(matrix); // Abilitare questa funzione per inizializzare la matrice a valori crescenti
	printMatrix(matrix);
	int p = 0, q = 0;
	setUserValues(&p, &q);
	MatrixID matrixId = getMaxSubMatrix(matrix, p, q);
	printResult(matrix, matrixId, p, q);
	pflush();
	getchar();
	return 0;
}

void initMatrix(int matrix[][N]) {
	int k = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			matrix[i][j] = ++k;
}

void setUserValues(int *p, int *q) {
	printf("Inserire il numero di righe della sottomatrice da cercare: ");
	scanf("%d", p);
	printf("Inserire il numero di colonne della sottomatrice da cercare: ");
	scanf("%d", q);
}

int printMatrix(int matrix[][N]) {
	printf("La matrice di partenza e':\n\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%4d", matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}

int printResult(int matrix[][N], MatrixID matrixId, int rows, int cols) {
	printf("La sottomatrice massima di ordine %dX%d nella matrice di ordine %dX%d e':\n\n", rows, cols, N, N);
	for (int i = matrixId.initIndex.row; i < matrixId.finalIndex.row; i++) {
		for (int j = matrixId.initIndex.column; j < matrixId.finalIndex.column; j++)
			printf("%-4d", matrix[i][j]);
		printf("\n");
	}
}

int sumMatrix(int matrix[][N], int i, int j, int p, int q) {
	int sum = 0;
	for (int h = i; h < p + i; h++)
		for (int k = j; k < q + j; k++)
			sum += matrix[h][k];
	return sum;
}

MatrixID getMaxSubMatrix(int matrix[][N], int p, int q)
{
	MatrixID matrixId = { { 0,0 } ,{ 0,0 } };
	int oldSum = 0;
	for (int i = 0; i < N - p + 1; i++)
	{
		for (int j = 0; j < N - q + 1; j++)
		{
			int sum = sumMatrix(matrix, i, j, p, q);
			if (sum > oldSum) {
				oldSum = sum;
				matrixId.initIndex.row = i;
				matrixId.initIndex.column = j;
				matrixId.finalIndex.row = i + p;
				matrixId.finalIndex.column = j + q;
			}
		}
	}
	return matrixId;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}