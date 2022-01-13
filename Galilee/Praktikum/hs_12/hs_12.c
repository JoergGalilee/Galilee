//hs_12
//18314726
//Jörg Galilee Uwimana

#include <stdio.h>
#include <stdlib.h>
int main(void){

	double
	* a;
	= (double*) malloc (10000 * sizeof (double));
	if(a==NULL)
	{
	printf ("Error\n") ;
	}
	else
	{

	printf("Done\n");
	}
	free(a);
	return 0;
	}
