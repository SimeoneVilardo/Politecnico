#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIGITS 4
#define MAX (int)(pow(10, DIGITS) - 1)
#define KAPREKAR_CONST 6174

typedef struct { int* values; int size; } Array;

int getLargestDigit(int);
Array convertIntToArray(int, int);
int getLargestInArray(Array*);
int countDigits(int);;
Array getDescendingDigits(int);
Array getAscendingDigits(int);
void bubbleSort(Array*);
void reverseBubbleSort(Array*);
void swap(int*, int, int);
void getInputNum(int *);
int getKaprekar(int);
int concatenateInts(int, int);
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
		printf("  3) Calcola le iterazioni di Kaprekar\n");
		printf("  99) Chiudi\n");
		printf("\nNumero operazione: ");
		scanf("%d", &op);
		printf("\n");
		switch (op)
		{
		case 1:
			getInputNum(&num);
			int largest = getLargestDigit(num);
			printf("La cifra piu' grande in %d e' %d", num, largest);
			break;
		case 2:
			getInputNum(&num);
			Array arr = getDescendingDigits(num);
			printf("Le cifre di %d in ordine decrescente sono: ", num);
			for (int i = 0; i < arr.size; i++)
				printf("%d", arr.values[i]);
			break;
		case 3:
			getInputNum(&num);
			int iterations = getKaprekar(num);
			printf("Il numero di iterazioni di Kaprekar del numero %d e' %d", num, iterations);
			break;
		case 99:
			printf("L'applicazione sara' terminata");
			break;
		default:
			printf("Comando sconosciuto");
			break;
		}
		num = -1;
		pflush();
		printf("\n\nPremi INVIO per continuare...");
		getchar();
	} while (op != 99);
	return 0;
}

void getInputNum(int *num) {
	while (*num < 0 || *num > MAX)
	{
		printf("Inserisci un numero compreso tra 0 e %d: ", MAX);
		scanf("%d", num);
	}
}

int getKaprekar(int num) {
	int index = 0;
	while (num != KAPREKAR_CONST)
	{
		Array descArr = getDescendingDigits(num);
		Array ascArr = getAscendingDigits(num);
		int descNum = descArr.values[0];
		int ascNum = ascArr.values[0];
		for (int i = 1; i < descArr.size; i++) {
			descNum = concatenateInts(descNum, descArr.values[i]);
			ascNum = concatenateInts(ascNum, ascArr.values[i]);
		}
		num = descNum - ascNum;
		printf("%d - %d = %d\n", descNum, ascNum, num);
		index++;
	}
	return index;
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
	reverseBubbleSort(&arr);
	return arr;
}

Array getAscendingDigits(int num) {
	Array arr = convertIntToArray(num, DIGITS);
	bubbleSort(&arr);
	return arr;
}

void bubbleSort(Array* arr) {
	for (int j = 0; j < arr->size - 1; j++)
		for (int i = 0; i < arr->size - 1; i++)
			if (arr->values[i] > arr->values[i + 1])
				swap(arr->values, i, i + 1);
}

void reverseBubbleSort(Array* arr) {
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

int concatenateInts(int x, int y) {
	int p = 10;
	while (y >= p)
		p *= 10;
	return x * p + y;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}