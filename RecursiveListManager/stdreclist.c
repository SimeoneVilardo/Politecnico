#include "stdreclist.h"

Node* create() {
	return NULL;
}

Node* prepend(Node* head, int value) {
	Node* newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = head;
	return newNode;
}

Node* append(Node* head, int value) {
	if (isEmpty(head)) {
		Node* newNode = malloc(sizeof(Node));
		newNode->next = NULL;
		newNode->value = value;
		return newNode;
	}
	else
	{
		head->next = append(head->next, value);
		return head;
	}
}

Node* insertAt(Node* head, int value, int pos) {
	if (pos <= 1 || isEmpty(head))
		return prepend(head, value);
	if (pos >= count(head) + 1)
		return append(head, value);
	if (pos > 1 && pos < count(head) + 1)
	{
		head->next = insertAt(head->next, value, pos - 1);
		return head;
	}
}

Node* shift(Node* head) {
	if (isEmpty(head))
		return NULL;
	Node* returnNode = head->next;
	free(head);
	return returnNode;
}

Node* pop(Node* head) {
	if (!hasNext(head)) {
		free(head);
		return NULL;
	}		
	else {
		head->next = pop(head->next);
		return head;
	}
}

Node* removeAt(Node* head, int pos) {
	if (pos <= 1 || isEmpty(head))
		return shift(head);
	if (pos > count(head) + 1)
		return pop(head);
	if (pos > 1 && pos < count(head) + 1)
	{
		head->next = removeAt(head->next, pos - 1);
		return head;
	}
}

int find(Node* head, int value)
{
	if (isEmpty(head))
		return 0;
	if (head->value == value)
		return 1;
	return 1 + find(head->next, value);
}

int exists(Node* head, int value)
{
	if (isEmpty(head))
		return 0;
	if (head->value == value)
		return 1;
	return exists(head->next, value);
}

int isEmpty(Node* node) {
	return node == NULL;
}

int hasNext(Node* node) {
	return (!isEmpty(node)) && (node->next != NULL);
}

int count(Node* head) {
	if (isEmpty(head))
		return 0;
	return 1 + count(head->next);
}