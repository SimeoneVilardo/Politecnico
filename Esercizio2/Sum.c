#include <stdio.h>
int main() {
	int num1 = 0, num2 = 0, res = 0;
	printf("Inserisci il primo numero: ");
	scanf("%d", &num1);
	printf("Inserisci il secondo numero: ");
	scanf("%d", &num2);
	res = num1 + num2;
	printf("%d + %d = %d", num1, num2, res);
	return 0;
}