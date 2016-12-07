#include <stdio.h>
#include <stdlib.h>

void pflush();

typedef struct Node
{
	int value;
	struct Node * next;
} Node;

Node* create();
void insert(Node*, int);
void print(Node*);

int main()
{
	int op = 0;
	printf("** File Manager **");
	Node* root = create();
	do {
		printf("\nMenu Principale:\n");
		printf("  1) Aggiungi un elemento alla fine della lista\n");
		printf("  2) Stampa gli elementi della lista\n");
		printf("  99) Chiudi\n");
		printf("\nNumero operazione: ");
		scanf("%d", &op);
		printf("\n");
		switch (op)
		{
		case 1:
			printf("Inserisci il nuovo elemento: ");
			int value = 0;
			scanf("%d", &value);
			insert(root, value);
			break;
		case 2:
			printf("La lista contiene i seguenti valori:\n");
			print(root);
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

Node* create() {
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = 0;
	root->next = NULL;
	return root;
}

void insert(Node* root, int value) {
	Node* currentNode = root;
	while (currentNode->next != NULL)
		currentNode = currentNode->next;
	currentNode->next = (Node*)malloc(sizeof(Node));
	currentNode->next->value = value;
	currentNode->next->next = NULL;
}

void print(Node* root) {
	Node* currentNode = root->next;
	for (int i = 0; currentNode != NULL; i++) {
		printf("Posizione: %d\tValore: %d\n",i, currentNode->value);
		currentNode = currentNode->next;
	}
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}