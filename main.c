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

double temperatura()
{
	scanf("%lf", &valores[6]);
	
if (valores[6]<-5)
    {
        q[6]=1;
    }
    else if (valores[6]>15)
    {
    q[6]=9;
    }
    else if (valores[6]<=15 && valores[6]>=-5)
    {
        q[6]=1/(0.0003869*pow(valores[6]+0.1815,2)+0.01081);
    }
    variacao_temperatura = pow(q[6],0.10);
}

double turbidez()
{

	scanf("%lf", &valores[7]);
	
	 if (valores[7]>100)
      {
       q[7]=5;
      }
       else if (valores[7]<=100)
        {
    		q[7]=97.34*exp(-0.01139*valores[7]+-0.04917*sqrt(valores[7]));
        }
	trb = pow(q[7],0.08);
}


double solidos()
{
	scanf("%lf", &valores[8]);
	 if (valores[8]>500)
     {
       q[8]=32;
     }
     else if (valores[8]<=500)
     {
        q[8]=80.26*exp(-0.00107*valores[8]+0.03009*sqrt(valores[8]))-0.1185*valores[8];
      }

	solidos_totais = pow(q[8],0.08);
}

int main(){

	oxigeniodissolvido();
	
	coliformesfecais();
	
	ph();
	
	DemandaBioquimicadeOxigenio();
	
	Nitrogenio();
	
	fosfato();
	
	temperatura();
	
	turbidez();
	
	solidos();
	
	IQA = (oxigenio_dissolvido)*(coliformes_fecais)*(pH)*(DBO)*(nitrogenio_total)*(fosfato_total)*(variacao_temperatura)*(trb)*(solidos_totais);
	
	printf("%.4lf\n",oxigenio_dissolvido);
	printf("%.4lf\n",coliformes_fecais);
	printf("%.4lf\n",pH);
	printf("%.4lf\n",DBO);
	printf("%.4lf\n",nitrogenio_total);
	printf("%.4lf\n",fosfato_total);
	printf("%.4lf\n",variacao_temperatura);
	printf("%.4lf\n",trb);
	printf("%.4lf\n",solidos_totais);
	printf("IQA = %.4lf\n",IQA);
	
	if (IQA>=0 && IQA<=19)
            {
                        printf("Pessima\n");
            }
            if (IQA>=20 && IQA<=36)
            {
                        printf("Ruim\n");
            }
            if (IQA>=37 && IQA<=50)
            {
                        printf("Aceitavel\n");
            }
            if (IQA>=51 && IQA<=79)
            {
                        printf("Boa\n");
            }
            if (IQA>=80 && IQA<=100)
            {
                        printf("Otima\n");
            }
	
	return 0;
}



