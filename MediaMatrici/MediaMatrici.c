#include <stdio.h>
#define K 4

void pflush();

int main() {
	int matrice[K][K];
	float media[K][K];
	printf("Inserisci i valori nella matrice\n");
	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++) {
			printf("Inserisci il valore alla riga %d e colonna %d: ", i + 1, j + 1);
			scanf("%d", &matrice[i][j]);
		}
	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++) {
			int num = 0;
			for (int j2 = 0; j2 < K; j2++)
				num = num + matrice[i][j2];
			for (int i2 = 0; i2 < K; i2++)
				if (i2 != i)
					num = num + matrice[i2][j];
			media[i][j] = ((float)num) / (K * 2 - 1);
		}
	printf("La matrice delle medie e':\n");
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++)
			printf("%.1f  ", media[i][j]);
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