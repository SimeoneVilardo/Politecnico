#ifndef STDRECLIST
#define STDRECLIST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEST_LEN 3
#define STR_DEST_LEN (DEST_LEN + 1)

typedef char* String;

typedef struct _item {
	String name;
	float price;
	int qty;	
} Item;

typedef struct Node
{
	Item value;
	struct Node* next;
} Node;

Node* create();
Node* append(Node* head, Item value);
Node* insertItem(Node* head, Item value);
Node* removeItem(Node* head);
int isEmpty(Node* node);
int hasNext(Node* node);
Node* getNode(Node* head, String name);
int exists(Node* head, String name);
int count(Node* head);
void print(Node* head);
void save(Node* head, const char* path);
float calculateTotPrice(Node* head);
#endif