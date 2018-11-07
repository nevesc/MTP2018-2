/* P4.c */
/* Gabriel Neves Cardoso */
/* 11811EBI014 */


#include <stdio.h>



double funcao(float x, float y)

{

	if(x==0) 

		return y+1;

	else if(x>0 && y==0) 

		funcao(x-1,1);

	else if(x>0 && y>0) 

		funcao(x-1, funcao(x, y-1));

}



int main ()

{

	float x, y;

	scanf ("%f + %f", &x, &y);

	printf("%g + %g = %g", x, y, funcao(x,y));

	return 0;

}