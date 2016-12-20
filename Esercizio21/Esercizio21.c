#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef int(*OpFn)(int, int);
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int muliply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }
int mod(int a, int b) { return a % b; }
int clcPxExp(char*, OpFn[]);

int main() {
	OpFn ops[256];
	ops['+'] = &add;
	ops['-'] = &subtract;
	ops['*'] = &muliply;
	ops['/'] = &divide;
	ops['%'] = &mod;
	char expression[256];
	printf("Inserire l'espressione in notazione prefissa: ");
	gets(expression);
	printf("Il risultato e': %d", clcPxExp(expression, ops));
	getchar();
	return 0;
}

int clcPxExp(char* exp, OpFn ops[]) {
	char ch = exp[0];
	memmove(exp, exp + 1, strlen(exp));
	if (ch == ' ') return clcPxExp(exp, ops);
	if (isdigit(ch)) return ch - '0';
	return ops[ch](clcPxExp(exp, ops), clcPxExp(exp, ops));
}