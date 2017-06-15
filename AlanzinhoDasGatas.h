#include <stdio.h>
#include <stdlib.h>
int SomaVet(int *V1, int *V2, int n);
void DeclaraVet(int opc_smenu_vetor);
void menu();
int LerVet(int *V1, int k);

struct Vetores
{
	int *Vet;
};

//=== Ler Vetores ===// FEITO POR DasGatas

int LerVet(int *V1, int k) //Passa 1 vetor par a funcao e o seu tamanho//
{
	printf("| ");
	for (int i = 0; i<k; i++) //Le o vetor e printa na tela//
	{
		printf("%d ", V1[i]);
	}
	printf("|\n\n");
}

//=== Soma Vetorial ===// FEITO POR DasGatas

int SomaVet(int *V1, int *V2, int n) //Passa 2 vetores e seu tamanho na tela//
{
	int Soma[n];
	for(int i=0; i<n; i++)
	{
		Soma[i] = V1[i]+V2[i];
		printf("%d ", Soma[i]);
	}
	printf("\n\n");
	menu();
}

//=== Declaração de vetores ===// FEITO POR DasGatas
void DeclaraVet(int opc_smenu_vetor)
{
	int k, len, Swi;
	printf("Digite quantos vetores voce quer operar:\n");
	scanf("%d", &len);
	struct Vetores V[len];
	printf("Digite o tamanho dos vetores\n");
	scanf("%d", &k);
	for(int j=0; j<len; j++)
	{
		V[j].Vet = malloc(k*sizeof(int));
		for(int i=0; i<k; i++)
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
			LerVet(V[Swi].Vet, k); //Puxa a funcao ler vetores e printa - los na tela//
			Swi++;
			}
			menu();
			break;
		case 2:
			SomaVet(V[0].Vet, V[1].Vet, k);
			break;
		case default:
			printf("      Opcao invalida. Digite outra opcao.\n");
			break;
	}
}
