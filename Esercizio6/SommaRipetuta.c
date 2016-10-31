#include <stdio.h>
int main()
{
	int num1, num2, res = 0;
	int i = 0; //Contatore per il ciclo while
	int negativo = 0; //Flag che indica se il risultato sarà negativo o no; 0 = FALSE. 1 = TRUE
	printf("Inserisci il primo numero: ");
	scanf("%d", &num1);
	printf("Inserisci il secondo numero: ");
	scanf("%d", &num2);
	if (num2 < 0) {
		negativo = 1;
		num2 = -num2; //Se il numero è negativo lo rende positivo
	}
	while (i < num2) {
		res += num1;
		i++;
	}
	if (negativo)
		res = -res;
	printf("Il prodotto e': %d\n", res);
	return 0;
}