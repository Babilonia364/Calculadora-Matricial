#include <stdio.h>
#include <stdlib.h>
//Cabecalho com funcoes//
int* SomaVet(int *V1, int *V2, int *n, int S);
void DeclaraVet(int opc_smenu_vetor);
void menu();
int LerVet(int *V1, int *L, int S);

struct Vetores //Struct para definir N vetores//
{
	int *Vet;
};

//=== Ler Vetores ===// FEITO POR DasGatas

int LerVet(int *V1, int *L, int S) //Passa 2 vetores para a funcao o vetor a ser lido e seu tamanho//
{
	int m;
	printf("| ");
	for (m = 0; m<L[S]; m++) //Le o vetor e printa na tela//
	{
		printf("%d ", V1[m]);
	}
	printf("|\n\n");
}

//=== Soma Vetorial ===// FEITO POR DasGatas

int* SomaVet(int *V1, int *V2, int *n, int S) //Passa 2 vetores e seu tamanho na tela//
{
	int *Soma2=malloc(n[S]*sizeof(int)), m;
	for(m=0; m<n[S]; m++) 
	{
		Soma2[m]=0;
		Soma2[m] = V1[m]; //Atribui os valores do vetor 1-n a Soma2//
		if(S>=1)
		{
			if(V2[m]>1000)
			{
			V2[m]=0;
			Soma2[m]=Soma2[m]+V2[m]; //Faz a soma caso haja 2 vetores//
			printf("%d ", Soma2[m]);
			} else{Soma2[m]=Soma2[m]+V2[m]; printf("%d ", Soma2[m]);}
		}
	}
	printf("\n\n");
	return Soma2;
}

//=== Declaração de vetores ===// FEITO POR DasGatas
void DeclaraVet(int opc_smenu_vetor)
{
	int *Soma=malloc(100*sizeof(int));
	int *k=malloc(100*sizeof(int)), len, i=0,j=0; //Declara um vetor 'k[x]' para o tamanho dos vetores, quantos vetores ele quer 'len' e uma variaveis de controle i e j//
	printf("Digite quantos vetores voce quer operar:\n");
	scanf("%d", &len);
	struct Vetores V[len]; //Vetorizando o struct, criando quantos vetores o Leopardo desejar//
	k[len]; //Definindo quantos tamanhos será armazeno nesse vetor malloqueiro//
	for (i=0; i<len; i++)
	{
	printf("Digite o tamanho do vetor %d\n", i+1);
	scanf("%d", &k[i]);
	}
	for(j=0; j<len; j++)
	{
		V[j].Vet = malloc(k[j]*sizeof(int));
		for(i=0; i<k[j]; i++)
		{
			printf("Digite o elemento %d do vetor %d: ", i+1, j+1);
			scanf("%d", &V[j].Vet[i]);
			printf("\n");
		}
	}
	switch (opc_smenu_vetor){ //Switch para puxar as outras funcoes presente na biblioteca//
		case 1:
			j=0;
			while(j<len)
			{
			LerVet(V[j].Vet, k, j); //Puxa a funcao ler vetores e printa - los na tela//
			j++;
			}
			menu();
			break;
		case 2:
			if(len>=2)
			{
				j=0;
				while(j<len)
				{
					Soma = SomaVet(V[j].Vet, Soma, k, j);
					j++;
				}
			} else {printf(":)\n:)\n:)\n");}
			menu();
			break;
		default:
			printf("      Opcao invalida. Digite outra opcao.\n");
			break;
	}
}
