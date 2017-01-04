#include <stdio.h>
#include "stdlist.h"
#define EXIT_CODE 99
#define BACK_CODE 98

typedef struct ComplexData { int id; char* name; char* description; } ComplexData;
typedef enum ListType { IntegerList = 1, ComplexDataList, Exit = EXIT_CODE } ListType;

int compareComplexData(void*, void*);
void printComplexData(Node*);
void complexDataListMenu(int*);
void intergerListMenu(int*);
void pflush();

//Globale
Node* head = NULL;

int main() {
	printf("**********************\n**** DYNAMIC LIST ****\n**********************\n");
	head = create();
	int op = 0;
	int opList = 0;
	do {
		printf("\nMenu Principale:\n");
		printf("  1) Crea una lista di numeri interi\n");
		printf("  2) Crea una lista di ComplexData\n");
		printf("  99) Chiudi\n");
		printf("\nNumero operazione: ");
		scanf("%d", &opList);
		do {
			printf("\nMenu Lista:\n");
			switch (opList)
			{
			case 1:
				intergerListMenu(&op);
				break;
			case 2:
				complexDataListMenu(&op);
				break;
			case EXIT_CODE:
				printf("L'applicazione sara' terminata");
				break;
			default:
				printf("Comando sconosciuto");
				break;
			}
		} while (op != EXIT_CODE && op != BACK_CODE);
	} while (op != EXIT_CODE && opList != EXIT_CODE);
	return 0;
}

void intergerListMenu(int* op) {
	printf("  1) Aggiungi un intero data la sua posizione\n");
	printf("  2) Rimuovi un intero dato il suo valore\n");
	printf("  3) Ottieni un intero data la sua posizione\n");
	printf("  4) Conta gli elementi della lista\n");
	printf("  5) Stampa gli elementi della lista come interi\n");
	printf("  98) Indietro\n");
	printf("  99) Chiudi\n");
	printf("\nNumero operazione: ");
	scanf("%d", op);
	printf("\n");
	switch (*op)
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
		printf("Inserire l'intero da rimuovere: ");
		int intToRemove = 0;
		scanf("%d", &intToRemove);
		removeAllByValDefault(&head, intToRemove, Integer);
		break;
	case 3:
		printf("Inserire la posizione dell'elemento che si vuole cercare: ");
		int intPosToSearch = 0;
		scanf("%d", &intPosToSearch);
		Node* intNode = getElement(head, intPosToSearch);
		printf("Alla posizione %d si trova l'elemento %d", intPosToSearch, (*(int*)intNode->value));
		break;
	case 4:
		printf("La lista contiene %d elementi", count(head));
		break;
	case 5:
		printListDefault(head, Integer);
		break;
	case BACK_CODE:
		destroy(&head);
		printf("L'applicazione ritornera' al menu' precedente");
		break;
	case EXIT_CODE:
		printf("L'applicazione sara' terminata");
		break;
	default:
		printf("Comando sconosciuto");
		break;
	}
	pflush();
	printf("\n\nPremi INVIO per continuare...");
	getchar();
}

void complexDataListMenu(int* op) {
	printf("  1) Aggiungi un ComplexData data la sua posizione\n");
	printf("  2) Rimuovi un ComplexData dato il suo valore\n");
	printf("  3) Ottieni un ComplexData data la sua posizione\n");
	printf("  4) Conta gli elementi della lista\n");
	printf("  5) Stampa gli elementi della lista come ComplexData\n");
	printf("  98) Indietro\n");
	printf("  99) Chiudi\n");
	printf("\nNumero operazione: ");
	scanf("%d", op);
	printf("\n");
	switch (*op)
	{
	case 1:
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
	case 2:
		printf("Inserire il ComplexData da rimuovere:\n");
		int idToAppend = 0;
		printf("ID: ");
		scanf("%d", &idToAppend);
		ComplexData* complexDataToRemove = malloc(sizeof(ComplexData));
		complexDataToRemove->id = idToAppend;
		append(&head, complexDataToRemove);
		removeAllByVal(&head, complexDataToRemove, compareComplexData);
		break;
	case 3:
		printf("Inserire la posizione dell'elemento che si vuole cercare: ");
		int complexDataPosToSearch = 0;
		scanf("%d", &complexDataPosToSearch);
		Node* complexDataNode = getElement(head, complexDataPosToSearch);
		ComplexData complexDataGetElement = (*(ComplexData*)complexDataNode->value);
		printf("Alla posizione %d si trova l'elemento:\nID: %d\nNome: %s\nDescrizione: %s", complexDataPosToSearch, complexDataGetElement.id, complexDataGetElement.name, complexDataGetElement.description);
		break;
	case 4:
		printf("La lista contiene %d elementi", count(head));
		break;
	case 5:
		printList(head, printComplexData);
		break;
	case BACK_CODE:
		destroy(&head);
		printf("L'applicazione ritornera' al menu' precedente");
		break;
	case EXIT_CODE:
		printf("L'applicazione sara' terminata");
		break;
	default:
		printf("Comando sconosciuto");
		break;
	}
	pflush();
	printf("\n\nPremi INVIO per continuare...");
	getchar();
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