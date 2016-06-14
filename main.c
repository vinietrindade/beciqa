#include <stdio.h>
#include <math.h>

double e=2.718281828459045235360287;
double pi=3.14159265358979323846;

double valores[9];
double q[9];

double coliformes_fecais;
double pH;
double DBO;
double nitrogenio_total;
double fosfato_total;
double variacao_temperatura;
double trb;
double solidos_totais;
double oxigenio_dissolvido;
double IQA;

double oxigeniodissolvido()
{
	scanf("%lf", &valores[0]);
	
	
 if (valores[0]>140)
    {
       q[0]=47;
    }
    else if (valores[0]<=140)
    {
       q[0]=100.8*exp(pow(valores[0]-106,2)/-3745);
    }
                                  
	
	oxigenio_dissolvido = pow(q[0],0.17);
}


double coliformesfecais()
{
	scanf("%lf", &valores[1]);
	
if (valores[1]>100000)
    {
      q[1]=3;
    }
    else if (valores[1]>=0 && valores[1]<=100000)
    {
      q[1]=98.03-36.45*(log10(valores[1]))+3.138*(log10(pow(valores[1],2)))+0.06776*(log10(pow(valores[1], 3)));
    }
	coliformes_fecais = pow(q[1], 0.15);
}	


	
double ph()
{
	scanf("%lf", &valores[2]);
	
	if (valores[2]>12)
    {
    q[2]=3;
    }
    else if (valores[2]<2)
    {
      q[2]=2;
    }
     else if (valores[2]<=12 && valores[2]>=2)
    {
     q[2]=0.05421*pow(valores[2],1.23*valores[2]-0.09873*pow(valores[2],2))+5.213;
    }
	pH = pow(q[2],0.12);
}	


