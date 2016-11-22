#include <stdio.h>

#define SIZE 10
#define SUM_SIZE SIZE*2

typedef struct { int checks; int swaps; } Stat;

void pflush();
void setArray(int arr[], int size, char* text);
Stat bubbleSort(int arr[], int size);
void printArray(int arr[], int size, char* text);
void sumArrays(int arr1[], int arr2[], int size, int sumArr[], int sumSize);
void swap(int arr[], int i, int j);

int main() {
	int arr1[SIZE];
	int arr2[SIZE];
	int sumArr[SUM_SIZE];
	setArray(arr1, SIZE, "Inserire gli elementi del primo array");
	setArray(arr2, SIZE, "Inserire gli elementi del secondo array");
	printArray(arr1, SIZE, "Il primo array originale e':");
	printArray(arr2, SIZE, "Il secondo array originale e':");
	Stat stat1 = bubbleSort(arr1, SIZE);
	Stat stat2 = bubbleSort(arr2, SIZE);
	Stat stat = { stat1.checks + stat2.checks, stat2.swaps + stat2.swaps };
	printArray(arr1, SIZE, "Il primo array ordinato e':");
	printArray(arr2, SIZE, "Il secondo array ordinato e':");
	sumArrays(arr1, arr2, SIZE, sumArr, SUM_SIZE);
	printArray(sumArr, SUM_SIZE, "La somma ordinata degli array e': ");
	printf("Numero totale di confronti: %d\nNumero totale di ordinamenti: %d\n", stat.checks, stat.swaps);
	pflush();
	getchar();
	return 0;
}

void setArray(int arr[], int size, char* text) {
	printf("%s\n", text);
	for (int i = 0; i < size; i++) {
		printf("Elemento numero %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
}

Stat bubbleSort(int arr[], int size) {
	Stat stat = { 0,0 };
	int count = SIZE - 1;
	while (count-- > 0)
		for (int i = 0; i < SIZE - 1; i++) {
			stat.checks++;
			if (arr[i] > arr[i + 1]) {
				stat.swaps++;
				swap(arr, i, i + 1);
			}
		}
	return stat;
}

void swap(int arr[], int i, int j) {
	int temp = 0;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;;
}

void sumArrays(int arr1[], int arr2[], int size, int sumArr[], int sumSize) {
	int a1 = 0, a2 = 0;
	for (int i = 0; i < sumSize; i++) {
		if ((arr1[a1] < arr2[a2] && a1 < size) || a2 >= size) {
			sumArr[i] = arr1[a1];
			a1++;
		}
		else
		{
			sumArr[i] = arr2[a2];
			a2++;
		}
	}
}

void printArray(int arr[], int size, char* text) {
	printf("%s\n", text);
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}