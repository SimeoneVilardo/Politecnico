#include <stdio.h>

#define N 4

void initMatrix(int matrix[][N]);
void printMatrix(int matrix[][N]);
void setInputData(int *p, int *q);

int main() {
	int matrix[N][N];
	int p, q;
	initMatrix(matrix);
	printMatrix(matrix);
	setInputData(&p, &q);
	return 0;
}

void initMatrix(int matrix[][N]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			printf("Inserire l'elemento alla riga %d e colonna %d: ", i + 1, j + 1);
			scanf("%d", &matrix[i][j]);
		}
}

void printMatrix(int matrix[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%-4d", matrix[i][j]);
		printf("\n");
	}
}

void setInputData(int *p, int *q) {
	printf("Inseire l'ordine delle righe: ");
	scanf("%d", p);
	printf("Inseire l'ordine delle colonne: ");
	scanf("%d", q);
}