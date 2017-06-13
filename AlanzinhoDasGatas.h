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

int LerVet(int *V1, int k) //Tá bugado, tá puxando o menu 2 vezes, REUPI
{
	printf("| ");
	for (int i = 0; i<k; i++)
	{
		printf("%d ", V1[i]);
	}
	printf("|\n\n");
	menu();
}

//=== Soma Vetorial ===// FEITO POR DasGatas

int SomaVet(int *V1, int *V2, int n)
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
	switch (opc_smenu_vetor){ //=== Gambiarra para fazer tudo numa funcao so ===// FEITO POR DasGatas o rei das gambiarras
		case 1:
			Swi=0; // Arrumar essa gambiarra o quanto antes, so ta lendo um vetor em vez de ler N //
			while(Swi<len)
			{
			LerVet(V[Swi].Vet, k);
			Swi++;
			}
			break;
		case 2:
			SomaVet(V[0].Vet, V[1].Vet, k);
			break;
	}
}
