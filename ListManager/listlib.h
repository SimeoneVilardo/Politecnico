#ifndef LISTLIBH
#define LISTLIBH
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int value;
	struct Node* next;
} Node;

Node* create();
Node* prepend(Node* head, int value);
Node* append(Node* head, int value);
Node* insertAt(Node* head, int value, int index);
Node* shift(Node* head);
Node* pop(Node* head);
Node* removeAt(Node* head, int index);
Node* removeByVal(Node* head, int value);
int find(Node* head, int value);
int exists(Node* head, int value);
int count(Node* node);
int isEmpty(Node* head);
int hasNext(Node* node);
void print(Node* head);
#endif
