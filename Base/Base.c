#include <stdio.h>
#include "baselib.h"

void pflush();

int main() {
	int op = 0;
	printf("File");
	do {
		printf("\nMenu Principale:\n");
		printf("  1) Cambia la base di un numero\n");
		printf("  99) Chiudi\n");
		printf("\nNumero operazione: ");
		scanf("%d", &op);
		printf("\n");
		switch (op)
		{
		case 1:
			changeBase();
			break;
		case 99:
			printf("L'applicazione sara' terminata");
			break;
		default:
			printf("Comando sconosciuto");
			break;
		}
		pflush();
		printf("\n\nPremi INVIO per continuare...");
		getchar();
	} while (op != 99);
	return 0;
}

int changeBase() {
	int inputBase, outputBase;
	char num[256];
	printf("Inserisci la base originale del numero: ");
	scanf("%d", &inputBase);
	printf("Inserisci il numero: ");
	scanf("%s", num);
	printf("Inserisci la base a cui lo si vuole convertire: ");
	scanf("%d", &outputBase);
	char* numConverted = convertFromBaseToBase(num, inputBase, outputBase);
	printf("Il numero %s in base %d si scrive %s in base %d", num, inputBase, numConverted, outputBase);
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}