#include <stdio.h>
#include "listlib.h"

void pflush();

int main() {
	int op = 0;
	printf("*********************\n");
	printf("*** LIST MANAGER ****\n");
	printf("*********************\n");
	Node* head = create();
	do {
		printf("\nMenu Principale:\n");
		printf("  1) Aggiungi un elemento alla fine della lista\n");
		printf("  2) Aggiungi un elemento all'inizio della lista\n");
		printf("  3) Aggiungi un elemento ad una posizione\n");
		printf("  4) Rimuovi il primo elemento della lista\n");
		printf("  5) Rimuovi l'ultimo elemento della lista\n");
		printf("  6) Rimuovi un elemento dato il suo indice\n");
		printf("  7) Rimuovi un elemento dato il suo valore\n");
		printf("  8) Trova la posizione di un elemento nella lista\n");
		printf("  9) Controlla se un elemento esiste nella lista\n");
		printf("  10) Conta gli elementi della lista\n");
		printf("  11) Stampa gli elementi della lista\n");
		printf("  99) Chiudi\n");
		printf("\nNumero operazione: ");
		scanf("%d", &op);
		printf("\n");
		switch (op)
		{
		case 1:
		{
			printf("Inserire il valore da aggiungere: ");
			int elToAppend = 0;
			scanf("%d", &elToAppend);
			append(&head, elToAppend);
			break;
		}
		case 2: {
			printf("Inserire il valore da aggiungere: ");
			int elToPrepend = 0;
			scanf("%d", &elToPrepend);
			prepend(&head, elToPrepend);
			break;
		}
		case 3:
		{
			printf("Inserire il valore da aggiungere: ");
			int elToInsert = 0;
			scanf("%d", &elToInsert);
			printf("Inserire la posizione dove si vuole aggiungere il valore: ");
			int indexInsert = 0;
			scanf("%d", &indexInsert);
			insertAt(&head, elToInsert, indexInsert);
			break;
		}
		case 4:
		{
			shift(&head);
			break;
		}
		case 5:
		{
			pop(&head);
			break;
		}
		case 6:
		{
			printf("Inserire la posizione dell'elemento che si vuole rimuovere: ");
			int indexRemove = 0;
			scanf("%d", &indexRemove);
			removeAt(&head, indexRemove);
			break;
		}
		case 7:
		{
			printf("Inserire il valore dell'elemento da eliminare: ");
			int elToRemove = 0;
			scanf("%d", &elToRemove);
			removeByVal(&head, elToRemove);
			break;
		}
		case 8: {
			printf("Inserire il valore dell'elemento da cercare: ");
			int elToSearch = 0;
			scanf("%d", &elToSearch);
			int pos = find(head, elToSearch);
			printf("L'elemento %d si trova alla posizione %d\n", elToSearch, pos);
			break;
		}
		case 9: {
			printf("Inserire il valore dell'elemento da cercare: ");
			int elToSearchExists = 0;
			scanf("%d", &elToSearchExists);
			printf("L'elemento %d %sesiste nella lista\n", elToSearchExists, exists(head, elToSearchExists) ? "" : "non ");
			break;
		}
		case 10: {
			int length = count(head);
			printf("La lista contiene %d elementi", length);
			break;
		}
		case 11: {
			printf("La lista contiene:\n");
			print(head);
			break;
		}
		case 99: {
			printf("L'applicazione sara' terminata");
			break;
		}
		default: {
			printf("Comando sconosciuto");
			break;
		}
		}
		pflush();
		printf("\n\nPremi INVIO per continuare...");
		getchar();
	} while (op != 99);
	return 0;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}