#include <stdio.h>
#include "vmath.h"

int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("Usage:\n\"Esercizio22.exe [n1] [n2]\"");
		getchar();
		return 1;
	}
	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);
	printf("Potenza = %d\n", pow(n1,n2));
	printf("MCD = %d\n", mcd(n1,n2));
	getchar();
	return 0;
}