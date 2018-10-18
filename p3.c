//Gabriel Neves
//11811EBI014

#include <stdio.h>
int main()
{
	int conv=0, cum=0, i=0;
	char numero[256];
	printf("Digite os caracteres: "); 
	scanf("%s", numero);
	getchar();
	for (i=0; numero[i]; i++)
	{
		if ((numero[i]-'0')>=0 && (numero[i]-'0')<=9)
			cum=cum*10+(numero[i]-'0');
		else;
	}
	printf("%i", cum);
	return 0;
}
