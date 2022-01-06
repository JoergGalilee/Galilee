#include <stdio.h>

void test(char c){ printf("%c“,c);}	// Beispielfunktion 1
int summe(int a, int b) {return a+b;}	// Beispielfunktion 2

void (*pf1) (char);                 // Zeiger auf eine Funktion mit einem
                                // Übergabewert vom Typ char 
                                // ohne Rückgabewert (wie Bsp.1)

int (*pf2) (int,int);           // Zeiger auf eine Funktion mit zwei
			        // Übergabewerten vom Typ int und
			        // einem Rückgabewert vom Typ int (Bsp.2)

pf1 = test;	// Zuweisen der Adresse von test an pf1
pf2 = summe;	// Zuweisen der Adresse von summe an pf2
pf2 = &summe;	// Zweite, gleichwertige Schreibweise

(*pf1)('#');	// Aufrufen von test über den Zeiger pf1
		// mit dem Übergabewert '#'.

int s = (*pf2)(3,4);    // Aufrufen von summe über den Zeiger pf2
			// mit den Übergabewerten 3 und 4.






