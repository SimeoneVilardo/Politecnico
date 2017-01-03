#include "stdutils.h"

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}