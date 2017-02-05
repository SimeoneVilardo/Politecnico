num1 = int(input("Inserisci un numero: "));
if (num1 % 2): print("Dispari\n");
else:
    if(num1 % 4): print("Pari\n");
    else: print("Divisibile per 4\n");

num2 = int(input("Inserisci un altro numero: "));
check = int(input("Inserisci di nuovo un altro numero: "));
if(num2 % check): print("{} non e' divisibile per {}\n".format(num2, check));
else: print("{} e' divisibile per {}\n".format(num2, check));