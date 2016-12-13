/**************************************************************************************************************************************************************************************
*	RULES:                                                                                                                                                                            *
*	You have to start with either with a white or a red wire.                                                                                                                         *
*	If you picked white wire you can either pick another white wire again or you can take an orange one.                                                                              *
*	If you picked a red wire you have the choice between a black and red wire.                                                                                                        *
*	When a second red wire is picked, you can start from rule one again.                                                                                                              *
*	Back to the second rule, if you picked another white one you will have to pick a black or red one now.                                                                            *
*	When the red wire is picked, you again go to rule one.                                                                                                                            *
*	On the other hand if you then picked an orange wire, you can choose between green, orange and black.                                                                              *
*	When you are at the point where you can choose between green, orange and black and you pick either green or orange you have to choose the other one and then the bomb is defused. *
*	If you ever pick a black wire you will be at the point where you have to choose between green, orange and black                                                                   *
**************************************************************************************************************************************************************************************/

#include <stdio.h>
#include <string.h>
#define WIRE_STR_LEN 16
#define WIRES_MAX_NUM 32
#define POSITIONS 6
#define MAX_RULE_POSITIONS 3
#define STR_LEN (WIRE_STR_LEN * WIRES_MAX_NUM)
#define DELIMITER " "
#define DELIMITER_CHAR (DELIMITER[0])
#define SIZE_ARR(arr) (sizeof(arr) / sizeof((arr)[0]))
#define UNDEFINED -1
#define UNDEFINED_STR "undefined"
#define RULE_POSITION_UNDEFINED { POS_UNDEFINED, VAL_UNDEFINED }

typedef struct {
	char** values;
	int size;
} *Array;

typedef enum {
	EXPLODED = 0,
	DEFUSED = 1,
	INVALID = UNDEFINED
} BOMB_STATUS;

typedef enum {
	VAL_WHITE = 1 << 1,
	VAL_BLACK = 1 << 2,
	VAL_RED = 1 << 3,
	VAL_ORANGE = 1 << 4,
	VAL_GREEN = 1 << 5,
	VAL_UNDEFINED = UNDEFINED
} COLOR;

typedef enum {
	POS_0,
	POS_1,
	POS_2,
	POS_3,
	POS_4,
	POS_5,
	POS_DEFUSE,
	POS_UNDEFINED = UNDEFINED
} POSITION;

typedef enum {
	RUL_POS_0 = VAL_RED,
	RUL_POS_1 = VAL_WHITE,
	RUL_POS_2 = VAL_RED | VAL_WHITE,
	RUL_POS_3 = VAL_BLACK | VAL_ORANGE,
	RUL_POS_4 = VAL_ORANGE,
	RUL_POS_5 = VAL_GREEN,
	RUL_POS_DEFUSE = VAL_GREEN | VAL_ORANGE,
	RUL_POS_UNDEFINED = UNDEFINED
} RULE_POS;

typedef enum {
	RUL_CUT_0 = VAL_WHITE | VAL_RED,
	RUL_CUT_1 = VAL_WHITE | VAL_ORANGE,
	RUL_CUT_2 = VAL_RED | VAL_BLACK,
	RUL_CUT_3 = VAL_BLACK | VAL_GREEN | VAL_ORANGE,
	RUL_CUT_4 = VAL_GREEN,
	RUL_CUT_5 = VAL_ORANGE,
	RUL_CUT_UNDEFINED = UNDEFINED
} RULE_CUT;

typedef struct {
	POSITION pos;
	RULE_POS rule;
} RulePosition;

typedef struct {
	RulePosition rulePos[MAX_RULE_POSITIONS];
	RULE_CUT ruleCut;
} Rule;

typedef struct {
	char* name;
	COLOR value;
} Wire;

BOMB_STATUS defuse(Wire*, int);
POSITION getNextPos(int, int);
Wire getWireByName(char*, int);
Array getColorsNames(char*);
int countChars(char*, char);

Wire bomb[] = {
	{ "bianco",    VAL_WHITE },
	{ "nero",      VAL_BLACK },
	{ "rosso",     VAL_RED },
	{ "arancione", VAL_ORANGE },
	{ "verde",     VAL_GREEN }
};
Rule positions[POSITIONS] = {
	{{{ POS_1, VAL_WHITE },       { POS_2, VAL_RED },      RULE_POSITION_UNDEFINED }, RUL_CUT_0 },
	{{{ POS_2, VAL_WHITE },       { POS_3, VAL_ORANGE },   RULE_POSITION_UNDEFINED }, RUL_CUT_1 },
	{{{ POS_0, VAL_RED },         { POS_3, VAL_BLACK },    RULE_POSITION_UNDEFINED }, RUL_CUT_2 },
	{{{ POS_3, VAL_BLACK },       { POS_4, VAL_ORANGE },   { POS_5, VAL_GREEN }},     RUL_CUT_3 },
	{{{ POS_DEFUSE, VAL_GREEN },  RULE_POSITION_UNDEFINED, RULE_POSITION_UNDEFINED }, RUL_CUT_4 },
	{{{ POS_DEFUSE, VAL_ORANGE }, RULE_POSITION_UNDEFINED, RULE_POSITION_UNDEFINED }, RUL_CUT_5 }
};

int main() {
	printf("** SecondBomb **\n");
	printf("C'e' una nuova bomba! Per disinnescarla devi tagliare i cavi.\nI cavi sono bianco, nero, rosso, arancione e verde. Ci sono piu' cavi dello stesso colore.\nDecidi quali cavi tagliare.\n");
	printf("Inserisci i cavi da tagliare nel formato [colore1 colore2 colore3 ... coloreN]:\n");
	char colorsStr[STR_LEN];
	gets(colorsStr);
	Array colors = getColorsNames(colorsStr);
	Wire* wires = (Wire*)malloc(sizeof(Wire) * colors->size);
	for (int i = 0; i < colors->size; i++)
		wires[i] = getWireByName(colors->values[i], SIZE_ARR(bomb));
	BOMB_STATUS status = defuse(wires, colors->size);
	switch (status)
	{
	case EXPLODED:
		printf("BOOM! Sei morto.\n");
		break;
	case DEFUSED:
		printf("Congratulazioni, bomba disinnescata.\n");
		break;
	case INVALID:
		printf("Dato non valido\n");
		break;
	default:
		printf("Stato sconosciuto\n");
		break;
	}
	getchar();
	return 0;
}

BOMB_STATUS defuse(Wire* wires, int len) {
	POSITION pos = 0;
	int resCut = 1;
	for (int i = 0; i < len && resCut && resCut != UNDEFINED && pos < POS_DEFUSE && pos != POS_UNDEFINED; i++)
	{
		if (wires[i].value != VAL_UNDEFINED) {
			resCut = wires[i].value & positions[pos].ruleCut;
			pos = wires[i].value != VAL_UNDEFINED ? getNextPos(pos, resCut) : POS_UNDEFINED;
		}
		else
			resCut = UNDEFINED;
	}
	return resCut != UNDEFINED ? (BOMB_STATUS)(resCut && pos == POS_DEFUSE) : INVALID;
}

Wire getWireByName(char* name, int len) {
	for (int i = 0; i < len; i++)
		if (strcmp(bomb[i].name, name) == 0) return bomb[i];
	return (Wire) { UNDEFINED_STR, VAL_UNDEFINED };
}

Array getColorsNames(char* wiresStr) {
	int wiresLen = countChars(wiresStr, DELIMITER_CHAR) + 1;
	char** wires = (char**)malloc(sizeof(char*)*wiresLen);
	char* splittedString = strtok(wiresStr, DELIMITER);
	for (int i = 0; i < wiresLen; i++) {
		wires[i] = (char*)malloc(sizeof(char) * WIRE_STR_LEN);
		strcpy(wires[i], splittedString);
		splittedString = strtok(NULL, DELIMITER);
	}
	Array arr = (Array)malloc(sizeof(Array));
	arr->values = wires;
	arr->size = wiresLen;
	return arr;
}

POSITION getNextPos(int currentPos, int cutRes) {
	for (int i = 0; i < MAX_RULE_POSITIONS; i++)
		if (positions[currentPos].rulePos[i].pos != POS_UNDEFINED && (cutRes & positions[currentPos].rulePos[i].rule))
			return positions[currentPos].rulePos[i].pos;
	return POS_UNDEFINED;
}

int countChars(char* str, char c)
{
	return *str == '\0' ? 0 : countChars(str + 1, c) + (*str == c);
}