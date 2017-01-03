#include "stddybstruct.h"
#include "stdutils.h"
#define YES 's'

const DynStructFieldType types[] = {
	{ T_CHAR, "char" },
	{ T_U_CHAR, "unsigned char" },
	{ T_S_CHAR, "signed char" },
	{ T_INT, "int" },
	{ T_U_INT, "unsigned int" },
	{ T_SHORT, "short" },
	{ T_U_SHORT, "unsigned short" },
	{ T_LONG, "long" },
	{ T_U_LONG, "unsigned long" },
	{ T_FLOAT, "float" },
	{ T_DOUBLE, "double" },
	{ T_L_DOUBLE, "long double" },
	{ T_STRING, "String" },
	{ T_STRUCT, "Struct" }
};

DynStruct* createDynamicStructElement(DynStruct* dynStruct) {
	createDynamicStructInstance(dynStruct, 0);
}

DynStruct* createDynamicStructSearchModel(DynStruct* dynStruct) {
	createDynamicStructInstance(dynStruct, 1);
}

DynStruct* createDynamicStructInstance(DynStruct* dynStruct, int searchModel) {
	DynStruct *newDynStruct = malloc(sizeof(DynStruct));
	newDynStruct->name = malloc(FIELD_NAME_SIZE);
	newDynStruct->name = dynStruct->name;
	newDynStruct->length = dynStruct->length;
	newDynStruct->array = malloc(dynStruct->length * sizeof(DynStructVar));
	int checkPK = hasPrimaryKey(dynStruct) && searchModel;
	for (int i = 0; i < dynStruct->length; i++) {
		if (checkPK && !dynStruct->array[i].primaryKey)
			continue;
		newDynStruct->array[i].name = malloc(FIELD_NAME_SIZE);
		newDynStruct->array[i].name = dynStruct->array[i].name;
		newDynStruct->array[i].type = dynStruct->array[i].type;
		newDynStruct->array[i].primaryKey = dynStruct->array[i].primaryKey;
		printf("Inserisci il valore di %s: ", dynStruct->array[i].name);
		switch (dynStruct->array[i].type.id)
		{
		case T_CHAR:
		case T_S_CHAR:
			cscanf("%c", &newDynStruct->array[i].data.integer);
			break;
		case T_U_CHAR:
			cscanf("%hhu", &newDynStruct->array[i].data.integer);
			break;
		case T_INT:
		case T_U_INT:
		case T_SHORT:
		case T_U_SHORT:
		case T_LONG:
		case T_U_LONG:
			printf("Inserisci il valore di %s: ", dynStruct->array[i].name);
			cscanf("%d", &newDynStruct->array[i].data.integer);
			break;
		case T_FLOAT:
			printf("Inserisci il valore di %s: ", dynStruct->array[i].name);
			cscanf("%f", &newDynStruct->array[i].data.decimal);
			break;
		case T_DOUBLE:
			printf("Inserisci il valore di %s: ", dynStruct->array[i].name);
			cscanf("%lf", &newDynStruct->array[i].data.decimal);
			break;
		case T_L_DOUBLE:
			printf("Inserisci il valore di %s: ", dynStruct->array[i].name);
			cscanf("%Lf", &newDynStruct->array[i].data.decimal);
			break;
		case T_STRING:
			printf("Inserisci il valore di %s: ", dynStruct->array[i].name);
			newDynStruct->array[i].data.str = malloc(sizeof(DynStructString));
			newDynStruct->array[i].data.str->length = dynStruct->array[i].data.str->length;
			newDynStruct->array[i].data.str->value = malloc(dynStruct->array[i].data.str->length);
			cscanf("%s", newDynStruct->array[i].data.str->value);
			break;
		case T_STRUCT:
			newDynStruct->array[i].data.ptr = createDynamicStructElement(dynStruct->array[i].data.ptr);
			break;
		default:
			break;
		}
	}
	return newDynStruct;
}

DynStruct* createDynamicStruct() {
	DynStruct *dynStruct = calloc(1, sizeof(DynStruct));
	printf("Creazione della struct\n\n");
	printf("Definire il nome della struct: ");
	dynStruct->name = calloc(FIELD_NAME_SIZE, sizeof(char));
	cscanf("%s", dynStruct->name);
	printf("Definire il numero delle proprieta' della struct: ");
	cscanf("%d", &dynStruct->length);
	dynStruct->array = calloc(dynStruct->length, sizeof(DynStructVar));
	for (int i = 0; i < dynStruct->length; i++) {
		printf("Generazione del campo numero %d\n", i + 1);
		printf("Definire il tipo del campo:\n");
		for (int i = 0; i < SIZE_ARR(types); i++)
			printf(" %d)  %s\n", types[i].id, types[i].name);
		printf("Tipo numero: ");
		int fieldType;
		cscanf("%d", &fieldType);
		printf("Definire il nome del campo: ");
		dynStruct->array[i].name = calloc(FIELD_NAME_SIZE, sizeof(char));
		cscanf("%s", dynStruct->array[i].name);
		dynStruct->array[i].type = getType(fieldType);
		if (dynStruct->array[i].type.id == T_STRING) {
			printf("Definire la grandezza della stringa: ");		
			dynStruct->array[i].data.str = calloc(1, sizeof(DynStructString));
			cscanf("%d", &dynStruct->array[i].data.str->length);
			dynStruct->array[i].data.str->value = calloc(dynStruct->array[i].data.str->length, sizeof(char));
		}
		else if (dynStruct->array[i].type.id == T_STRUCT) {
			dynStruct->array[i].data.ptr = createDynamicStruct();
		}
		printf("Impostare il campo %s come chiave primaria? [s/n] ", dynStruct->array[i].name);
		char primaryKeyChar = getchar();
		dynStruct->array[i].primaryKey = primaryKeyChar == YES;
	}
	return dynStruct;
}

DynStructFieldType getType(int typeID) {
	for (int i = 0; i < SIZE_ARR(types); i++)
		if (typeID == types[i].id)
			return types[i];
	return (DynStructFieldType) { T_NULL, NULL };
}

int hasPrimaryKey(DynStruct* dynStruct) {
	for (int i = 0; i < dynStruct->length; i++)
		if (dynStruct->array[i].primaryKey)
			return 1;
	return 0;
}