#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char* name;
	int value;
} Colors[];

#define SIZE_ARR(x)  (sizeof(x) / sizeof((x)[0]))

void pflush();

int main() {
	printf("*****************\n");
	printf("**** COLORS *****\n");
	printf("*****************\n");
	Colors colors = { {"bianco", 1 << 1}, {"rosso", 1 << 2}, {"nero", 1 << 3}, {"arancione", 1 << 4}, {"verde", 1 << 5}, {"viola", 1 << 6} };
	int op = 0;
	int color = 0;
	while (op != 99)
	{
		for (int i = 0; i < SIZE_ARR(colors); i++)
			printf("%d)  %s %s\n", i+1, color & colors[i].value ? "Rimuovi" : "Aggiungi", colors[i].name);
		printf("99) Esci\n");
		printf("Operazione: ");
		scanf("%d", &op);
		color ^= colors[op - 1].value;
		if (color) {
			printf("\nI tuoi colori sono: ");
			for (int i = 0; i < SIZE_ARR(colors); i++)
				if (color & colors[i].value)
					printf("%s ", colors[i].name);
		}
		else
			printf("\nNon hai colori selezionati");
		printf("\nPremi INVIO per continuare\n");
		pflush();
		getchar();
	}	
	return 0;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF){}
}