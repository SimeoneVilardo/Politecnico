#include <stdio.h>

#define SIZE 10

void staticAddOne(int matrix[][SIZE]);
void dynamicAddOne(int** matrix);

int main() {
	// Dichiarazione di matrice statica
	int matrix[SIZE][SIZE]; 

	// Dichiarazione di matrice dinamica (utilizza il puntatore)
	int** pMatrix = (int**)malloc(sizeof(int) * SIZE); 
	// E' necessario inizializzare anche ogni elemento dell'array come array (una matrice è di fatto un array di array)
	for (int i = 0; i < SIZE; i++)
		pMatrix[i] = (int*)malloc(SIZE * sizeof(int));

	// Inizializzazione dei valori della matrice statica
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix[i][j] = (i+1)*(j+1); //(i+1)*(j+1) perchè mi piace

	// Inizializzazione dei valori della matrice dinamica
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			pMatrix[i][j] = (i + 1)*(j + 1); //(i+1)*(j+1) perchè mi piace

	// Stampa a video della matrice statica
	printf("Matrice statica (senza il puntatore):\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			printf("%-4d", matrix[i][j]);
		printf("\n");
	}
	printf("\n");

	// Stampa a video della matrice dinamica
	printf("Matrice dinamica (con il puntatore):\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			printf("%-4d", pMatrix[i][j]);
		printf("\n");
	}
	printf("\n");

	//Manipola la matrice statica con una funzione
	staticAddOne(matrix);

	//Manipola la matrice dinamica con una funzione
	dynamicAddOne(pMatrix);

	// Stampa a video della matrice statica
	printf("Matrice statica (senza il puntatore) dopo la manipolazione:\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			printf("%-4d", matrix[i][j]);
		printf("\n");
	}
	printf("\n");

	// Stampa a video della matrice dinamica
	printf("Matrice dinamica (con il puntatore) dopo la manipolazione:\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			printf("%-4d", pMatrix[i][j]);
		printf("\n");
	}
	printf("\n");

	getchar();
	return 0;
}

//Questa funzione aggiunge "1" ad ogni elemento della matrice e prende come parametro una matrice statica
void staticAddOne(int matrix[][SIZE]) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix[i][j]++;
}

//Questa funzione aggiunge "1" ad ogni elemento della matrice e prende come parametro una matrice dinamica
void dynamicAddOne(int** matrix) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix[i][j]++;
}