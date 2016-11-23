#include <stdio.h>
#define N 3

int quadratoMagico(int arr[][N], int size);

int main() {
	int arr[N][N] = { { 8,3,4 },{ 1, 5, 9 },{ 6, 7, 2 } };
	int magic = quadratoMagico(arr, N);
	printf("Magic: %d", magic);
	getchar();
}

int quadratoMagico(int arr[][N], int size) {
	int magic = 1;
	int genericSum = 0;
	for (int i = 0; i < size; i++)
		genericSum += arr[i][0];

	for (int i = 1; i < size; i++) {
		int rowSum = 0;
		for (int j = 0; j < size; j++)
			rowSum += arr[i][j];
		if (rowSum != genericSum)
			magic = 0;
	}

	for (int j = 0; j < size; j++) {
		int colSum = 0;
		for (int i = 0; i < size; i++) 
			colSum += arr[i][j];	
		if (colSum != genericSum) 
			magic = 0;
	}

	int dia1Sum = 0;
	int d1j = 0;
	for (int i = 0; i < size; i++) {
		dia1Sum += arr[i][d1j];
		d1j++;
	}

	if (dia1Sum != genericSum) 
		magic = 0;

	int dia2Sum = 0;
	int d2j = size - 1;
	for (int i = 0; i < size; i++) {
		dia2Sum += arr[i][d2j];
		d2j--;
	}

	if (dia2Sum != genericSum) 
		magic = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i][j] < 1 || arr[i][j] > size*size)
				magic = 0;
			for (int h = 0; h < size; h++) 
				for (int k = 0; k < size; k++) 
					if (arr[i][j] == arr[h][k] && (i != h && j != k)) 
						magic = 0;				
		}
	}
	return magic;
}