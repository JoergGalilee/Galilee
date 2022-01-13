//hs_16
//18314726
//Jörg Galilee Uwimana
#include <stdio.h>
#pragma pack(1)



struct Geo
{


};
struct messwert
{
	int iMessungNummer;
  	double dLuftdruck;
  	float fTemperatur[3];
 
};

void output(struct messwert);
int main ()
{
	struct messwert messung={12,14,13,4};
	printf("The Size of Messung %ld: ",sizeof(messung)); 
	//printf("The Size of the first number  %ld: The size of second number %ld: ",sizeof(messung.firstnumber , messung.secondnumber)); 
	printf("fTemperatur nach Veränderungr  %lf : ",messung.fTemperatur[3]); 
	return 0;
}
