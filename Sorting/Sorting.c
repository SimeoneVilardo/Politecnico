#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef void(*FillFunc)(int*, int);
typedef void(*SortFunc)(int*, int);

int* allocateArr(int, FillFunc);
void fillArrMan(int*, int);
void fillArrRnd(int*, int);
void deallocateArr(int*);
void sortArr(int*, int, SortFunc);
void bubbleSort(int*, int);
void reverseBubbleSort(int*, int);
void evenBubbleSort(int*, int);
void oddBubbleSort(int*, int);
void printArr(int*, int);
void swap(int*, int, int);
void pflush();

int main() {
	printf("*************************\n");
	printf("*** FUNCTION POINTERS ***\n");
	printf("******** SORTING ********\n");
	printf("*************************\n");
	
	int len = 0, op = 0;
	int* arr = NULL;
	while (op != 99)
	{
		printf("\nMenu Principale:\n");
		printf("1)  Alloca l'array\n");
		printf("2)  Dealloca l'array\n");
		printf("3)  Ordina l'array in ordine crescente\n");
		printf("4)  Ordina l'array in ordine decrescente\n");
		printf("5)  Ordina l'array con prima i numeri pari\n");
		printf("6)  Ordina l'array con prima i numeri dispari\n");
		printf("7)  Stampa l'array\n");
		printf("99) Esci\n");
		printf("\nNumero operazione: ");
		scanf("%d", &op);
		printf("\n");
		switch (op)
		{
		case 1:
			if (arr) {
				printf("Per effettuare questa operazione bisogna prima deallocare l'array\n");
				break;
			}
			printf("Inserisci la dimensione dell'array: ");
			scanf("%d", &len);
			pflush();
			printf("Vuoi riempire l'array manualmente? [s/n] ");
			char fMethod = getchar();
			arr = fMethod == 's' ? allocateArr(len, fillArrMan) : allocateArr(len, fillArrRnd);
			printArr(arr,len);
			break;
		case 2:
			if (!arr) {
				printf("Per effettuare questa operazione bisogna prima allocare l'array\n");
				break;
			}
			deallocateArr(arr);
			arr = NULL;
			len = 0;
			printf("Array deallocato");
			break;
		case 3:
			if (!arr) {
				printf("Per effettuare questa operazione bisogna prima allocare l'array\n");
				break;
			}
			printf("Ordinamento dell'array in ordine crescente...\n");
			sortArr(arr, len, bubbleSort);
			break;
		case 4:
			if (!arr) {
				printf("Per effettuare questa operazione bisogna prima allocare l'array\n");
				break;
			}
			printf("Ordinamento dell'array in ordine decrescente...\n");
			sortArr(arr, len, reverseBubbleSort);
			break;
		case 5:
			if (!arr) {
				printf("Per effettuare questa operazione bisogna prima allocare l'array\n");
				break;
			}
			printf("Ordinamento dell'array con prima i numeri pari...\n");
			sortArr(arr, len, evenBubbleSort);
			break;
		case 6:
			if (!arr) {
				printf("Per effettuare questa operazione bisogna prima allocare l'array\n");
				break;
			}
			printf("Ordinamento dell'array con prima i numeri dispari...\n");
			sortArr(arr, len, oddBubbleSort);
			break;
		case 7:
			if (!arr) {
				printf("Per effettuare questa operazione bisogna prima allocare l'array\n");
				break;
			}
			printArr(arr, len);
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
	}
	return 0;
}

int* allocateArr(int len, FillFunc f) {
	int* arr = (int*)malloc(sizeof(int) * len);
	if (f) f(arr, len);
	return arr;
}

void fillArrMan(int* arr, int len) {
	int n = 0;
	for (int i = 0; i < len; i++) {
		printf("Inserisci l'elemento numero %d: ", i + 1);
		scanf("%d", &n);
		arr[i] = n;
	}
}

void fillArrRnd(int* arr, int len) {
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % 100;
}

void deallocateArr(int* arr) {
	free(arr);
}

void sortArr(int* arr, int len, SortFunc f) {
	f(arr, len);
	printArr(arr, len);
}

void bubbleSort(int* arr, int len) {
	for (int i = 0; i < len - 1; i++)
		for (int j = 0; j < len - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
}

void reverseBubbleSort(int* arr, int len) {
	for (int i = 0; i < len - 1; i++)
		for (int j = 0; j < len - 1; j++)
			if (arr[j] < arr[j + 1])
				swap(arr, j, j + 1);
}

void evenBubbleSort(int* arr, int len) {
	for (int i = 0; i < len - 1; i++)
		for (int j = 0; j < len - 1; j++)
			if (arr[j + 1] % 2 == 0 && arr[j] % 2 != 0)
				swap(arr, j, j + 1);
}

void oddBubbleSort(int* arr, int len) {
	for (int i = 0; i < len - 1; i++)
		for (int j = 0; j < len - 1; j++)
			if (arr[j + 1] % 2 != 0 && arr[j] % 2 == 0)
				swap(arr, j, j + 1);
}

void printArr(int* arr, int len) {
	printf("L'array attualmente allocato e':\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
}

void swap(int* arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF){}
}