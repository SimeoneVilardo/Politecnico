#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void pflush();
int* createRandomArray(int len);
void factorial();
void exponentiation();
void palindrome();
void findInArray();
void findLargestInArray();
void reverseString();
void findCapitalInString();
int factLogic(int num);
int expLogic(int base, int exponent);
int palLogic(char str[], int start, int end);
int findInArrayLogic(int* arr, int len, int el, int index);
int findLarInArrLogic(int* arr, int len, int largest, int index);
char* reverseStrLogic(char* str, int len, int index);
char findCapInStrLogic(char* str, int len, int index, int capital);

int main() {
	int op = 0;
	printf("Ricursione");
	do {
		printf("\nMenu Principale:\n");
		printf("  1) Calcola fattoriale\n");
		printf("  2) Calcola potenza\n");
		printf("  3) Controlla se una parola e' palindroma\n");
		printf("  4) Trova elemento in array\n");
		printf("  5) Trova l'elemento piu' grande in un array\n");
		printf("  6) Inverti una stringa\n");
		printf("  7) Trova la prima lettera maiuscola in una stringa\n");
		printf("  99) Chiudi\n");
		printf("\nNumero operazione: ");
		scanf("%d", &op);
		printf("\n");
		switch (op)
		{
		case 1:
			factorial();
			break;
		case 2:
			exponentiation();
			break;
		case 3:
			palindrome();
			break;
		case 4:
			findInArray();
			break;
		case 5:
			findLargestInArray();
			break;
		case 6:
			reverseString();
			break;
		case 7:
			findCapitalInString();
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
void findCapitalInString() {
	char str[100];
	printf("Inserisci una stringa: ");
	scanf("%s", str);
	char capital = findCapInStrLogic(str, strlen(str), 0, -1);
	capital > -1 ? printf("La prima lettera maiuscola in %s e': %c", str, capital) : printf("Non e' presente alcuna lettera maiuscula nella stringa %s", str);
}

char findCapInStrLogic(char* str, int len, int index, int capital) {
	return index >= len ? capital : findCapInStrLogic(str, len, index + 1, str[index] >= 'A' && str[index] < 'Z' ? str[index] : capital);
}

void reverseString() {
	char str[100];
	printf("Inserisci una stringa: ");
	scanf("%s", str);
	char* reversedStr = reverseStrLogic(str, strlen(str), 0);
	printf("La stringa invertita e': %s", reversedStr);
}

char* reverseStrLogic(char* str, int len, int index) {
	if (index > len / 2 - 1)
		return str;
	else
	{
		char c = str[index];
		str[index] = str[len - 1 - index];
		str[len - 1 - index] = c;
		reverseStrLogic(str, len, index + 1);
	}
}

void findLargestInArray() {
	int len = 0;
	printf("Inserisci la lunghezza dell'array: ");
	scanf("%d", &len);
	int* arr = createRandomArray(len);
	printf("L'array generato e':\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	int largest = findLarInArrLogic(arr, len, arr[0], 1);
	printf("\nL'elemento piu' grande nell'array e': %d", largest);
}

int findLarInArrLogic(int* arr, int len, int largest, int index) {
	return index >= len - 1 ? largest : findLarInArrLogic(arr, len, (largest > arr[index] ? largest : arr[index]), index + 1);
}

void findInArray() {
	int len = 0, el = 0;
	printf("Inserisci la lunghezza dell'array: ");
	scanf("%d", &len);
	int* arr = createRandomArray(len);
	printf("L'array generato e':\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\nInserisci l'elemento da cercare: ");
	scanf("%d", &el);
	int found = findInArrayLogic(arr, len, el, 0);
	printf("L'elemento %se' stato trovato", found ? "" : "non ");
}

int findInArrayLogic(int* arr, int len, int el, int index) {
	return index == len - 1 ? 0 : arr[index] == el || findInArrayLogic(arr, len, el, index + 1);
}

int* createRandomArray(int len) {
	int* arr = (int*)malloc(sizeof(int) * len);
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % 100;
	return arr;
}

void palindrome() {
	char str[100];
	printf("Inserisci una parola: ");
	scanf("%s", str);
	int pal = palLogic(str, 0, strlen(str) - 1);
	printf("La parola %se' palindroma", pal ? "" : "non ");
}

int palLogic(char str[], int start, int end) {
	return start >= end ? 1 : str[start] == str[end] && palLogic(str, start + 1, end - 1);
}

void exponentiation() {
	int base = 0, exponent = 0;
	printf("Inserisci la potenza da calcolare nel formato [a^b]: ");
	scanf("%d^%d", &base, &exponent);
	int pow = expLogic(base, exponent);
	printf("La potenza di %d^%d e' %d", base, exponent, pow);
}

int expLogic(int base, int exponent) {
	return !exponent ? 1 : base * expLogic(base, exponent - 1);
}

void factorial() {
	int num = 0;
	printf("Inserisci un numero: ");
	scanf("%d", &num);
	int fact = factLogic(num);
	printf("Il fattoriale di %d e' %d", num, fact);
}

int factLogic(int num) {
	return !num ? 1 : num * factLogic(num - 1);
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}