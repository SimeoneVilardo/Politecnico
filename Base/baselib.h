#ifndef BASELIB_H
#define BASELIB_H
#include <string.h>
#include <math.h>
#include <ctype.h>

char* convertFromBaseToBase(char*, int, int);
int convertToBaseTen(int*, int, int);
char* convertFromBaseTen(int, int, int);
int* convertStringToIntArr(char*, int);
int* convertIntToArray(int, int, int);
#endif
