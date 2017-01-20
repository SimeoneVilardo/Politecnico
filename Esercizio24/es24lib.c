#include "es24lib.h"
#define NOT_FOUND -1

Node* create() {
	return NULL;
}

Node* append(Node* head, int value) {
	Node* newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	if (isEmpty(head))
		return newNode;
	Node* currentNode = head;
	while (hasNext(currentNode))
		currentNode = currentNode->next;
	currentNode->next = newNode;
	return head;
}

Node* prepend(Node* head, int value) {
	Node* newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = head;
	return newNode;
}

Node* insertAt(Node* head, int value, int index) {
	if (index == 0)
		return prepend(head, value);
	if (index >= count(head))
		return append(head, value);
	Node* currentNode = head;
	for (int i = 0; i < index - 1; i++)
		currentNode = currentNode->next;
	Node* tempNode = currentNode->next;
	Node* newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = tempNode;
	currentNode->next = newNode;
	return head;
}

Node* shift(Node* head) {
	if (isEmpty(head))
		return head;
	Node* tmpNode = head;
	head = tmpNode->next;
	free(tmpNode);
	return head;
}

Node* pop(Node* head) {
	if (isEmpty(head))
		return head;
	Node* currentNode = head;
	while (hasNext(currentNode->next))
		currentNode = currentNode->next;
	Node* tmpNode = currentNode->next;
	currentNode->next = NULL;
	free(tmpNode);
	return head;
}

Node* removeAt(Node* head, int index) {
	if (index == 0)
		return shift(head);
	if (index >= count(head))
		return pop(head);
	Node* currentNode = head;
	for (int i = 0; i < index - 1; i++)
		currentNode = currentNode->next;
	Node* tmpNode = currentNode->next;
	currentNode->next = currentNode->next->next;
	free(tmpNode);
	return head;
}

Node* removeByVal(Node * head, int value)
{
	int index = find(head, value);
	if (index == NOT_FOUND)
		return head;
	return removeAt(head, index);
}

Node* getElement(Node* head, int index) {
	for (int i = 0; i < index && !isEmpty(head); i++)
		head = head->next;
	return head;
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

int countElement(Node* head, int value) {
	int index = 0;
	while (!isEmpty(head))
	{
		if (head->value == value)
			index++;
		head = head->next;
	}
	return index;
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


Node* removeReps(Node* head) {
	if (isEmpty(head))
		return head;
	Node* currentNode = head;
	while (hasNext(currentNode)) {
		int currentVal = currentNode->value;
		int originalCount = countElement(head, currentVal);
		while(countElement(head, currentVal) > 1)
			head = removeByVal(head, currentVal);
		if(originalCount > 1)
			currentNode = head;
		else
			currentNode = currentNode->next;
	}
	return head;
}

Node* sumList(Node* head) {
	if (isEmpty(head))
		return head;
	Node* currentNode = head;
	while (!isEmpty(currentNode)) {
		Node* currentSumNode = currentNode;
		while (hasNext(currentSumNode)) {
			currentNode->value += currentSumNode->next->value;
			currentSumNode = currentSumNode->next;
		}
		currentNode = currentNode->next;
	}
	return head;
}