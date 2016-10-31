#include <stdio.h>
#include <math.h>
#define GIORNI 7

int main() {
	float temps[GIORNI];
	int starsLen[GIORNI];
	int maxLen = 0;
	printf("Inserisci le temperature nei vari giorni\n");
	float tot = 0, min = 1000, max = 0;
	for (int i = 0; i < GIORNI; i++) {
		printf("Temperatura giorno %d: ", i + 1);
		scanf("%f", &temps[i]);
		starsLen[i] = floorf(temps[i] - 34);
		maxLen = starsLen[i] > maxLen ? starsLen[i] : maxLen;
		max = temps[i] > max ? temps[i] : max;
		min = temps[i] < min ? temps[i] : min;
		tot += temps[i];
	}
	while (maxLen-- > 0) {
		char str[512];
		strcpy(str, "");
		for (int i = 0; i < GIORNI; i++) {
			strcat(str, ((starsLen[i] > 0) && (maxLen + 1 - starsLen[i] < 1)) ? "*" : "");
			strcat(str, "\t");
		}
		strcat(str, "\n");
		printf(str);
	}
	for (int i = 0; i < GIORNI; i++) {
		printf("%.1f\t", temps[i]);
	}
	printf("\n");
	printf("Temperatura minima: %.1f\n", min);
	printf("Temperatura massima: %.1f\n", max);
	printf("Temperatura media: %.1f\n", tot / GIORNI);
	return 0;
}