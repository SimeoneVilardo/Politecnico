#include <stdio.h>
#include <string.h>

void pflush();
int isPal(const char* word, int wLen);

int main() {
	char word[100];
	printf("Inserisci una parola: ");
	scanf("%s", word);
	int wLen = strlen(word);
	int pLen = 0;
	for (int i = 0; (i < wLen) && !pLen; i++) {
		if (isPal(word, wLen - i))
			pLen = wLen - i;
	}
	int res = pLen == 0 ? wLen - 1 : wLen - pLen;
	printf("Il numero minimo di caratteri per rendere la stringa palindroma e': %d\n", res);
	printf("Premere INVIO per terminare il programma\n");
	pflush();
	getchar();
	return 0;
}

int isPal(const char* word, int wLen) {
	int pal = 1;
	for (int i = 0; (i < wLen / 2) && pal; i++)
		if (word[i] != word[wLen - (i + 1)])
			pal = 0;
	return pal;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}