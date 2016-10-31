#include <stdio.h>
int main() {
	int barCode[11];
	int checkDigit = 0;
	printf("Inserire la prima (singola) cifra: ");
	scanf("%d", &barCode[0]);
	printf("Inserire il primo gruppo di cinque cifre: ");
	scanf("%1d%1d%1d%1d%1d", &barCode[1], &barCode[2], &barCode[3], &barCode[4], &barCode[5]);
	printf("Inserire il secondo gruppo di cinque cifre: ");
	scanf("%1d%1d%1d%1d%1d", &barCode[6], &barCode[7], &barCode[8], &barCode[9], &barCode[10]);
	checkDigit = 9 - (((((barCode[0] + barCode[2] + barCode[4] + barCode[6] + barCode[8] + barCode[10]) * 3) + barCode[1] + barCode[3] + barCode[5] + barCode[7] + barCode[9])-1)%10);
	printf("Cifra di controllo: %d", checkDigit);
	return 0;
}