#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int i5=5;

int main(){
	int i1,i2,i3;//definieren der Variablen
	i1= 1;
	i2=2;
	i3=3;
 	static int i4;
	i4=4;
	int * pi1;
	int*pi2;
	int *pi3;//Pointers
	int*pi4;
	int*pi5;

	pi1=&i1;
	pi2=&i2;
	pi3=&i3;
	pi4=&i4;
	pi5=&i5;

	printf("pi1 adresse %p\n",pi1);
	printf("pi2 adresse %p\n",pi2);
	printf("pi3 adresse %p\n",pi3);
	printf("p4  adresse %p\n",pi4);
	printf("p5  adresse %p\n",pi5);

	printf("pi1 inhalt %i\n",*pi1);
	printf("pi2 inhalt %i\n",*pi2);
	printf("pi3 inhalt %i\n",*pi3);

	printf("pi4 inhalt %i\n",*pi4);
	printf("pi5 inhalt %i\n",*pi5);

 return 0;
}
