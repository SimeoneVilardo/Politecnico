#include <stdio.h>
#include "stdutils.h"
#include "stdlist.h"
#include "stddybstruct.h"

int compareDynamicStruct(void* a, void* b);
void printDynamicStructField(DynStruct* dynStruct);
void printDynamicStruct(Node* node);

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
		scanf("%d", &op);
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
			scanf("%d", &indexInsert);
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
			scanf("%d", &indexRemove);
			removeAt(&head, indexRemove);
			break;
		case 7:
			printf("Inserire il valore dell'elemento da eliminare\n");
			DynStruct* elToRemove = createDynamicStructElement(dynStruct);
			removeByVal(&head, elToRemove, compareDynamicStruct);
			break;
		case 8:
			printf("Inserire il valore dell'elemento da cercare\n");
			DynStruct* elToSearch = createDynamicStructElement(dynStruct);
			int pos = find(head, elToSearch, compareDynamicStruct);
			printf("L'elemento %d si trova alla posizione %d\n", elToSearch, pos);
			break;
		case 9:
			printf("Inserire il valore dell'elemento da cercare\n");
			DynStruct* elToSearchExists = createDynamicStructElement(dynStruct);
			printf("L'elemento %d %sesiste nella lista\n", elToSearchExists, exists(head, elToSearchExists, compareDynamicStruct) ? "" : "non ");
			break;
		case 10:
			printf("La lista contiene %d elementi", count(head));
			break;
		case 11:
			printf("La lista contiene:\n");
			print(head, printDynamicStruct);
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

int compareDynamicStruct(void* a, void* b) {
	DynStruct* dynStructA = (DynStruct*)a;
	DynStruct* dynStructB = (DynStruct*)b;
	if (dynStructA->length != dynStructB->length)
		return 0;
	for (int i = 0; i < dynStructA->length; i++) {
		if (dynStructA->array[i].type.id != dynStructB->array[i].type.id)
			return 0;
		switch (dynStructA->array[i].type.id)
		{
		case T_CHAR:
		case T_U_CHAR:
		case T_S_CHAR:
		case T_INT:
		case T_U_INT:
		case T_SHORT:
		case T_U_SHORT:
		case T_LONG:
		case T_U_LONG:
			if (dynStructA->array[i].data.integer != dynStructB->array[i].data.integer)
				return 0;
			break;
		case T_FLOAT:
		case T_DOUBLE:
		case T_L_DOUBLE:
			if (dynStructA->array[i].data.decimal != dynStructB->array[i].data.decimal)
				return 0;
			break;
		case T_STRING:
			if (strcmp(dynStructA->array[i].data.str->value, dynStructB->array[i].data.str->value) != 0)
				return 0;
			break;
		case T_STRUCT:
			if (compareDynamicStruct(dynStructA->array[i].data.ptr, dynStructB->array[i].data.ptr) == 0)
				return 0;	
			break;
		default:
			break;
		}
	}
	return 1;
}

void printDynamicStructField(DynStruct* dynStruct) {
	for (int i = 0; i < dynStruct->length; i++) {
		switch (dynStruct->array[i].type.id)
		{
		case T_CHAR:
		case T_U_CHAR:
		case T_S_CHAR:
		case T_INT:
		case T_U_INT:
		case T_SHORT:
		case T_U_SHORT:
		case T_LONG:
		case T_U_LONG:
			printf("%s: %d\n", dynStruct->array[i].name, dynStruct->array[i].data.integer);
			break;
		case T_FLOAT:
		case T_DOUBLE:
		case T_L_DOUBLE:
			printf("%s: %f\n", dynStruct->array[i].name, dynStruct->array[i].data.decimal);
			break;
		case T_STRING:
			printf("%s: %s\n", dynStruct->array[i].name, dynStruct->array[i].data.str->value);
			break;
		case T_STRUCT:
			printDynamicStructField(dynStruct->array[i].data.ptr);
			break;
		default:
			break;
		}
	}
	printf("\n");
}

void printDynamicStruct(Node* node) {
	DynStruct* dynStruct = (DynStruct*)node->value;
	printDynamicStructField(dynStruct);
}