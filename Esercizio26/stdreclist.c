#include "stdreclist.h"

Node* create() {
	return NULL;
}

Node* insertItem(Node* head, Item value) {
	Node* oldNode = getNode(head, value.name);
	if (!oldNode) 
		return append(head, value);
	oldNode->value.qty += value.price;
	return head;	
}

Node* append(Node* head, Item value) {
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

Node* removeItem(Node* head) {
	if (!hasNext(head)) {
		free(head);
		return NULL;
	}
	else {
		head->next = removeItem(head->next);
		return head;
	}
}

Node* getNode(Node* head, String name)
{
	if (isEmpty(head))
		return NULL;
	if (strcmp(head->value.name, name) == 0)
		return head;
	return getNode(head->next, name);
}


int exists(Node* head, String name)
{
	if (isEmpty(head))
		return 0;
	if (strcmp(head->value.name, name) == 0)
		return 1;
	return exists(head->next, name);
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

void print(Node* head) {
	if (isEmpty(head))
		return;
	printf("Nome: %s\nQuantita': %d\nPrezzo: %f\n", head->value.name, head->value.qty, head->value.price);
	print(head->next);
}

void save(Node* head, const char* path) {
	FILE* file = fopen(path, "w+");
	int size = count(head);
	float tot = calculateTotPrice(head);
	for (int i = 0; i < size; i++) {
		fprintf(file, "Nome: %-15s\tQuantita': %-2d\tPrezzo: %-6.2f\n", head->value.name, head->value.qty, head->value.price);
		head = head->next;
	}
	fprintf(file, "\nTotale spesa: %-6.2f", tot);
	fclose(file);
}

float calculateTotPrice(Node* head) {
	if (isEmpty(head))
		return 0;
	return (head->value.price * head->value.qty) + calculateTotPrice(head->next);
}