#include <stdio.h>

#define SIZE 10
#define SUM_SIZE SIZE*2

void pflush();
void setArray(int arr[], char* text);
void bubbleSort(int arr[]);
void printArray(int arr[],int size, char* text);
void sumArrays(int arr1[], int arr2[], int sumArr[]);

int main() {
	int arr1[SIZE];
	int arr2[SIZE];
	int sumArr[SUM_SIZE];
	setArray(arr1, "Inserire gli elementi del primo array");
	setArray(arr2, "Inserire gli elementi del secondo array");
	printArray(arr1, SIZE, "Il primo array originale e':");
	printArray(arr2, SIZE,"Il secondo array originale e':");
	bubbleSort(arr1);
	bubbleSort(arr2);
	printArray(arr1, SIZE,"Il primo array ordinato e':");
	printArray(arr2, SIZE,"Il secondo array ordinato e':");
	sumArrays(arr1, arr2, sumArr);
	printArray(sumArr, SUM_SIZE, "La somma ordinata degli array e': ");
	pflush();
	getchar();
	return 0;
}

void setArray(int arr[], char* text) {
	printf("%s\n", text);
	for (int i = 0; i < SIZE; i++) {
		printf("Elemento numero %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
}

void bubbleSort(int arr[]) {
	int temp = 0;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (arr[j] > arr[i]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;;
			}
}

void sumArrays(int arr1[], int arr2[], int sumArr[]) {
	int a1 = 0, a2 = 0;
	for (int i = 0; i < SUM_SIZE; i++) {
		if ((arr1[a1] < arr2[a2] && a1 < SIZE )|| a2 >= SIZE) {
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