#include <stdio.h>
#include "stdutils.h"
#define N 27
#define KEY_SIZE 5
#define PATH_SIZE 128
#define WHITESPACE ' '

int main() {
	char key[][5] = { {'a', 'b', 'c', 'd', 'e'},{ 'f', 'g', 'h', 'i', 'k' },{ 'l', 'm', 'n', 'o', 'p' },{ 'q', 'r', 's', 't', 'u' },{ 'v', 'w', 'x', 'y', 'z' } };
	char* path = malloc(PATH_SIZE);
	printf("Path: ");
	cscanf("%s", path);
	FILE* fp = fopen(path, "r");
	int* cifratura = malloc(sizeof(int) * N);
	polybius(fp, key, cifratura);
	fclose(fp);
	for (int i = 0; i < N; i++)
		printf("%d ", cifratura[i]);
	getchar();
	return 0;
}

int polybius(FILE *fp, char key[][KEY_SIZE], int* cifratura) {
	char c;
	int index = -1;
	while ((c = getc(fp)) != EOF) {
		index++;
		if (c == WHITESPACE)
		{
			cifratura[index] = 0;
			continue;
		}
		if (c == 'j')
			c = 'i';
		int found = 0;
		for (int i = 0; i < KEY_SIZE && !found; i++)
			for (int j = 0; j < KEY_SIZE && !found; j++)
				if (key[i][j] == c) {
					cifratura[index] = (j + 1) + ((i + 1) * 10);
					found = 1;
				}
	}
}