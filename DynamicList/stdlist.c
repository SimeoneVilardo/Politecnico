#include "stdlist.h"
#define NOT_FOUND -1

/********************************************************************************
* Funzioni standard (dichiarazione)
*
* Queste sono le implementazioni standard per i tipi più comuni, ulteriori
* implementazioni per gli stessi tipo, o nuove implementazioni per nuovi tipi
* possono essere realizzate rispettando il prototype della funzione.
*/

int compareInts(void* num1, void* num2);
int compareStrings(void* str1, void* str2);
void printInts(Node* node);
void printStrings(Node* node);

/******************************************************************************/

Node* create() {
	return NULL;
}

void destroy(Node** headRef)
{
	int length = count(*headRef);
	for (int i = 0; i < length; i++)
		shift(headRef);
	headRef = NULL;
}

void append(Node** headRef, void* value) {
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

void prepend(Node** headRef, void* value) {
	Node* newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = *headRef;
	*headRef = newNode;
}

void insertAt(Node** headRef, void* value, int index) {
	if (index == 0)
		prepend(headRef, value);
	else if (index >= count(*headRef))
		append(headRef, value);
	else {
		Node* currentNode = *headRef;
		for (int i = 0; i < index - 1; i++)
			currentNode = currentNode->next;
		Node* tempNode = currentNode->next;
		Node* newNode = malloc(sizeof(Node));
		newNode->value = value;
		newNode->next = tempNode;
		currentNode->next = newNode;
	}
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

void removeByVal(Node** headRef, void* value, fnCompare compareFunc)
{
	int index = find(*headRef, value, compareFunc);
	if (index != NOT_FOUND)
		removeAt(headRef, index);
}

void removeByValDefault(Node** headRef, void* value, Type type)
{
	switch (type)
	{
	case Integer:
		removeByVal(headRef, value, compareInts);
		break;
	case String:
		removeByVal(headRef, value, compareStrings);
		break;
	}
}

void* getElement(Node* head, int index) {
	for (int i = 0; i < index && !isEmpty(head); i++)
		head = head->next;
	return head->value;
}

Node* getNode(Node * head, int index)
{
	for (int i = 0; i < index && !isEmpty(head); i++)
		head = head->next;
	return head;
}

int find(Node* head, void* value, fnCompare compareFunc) {
	int index = 0;
	while (!isEmpty(head))
	{
		if (compareFunc(head->value, value))
			return index;
		head = head->next;
		index++;
	}
	return NOT_FOUND;
}

int findDefault(Node* head, void* value, Type type)
{
	switch (type)
	{
	case Integer:
		return find(head, value, compareInts);
	case String:
		return find(head, value, compareStrings);
	}
}

int exists(Node* head, void* value, fnCompare compareFunc) {
	return find(head, value, compareFunc) != NOT_FOUND;
}

int existsDefault(Node* head, void* value, Type type) {
	switch (type)
	{
	case Integer:
		return find(head, value, compareInts) != NULL;
	case String:
		return find(head, value, compareStrings) != NULL;
	}
}

void print(Node* head, fnPrint printFunc) {
	while (!isEmpty(head))
	{
		printFunc(head);
		head = head->next;
	}
}

void printDefault(Node* head, Type type)
{
	switch (type)
	{
	case Integer:
		print(head, printInts);
		break;
	case String:
		print(head, printStrings);
		break;
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

/********************************************************************************
* Funzioni standard (implementazione)
*/

int compareInts(void* num1, void* num2) {
	return *(int*)num1 == *(int*)num2;
}

int compareStrings(void* str1, void* str2) {
	return strcmp((char*)str1, (char*)str2) == 0;
}

void printInts(Node* node) {
	printf("%d  ", node->value);
}

void printStrings(Node* node) {
	printf("%s  ", node->value);
}

/******************************************************************************/