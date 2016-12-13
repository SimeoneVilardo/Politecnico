#include <stdio.h>
#include <math.h>

typedef struct Node
{
	int value;
	struct Node * next;
} Node;

Node* getKaprekarNumbers(int, int);
int countDigits(int);
int* convertIntToArray(int, int);
int concatenateInts(int, int);
Node* create();
void insert(Node*, int);
void print(Node*);
void pflush();

int main() {
	printf("************************\n");
	printf("*** Kaprekar Numbers ***\n");
	printf("************************\n");
	int start, end;
	printf("Inserisci il range di numeri (inclusivo) in cui cercare i numeri di Kaprekar ner formato [a-b]: ");
	scanf("%d-%d", &start, &end);
	Node* root = getKaprekarNumbers(start, end);
	print(root);
	printf("Premi INVIO per terminare\n");
	pflush();
	getchar();
	return 0;
}

Node* getKaprekarNumbers(int start, int end) {
	Node* root = create();
	int numPow, count;
	int* numPowArr;
	for (int i = start; i <= end; i++) {
		if(i==1)
			insert(root, i);
		numPow = pow(i, 2);
		count = countDigits(numPow);
		numPowArr = convertIntToArray(numPow, count);
		for (int j = 0; j < count-1; j++) {
			int num1 = 0, num2 = 0;
			int sizeNum1 = j + 1;
			int sizeNum2 = count - 1 - j;
			if (!sizeNum2) continue;
			for (int iNum1 = 0; iNum1 < sizeNum1; iNum1++) 
				num1 = concatenateInts(num1, numPowArr[iNum1]);
			for (int iNum2 = sizeNum1; iNum2 < count; iNum2++) 
				num2 = concatenateInts(num2, numPowArr[iNum2]);
			if (num1 != 0 && num2!= 0 && num1 + num2 == i)
				insert(root, i);
		}
	}
	return root;
}

int countDigits(int num) {
	int c = 1;
	while (num /= 10) c++;
	return c;
}

int* convertIntToArray(int num, int len) {
	if (!len)
		len = countDigits(num);
	int* arr = (int*)malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++)
		arr[len - 1 - i] = (num / (int)pow(10, i)) % 10;
	return arr;
}

int concatenateInts(int num1, int num2) {
	int base = 10;
	while (num2 >= base)
		base *= 10;
	return num1 * base + num2;
}

Node* create() {
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = 0;
	root->next = NULL;
	return root;
}

void insert(Node* root, int value) {
	Node* currentNode = root;
	while (currentNode->next != NULL)
		currentNode = currentNode->next;
	currentNode->next = (Node*)malloc(sizeof(Node));
	currentNode->next->value = value;
	currentNode->next->next = NULL;
}

void print(Node* root) {
	Node* currentNode = root->next;
	for (int i = 0; currentNode != NULL; i++) {
		printf("Posizione: %d\tValore: %d\n", i, currentNode->value);
		currentNode = currentNode->next;
	}
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}