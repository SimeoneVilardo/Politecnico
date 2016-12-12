#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_BUF 100
#define JOLLY '?'

void charsValid();
void charsValidJolly();
int charsValidLgc(char*, char*);
int charsValidJollyLgc(char*, char*);
void pflush();

int main() {
	int op = 0;
	printf("Rack Management");
	do {
		printf("\nMenu Principale:\n");
		printf("  1) Verifica se e' possibile formare una parola date le lettere\n");
		printf("  2) Verifica se e' possibile formare una parola date le lettere (con jolly)\n");
		printf("  99) Chiudi\n");
		printf("\nNumero operazione: ");
		scanf("%d", &op);
		printf("\n");
		switch (op)
		{
		case 1:
			charsValid();
			break;
		case 2:
			charsValidJolly();
			break;
		case 99:
			printf("L'applicazione sara' terminata");
			break;
		default:
			printf("Comando sconosciuto");
			break;
		}
		pflush();
		printf("\n\nPremi INVIO per continuare...");
		getchar();
	} while (op != 99);

	return 0;
}

void charsValid() {
	char* letters = (char*) calloc(STR_BUF, sizeof(char));
	char* word    = (char*) calloc(STR_BUF, sizeof(char));
	printf("Inserire le lettere disponibili: ");
	scanf("%100s", letters);
	printf("Inserire la parola: ");
	scanf("%100s", word);
	printf("La parola %s %se' creabile", word, !charsValidLgc(letters, word) ? "non " : "");
}

int charsValidLgc(char* letters, char* word) {
	int found = 0, valid = 1;
	int wLen = strlen(word);
	int lLen = strlen(letters);
	for (int i = 0; i < wLen && valid; i++) {
		found = 0;
		for (int j = 0; j < lLen && !found; j++)
			if (word[i] == letters[j]) {
				letters[j] = 0;
				found = 1;
			}		
		if (!found)
			valid = 0;
	}
	return valid;
}

void charsValidJolly() {
	char* letters = (char*)calloc(STR_BUF, sizeof(char));
	char* word = (char*)calloc(STR_BUF, sizeof(char));
	printf("Inserire le lettere disponibili: ");
	scanf("%100s", letters);
	printf("Inserire la parola: ");
	scanf("%100s", word);
	printf("La parola %s %se' creabile", word, !charsValidJollyLgc(letters, word) ? "non " : "");
}

int charsValidJollyLgc(char* letters, char* word) {
	int found = 0, valid = 1, jolly = 0;
	int wLen = strlen(word);
	int lLen = strlen(letters);
	for (int i = 0; i < wLen && valid; i++) {
		found = jolly = 0;
		for (int j = 0; j < lLen && !found; j++)
			if (word[i] == letters[j]) {
				letters[j] = 0;
				found = 1;
			}
		if (!found) {
			for (int j = 0; j < lLen && !jolly; j++)
				if (letters[j] == JOLLY) {
					letters[j] = 0;
					jolly = 1;
					found = 1;
				}
			if(!jolly)
				valid = 0;
		}		
	}
	return valid;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}