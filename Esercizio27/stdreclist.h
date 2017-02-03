#ifndef STDRECLIST
#define STDRECLIST

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node* next;
} Node;

Node* create();
Node* prepend(Node* head, int value);
Node* append(Node* head, int value);
Node* insertAt(Node* head, int value, int pos);
Node* insertOrdered(Node* head, int value);
Node* shift(Node* head);
Node* pop(Node* head);
Node* removeAt(Node* head, int pos);
int isEmpty(Node* node);
int hasNext(Node* node);
void print(Node* head);

#endif