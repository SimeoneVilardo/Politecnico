#include <stdio.h>
#include <math.h>

#define K 40

int main() {
	int setaccio[K];
	for (int i = 0; i < K; i++)
		setaccio[i] = i + 2;
	int root = (int)sqrt(K);
	for (int i = 0; i < root; i++)
		for (int j = i + 1; j < K; j++)
			if (setaccio[i] != 0 && (setaccio[j] % setaccio[i]) == 0)
				setaccio[j] = 0;
	for (int i = 0; i < K; i++)
		if (setaccio[i] != 0)
			printf("%d ", setaccio[i]);
	return 0;
}
