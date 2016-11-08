#include <stdio.h>
#define SIZE 8

int main()
{
	char array[SIZE] = { 'f','u', 'r', 'v', 'h', 'g', 'z', 'c' };
	int count, i;

	printf("Stampa array originale:\n");
	for (i = 0; i < SIZE; i++)
		printf("%c ", array[i]);

	for (count = 1; count < SIZE; count++)
	{
		for (i = 0; i <SIZE-1; i++)
		{
			if (array[i] > array[i + 1])
			{
				char temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}

	printf("\nStampa array in ordine alfabetico:\n");

	for (i = 0; i < SIZE; i++)
		printf("%c ", array[i]);
	getchar();

	return 0;
}