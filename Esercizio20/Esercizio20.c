#include <stdio.h>
#include <stdlib.h>
#define DEF_PATH "C:\\Users\\Simeone\\Documents\\Esercizio20.sav"
#define DEF_PARTITE (Partita[]) { {TESTA, 1, 2}, {CROCE, 3,4}, {TESTA, 6,5}, {CROCE, 6, 1}, {TESTA, 5, 4} }
#define DEF_SIZE_PARTITE 5

typedef enum {
	TESTA = 't',
	CROCE = 'c'
} Moneta;

typedef struct {
	char moneta;
	int dadoGiocatore1;
	int dadoGiocatore2;
} Partita;

int play(Partita*, int);
void save(Partita*, int, char*);
Partita* load(char*);
void pflush();

int main() {
	char* saveName = malloc(255);
	printf("Inserire il nome del file di salvataggio: ");
	scanf("%s", saveName);
	Partita* partite = load(saveName);
	if (partite == NULL) {
		printf("Nome non valido! La partita sara' salvata in: %s\n", DEF_PATH);
		saveName = DEF_PATH;
		save(DEF_PARTITE, DEF_SIZE_PARTITE, DEF_PATH);
		partite = load(saveName);
	}
	int win = play(partite, DEF_SIZE_PARTITE);
	win ? printf("Vittoria giocatore %d\n", win) : printf("Pareggio\n");
	pflush();
	getchar();
	return 0;
}
int play(Partita* partite, int size) {
	int winG1 = 0, winG2 = 0;
	for (int i = 0; i < size; i++) {
		if (partite[i].moneta == TESTA && partite[i].dadoGiocatore1 > partite[i].dadoGiocatore2 || partite[i].moneta == CROCE && partite[i].dadoGiocatore1 < partite[i].dadoGiocatore2)
			winG1++;
		if (partite[i].moneta == TESTA && partite[i].dadoGiocatore2 > partite[i].dadoGiocatore1 || partite[i].moneta == CROCE && partite[i].dadoGiocatore2 < partite[i].dadoGiocatore1)
			winG2++;
	}
	if (winG1 > winG2)
		return 1;
	else if (winG2 > winG1)
		return 2;
	return 0;
}

void save(Partita* partite, int size, char* path) {
	FILE* file = fopen(path, "wb");
	fwrite(partite, sizeof(Partita), size, file);
	fclose(file);
}

Partita* load(char* path) {
	Partita* partite = calloc(1, sizeof(Partita));
	FILE* file = fopen(path, "rb");
	if (file == NULL)
		return NULL;
	int read;
	for (int i = 0; (read = fread(&partite[i], sizeof(Partita), 1, file)) > 0; i++)
		partite = _recalloc(partite, i + 2, sizeof(Partita)); //OPPURE realloc(partite, sizeof(Partita) * (i+2))
	fclose(file);
	return partite;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}