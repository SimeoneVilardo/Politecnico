#include <stdio.h>

#define K 10
#define N 4

typedef struct { int mossaRiga; int mossaColonna; } Mossa;

//Questa versione del programma considera nella somma anche la posizione di partenza {0,0},
//dato che non viene espressamente spiegato nel testo dell'esercizio.
int main() {
	Mossa mosse[K];
	int matrice[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			printf("Inserire l'elemento alla riga %d e colonna %d: ", i + 1, j+1);
			scanf("%d", &matrice[i][j]);
		}
	for (int i = 0; i < K; i++) {
		printf("Inserire la mossa numero %d per la riga: ", i + 1);
		scanf("%d", &mosse[i].mossaRiga);
		printf("Inserire la mossa numero %d per la colonna: ", i + 1);
		scanf("%d", &mosse[i].mossaColonna);
	}
	int h = 0, k = 0, somma = matrice[0][0];
	for (int i = 0; i < K && somma != -1; i++) {
		h += mosse[i].mossaRiga;
		k += mosse[i].mossaColonna;
		somma = (h < 0 || h >= N || k < 0 || k >= N) ? -1 : somma + matrice[h][k];
	}
	printf("Il totale dei valori selezionato e': %d", somma);
	return 0;
}