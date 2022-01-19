#include<stdio.h>
#include<stdlib.h>
//#pragma pack(1)//remove the "//" if you want to enable pragma pack.

//pragma pack compresses the size of every element of a struct to its minimal size. Usually every element takes a multiple of 8bytes because thats the size of int in this case.
//notice an array inside a struct is also just one element thats why ftemperatur is 16bytes uncompressed (3*4byte) rounds up to 16 not  24.

struct Geo
{
//The first number is the size of the element with pragma pack the second is without.
//If its just one they're identical.
	double dLatitude;//8
	double dLongitude;//8
	float fAltitude;//4/8
};

struct Messwert
{
	int iMessungNummer;//4/8
	double dLuftdruck;//8
	float fTemperatur[3];//12/16
	struct Geo Position;//20/24
	struct Messwert *pNext
};

void ausgabe(struct Messwert);
void ausgabe_p(struct Messwert *);
struct Messwert set_mw(int);
int addToList(struct Messwert **pStart, int data);
int printList(struct Messwert *pStart);
void emptyList(struct Messwert **pStart);


//Main
int main(int argc, char* argv[]){
	//float temps[] = {12.2f, 12.6f, 13.4f};
	//struct Geo schatz = {51.419861, 7.254779, -1.5f};
	struct Messwert messung = {1, 0.9178,{12.2f, 12.6f, 13.4f} , {51.419861, 7.254779, -1.5f}};
	printf("Größe von Position: %ld\n", sizeof(messung.Position));
	printf("Größe von Messung: %ld\n", sizeof(messung));
	ausgabe_p(&messung);
	printf("fTemperatur[0] nach Änderung: %lf\n",messung.fTemperatur[0]);

	struct Messwert test = set_mw(3);
	ausgabe(test);

	struct Messwert *pStart = NULL;

	int Resultat = addToList(&pStart, 3);
	if (Resultat == 0){
		printf("\Adding is complete\n");
		printf("Der Inhalt von pStart nach dem Zufügen: %p\n\n",pStart);
	}
	addToList(&pStart, 4);
	printf("\nListe wird jetzt gelöscht\n");
	emptyList(&pStart);
	printf(" pStart contains: %p\n\n",pStart);
	
	return 0;
}

void ausgabe(struct Messwert pMess){
	//Ausgabe
	printf("iMessungNummer: %d\n",pMess.iMessungNummer);
	printf("dLuftdruck: %lf\n",pMess.dLuftdruck);
	for(int i = 0; i < sizeof(pMess.fTemperatur)/ sizeof(pMess.fTemperatur[0]); i++){
		printf("fTemperatur[%d]: %f\n",i,pMess.fTemperatur[i]);
	}
	printf("Geo:\n");
	printf(" dLatitude: %lf\n",pMess.Position.dLatitude);
	printf(" dLongitude: %lf\n",pMess.Position.dLongitude);
	printf(" fAltitude: %f\n",pMess.Position.fAltitude);
	//Array Ändern
	pMess.fTemperatur[0] = 50.2f;


}

void ausgabe_p(struct Messwert *pMess){
	//Ausgabe
	printf("iMessungNummer: %d\n",pMess->iMessungNummer);
	printf("dLuftdruck: %lf\n",pMess->dLuftdruck);
	for(int i = 0; i < sizeof(pMess->fTemperatur)/ sizeof(pMess->fTemperatur[0]); i++){
		printf("fTemperatur[%d]: %f\n",i,pMess->fTemperatur[i]);
	}
	printf("Geo:\n");
	printf(" dLatitude: %lf\n",pMess->Position.dLatitude);
	printf(" dLongitude: %lf\n",pMess->Position.dLongitude);
	printf(" fAltitude: %f\n",pMess->Position.fAltitude);
	//Array Ändern
	(*pMess).fTemperatur[0] = 64.0f;


}

struct Messwert set_mw(int nummer){
/*
This stuff is all not necessary
just make the same everytime and change the number.
like this:
struct Messwert neu = {nummer, 0.9178,{12.2f, 12.6f, 13.4f} , {51.419861, 7.254779, -1.5f}};

*/

	srand((unsigned int)nummer);
	double pressure = (1.0 + ((rand()%51)-25)/1000);
	struct Messwert ausg = {nummer, pressure, {0.0f,0.0f,0.0f} , {0.0, 0.0, 0.0f}};
	for(int i = 0; i < sizeof(ausg.fTemperatur)/ sizeof(ausg.fTemperatur[0]); i++){
		ausg.fTemperatur[i] = 20.0f +  (float)((rand()%31)-15)/10.0f;
	}
	ausg.Position.dLongitude = (double)(rand()%1801)/10.0;
	ausg.Position.dLatitude= (double)((rand()%1801)-900)/10.0;
	ausg.Position.fAltitude = (float)((rand()%10001)-5000)/10.0f;//Precision of float adds extra randomness. Nice!

	return ausg;
}
int addToList(struct Messwert **pStart, int data){
	
	struct Messwert *ptr_Wert = (struct Messwert*) malloc(sizeof(struct Messwert));
	if (ptr_Wert == 0){
		exit(-1);
	}
	ptr_Wert->iMessungNummer = data;
	ptr_Wert->pNext = (*pStart);
	(*pStart) = ptr_Wert;
	int count = printList((*pStart));
	printf("\nZahl der Listenelemente: %d\n\n", count);
	return(0);

}


int printList(struct Messwert *pStart){
	int count = 0;
	struct Messwert *ptr = pStart;
	while (ptr != NULL)
	{
		//if(pStart->iMessungNummer == 3)
			//{
		ausgabe_p(ptr);
		count++;
		ptr = ptr->pNext;
			//}
	}
	return count;
}

void emptyList(struct Messwert **pStart){
	struct Messwert *ptr_current = *pStart;
	struct Messwert *pNext;
	while (ptr_current != NULL)
	{
		pNext = ptr_current->pNext;
		free(ptr_current);
		ptr_current = pNext;
	}
	(*pStart) = NULL;
}
