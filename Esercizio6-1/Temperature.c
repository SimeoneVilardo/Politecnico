#include <stdio.h>
#include <math.h>
#define GIORNI 7

int main() {
	float temps[GIORNI];
	printf("Inserisci le temperature nei vari giorni\n");
	for (int i = 0; i < GIORNI; i++) {
		printf("Temperatura giorno %d: ", i + 1);
		scanf("%f", &temps[i]);
	}
	float tot = 0, min = 1000, max = 0;
	char *pad = "************************";
	printf("GIRONO\tVALORE\tISTOGRAMMA\n");
	for (int i = 0; i < GIORNI; i++) {
		max = temps[i] > max ? temps[i] : max;
		min = temps[i] < min ? temps[i] : min;
		tot += temps[i];
		int len = floorf(temps[i]) - 34;
		printf("%6d\t%6.1f\t%.*s\n", i + 1, temps[i], len > 0 ? len : 0, pad);
	}
	printf("Temperatura minima: %.1f\n", min);
	printf("Temperatura massima: %.1f\n", max);
	printf("Temperatura media: %.1f\n", tot / GIORNI);
	return 0;
}