#include <stdio.h>
#define N_ESAMI 30
#define N_STR 100

typedef enum { NON_SOSTENUTO = -2, NON_SUPERATO = 1 } StatoEsame;

typedef struct {
	int codice;
	char* nome;
	int voto;
} Esame;

typedef struct {
	int matricola;
	char nome[N_STR];
	char cognome[N_STR];
	char indirizzo[N_STR];
	Esame esami[N_ESAMI];
} Studente;

void pflush();
Studente addEsame(Studente studente, int codiceEsame, char* nomeEsame, int voto);

int main() {
	Studente studente = { 100, "Simeone", "Vilardo", "Via Bella 123" };
	for (int i = 0; i < N_ESAMI; i++) {
		studente.esami[i].codice = -1;
		studente.esami[i].voto = NON_SOSTENUTO;
	}
	printf("Lo studente si chiama: %s %s\n", studente.nome, studente.cognome);
	printf("Aggiunta di un esame allo studente...\n");
	studente = addEsame(studente, 1, "Analisi", 18);
	printf("Stampa degli esami dello studente:\n");
	for (int i = 0; i < N_ESAMI; i++)
		printf("Codice Esame: %d \t Voto Esame: %d\n", (studente.esami[i]).codice, studente.esami[i].voto);
	printf("Premere INVIO per terminare il programma\n");
	getchar();
	return 0;
}

Studente addEsame(Studente studente, int codiceEsame, char* nomeEsame, int voto) {
	for (int i = 0; i < N_ESAMI; i++)
		if (studente.esami[i].voto == NON_SOSTENUTO) {
			Esame esame = { codiceEsame, nomeEsame, voto };
			studente.esami[i] = esame;
			break;
		}
	return studente;
}

void pflush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}