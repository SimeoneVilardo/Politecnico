#include <stdio.h>
#define N 4

void pflush();

int main() {
	int matrice[N][N];
	printf("Inserisci i valori nella matrice\n");
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			printf("Inserisci il valore alla riga %d e colonna %d: ", i + 1, j + 1);
			scanf("%d", &matrice[i][j]);
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int num = 0;
			for (int j2 = 0; j2 < N; j2++)
				num = num + matrice[i][j2];
			for (int i2 = 0; i2 < N; i2++)
				if (i2 != j)
					num = num + matrice[i2][j];
			matrice[i][j] = num / (N * 2 - 1);
		}
	printf("La matrice delle medie e':\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d  ", matrice[i][j]);
		printf("\n");
	}
	printf("Premere INVIO per terminare il programma\n");
	pflush();
	getchar();
	return 0;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}