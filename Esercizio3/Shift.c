#include <stdio.h>
int main() {
	int a, b, c, temp;
	printf("Inserire il valore di a: ");
	scanf("%d", &a);
	printf("Inserire il valore di b: ");
	scanf("%d", &b);
	printf("Inserire il valore di c: ");
	scanf("%d", &c);
	temp = a;
	a = c;
	c = b;
	b = temp;
	printf("Il valore di a e': %d\n", a);
	printf("Il valore di b e': %d\n", b);
	printf("Il valore di c e': %d\n", c);
	return 0;
	}