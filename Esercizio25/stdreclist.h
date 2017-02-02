#ifndef STDRECLIST
#define STDRECLIST
#define DEST_LEN 3
#define STR_DEST_LEN (DEST_LEN + 1)

#include <stdio.h>
#include <stdlib.h>

typedef struct _time {
	int hours;
	int minutes;
} Time;

typedef struct _volo {
	int id;
	char dest[STR_DEST_LEN];
	Time scheduledDep;
	Time actualDep;
	int passenger;
} Volo;

typedef struct Node
{
	Volo value;
	struct Node* next;
} Node;

Node* create();
Node* prepend(Node* head, Volo value);
Node* append(Node* head, Volo value);
Node* insertAt(Node* head, Volo value, int pos);
Node* shift(Node* head);
Node* pop(Node* head);
Node* removeAt(Node* head, int pos);
int isEmpty(Node* node);
int hasNext(Node* node);
int find(Node* head, int id);
int exists(Node* head, int id);
int count(Node* head);
void print(Node* head);
void save(Node* head, const char* path);
Node* load(const char* path);

#endif

