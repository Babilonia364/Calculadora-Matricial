#include <stdio.h>
#include <stdlib.h>
//Cabecalho com funcoes//
int SomaVet(int *V1, int *V2, int *n, int S);
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
	printf("| ");
	for (int i = 0; i<L[S]; i++) //Le o vetor e printa na tela//
	{
		printf("%d ", V1[i]);
	}
	printf("|\n\n");
}

//=== Soma Vetorial ===// FEITO POR DasGatas

int SomaVet(int *V1, int *V2, int *n, int S) //Passa 2 vetores e seu tamanho na tela//
{
	int *Soma2=malloc(n[S]*sizeof(int));
	for(int i=0; i<n[S]; i++) 
	{
		Soma2[i] = V1[i]; //Atribui os valores do vetor 1-n a Soma2//
		if(S>=1)
		{
			Soma2[i]=Soma2[i]+V2[i]; //Faz a soma caso haja 2 vetores//
			printf("%d ", Soma2[i]);
		}
	}
	printf("\n\n");
	return *Soma2;
	free (Soma2);
	Soma2 = NULL;
}

//=== Declaração de vetores ===// FEITO POR DasGatas
void DeclaraVet(int opc_smenu_vetor)
{
	int *Soma=malloc(100*sizeof(int));
	int *k=malloc(100*sizeof(int)), len, Swi; //Declara um vetor 'k[x]' para o tamanho dos vetores, quantos vetores ele quer 'len' e uma variavel de controle Swi//
	printf("Digite quantos vetores voce quer operar:\n");
	scanf("%d", &len);
	struct Vetores V[len]; //Vetorizando o struct, criando quantos vetores o Leopardo desejar//
	k[len]; //Definindo quantos tamanhos será armazeno nesse vetor malloqueiro//
	for (int i=0; i<len; i++)
	{
	printf("Digite o tamanho dos vetor %d\n", i+1);
	scanf("%d", &k[i]);
	}
	for(int j=0; j<len; j++)
	{
		V[j].Vet = malloc(k[j]*sizeof(int));
		for(int i=0; i<k[j]; i++)
		{
			printf("Digite o elemento %d do vetor %d: ", i+1, j+1);
			scanf("%d", &V[j].Vet[i]);
			printf("\n");
		}
	}
	switch (opc_smenu_vetor){ //Switch para puxar as outras funcoes presente na biblioteca//
		case 1:
			Swi=0;
			while(Swi<len)
			{
			LerVet(V[Swi].Vet, k, Swi); //Puxa a funcao ler vetores e printa - los na tela//
			Swi++;
			}
			menu();
			break;
		case 2:
			if(len>=2)
			{
				Swi=0;
				while(Swi<len)
				{
					*Soma = SomaVet(V[Swi].Vet, Soma, k, Swi);
					Swi++;
				}
			} else {printf(":)\n:)\n:)\n");}
			menu();
			break;
		default:
			printf("      Opcao invalida. Digite outra opcao.\n");
			break;
	}
}
