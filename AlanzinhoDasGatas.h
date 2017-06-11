#include <stdio.h>

int SomaVet(int *V1, int *V2, int n)
{
	int Soma[n];
	for(int i=0; i<n; i++)
	{
		Soma[i] = V1[i]+V2[i];
		printf("%d ", Soma[i]);
	}
	printf("\n \n");
}

void DeclaraVet()
{
	int k;
	printf("Digite o tamanho dos vetores\n");
	scanf("%d", &k);
	int Vet1[k], Vet2[k];
	for(int i=0; i<k; i++)
	{
		printf("Digite o %d numero do vetor%d\nDigite o %d numero do vetor%d\n", i+1, 1, i+1, 2);
		scanf("%d %d", &Vet1[i], &Vet2[i]);
	}
	SomaVet(Vet1, Vet2, k);
}