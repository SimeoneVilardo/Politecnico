#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define STR_LEN 100
#define C_STR_LEN 400

typedef struct {
	int size;
	void **keys;
	void **values;
} hash_t;

hash_t *hash_new(int);
int hash_index(hash_t *, void *);
void hash_insert(hash_t *, void *, void *);
void *hash_lookup(hash_t *, void *);
char* charToString(char);

int main() {
	hash_t *h = hash_new(5);
	hash_insert(h, 'a', "affa");
	hash_insert(h, 'e', "effe");
	hash_insert(h, 'i', "iffi");
	hash_insert(h, 'o', "offo");
	hash_insert(h, 'u', "uffu");
	char str[STR_LEN];
	char codedStr[C_STR_LEN] = "";
	printf("Inserisci una frase: ");
	gets(str);
	for (int i = 0; i < strlen(str); i++) {
		char* s = (char*) hash_lookup(h, tolower(str[i]));
		strcat(codedStr, s ? s : charToString(str[i]));
	}
	printf("La frase in farfallino e': ");
	puts(codedStr);
	printf("Premi INVIO per terminare");
	getchar();
	return 0;
}

hash_t *hash_new(int size) {
	hash_t *h = calloc(1, sizeof(hash_t));
	h->keys = calloc(size, sizeof(void *));
	h->values = calloc(size, sizeof(void *));
	h->size = size;
	return h;
}

int hash_index(hash_t *h, void *key) {
	int i = (int)key % h->size;
	for (int j = 0; (h->keys[i] && h->keys[i] != key) && (i >= 0); j++)
		i = j < h->size ? (i + 1) % h->size : -1;
	return i;
}

void hash_insert(hash_t *h, void *key, void *value) {
	int i = hash_index(h, key);
	h->keys[i] = key;
	h->values[i] = value;
}

void *hash_lookup(hash_t *h, void *key) {
	int i = hash_index(h, key);
	return i >= 0 ? h->values[i] : NULL;
}

char* charToString(char c) {
	char *str = malloc(2 * sizeof(char));
	str[0] = c;
	str[1] = '\0';
	return str;
}