#include "stdutils.h"

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

int cscanf(const char *format, ...)
{
	int count;
	va_list ap;
	va_start(ap, format);
	count = vfscanf(stdin, format, ap);
	va_end(ap);
	pflush();
	return count;
}
