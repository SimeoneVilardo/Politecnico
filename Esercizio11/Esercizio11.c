#include <stdio.h>
#include <math.h>

#define N 40

int main() {
	int num = 0;
	int setaccio[N];
	for (int i = 0; i < N; i++)
		setaccio[i] = i + 2;
	int root = (int)sqrt(N);
	for (int i = 0; i < root; i++)
		for (int j = i + 1; j < N; j++)
			if (setaccio[i] != 0 && !(setaccio[j] % setaccio[i]))
				setaccio[j] = 0;
	for (int i = 0; i < N; i++)
		if (setaccio[i])
			printf("%d ", setaccio[i]);
	return 0;
}