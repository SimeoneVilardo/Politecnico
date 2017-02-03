#include <stdio.h>
#include "stdreclist.h"
#include "stdstring.h"
#define EXIT_CODE 99
#define DEF_QTY 1
#define DEF_STR_SIZE 16
#define DEFAULT_PATH "..\\Esercizio26\\ListaSpesa.txt"

void pflush();

int main() {
	int command = 0;
	Node* head = create();
	do
	{
		printf("Menu Principale:\n\n");
		printf("01) Inserisci elemento\n");
		printf("02) Rimuovi ultimo elemento inserito\n");
		printf("03) Calcola spesa totale\n");
		printf("04) Stampa lista\n");
		printf("%d) Termina\n", EXIT_CODE);
		printf("Selezionare l'operazione da effettuare: ");
		scanf("%d", &command);
		switch (command)
		{
		case 1: 
			printf("Inserisci il nome: ");
			String name = initString(DEF_STR_SIZE);
			scanf("%s", name);
			printf("Inserisci il prezzo: ");
			float price = 0;
			scanf("%f", &price);
			Item item = { name, price, DEF_QTY };
			head = insertItem(head, item);
			break;
		case 2: 
			head = removeItem(head);
			break;
		case 3: 
			printf("Il costo totale e': %.2f\n", calculateTotPrice(head));
			break;
		case 4: 
			save(head, DEFAULT_PATH);
			break;
		case EXIT_CODE: 
			printf("Goodbye :)\n");
			break;
		default:
			printf("Comando sconosciuto\n");
			break;
		}
		pflush();
		printf("Premi INVIO per continuare...\n\n");
		getchar();
	} while (command != EXIT_CODE);
	return 0;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}