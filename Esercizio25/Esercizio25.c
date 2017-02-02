#include <stdio.h>
#include <stdlib.h>
#include "stdreclist.h"
#define DEFAULT_PATH "..\\Esercizio25\\ListaVoli.bin"

int main() {
	Node* head = load(DEFAULT_PATH);
	print(head);
	depart(head, 3497, (Time) { 11, 30 });
	depart(head, 2193, (Time) { 11, 53 });
	depart(head, 4284, (Time) { 11, 07 });
	printf("\nVoli con piu' di %d passeggeri:", PASSENGER_LARGE_FLIGHT);
	printLargeFlights(head);
	printf("\nVoli con piu' di %d minuti di ritardo:", SMALL_DELAY);
	printSmallDelay(head);
	printf("\nVoli con piu' di %d minuti di ritardo:", BIG_DELAY);
	printBigDelay(head);
	return 0;
}