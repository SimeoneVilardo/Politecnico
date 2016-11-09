#include <stdio.h>
#define N 10

int main() {
	char array1[N] = { 'f', 'c', 's', 'q', 'b', 'e', 'e', 'k', 'i', 'g' };
	char array2[N] = { 'f', 's', 'c', 'k', 'e', 'b', 'e', 'g', 'i', 'q' };
	int anagramma = 1;
	for (int i = 0; i < N && anagramma; i++) {
		int exist = 0;
		for (int j = 0; j < N && !exist; j++)
			if (array1[i] == array2[j]) {
				array2[j] = 0;
				exist = 1;
			}
		if (!exist)
			anagramma = 0;
	}
	if (anagramma)
		printf("Le due parole sono anagrammi\n");
	else
		printf("Le due parole non sono anagrammi\n");
	return 0;
}