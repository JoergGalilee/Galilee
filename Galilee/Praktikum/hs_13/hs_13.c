//hs_16
//18314726
//Jörg Galilee Uwimana

#include <stdio.h>
int main() {
    char var;
    char *pvar;
    pvar = &var;
    pvar +=1;
    *pvar=123;
    long difference = pvar - &var;
    printf("The difference in the address is: %ld \n", difference);
    printf("The address of var is: %p\nthe address of pvar is: %p\n", &var, pvar);
    
    return 0;
}
