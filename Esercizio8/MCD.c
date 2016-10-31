#include <stdio.h>
int main() {
	int num1 = 0, num2 = 0, mcd = 0;
	printf("Inserisci il primo numero: ");
	scanf("%d", &num1);
	printf("Inserisci il secondo numero: ");
	scanf("%d", &num2);
	int min = num1 < num2 ? num1 : num2;
	for (int i = min; i > 0; i--) {
		if (num1 % i == 0 && num2 % i == 0) {
			mcd = i;
			break;
		}		
	}
	printf("L'MCD di %d e %d e': %d",num1, num2, mcd);
	return 0;
}