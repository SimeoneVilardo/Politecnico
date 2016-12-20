#include "baselib.h"
#define ASCII_OFFSET 39
#define DEF_BASE 10

int countDigits(int, int);

char* convertFromBaseToBase(char* numStr, int inputBase, int outputBase)
{
	int sizeStr = strlen(numStr);
	int* numArr = convertStringToIntArr(numStr, sizeStr);
	int numTen = convertToBaseTen(numArr, sizeStr, inputBase);
	int sizNumOutputStr = countDigits(outputBase, numTen) + 1;
	char* numOutputStr = convertFromBaseTen(numTen, sizNumOutputStr, outputBase);
	return numOutputStr;
}

int* convertStringToIntArr(char* num, int size) {
	int* arr = malloc(sizeof(int)*size);
	char dig = 0;
	for (int i = 0; i < size; i++) {
		dig = tolower(num[i])-'0';
		arr[i] = dig >= 0 && dig < 10 ? dig : dig - ASCII_OFFSET;
	}		
	return arr;
}

int convertToBaseTen(int* num, int size, int base)
{
	int numBaseTen = 0;
	for (int i = 0; i < size; i++)
		numBaseTen += num[i] * pow(base, size-i-1);
	return numBaseTen;
}

char* convertFromBaseTen(int num, int size, int base)
{
	char* numOutput = malloc(size);
	int index = 0;
	char dig = 0;
	for (int i = size-2; num!=0; i--) {
		dig = num % base + '0';
		num = num / base;
		numOutput[i] = toupper(((dig >= '0' && dig <= '9') || (dig >= 'a' && dig <= 'f')) ? dig : dig + ASCII_OFFSET);
	}
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
	return (int)(log(num) / log(base)) + 1;
}