/* Gabriel Neves Cardoso */
/* P6.c */
/* 11811EBI014 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct dot
{
	double x;
	double y;
};



struct dot *gerar (int n)

{

	struct dot *p = (struct dot*) malloc(n*sizeof(struct dot));
	int i;
	printf ("\n\nOs pontos gerados sao: \n");
	for (i=0; i<n; i++)
	{
		(*p).x = cos(i*2.0*M_PI/(n-1));
		(*p).y = sin(i*2.0*M_PI/(n-1));
		printf ("(%.3lf, %.3lf) \n", (*p).x, (*p).y);
	}
	return p;
}

int main ()
{
	struct dot *p;
	int n;
	printf ("Digite o numero de pontos que deseja encontrar: ");
	scanf ("%d", &n);
	getchar();
	p = gerar(n);
	free(p);
	return 0;
}