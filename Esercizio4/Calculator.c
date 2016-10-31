#include <stdio.h>
int main() {
	float num1 = 0, num2 = 0, sum = 0, diff = 0, prod = 0, div = 0;
	printf("Inserisci il primo numero: ");
	scanf("%f", &num1);
	printf("Inserisci il secondo numero: ");
	scanf("%f", &num2);
	sum = num1 + num2;
	diff = num1 - num2;
	prod = num1 * num2;
	div = num1 / num2;
	printf("%f + %f = %f\n", num1, num2, sum);
	printf("%f - %f = %f\n", num1, num2, diff);
	printf("%f * %f = %f\n", num1, num2, prod);
	printf("%f / %f = %f\n", num1, num2, div);
	return 0;
}