#include <stdio.h>
#include <string.h>
#define SIZE 8

char* intToBin(int num);
void pflush();
void printIntArray(char* bin);

int main() {
	int num = 0;
	printf("Inserire un numero: ");
	scanf("%d", &num);
	char* bin = intToBin(num);
	printIntArray(bin);
	pflush();
	getchar();
	return 0;
}

char* intToBin(int num) {
	char* bin = malloc(SIZE);
	for (int i = SIZE - 1; i >= 0; i--) {
		bin[i] = num % 2;
		num = num / 2;
	}
	return bin;
}

void printIntArray(char* bin) {
	for (int i = 0; i < SIZE; i++)
		printf("%d", bin[i]);
	printf("\n");
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}