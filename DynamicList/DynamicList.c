#include <stdio.h>
#include "stdlist.h"

typedef struct ComplexData { int id; char* name; char* description; } ComplexData;

int compareComplexData(void*, void*);
void printComplexData(Node*);
void pflush();

int main() {
	printf("**********************\n**** DYNAMIC LIST ****\n**********************\n");
	printf("ATTENZIONE!\nQuesto applicativo e' un tester per la liberia \"stdlist\".\n\"stdlist\" permette di gestire una\
 lista che supporta come valore qualunque tipo.\nAllo scopo di testarla, sono state implementate la gestione della lista con\
 numeri\ninteri e con una struct contenente un intero e due stringhe.\nOvviamente, l'utilizzo di alcune funzioni (che richiedono\
 il casting di un puntatore void)\nandranno in crash nel caso in cui il tipo non coincida.\nQuesto signifa che la lista e'\
 creata in modo tale da essere riempita da qualunque\ntipo di dato, ma tutti dello stesso tipo tra loro.");
	int op = 0;
	Node* head = create();
	do {
		printf("\nMenu Principale:\n");
		printf("  1) Aggiungi un intero data la sua posizione\n");
		printf("  2) Aggiungi un ComplexData data la sua posizione\n");
		printf("  3) Rimuovi un intero dato il suo valore\n");
		printf("  4) Rimuovi un ComplexData dato il suo valore\n");
		printf("  5) Ottieni un intero data la sua posizione\n");
		printf("  6) Ottieni un ComplexData data la sua posizione\n");
		printf("  7) Conta gli elementi della lista\n");
		printf("  8) Stampa gli elementi della lista come interi\n");
		printf("  9) Stampa gli elementi della lista come ComplexData\n");
		printf("  99) Chiudi\n");
		printf("\nNumero operazione: ");
		scanf("%d", &op);
		printf("\n");
		switch (op)
		{
		case 1:
			printf("Inserire la posizione dell'elemento che si vuole aggiungere: ");
			int intPosToAdd = 0;
			scanf("%d", &intPosToAdd);
			printf("Inserire l'intero da aggiungere: ");
			int intToAdd = 0;
			scanf("%d", &intToAdd);
			insertAt(&head, intToAdd, intPosToAdd);
			break;
		case 2:
			printf("Inserire la posizione dell'elemento che si vuole aggiungere: ");
			int complexDataPosToAdd = 0;
			scanf("%d", &complexDataPosToAdd);
			printf("Inserire il ComplexData da aggiungere:\n");
			int idToAdd = 0;
			char* nameToAdd = malloc(128);
			char* descToAdd = malloc(128);
			printf("ID: ");
			scanf("%d", &idToAdd);
			printf("Nome: ");
			scanf("%s", nameToAdd);
			printf("Descrizione: ");
			scanf("%s", descToAdd);
			ComplexData* complexDataToAppend = malloc(sizeof(ComplexData));
			complexDataToAppend->id = idToAdd;
			complexDataToAppend->name = nameToAdd;
			complexDataToAppend->description = descToAdd;
			insertAt(&head, complexDataToAppend, complexDataPosToAdd);
			break;
		case 3:
			printf("Inserire l'intero da rimuovere: ");
			int intToRemove = 0;
			scanf("%d", &intToRemove);
			removeByValDefault(&head, intToRemove, Integer);
			break;
		case 4:
			printf("Inserire il ComplexData da rimuovere:\n");
			int idToAppend = 0;
			printf("ID: ");
			scanf("%d", &idToAppend);
			ComplexData* complexDataToRemove = malloc(sizeof(ComplexData));
			complexDataToRemove->id = idToAppend;
			append(&head, complexDataToRemove);
			removeByVal(&head, complexDataToRemove, compareComplexData);
			break;
		case 5:
			printf("Inserire la posizione dell'elemento che si vuole cercare: ");
			int intPosToSearch = 0;
			scanf("%d", &intPosToSearch);
			Node* intNode = getElement(head, intPosToSearch);
			printf("Alla posizione %d si trova l'elemento %d", intPosToSearch, (*(int*)intNode->value));
			break;
		case 6:
			printf("Inserire la posizione dell'elemento che si vuole cercare: ");
			int complexDataPosToSearch = 0;
			scanf("%d", &complexDataPosToSearch);
			Node* complexDataNode = getElement(head, complexDataPosToSearch);
			ComplexData complexDataGetElement = (*(ComplexData*)complexDataNode->value);
			printf("Alla posizione %d si trova l'elemento:\nID: %d\nNome: %s\nDescrizione: %s", complexDataPosToSearch, complexDataGetElement.id, complexDataGetElement.name, complexDataGetElement.description);
			break;
		case 7:
			printf("La lista contiene %d elementi", count(head));
			break;
		case 8:
			printDefault(head, Integer);
			break;
		case 9:
			print(head, printComplexData);
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

void printComplexData(Node* node) {
	ComplexData tmpVal = *(ComplexData*)node->value;
	printf("ID: %d\nNome: %s\nDescrizione: %s\n\n", tmpVal.id, tmpVal.name, tmpVal.description);
}

int compareComplexData(void* data1, void* data2) {
	return (*(ComplexData*)data1).id == (*(ComplexData*)data2).id;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}