#include <stdio.h>

int sum(int);

int main() {
	int num;
	printf("Inserisci un numero: ");
	scanf("%d", &num);
	printf("La somma dei numeri pari minori uguali di %d e': %d\n", num, sum(num));
	return 0;
}

int sum(int n) {
	return n < 1 ? 0 : n % 2 ? n - 1 + sum(n - 2) : n + sum(n - 2);
}