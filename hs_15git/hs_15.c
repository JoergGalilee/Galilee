#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANZAHL 10

int qs(int z){ // 1234
    if(z < 10){
       return z; 
    }else{
      return (z% 10 + qs (z / 10));
    }
}

void bubble (int* , int, int (*)());
void ausgabe (int *, int);
int compare_value (int, int);
int compare_qs(int , int);
int main ()
{
  int (*ptr)(int, int) = &compare_value;
  int zahl1=-1;
 printf("Wählen Sie eine Sortiervorschrift‘\n ");
 printf("Werte:0 und Quersumme:1\n ");
 scanf("%d", &zahl1);
if (zahl1!=-1)
{
	if(zahl1){
		ptr=&compare_qs;
		
	}else{
		ptr=&compare_value;
	}
}
 printf ("\nHS_15 - Sortieren mit Funktionszeigern\n\n");
srand ((unsigned int) time (NULL));//Zufallszahlen initialisieren
int *iDaten = (int *) malloc (ANZAHL * sizeof (int));
if (iDaten != NULL)//Check if the memory has been successfully
// allocated by malloc or not
{
 for (int i = 0; i < ANZAHL; i++)    //Get the element of iDaten
{
 *(iDaten + i) = rand () % (ANZAHL * 100); //Assigning randoms numbers between 0 and 999 to memory allocated
}
printf ("\n--- VOR dem Sortieren ---\n");
ausgabe (iDaten, ANZAHL);
bubble (iDaten, ANZAHL, ptr);    //Calling the Function.
printf ("\n--- NACH dem Sortieren ---\n");
ausgabe (iDaten, ANZAHL);
free (iDaten);// reservierten Speicher wieder freigeben
}
else
printf ("Reservierung fehlgeschlagen - FEHLER!");
return 0;
}

void ausgabe (int *iWerte, int iZahl)   // Ausgeben eines int-Arrays
{
 for (int i = 0; i < iZahl; i++){
   printf ("%d\t%d\t%d\n", i, iWerte[i], qs(iWerte[i]));
   
 }

}

void bubble (int *iWerte, int iZahl, int (*ptr)())    // Sortieren eines int-Arrays
{
int iFlag;
do
{
iFlag = 0;
for (int i = 0; i < iZahl - 1; i++)
{
if ((*ptr)(iWerte[i], iWerte[i + 1]))     // Vergleich der Elemente
{
// ggf. Tauschen der Elemente
int iHilf = iWerte[i];
iWerte[i] = iWerte[i + 1];
iWerte[i + 1] = iHilf;
iFlag = 1;
}
}
}
while (iFlag);
}

int compare_value (int a, int b)// Vergleichsfunktion
{
return (a > b);
}
int compare_qs(int c, int d){
    return (qs(c) > qs(d));
}

