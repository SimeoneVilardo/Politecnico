#include <stdio.h>

int mcd(int, int);
void pflush();

int main() {
	int num1, num2;
	printf("Inserisci la base: ");
	scanf("%d", &num1);
	printf("Inserisci l'esponente: ");
	scanf("%d", &num2);
	int numPow = pow(num1, num2);
	printf("La potenza di %d alla %d e': %d", num1, num2, numPow);
	pflush();
	getchar();
	return 0;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

int pow(int base, int exp) {
	return !exp ? 1 : base*pow(base, exp - 1);
}