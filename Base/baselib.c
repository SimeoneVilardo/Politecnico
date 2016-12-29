#include "baselib.h"
#define ASCII_OFFSET 39
#define DEF_BASE 10
#define MINUS '-'
#define MINUS_STR "-"

int countDigits(int, int);
void prepend(char*, const char*);

char* convertFromBaseToBase(char* numStr, int inputBase, int outputBase)
{
	int minus = 0;
	numStr = (minus = numStr[0] == MINUS) ? numStr + 1 : numStr;
	int sizeStr = strlen(numStr);
	int* numArr = convertStringToIntArr(numStr, sizeStr);
	int numTen = convertToBaseTen(numArr, sizeStr, inputBase);
	int sizNumOutputStr = countDigits(outputBase, numTen) + 1;
	char* numOutputStr = convertFromBaseTen(numTen, sizNumOutputStr, outputBase);
	if (minus) prepend(numOutputStr, MINUS_STR);
	return numOutputStr;
}

int* convertStringToIntArr(char* num, int size) {
	int* arr = malloc(sizeof(int)*size);
	char dig = 0;
	for (int i = 0; i < size; i++) {
		dig = tolower(num[i]) - '0';
		arr[i] = dig >= 0 && dig < 10 ? dig : dig - ASCII_OFFSET;
	}
	return arr;
}

int convertToBaseTen(int* num, int size, int base)
{
	int numBaseTen = 0;
	for (int i = 0; i < size; i++) {
		if (num[i] >= base) return 0;
		numBaseTen += num[i] * pow(base, size - i - 1);
	}
	return numBaseTen;
}

char* convertFromBaseTen(int num, int size, int base)
{
	char* numOutput = malloc(size);
	int index = size - 2;
	char dig = 0;
	do {
		dig = num % base + '0';
		num = num / base;
		numOutput[index] = toupper(((dig >= '0' && dig <= '9') || (dig >= 'a' && dig <= 'z')) ? dig : dig + ASCII_OFFSET);
		index--;
	} while (num != 0);
	numOutput[size - 1] = '\0';
	return numOutput;
}

int* convertIntToArray(int num, int base, int size) {
	int* arr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		arr[size - 1 - i] = (num / (int)pow(base, i)) % base;
	return arr;
}

int countDigits(int base, int num) {
	return (num != 0 ? (int)(log(abs(num)) / log(base)) : 0) + 1;
}

void prepend(char* s, const char* t)
{
	size_t len_t = strlen(t);
	size_t len_s = strlen(s);
	s = realloc(s, len_s + 2 * sizeof(char));
	memmove(s + len_t, s, len_s + 1);
	for (size_t i = 0; i < len_t; i++)
		s[i] = t[i];
}