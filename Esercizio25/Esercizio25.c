#include <stdio.h>
#include <stdlib.h>
#include "stdreclist.h"
#define DEFAULT_PATH "..\\Esercizio25\\ListaVoli.bin"

int main() {
	Node* head = load(DEFAULT_PATH);
	print(head);
	return 0;
}

Node* depart(Node* head, int id, Time actualDep) {
	find
}