#include "stdstring.h"

String initString(int size)
{
	return malloc(sizeof(char) * size);
}
