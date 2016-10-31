#include <stdio.h>
int main()
{
	float square = 0;
	float cube = 0;
	printf("Numero      Quadrato      Cubo\n");
	for (int i = 0; i < 11; i++) {
		square = i*i;
		cube = square*i;
		printf("%6d%14.2f%-6s%0.1f\n", i, square, "", cube);
	}
	getchar();
	return 0;
}

