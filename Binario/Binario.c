#include <stdio.h>
#include <math.h>

#define SIZE 7

int convertBinToDec(int arr[], int size);
void pflush();

int main() {
	int bin[SIZE];
	for (int i = 0; i < SIZE; i++) {
		printf("Inserisci il valore binario numero %d: ", i+1);
		scanf("%d", &bin[i]);
	}
	int dec = convertBinToDec(bin, SIZE);
	printf("Il valore in decimale e: %d", dec);
	pflush();
	getchar();
}

int convertBinToDec(int arr[], int size) {
	int dec = -arr[0] * pow(2, size-1);
	for (int i = 1; i < size; i++) {
		dec += arr[i] * pow(2, size -1-i);
	}
	return dec;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}