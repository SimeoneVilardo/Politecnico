#include <stdio.h>
int main() {
	int num1 = 0, num2 = 0, mcd = 0;
	printf("Inserisci il primo numero: ");
	scanf("%d", &num1);
	printf("Inserisci il secondo numero: ");
	scanf("%d", &num2);
	while (num1 != num2) {
		if (num1 > num2)
			num1 -= num2;
		else
			num2 -= num1;
	}
	printf("L'MCD di e': %d", num1);
	return 0;
}