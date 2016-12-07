/*
	REGOLE:
	Se tagli un cavo bianco non puoi tagliare un cavo bianco o nero.
	Se tagli un cavo rosso devi tagliare un cavo verde.
	Se tagli un cavo nero non è permesso tagliare un cavo bianco, verde o arancione.
	Se tagli un cavo arancione devi tagliare un cavo rosso o nero.
	Se tagli un cavo verde devi tagliare un cavo arancione o bianco.
	Se tagli un cavo viola non puoi tagliare un cavo viola, verde, arancione o bianco.
*/

#include <stdio.h>
#include <string.h>
#define SIZE_ARR(x) (sizeof(x) / sizeof((x)[0]))
#define WIRES_LEN 4
#define STR_LEN 16

typedef enum
{
	VAL_WHITE = 1 << 1,
	VAL_RED = 1 << 2,
	VAL_BLACK = 1 << 3,
	VAL_ORANGE = 1 << 4,
	VAL_GREEN = 1 << 5,
	VAL_PURPLE = 1 << 6,
	VAL_UNKNOWN = -1
} COLOR_VALUE;

typedef enum
{
	RUL_WHITE = VAL_WHITE | VAL_BLACK,
	RUL_RED = VAL_WHITE | VAL_RED | VAL_BLACK | VAL_ORANGE | VAL_PURPLE,
	RUL_BLACK = VAL_WHITE | VAL_GREEN | VAL_ORANGE,
	RUL_ORANGE = VAL_WHITE | VAL_ORANGE | VAL_GREEN | VAL_PURPLE,
	RUL_GREEN = VAL_RED | VAL_BLACK | VAL_GREEN | VAL_PURPLE,
	RUL_PURPLE = VAL_WHITE | VAL_ORANGE | VAL_GREEN | VAL_PURPLE,
	RUL_UNKNOWN = -1
} RULE_VALUE;

typedef struct
{
	char* name;
	COLOR_VALUE value;
	RULE_VALUE rule;
} Color;

Color getColorByName(Color*, char*, int);
void pflush();

int main() {
	Color colors[] = {
		{ "bianco", VAL_WHITE, RUL_WHITE },
		{ "rosso", VAL_RED, RUL_RED },
		{ "nero", VAL_BLACK, RUL_BLACK },
		{ "arancione", VAL_ORANGE, RUL_ORANGE },
		{ "verde", VAL_GREEN, RUL_GREEN },
		{ "viola", VAL_PURPLE, RUL_PURPLE }
	};
	int colLen = SIZE_ARR(colors);
	char wires[WIRES_LEN][STR_LEN];
	printf("** Bomba **\n");
	printf("C'e' una bomba! Per disinnescarla devi tagliare i cavi.\nI cavi sono bianco, nero, viola, rosso, verde ed arancione. Ci sono piu' cavi dello stesso colore.\nDecidi quali cavi tagliare.\n");
	printf("Inserisci quattro cavi nel formato [colore colore colore colore]: ");
	scanf("%16s %16s %16s %16s", wires[0], wires[1], wires[2], wires[3]);
	pflush();
	Color col, nextCol;
	int boom = 0;
	for (int i = 0; i < WIRES_LEN - 1 && !boom; i++) {
		col = getColorByName(colors, wires[i], colLen);
		nextCol = getColorByName(colors, wires[i + 1], colLen);
		if (col.value < 0 || nextCol.value < 0)
		{
			printf("Cavo non valido.\n");
			getchar();
			return 1;
		}
		boom = col.rule & nextCol.value;
	}		
	boom ? printf("BOOM! Sei morto.\n") : printf("Congratulazioni, bomba disinnescata.\n");	
	getchar();
	return 0;
}

Color getColorByName(Color* colors, char* name, int len) {
	for (int i = 0; i < len; i++)
		if (strcmp(colors[i].name, name) == 0) return colors[i];
	return (Color) { "unknown", VAL_UNKNOWN, RUL_UNKNOWN };
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}