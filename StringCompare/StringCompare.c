#include <stdio.h>
#include <string.h>

void pflush();

int main() {
	char s1[30], s2[30];
	printf("Inserisci la prima stringa: ");
	scanf("%s", s1);
	printf("Inserisci la seconda stringa: ");
	scanf("%s", s2);
	int j = 0;
	for (int i = 0; i < strlen(s1) && j < strlen(s2); i++)
		if (s1[i] == s2[j])
			j++;
		else
			j = 0;
	if (j == strlen(s2))
		printf("Yap");
	else
		printf("Nope");
	pflush();
	getchar();
	return 0;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}