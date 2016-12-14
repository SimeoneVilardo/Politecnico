#include <stdio.h>
#define PATH "C:\\Users\\Simeone\\Documents\\prova.txt"

int main() {
	/******************************************************/
	//PARTE 1
	char str[] = "linea 1\nlinea 2\nlinea 3\n";
	FILE* fileToWrite = fopen(PATH, "w");
	if (fileToWrite == NULL) {
		printf("Errore durante l'apertura del file in scrittura");
		getchar();
		return 1;
	}		
	for (int i = 0; str[i] != '\0'; i++)
		if (fputc(str[i], fileToWrite) == EOF || ferror(fileToWrite)) {
			printf("Errore durante la scrittura del file");
			getchar();
			return 1;
		}
	if (fclose(fileToWrite) == EOF) {
		printf("Errore durante la chiusura del file in scrittura");
		getchar();
		return 1;
	}
	/******************************************************/

	/******************************************************/
	//PARTE 2
	FILE* fileToRead = fopen(PATH, "r");
	if (fileToRead == NULL) {
		printf("Errore durante l'apertura del file in lettura");
		getchar();
		return 1;
	}
	char line1[1024];
	int index = 0;
	while ((line1[index] = fgetc(fileToRead)) != '\n')
	{
		index++;
		if (line1[index] == EOF || ferror(fileToRead) || feof(fileToRead)) {
			printf("Errore durante la lettura della prima riga del file");
			getchar();
			return 1;
		}
	}
	line1[index+1] = '\0';
	
	char line2[1024];
	if (fgets(line2, 1024, fileToRead) == EOF || ferror(fileToRead) || feof(fileToRead)) {
		printf("Errore durante la lettura della seconda riga del file");
		getchar();
		return 1;
	}
	
	char line3[1024];
	int line3Num;
	if (fscanf(fileToRead, "%s%d", line3, &line3Num) == 0 || ferror(fileToRead) || feof(fileToRead)) {
		printf("Errore durante la lettura della terza riga del file");
		getchar();
		return 1;
	}

	if (fclose(fileToRead) == EOF) {
		printf("Errore durante la chiusura del file in lettura");
		getchar();
		return 1;
	}
	/******************************************************/

	/******************************************************/
	//PARTE 3
	printf("Prima riga: %s", line1);
	printf("Seconda riga: %s", line2);
	printf("Terza riga: %s %d", line3, line3Num);
	/******************************************************/

	getchar();
	return 0;
}