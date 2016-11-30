#include <stdio.h>
#define PATH_R_FILE "../File/read_text.txt"
#define PATH_W_FILE "../File/write_text.txt"
#define CHUNK_SIZE 1024
#define TEXT "You know, Morgan has this crazy idea.\r\nWhat is it?\r\nHe thinks that, with one kiss, you'll remember everything.\r\nHa. One magical kiss?\r\nYeah. Ha, ha. exactly. I know, it's...\r\nChuck.\r\nYeah?\r\nKiss me."

void readCharByChar(char* path);
void readByChunk(char* path);
void readByDynChunk(int chunk_size, char* path);
void readFscanf(char* path);
void writeCharByChar(char* text, char* path);
void writeFprintf(char* text, char* path);
void pflush();

int main() {
	int op = 0;
	printf("File");
	do {
		printf("\nMenu Principale:\n");
		printf("  1) Leggi un file (char by char)\n");
		printf("  2) Leggi un file (by static chunk)\n");
		printf("  3) Leggi un file (by dynamic chunk)\n");
		printf("  4) Leggi un file (fscanf)\n");
		printf("  5) Scrivi un file (char by char)\n");
		printf("  6) Scrivi un file (fprintf)\n");
		printf("  99) Chiudi\n");
		printf("\nNumero operazione: ");
		scanf("%d", &op);
		printf("\n");
		switch (op)
		{
		case 1:
			readCharByChar(PATH_R_FILE);
			break;
		case 2:
			readByChunk(PATH_R_FILE);
			break;
		case 3:
			readByDynChunk(4, PATH_R_FILE);
			break;
		case 4:
			readFscanf(PATH_R_FILE);
			break;
		case 5:
			writeCharByChar(TEXT, PATH_W_FILE);
			break;
		case 6:
			writeFprintf(TEXT, PATH_W_FILE);
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

void readCharByChar(char* path) {
	FILE *file = NULL;
	file = fopen(path, "r");
	char c;
	if (file) {
		while ((c = getc(file)) != EOF)
			putchar(c);
		fclose(file);
	}
	else
		printf("Impossibile aprire il file %s", path);
}

void readByChunk(char* path) {
	FILE *file = NULL;
	char buf[CHUNK_SIZE];
	size_t nread;
	file = fopen(path, "r");
	if (file) {
		while ((nread = fread(buf, 1, sizeof buf, file)) > 0)
			fwrite(buf, 1, nread, stdout);
		if (ferror(file))
			printf("Errore nella lettura del file %s", path);
		fclose(file);
	}
	else
		printf("Impossibile aprire il file %s", path);
}

void readByDynChunk(int chunk_size, char* path) {
	FILE *file = NULL;
	char *buf = malloc(chunk_size);
	size_t nread;
	if (buf == NULL)
		printf("Errore nell'allocazione della memoria");
	file = fopen(path, "r");
	if (file) {
		while ((nread = fread(buf, 1, chunk_size, file)) > 0)
			fwrite(buf, 1, nread, stdout);
		if (ferror(file))
			printf("Errore nella lettura del file %s", path);
		fclose(file);
	}
	else
		printf("Impossibile aprire il file %s", path);
}

void readFscanf(char* path) {
	FILE * file = NULL;
	char text[CHUNK_SIZE];
	file = fopen(path, "r");
	if (file) {
		fscanf(file, "%s", text);
		printf("%s", text);
		fclose(file);
	}
	else
		printf("Impossibile aprire il file %s", path);
}

void writeCharByChar(char* text, char* path) {
	FILE *file = NULL;
	file = fopen(path, "ab+");
	if (file) {
		fputs(text, file);
		fclose(file);
	}
	else
		printf("Impossibile aprire il file %s", path);
}

void writeFprintf(char* text, char* path) {
	FILE *file = NULL;
	file = fopen(path, "ab+");
	if (file) {
		fprintf(file, "%s", text);
		fclose(file);
	}
	else
		printf("Impossibile aprire il file %s", path);
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}