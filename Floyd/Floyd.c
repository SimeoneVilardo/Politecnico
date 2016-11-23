#include <stdio.h>
#define N 5
int floyd(int matrix[N][N], int g);
int main() {
	int matrix[N][N] = { 0 };
	int sum = floyd(matrix, N);
	printf("La somma della matrice e': %d", sum);
	getchar();
	return 0;
}

int floyd(int matrix[N][N], int size) {
	int k = 0, h = 1, somma = 0;
	for (int i = 0; i < size; i++) {
		k++;
		for (int j = 0; j < k; j++) {
			matrix[i][j] = h;
			h++;
		}
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			somma = somma + matrix[i][j];
	return somma;
}