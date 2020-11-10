#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void func(int* a)
{
*a = 1;
}
int main()
{
int* a;
func(a);
printf("%d\n",&a);
}