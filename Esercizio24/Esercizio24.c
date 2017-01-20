#include <stdio.h>
#include <stdlib.h>
#include "es24lib.h"
#define STOP_CODE -1

int main() {
	Node* head = create();
	printf("Inserire i valori nella lista. Inserire -1 per terminare l'inserimento.\n");
	int val = 0, pos = 0;
	while(1)
	{
		printf("Valore: ");
		scanf("%d", &val);
		if (val == STOP_CODE) break;
		printf("Posizione: ");
		scanf("%d", &pos);
		head = insertAt(head, val, pos);
		printf("Lista:\n");
		print(head);
		printf("\n\n");
	}
	printf("La lista contiene %d elementi\n", count(head));
	printf("Rimozione delle ripetizioni...\n");
	head = removeReps(head);
	printf("Lista:\n");
	print(head);
	printf("\nSommando i valori...\n");
	head = sumList(head);
	printf("Lista:\n");
	print(head);
	return 0;
}