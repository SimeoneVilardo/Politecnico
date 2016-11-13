#include <stdio.h>
#include <string.h>
#define SIZE 100

int main() {
	char str1[SIZE], str2[SIZE];
	int x, y, i;

	/****************************************************************************************************************/
	/*Soluzione easy per leggere una stringa con gli spazi.
	ATTENZIONE: Rischio di BufferOverflow!
	Se la stringa inserita fosse più lunga dell'array che deve contenerla il programma andrebbe in BufferOverflow,
	causando il crash del programma (o in alcuni casi anche di peggio).*/

	//printf("Scrivere una stringa\n");
	//scanf("%[^\n]s", str1);
	//printf("Scrivere un'altra stringa\n");
	//scanf("%[^\n]s", str2);
	/****************************************************************************************************************/


	/****************************************************************************************************************/
	/*Soluzione seria senza rischio di BufferOverflow.*/
	printf("Scrivere una stringa\n");
	fgets(str1, SIZE, stdin);
	if ((strlen(str1)>0) && (str1[strlen(str1) - 1] == '\n'))
		str1[strlen(str1) - 1] = '\0';
	printf("Scrivere un'altra stringa\n");

	fgets(str2, SIZE, stdin);
	if ((strlen(str2)>0) && (str2[strlen(str2) - 1] == '\n'))
		str2[strlen(str2) - 1] = '\0';
	/****************************************************************************************************************/

	x = strlen(str1);
	y = strlen(str2);
	for (i = 0; i < x; i++)
		printf("%c", str1[i]);
	for (i = 0; i < y; i++)
		printf("%c", str2[i]);
	printf("\n");
	printf("Premi INVIO per terminare il programma\n");
	getchar();
	return 0;
}