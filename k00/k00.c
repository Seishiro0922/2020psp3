#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(void)
{
    double a,b,c;
    a=1.05946309436;
    c=221.5;

    for(b=1;b<=10;b++){
        c=c*a;
        printf("c=%d\n",c);
    }
   return 0;
}