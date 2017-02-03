#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdreclist.h"
#define DEFAULT_PATH "..\\Esercizio27\\Numbers.txt"

int isPts(char*);
int isPrime(int);
int removeLastChar(char*);

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Usage: Esercizio27.exe [path]");
		return 1;
	}
	Node* head = create();
	FILE* file = fopen(argv[1], "r");
	if (!file) {
		printf("Impossibile aprire il file %s", argv[1]);
		return 2;
	}
	char* strNum = malloc(sizeof(char) * 128);
	while (!feof(file) && (fscanf(file, "%s", strNum) != EOF)){
		int num = atoi(strNum);
		if (isPts(strNum))
			head = append(head, num);
	}
	print(head);
	return 0;
}

int isPts(char* strNum) {
	int prime = 1;
	int end = 0;
	while (prime && !end)
	{
		prime = isPrime(atoi(strNum));
		end = !removeLastChar(strNum);
	}
	return end;
}

int isPrime(int num) {
	for (int i = 2; i<num; i++) 
		if (num % i == 0 && i != num)
			return 0;
	return 1;
}

int removeLastChar(char* str) {
	int len = strlen(str);
	if (len > 0) {
		str[len - 1] = 0;
		return 1;
	}
	return 0;
}