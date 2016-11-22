#include <stdio.h>

#define SIZE 10
#define SUM_SIZE SIZE*2

void pflush();
void setArray(int arr[], int size, char* text);
void bubbleSort(int arr[], int size);
void printArray(int arr[], int size, char* text);
void sumArrays(int arr1[], int arr2[], int size, int sumArr[], int sumSize);

int main() {
	int arr1[SIZE];
	int arr2[SIZE];
	int sumArr[SUM_SIZE];
	setArray(arr1, "Inserire gli elementi del primo array", SIZE);
	setArray(arr2, "Inserire gli elementi del secondo array", SIZE);
	printArray(arr1, SIZE, "Il primo array originale e':");
	printArray(arr2, SIZE, "Il secondo array originale e':");
	bubbleSort(arr1, SIZE);
	bubbleSort(arr2, SIZE);
	printArray(arr1, SIZE, "Il primo array ordinato e':");
	printArray(arr2, SIZE, "Il secondo array ordinato e':");
	sumArrays(arr1, arr2, SIZE, sumArr, SUM_SIZE);
	printArray(sumArr, SUM_SIZE, "La somma ordinata degli array e': ");
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

void bubbleSort(int arr[], int size) {
	int temp = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (arr[j] > arr[i]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;;
			}
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