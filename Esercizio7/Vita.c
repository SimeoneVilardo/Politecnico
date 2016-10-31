#include <stdio.h>

#define MONTHS_NUMBER 12;

int monthIsValid(int month);

int main()
{
	int cYear = 0, cMonth = 0, bYear = 0, bMonth = 0;
	int uYears = 0, uMonths = 0;
	printf("Inserire l'anno corrente: ");
	scanf("%d", &cYear);
	while (!monthIsValid(cMonth))
	{
		printf("Inserire il mese corrente: ");
		scanf("%d", &cMonth);
	}
	do
	{
		printf("Inserire l'anno di nascita: ");
		scanf("%d", &bYear);
	} while (!(cYear > bYear));
	while (!monthIsValid(bMonth))
	{
		printf("Inserire il mese di nascita: ");
		scanf("%d", &bMonth);
	}
	uYears = cMonth < bMonth ? cYear - bYear - 1 : cYear - bYear;
	uMonths = cMonth > bMonth ? cMonth - bMonth : cMonth + MONTHS_NUMBER - bMonth;

	printf("L'utente ha %d anni e %d mesi", uYears, uMonths);
	return 0;
}

int monthIsValid(int month) {
	return (month > 0 && month < 13) ? 1 : 0;
}