#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIGITS 4
#define MAX (int)(pow(10, DIGITS) - 1)

typedef struct { int* values; int size; } Array;

int getLargestDigit(int);
Array convertIntToArray(int, int);
int getLargestInArray(Array*);
int countDigits(int);;
Array getDescendingDigits(int);
void sortArray(Array*);
void swap(int*, int, int);
void pflush();

int main() {
	int op = 0, num = -1;
	printf("*****************\n");
	printf("**** DIGITS *****\n");
	printf("*****************\n");
	do {
		printf("\nMenu Principale:\n");
		printf("  1) Trova la cifra piu' grande in un intero\n");
		printf("  2) Ordina le cifre di un intero in ordine decrescente\n");
		printf("  99) Chiudi\n");
		printf("\nNumero operazione: ");
		scanf("%d", &op);
		printf("\n");
		switch (op)
		{
		case 1:
			while (num < 0 || num > MAX)
			{
				printf("Inserisci un numero compreso tra 0 e %d: ", MAX);
				scanf("%d", &num);
			}
			int largest = getLargestDigit(num);
			printf("La cifra piu' grande in %d e' %d", num, largest);
			num = -1;
			break;
		case 2:
			while (num < 0 || num > MAX)
			{
				printf("Inserisci un numero compreso tra 0 e %d: ", MAX);
				scanf("%d", &num);
			}
			Array arr = getDescendingDigits(num);
			printf("Le cifre di %d in ordine decrescente sono: ", num);
			for (int i = 0; i < arr.size; i++)
				printf("%d", arr.values[i]);
			num = -1;
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

int countDigits(int num) {
	int c = 1;
	while (num /= 10) c++;
	return c;
}

int getLargestDigit(int num) {
	Array arr = convertIntToArray(num, DIGITS);
	int largest = getLargestInArray(&arr);
	return largest;
}

Array getDescendingDigits(int num) {
	Array arr = convertIntToArray(num, DIGITS);
	sortArray(&arr);
	return arr;
}

void sortArray(Array* arr) {
	for (int j = 0; j < arr->size - 1; j++)
		for (int i = 0; i < arr->size - 1; i++)
			if (arr->values[i] < arr->values[i + 1])
				swap(arr->values, i, i + 1);
}

void swap(int* arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int getLargestInArray(Array* arr) {
	int largest = arr->values[0];
	for (int i = 1; i < arr->size; i++)
		if (arr->values[i] > largest)
			largest = arr->values[i];
	return largest;
}

Array convertIntToArray(int num, int len) {
	if (!len)
		len = countDigits(num);
	int* arr = (int*)malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++)
		arr[len - 1 - i] = (num / (int)pow(10, i)) % 10;
	return (Array) { arr, len };
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}