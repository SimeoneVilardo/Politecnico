#ifndef STDLISTH
#define STDLISTH
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node { void* value; struct Node* next; } Node;
typedef int(*fnCompare)(void*, void*);
typedef void(*fnPrint)(Node* node);
typedef enum Type { Integer, String } Type;

Node* create();
void destroy(Node** headRef);
void prepend(Node** headRef, void* value);
void append(Node** headRef, void* value);
void insertAt(Node** headRef, void* value, int index);
void shift(Node** headRef);
void pop(Node** headRef);
void removeAt(Node** headRef, int index);
void removeByVal(Node** headRef, void* value, fnCompare compareFunc);
void removeByValDefault(Node** headRef, void* value, Type type);
void* getElement(Node* head, int index);
Node* getNode(Node* head, int index);
int find(Node* head, void* value, fnCompare compareFunc);
int findDefault(Node* head, void* value, Type type);
int exists(Node* head, void* value, fnCompare compareFunc);
int existsDefault(Node* head, void* value, Type type);
int count(Node* node);
int isEmpty(Node* head);
int hasNext(Node* node);
void print(Node* head, fnPrint printFunc);
void printDefault(Node* head, Type type);
#endif