#include <stdio.h>
#include <string.h>

void pflush();

int main() {
	char str[100];
	char c;
	printf("Inserire una stringa: ");
	scanf("%s", str);
	pflush();
	printf("Inserire un carattere: ");
	scanf("%c", &c);
	int len = strlen(str);
	int oldSuc = 0;
	int newSuc = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == c)
			newSuc++;	
		else if(newSuc > oldSuc) {
			oldSuc = newSuc;
			newSuc = 0;
		}	
	}
	printf("La piu' lunga successione e': %d", oldSuc > newSuc ? oldSuc : newSuc);
	pflush();
	getchar();
	return 0;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}