//hs_16
//18314726
//Jörg Galilee Uwimana
#include <stdio.h>
//#pragma pack(1)



struct Geo
{


};
struct messwert
{
	int iMessungNummer;
  	double dLuftdruck;
  	float fTemperatur[3];
 
};

void output(struct  messwert mess)
{	//Anzeigen der enthaltene Messwerte
	

	printf("dLuftdruck %lf:\n ",mess.fTemperatur[0]);
	

	//Verändern Sie den Inhalt eines der Array-Elemente

	for(int i = 0; i < sizeof (mess.fTemperatur)/ sizeof (mess.fTemperatur[0]); i++){
	printf ("Temperatur[d]: %ld\n",mess. fTemperatur[i]);
}}
void output_p(struct  messwert Pointer){
struct messwerte *pMess,mess;
mess.iMessungNummer; 
pMess=&mess;

printf("trying %d\n",(*pMess).iMessungNummer);

return pMess;
}
int main ()
{
	struct messwert messung={12,14,{1,2,3,{13,4}}};
	struct messwert messung2=2;
	printf("The Size of Messung %ld:\n ",sizeof(messung)); 
	printf("The Size of the first number  %ld:\n ",sizeof(messung.iMessungNummer )); 
	printf("neue fTemperatur   %ld :\n ",messung.fTemperatur[0]); 
	output;
	output_p(&messung)
	return 0;
	


}
