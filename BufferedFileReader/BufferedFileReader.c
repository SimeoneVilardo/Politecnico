#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_PATH "..\\BufferedFileReader\\Text.txt"
#define BUFFER_SIZE 64
#define STR_SIZE (BUFFER_SIZE + 1)

void readAndPrint(FILE* file);
char* readAndGet(FILE* file);

int main() {
	FILE* file = fopen(DEFAULT_PATH, "r");
	if (!file) {
		printf("Impossibile aprire il file %s", DEFAULT_PATH);
		return 1;
	}
	printf("Stringa:\n\n");
	readAndPrint(file);
	printf("\n\n*******************\n\n");
	rewind(file);
	printf("Buffer:\n\n");
	char* text = readAndGet(file);
	printf("%s", text);
	fclose(file);
	return 0;
}

void readAndPrint(FILE* file) {
	char* buffer = malloc(sizeof(char) * STR_SIZE);
	size_t nRead;
	while ((nRead = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
		buffer[nRead] = 0;
		printf("%s", buffer);
	}
	free(buffer);
}

char* readAndGet(FILE* file) {
	char* text = malloc(sizeof(char) * BUFFER_SIZE);
	char* buffer = malloc(sizeof(char) * BUFFER_SIZE);
	size_t nRead, textSize = 0;
	while ((nRead = fread(buffer, sizeof(char), sizeof(buffer), file)) > 0) {
		textSize += nRead;
		text = realloc(text, textSize);
		memcpy(&text[textSize - nRead], buffer, nRead);
	}
	free(buffer);
	return text;
}