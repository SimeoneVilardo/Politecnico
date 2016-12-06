#include <stdio.h>
#include <math.h>

int calcPol(int* coeffs, int grade, int x, int index);
int* arrAlloc(int len);
void pflush();

int main()
{
	char exit = 0;
	int grade = 0, x = 0, res = 0;
	printf("*** POLINOMIO ***");
	while (exit != 's') {
		printf("\nInserisci il grado del tuo polinomio: ");
		scanf("%d", &grade);
		int* coeffs = arrAlloc(grade + 1);
		for (int i = 0; i < grade + 1; i++)
		{
			printf("Inserisci il coefficiente di X^%d: ", grade - i);
			scanf("%d", &coeffs[grade - i]);
		}
		printf("Inserisci il valore della X: ");
		scanf("%d", &x);
		res = calcPol(coeffs, grade, x, 0);
		printf("Il risultato e': %d\n", res);
		pflush();
		printf("Terminare il programma? [s/n] ");
		exit = getchar();
	}
	return 0;
}

int calcPol(int* coeffs, int grade, int x, int index) {
	return index < grade + 1 ? coeffs[grade - index] * pow(x, grade - index) + calcPol(coeffs, grade, x, index + 1) : 0;
}

int* arrAlloc(int len) {
	int* arr = (int*)calloc(sizeof(int) * len);
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}