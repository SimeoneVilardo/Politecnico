#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct { int row; int column; } Index;
typedef struct { Index initIndex; Index finalIndex; } MatrixID;

void pflush();
int* createRandomArray(int len);
int** createRandomMatrix(int rows, int cols);
void factorial();
void exponentiation();
void palindrome();
void findInArray();
void findLargestInArray();
void findLargestInArray2();
void reverseString();
void findCapitalInString();
void sumMatrix();
void findLargestSubMatrixInMatrix();
void reverseBubbleSort();
void countPeaks();
int factLogic(int num);
int expLogic(int base, int exponent);
int palLogic(char str[], int start, int end);
int findInArrayLogic(int* arr, int len, int el, int index);
int findLarInArrLogic(int* arr, int len, int largest, int index);
int findLarInArrLogic2(int* arr, int len);
void reverseStrLogic(char* str, int len, int index);
char findCapInStrLogic(char* str, int len, int index, int capital);
int sumMatrixLogic(int** matrix, int rows, int cols, int rIndex, int cIndex);
MatrixID findLarSubMatrixInMatrixLogic(int** matrix, int rows, int cols, int sRows, int sCols, int rIndex, int cIndex, int smrIndex, int smcIndex, int oldSum, int newSum, MatrixID matrixId);
void reverseBubbleSortLogic(int* arr, int len, int arrIndex, int bsIndex);
int countPeaksLogic(int* arr, int len, int index);

int main() {
	int op = 0;
	printf("Recursione");
	do {
		printf("\nMenu Principale:\n");
		printf("  1) Calcola fattoriale\n");
		printf("  2) Calcola potenza\n");
		printf("  3) Controlla se una parola e' palindroma\n");
		printf("  4) Trova elemento in un array\n");
		printf("  5) Trova l'elemento piu' grande in un array\n");
		printf("  6) Trova l'elemento piu' grande in un array (metodo alternativo)\n");
		printf("  7) Inverti una stringa\n");
		printf("  8) Trova la prima lettera maiuscola in una stringa\n");
		printf("  9) Somma gli elementi di una matrice\n");
		printf("  10) Trova la sottomatrice massima in una matrice\n");
		printf("  11) Ordina un array in ordine decrescente\n");
		printf("  12) Trova il numero di vette in un array\n");
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
			findLargestInArray2();
			break;
		case 7:
			reverseString();
			break;
		case 8:
			findCapitalInString();
			break;
		case 9:
			sumMatrix();
			break;
		case 10:
			findLargestSubMatrixInMatrix();
			break;
		case 11:
			reverseBubbleSort();
			break;
		case 12:
			countPeaks();
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

void reverseBubbleSort() {
	int len = 0;
	printf("Inserisci la lunghezza dell'array: ");
	scanf("%d", &len);
	int* arr = createRandomArray(len);
	printf("L'array generato e':\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	reverseBubbleSortLogic(arr, len, 0, 0);
	printf("\nL'array ordinato e':\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
}

void countPeaks() {
	int len = 0;
	printf("Inserisci la lunghezza dell'array: ");
	scanf("%d", &len);
	int* arr = createRandomArray(len);
	printf("L'array generato e':\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	int peaks = countPeaksLogic(arr, len, 0);
	printf("\nIl numero di vette e': %d\n", peaks);
}

int countPeaksLogic(int* arr, int len, int index) {
	if (len <= 1)
		return 0;
	if (index >= len)
		return 1 + countPeaksLogic(&arr[1], len - 1, 0);
	return arr[0] >= arr[index] ? countPeaksLogic(arr, len, index + 1) : countPeaksLogic(&arr[1], len - 1, 0);
}

void reverseBubbleSortLogic(int* arr, int len, int arrIndex, int bsIndex) {
	if (bsIndex >= len - 1)
		return;
	if (arrIndex >= len - 1) {
		bsIndex = bsIndex + 1;
		arrIndex = 0;
	}
	if (arr[arrIndex + 1] > arr[arrIndex]) {
		int temp = arr[arrIndex];
		arr[arrIndex] = arr[arrIndex + 1];
		arr[arrIndex + 1] = temp;
	}
	reverseBubbleSortLogic(arr, len, arrIndex + 1, bsIndex);
}

void findLargestSubMatrixInMatrix() {
	int rows = 0, cols = 0, sRows = 0, sCols = 0;
	printf("Inserisci il numero di righe della matrice: ");
	scanf("%d", &rows);
	printf("Inserisci il numero di colonne della matrice: ");
	scanf("%d", &cols);
	printf("Inserisci il numero di righe della sotto-matrice: ");
	scanf("%d", &sRows);
	printf("Inserisci il numero di colonne della sotto-matrice: ");
	scanf("%d", &sCols);
	int** matrix = createRandomMatrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			printf("%4d ", matrix[i][j]);
		putchar('\n');
	}
	MatrixID matrixId = { {0,0},{0,0} };
	matrixId = findLarSubMatrixInMatrixLogic(matrix, rows, cols, sRows, sCols, 0, 0, 0, 0, 0, 0, matrixId);
	printf("La sottomatrice massima di ordine %dX%d nella matrice di ordine %dX%d e':\n", sRows, sCols, rows, cols);
	for (int i = matrixId.initIndex.row; i <= matrixId.finalIndex.row; i++) {
		for (int j = matrixId.initIndex.column; j <= matrixId.finalIndex.column; j++)
			printf("%4d ", matrix[i][j]);
		printf("\n");
	}
}

MatrixID findLarSubMatrixInMatrixLogic(int** matrix, int rows, int cols, int sRows, int sCols, int rIndex, int cIndex, int smrIndex, int smcIndex, int oldSum, int newSum, MatrixID matrixId) {
	if (rIndex + 1 == sRows && cIndex == sCols) {
		if (newSum > oldSum) {
			oldSum = newSum;
			matrixId = (MatrixID) { { smrIndex, smcIndex }, { smrIndex + rIndex, smcIndex + cIndex - 1 } };
		}
		if (smrIndex + rIndex + 1 == rows && smcIndex + cIndex == cols)
			return matrixId;
		newSum = 0;
		smcIndex = smcIndex + 1;
		cIndex = 0;
		rIndex = 0;
	}
	if (smcIndex - 1 == cols - sCols) {
		smcIndex = 0;
		smrIndex = smrIndex + 1;
	}
	if (cIndex == sCols) {
		rIndex = rIndex + 1;
		cIndex = 0;
	}
	newSum += matrix[smrIndex + rIndex][smcIndex + cIndex];
	return findLarSubMatrixInMatrixLogic(matrix, rows, cols, sRows, sCols, rIndex, cIndex + 1, smrIndex, smcIndex, oldSum, newSum, matrixId);
}

void sumMatrix() {
	int rows = 0, cols = 0, sRows = 0, sCols = 0;
	printf("Inserisci il numero di righe della matrice: ");
	scanf("%d", &rows);
	printf("Inserisci il numero di colonne della matrice: ");
	scanf("%d", &cols);
	int** matrix = createRandomMatrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			printf("%4d ", matrix[i][j]);
		putchar('\n');
	}
	int sum = sumMatrixLogic(matrix, rows, cols, 0, 0);
	printf("La somma di tutti gli elementi della matrice e': %d", sum);
}

int sumMatrixLogic(int** matrix, int rows, int cols, int rIndex, int cIndex) {
	if (rIndex >= rows - 1 && cIndex >= cols)
		return 0;
	else {
		if (cIndex >= cols) {
			rIndex = rIndex + 1;
			cIndex = 0;
		}
		return matrix[rIndex][cIndex] + sumMatrixLogic(matrix, rows, cols, rIndex, cIndex + 1);
	}
}

void findCapitalInString() {
	char str[100];
	printf("Inserisci una stringa: ");
	scanf("%s", str);
	char capital = findCapInStrLogic(str, strlen(str), 0, -1);
	capital > -1 ? printf("La prima lettera maiuscola in %s e': %c", str, capital) : printf("Non e' presente alcuna lettera maiuscula nella stringa %s", str);
}

char findCapInStrLogic(char* str, int len, int index, int capital) {
	return index >= len || capital > -1 ? capital : findCapInStrLogic(str, len, index + 1, str[index] >= 'A' && str[index] < 'Z' ? str[index] : capital);
}

void reverseString() {
	char str[100];
	printf("Inserisci una stringa: ");
	scanf("%s", str);
	reverseStrLogic(str, strlen(str), 0);
	printf("La stringa invertita e': %s", str);
}

void reverseStrLogic(char* str, int len, int index) {
	if (index >= len / 2)
		return;
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

void findLargestInArray2() {
	int len = 0;
	printf("Inserisci la lunghezza dell'array: ");
	scanf("%d", &len);
	int* arr = createRandomArray(len);
	printf("L'array generato e':\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	int largest = findLarInArrLogic2(arr, len);
	printf("\nL'elemento piu' grande nell'array e': %d", largest);
}

//int findLarInArrLogic(int* arr, int len, int largest, int index) {
//	return index >= len - 1 ? largest : findLarInArrLogic(arr, len, (largest > arr[index] ? largest : arr[index]), index + 1);
//}

//Per Laura
int findLarInArrLogic(int* arr, int len, int largest, int index) {
	if (index >= len - 1) {
		return largest;
	}
	else
	{
		int tmpLargest;
		if (largest > arr[index]) {
			tmpLargest = largest;
		}
		else
		{
			tmpLargest = arr[index];
		}
		return findLarInArrLogic(arr, len, tmpLargest, index + 1);
	}
}

int findLarInArrLogic2(int* arr, int len) {
	if (len == 1) return arr[0];
	return arr[len - 1] > findLarInArrLogic2(arr, len - 1) ? arr[len - 1] : findLarInArrLogic2(arr, len - 1);
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

int** createRandomMatrix(int rows, int cols) {
	int** matrix = (int**)malloc(sizeof(int*) * rows);
	srand(time(NULL));
	for (int i = 0; i < rows; i++) {
		int* arr = (int*)malloc(sizeof(int) * cols);
		for (int j = 0; j < cols; j++) {
			arr[j] = rand() % 100;
		}
		matrix[i] = arr;
	}
	return matrix;
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