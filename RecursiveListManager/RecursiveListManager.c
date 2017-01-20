#include <stdio.h>
#include "stdreclist.h"

int main() {
	Node* head = create();
	head = prepend(head, 2);
	head = prepend(head, 4);
	head = prepend(head, 6);
	head = append(head, 10);
	head = append(head, 20);
	head = append(head, 30);
	head = insertAt(head, 100, 4);
	head = insertAt(head, 200, 20);
	head = insertAt(head, 300, 0);
	head = shift(head);
	head = pop(head);
	head = removeAt(head, 4);
	return 0;
}