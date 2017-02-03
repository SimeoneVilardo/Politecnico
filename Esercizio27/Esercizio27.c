#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdreclist.h"
#define DEFAULT_PATH "..\\Esercizio27\\Numbers.txt"
#define SUCCESS_EXIT_CODE 0
#define USAGE_ERROR_EXIT_CODE 1
#define FILE_ERROR_EXIT_CODE 2

int isPts(char*);
int isPrime(int);
int removeLastChar(char*);
Node* populateList(Node*, FILE*);

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Usage: Esercizio27.exe [path]");
		return USAGE_ERROR_EXIT_CODE;
	}
	Node* head = create();
	FILE* file = fopen(argv[1], "r");
	if (!file) {
		printf("Impossibile aprire il file %s", argv[1]);
		return FILE_ERROR_EXIT_CODE;
	}
	head = populateList(head, file);
	print(head);
	return SUCCESS_EXIT_CODE;
}

Node* populateList(Node* head, FILE* file) {
	char* strNum = malloc(sizeof(char) * 128);
	while (!feof(file) && (fscanf(file, "%s", strNum) != EOF)) {
		int num = atoi(strNum);
		if (isPts(strNum))
			head = insertOrdered(head, num);
	}
	return head;
}

int isPts(char* strNum) {
	int end = 0;
	while (isPrime(atoi(strNum)) && !end)
		end = !removeLastChar(strNum);
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