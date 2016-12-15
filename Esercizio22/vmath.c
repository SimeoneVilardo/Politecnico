#include "vmath.h"

int mcd(int a, int b) {
	return !b ? a : mcd(b, a%b);
}

int pow(int base, int exp) {
	return !exp ? 1 : base*pow(base, exp - 1);
}