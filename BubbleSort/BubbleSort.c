#include <stdio.h>
#define SIZE 10

void pflush();

int main() {
	int arr[SIZE];
	printf("Inserire 10 elementi nell'array\n");
	for (int i = 0; i < SIZE; i++) {
		printf("Inserire l'elemento numero %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
	int temp = 0;
	int count = SIZE;
	while (count-- > 0)
		for (int j = 0; j < SIZE - 1; j++)
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	printf("Il nuovo array ordinato e': ");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	pflush();
	printf("\nPremi INVIO per terminare il programma\n");
	getchar();
	return 0;
}

void pflush() {
	char c;
	while (c = getchar() != '\n' && c != EOF) {}
}