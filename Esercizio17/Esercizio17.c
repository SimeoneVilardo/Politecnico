#include <stdio.h>

int mcd(int, int);
void pflush();

int main() {
	int num1, num2;
	printf("Inserisci il primo numero: ");	
	scanf("%d", &num1);
	printf("Inserisci il secondo numero: ");
	scanf("%d", &num2);
	int numMCD = mcd(num1, num2);
	printf("L'MCD di %d e %d e': %d", num1, num2, numMCD);
	pflush();
	getchar();
	return 0;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

int mcd(int a, int b) {
	return !b ? a : mcd(b, a%b);
}