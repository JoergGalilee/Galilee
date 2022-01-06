#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int i1,i2;

i1=1;
i2=2;
void tausche(int *pi1,int *pi2){

	pi1=&i1;
	pi2=&i2;

	int *pi3;

	pi1=pi3;
	pi2=pi1;
	pi3=pi2;
}
int main(){
	printf("i1 adresse %p\n",&i1);
	printf("i2 adresse %p\n",&i2);


	tausche(&i1,&i2);
	printf("i1 adresse %p\n",&i1);
	printf("i2 adresse %p\n",&i2);

 return 0;
}
