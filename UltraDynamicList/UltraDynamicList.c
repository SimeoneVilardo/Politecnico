#include <stdio.h>
#include "stdutils.h"
#include "stdlist.h"
#include "stddynstruct.h"

void printDynamicStructList(Node* node);

int main() {
	printf("**************************\n");
	printf("*** ULTRA DYNAMIC LIST ***\n");
	printf("**************************\n\n");
	printf("\"Ultra Dynamic List\" e' un programma in C che permette di generare dinamicamente una struct e poi una lista\nche e' in grado di memorizzare i dati della struct generata.\n");
	DynStruct *dynStruct = createDynamicStruct();
	int op = 0;
	printf("Gestione lista di %s", dynStruct->name);
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
		cscanf("%d", &op);
		printf("\n");
		switch (op)
		{
		case 1:
			printf("Inserire il valore da aggiungere\n");
			DynStruct* elToAppend = createDynamicStructElement(dynStruct);
			append(&head, elToAppend);
			break;
		case 2:
			printf("Inserire il valore da aggiungere\n");
			DynStruct* elToPrepend = createDynamicStructElement(dynStruct);
			prepend(&head, elToPrepend);
			break;
		case 3:
			printf("Inserire il valore da aggiungere\n");
			DynStruct* elToInsert = createDynamicStructElement(dynStruct);
			printf("Inserire la posizione dove si vuole aggiungere il valore: ");
			int indexInsert = 0;
			cscanf("%d", &indexInsert);
			insertAt(&head, elToInsert, indexInsert);
			break;
		case 4:
			shift(&head);
			break;
		case 5:
			pop(&head);
			break;
		case 6:
			printf("Inserire la posizione dell'elemento che si vuole rimuovere: ");
			int indexRemove = 0;
			cscanf("%d", &indexRemove);
			removeAt(&head, indexRemove);
			break;
		case 7:
			printf("Inserire il valore dell'elemento da eliminare\n");
			DynStruct* elToRemove = createDynamicStructSearchModel(dynStruct);
			removeAllByVal(&head, elToRemove, isEquals);
			break;
		case 8:
			printf("Inserire il valore dell'elemento da cercare\n");
			DynStruct* elToSearch = createDynamicStructElement(dynStruct);
			int pos = find(head, elToSearch, isEquals);
			printf("L'elemento %d si trova alla posizione %d\n", elToSearch, pos);
			break;
		case 9:
			printf("Inserire il valore dell'elemento da cercare\n");
			DynStruct* elToSearchExists = createDynamicStructElement(dynStruct);
			printf("L'elemento %d %sesiste nella lista\n", elToSearchExists, exists(head, elToSearchExists, isEquals) ? "" : "non ");
			break;
		case 10:
			printf("La lista contiene %d elementi", count(head));
			break;
		case 11:
			printf("La lista contiene:\n");
			print(head, printDynamicStructList);
			break;
		case 99:
			printf("L'applicazione sara' terminata");
			break;
		default:
			printf("Comando sconosciuto");
			break;
		}
		printf("\n\nPremi INVIO per continuare...");
		getchar();
	} while (op != 99);
	return 0;
}

void printDynamicStructList(Node* node) {
	DynStruct* dynStruct = (DynStruct*)node->value;
	printDynamicStruct(dynStruct);
}