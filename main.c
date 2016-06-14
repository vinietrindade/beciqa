#include <stdio.h>
#include <math.h>

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


double DemandaBioquimicadeOxigenio()
{
	scanf("%lf", &valores[3]);
	
  if (valores[3]>30)
    {
      q[3]=2;
    }
      else if (valores[3]<=30)
    {
       q[3]=102.6*exp(-0.01101*valores[3]);
    }
                                  
	DBO = pow(q[3],0.10);
}	


double Nitrogenio()
{

	scanf("%lf", &valores[4]);
	
	if (valores[4]>100)
    {
       q[4]=1;
    }
       else if (valores[4]<=100)
    {
       q[4]=98.96*pow(valores[4],-0.2232-0.006457*valores[4]);
    }
	nitrogenio_total = pow(q[4],0.10);
}

double fosfato()
{
	scanf("%lf", &valores[5]);
	
	 if (valores[5]>10)
    {
       q[5]=5;
    }
      else if (valores[5]<=10)
    {
      q[5]=213.7*exp(-1.680*pow(valores[5],0.3325));
    }
                                  
	fosfato_total = pow(q[5],0.10);
}
