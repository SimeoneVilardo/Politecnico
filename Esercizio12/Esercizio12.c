#include <stdio.h>

#define K 5

typedef struct { char nome[100]; char docente[100]; int numeroCFU; int voto; } Esame;

int main() {
	Esame esami[K];
	for (int i = 0; i < K; i++) {
		printf("Inserire il nome del corso: ");
		scanf("%s", &esami[i].nome);
		printf("Inserire il cognome del docente: ");
		scanf("%s", &esami[i].docente);
		printf("Inserire il numero di CFU: ");
		scanf("%d", &esami[i].numeroCFU);
		printf("Inserire il voto: ");
		scanf("%d", &esami[i].voto);
	}
	int somma = 0, totCFU = 0;
	for (int i = 0; i < K; i++) {
		somma += esami[i].voto * esami[i].numeroCFU;
		totCFU += esami[i].numeroCFU;
		printf("Il nome del corso e': %s\n", esami[i].nome);
		printf("Il cognome del docente e': %s\n", esami[i].docente);
		printf("Il numero di CFU e': %d\n", esami[i].numeroCFU);
		printf("Il voto del'esame e': %d\n", esami[i].voto);
	}
	printf("La media e': %.1f\n", ((float)somma) / totCFU);
	return 0;
}