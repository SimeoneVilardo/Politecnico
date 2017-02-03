import sys;
import datetime;

TARGET_AGE = 100;
name = input("Inserisci il tuo nome: ");
age = int(input("Inserisci la tua eta': "));
year = datetime.datetime.now().year + (TARGET_AGE - age);
iteration = int(input("Inserisci il numero di volte che vuoi stampare il messaggio: "));
print(iteration * "Ciao {}, compierai {} anni nel {}!\n".format(name, TARGET_AGE, year));