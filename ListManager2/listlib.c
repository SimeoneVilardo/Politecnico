#include "listlib.h"
#define NOT_FOUND -1

Node* create() {
	return NULL;
}

void append(Node** headRef, int value) {
	Node* newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	if (isEmpty(*headRef))
		*headRef = newNode;
	else {
		Node* currentNode = *headRef;
		while (hasNext(currentNode))
			currentNode = currentNode->next;
		currentNode->next = newNode;
	}
}

void prepend(Node** headRef, int value) {
	Node* newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = *headRef;
	*headRef = newNode;
}

void insertAt(Node** headRef, int value, int index) {
	if (index == 0)
		prepend(headRef, value);
	if (index >= count(*headRef))
		append(headRef, value);
	Node* currentNode = *headRef;
	for (int i = 0; i < index - 1; i++)
		currentNode = currentNode->next;
	Node* tempNode = currentNode->next;
	Node* newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = tempNode;
	currentNode->next = newNode;
}

void shift(Node** headRef) {
	if (!isEmpty(*headRef)) {
		Node* tmpNode = *headRef;
		*headRef = tmpNode->next;
		free(tmpNode);
	}
}

void pop(Node** headRef) {
	if (!isEmpty(*headRef)) {
		Node* currentNode = *headRef;
		while (hasNext(currentNode->next))
			currentNode = currentNode->next;
		Node* tmpNode = currentNode->next;
		currentNode->next = NULL;
		free(tmpNode);
	}
}

void removeAt(Node** headRef, int index) {
	if (index == 0)
		shift(headRef);
	if (index >= count(*headRef))
		pop(headRef);
	Node* currentNode = *headRef;
	for (int i = 0; i < index - 1; i++)
		currentNode = currentNode->next;
	Node* tmpNode = currentNode->next;
	currentNode->next = currentNode->next->next;
	free(tmpNode);
}

void removeByVal(Node** headRef, int value)
{
	int index = find(*headRef, value);
	if (index != NOT_FOUND)
		removeAt(headRef, index);
}

int find(Node* head, int value) {
	int index = 0;
	while (!isEmpty(head))
	{
		if (head->value == value)
			return index;
		head = head->next;
		index++;
	}
	return NOT_FOUND;
}

int exists(Node* head, int value) {
	return find(head, value) != NOT_FOUND;
}

void print(Node* head) {
	while (!isEmpty(head))
	{
		printf("%d  ", head->value);
		head = head->next;
	}
}

int isEmpty(Node* head) {
	return head == NULL;
}

int hasNext(Node* node) {
	return node->next != NULL;
}

int count(Node* head) {
	int index = 0;
	while (!isEmpty(head))
	{
		head = head->next;
		index++;
	}
	return index;
}