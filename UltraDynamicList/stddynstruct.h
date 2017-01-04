#ifndef STDDYNSTRUCTH
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STDDYNSTRUCTH
#define FIELD_NAME_SIZE 32
#define SIZE_ARR(x) (sizeof(x) / sizeof((x)[0]))

typedef enum _DynStructTypeID {
	T_NULL,
	T_CHAR,
	T_U_CHAR,
	T_S_CHAR,
	T_INT,
	T_U_INT,
	T_SHORT,
	T_U_SHORT,
	T_LONG,
	T_U_LONG,
	T_FLOAT,
	T_DOUBLE,
	T_L_DOUBLE,
	T_STRING,
	T_STRUCT
} DynStructTypeID;

typedef struct _DynStructFieldType {
	int id;
	char* name;
} DynStructFieldType;

struct DynStructVar;

typedef struct _DynStruct {
	char* name;
	int length;
	struct DynStructVar* array;
} DynStruct;

typedef struct _DynStructString {
	char* value;
	int length;
} DynStructString;

typedef struct DynStructVar {
	DynStructFieldType type;
	char* name;
	union _Data {
		long integer;
		long double decimal;
		DynStructString* str;
		DynStruct* ptr;
	} data;
	int primaryKey;
} DynStructVar;

DynStruct* createDynamicStruct();
DynStruct* createDynamicStructInstance(DynStruct*, int);
DynStruct* createDynamicStructElement(DynStruct*);
DynStruct* createDynamicStructSearchModel(DynStruct*);
int isEquals(void*, void*);
void printDynamicStruct(DynStruct*);
DynStructFieldType getType(int);
int hasPrimaryKey(DynStruct*);
#endif