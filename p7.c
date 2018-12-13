/*Gabriel Neves Cardoso*/
/*11811EBI014*/
/*p7.c*/


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

	for (i=0; i<n; i++)
    {
        p[i].x = cos(i*2.0*M_PI/(n-1));
        p[i].y = sin(i*2.0*M_PI/(n-1));
    }
    return p;
}

void salvar (struct dot *p, int n)
{
	FILE *arq;
	arq = fopen("pontos.dat", "w");

    int i, j;
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < 20; j++) 
		{
            fprintf(arq, "%d\t%d\t\t", p[i].x, p[i].y);
        }    
        fprintf(arq, "\n");
    }
    fclose(arq);
}

void arqembin (struct dot *p, int n)

{
    FILE * arq;
    arq = fopen("pontos.dat", "wb");
    fwrite (p, n, sizeof(struct dot), arq);
    fclose (arq);
}

struct dot *read (int *pn)
{
    struct dot *p = (struct dot *) malloc(sizeof(struct dot));
    unsigned int n = 0;
    FILE *arq;
    arq = fopen("pontos.dat", "rb");
    while(1) 

	{
        fread(p, 1, sizeof(struct dot), arq);
        if(feof(arq)) 
			break;
        n++;
    }
    rewind(arq);
    p = (struct dot *) realloc(p, n*sizeof(struct dot));
    fread(p, n, sizeof(struct dot), arq);
    fclose(arq);
    *pn = n;
    return p;
}
void show (struct dot *p, struct dot *pf)

 {
    if(p < pf)
	{
		printf("(%.3lf , %.3lf) \n", (*p).x, (*p).y);
		show (p+1, pf);
	}
}

int main ()

{
	struct dot *p;
	int n, op;
	do
	    {
		system ("cls");
		printf("            MENU \n\n1) Gerar arquivo com pontos. \n2) Recuperar pontos de arquivo. \
			\n3) Sair do programa.\n\n");
		scanf("%d", &op);
		switch (op)
		{
		    case 1:
			printf ("\nDigite o numero de pontos que deseja achar: ");
			scanf ("%d", &n);
			getchar();
			p = gerar(n);
			salvar (p, n);
			arqembin(p, n);
			printf ("\nArquivo salvo!");
			getch ();
			break;
			
		    case 2:
			p = read(&n);
			show(p, p+n);
			getch ();
			break;
		    default:
			if (op != 3)
			    printf("Opcao não pode ser executada!");
			getch();
			break;
		}
	    } 
	while(op != 3);
	printf ("Tchau!");
	free(p);
	return 0;
}

