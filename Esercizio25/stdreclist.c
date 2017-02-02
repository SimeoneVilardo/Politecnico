#include "stdreclist.h"

Node* create() {
	return NULL;
}

Node* prepend(Node* head, Volo value) {
	Node* newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = head;
	return newNode;
}

Node* append(Node* head, Volo value) {
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

Node* insertAt(Node* head, Volo value, int pos) {
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

int find(Node* head, int id)
{
	if (isEmpty(head))
		return 0;
	if (head->value.id == id)
		return 1;
	return 1 + find(head->next, id);
}

int exists(Node* head, int id)
{
	if (isEmpty(head))
		return 0;
	if (head->value.id == id)
		return 1;
	return exists(head->next, id);
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
	printf("\nID: %d\nDestinazione: %s\nOrario partenza previsto: %02d:%02d\nOrario partenza effettivo: %02d:%02d\nNumero passeggeri: %d\n", head->value.id, head->value.dest, head->value.scheduledDep.hours, head->value.scheduledDep.minutes, head->value.actualDep.hours, head->value.actualDep.minutes, head->value.passenger);
	print(head->next);
}

void save(Node* head, const char* path) {
	FILE* file = fopen(path, "wb");
	int size = count(head);
	for (int i = 0; i < size; i++) {
		fwrite(&head->value, sizeof(Volo), 1, file);
		head = head->next;
	}
	fclose(file);
}

Node* load(const char* path) {
	FILE* file = fopen(path, "rb");
	if (file == NULL)
		return NULL;
	Node* head = create();
	Volo* tmpVolo = malloc(sizeof(Volo));
	int read;
	while (read = fread(tmpVolo, sizeof(Volo), 1, file))
		head = append(head, *tmpVolo);
	free(tmpVolo);
	return head;
}