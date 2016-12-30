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
void prepend(Node** headRef, int value);
void append(Node** headRef, int value);
void insertAt(Node** headRef, int value, int index);
void shift(Node** headRef);
void pop(Node** headRef);
void removeAt(Node** headRef, int index);
void removeByVal(Node** headRef, int value);
int find(Node* head, int value);
int exists(Node* head, int value);
int count(Node* node);
int isEmpty(Node* head);
int hasNext(Node* node);
void print(Node* head);
#endif