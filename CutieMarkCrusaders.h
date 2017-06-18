#include <stdio.h>
#include <stdlib.h>
//Cabecalho com funcoes//
void menu();
												// --------- FUNCOES DOS VETORES --------- //
int* SomaVet(int *V1, int *V2, int *n, int S);
void DeclaraVet(int opc_smenu_vetor);
int LerVet(int *V1, int *L, int S);
int LerMat(int **M, int *Lin, int *Col, int Matz);
												// --------- FUNCOES DAS MATRIZES --------- //
void DeclaraMat(int opc_smenu_matriz);
												// --------- ESCOPO DAS FUNCOES VETORES ---------//

struct Vetores 															//Struct para definir N vetores//
{
	int *Vet;
};

struct Matrizes 														//Struct para definir N Matrizes//
{
	int **Mat;
};

//=== Ler Vetores ===// FEITO POR Twily

int LerVet(int *V1, int *L, int S) 										//Passa 2 vetores para a funcao o vetor a ser lido e seu tamanho//
{
	int m;
	printf("| ");
	for (m = 0; m<L[S]; m++) 											//Le o vetor e printa na tela//
	{
		printf("%d ", V1[m]);
	}
	printf("|\n\n");
}

//=== Soma Vetorial ===// FEITO POR Twily

int* SomaVet(int *V1, int *V2, int *n, int S) 							//Passa 2 vetores e seu tamanho na tela//
{
	int *Soma2=malloc(n[S]*sizeof(int)), m;
	for(m=0; m<n[S]; m++) 
	{
		Soma2[m]=0;
		Soma2[m] = V1[m]; 												//Atribui os valores do vetor 1-n a Soma2//
		if(S>=1)
		{
			if(V2[m]>1000)
			{
			V2[m]=0;
			Soma2[m]=Soma2[m]+V2[m]; 									//Faz a soma caso haja 2 vetores//
			printf("%d ", Soma2[m]);
			} else{Soma2[m]=Soma2[m]+V2[m]; printf("%d ", Soma2[m]);}
		}
	}
	printf("\n\n");
	return Soma2;
}

//=== Declaração de vetores ===// FEITO POR Twily

void DeclaraVet(int opc_smenu_vetor)
{
	int *Soma=malloc(100*sizeof(int));
	int *k=malloc(100*sizeof(int)), len, i=0,j=0; 						//Declara um vetor 'k[x]' para o tamanho dos vetores, quantos vetores ele quer 'len' e uma variaveis de controle i e j//
	
	printf("Digite quantos vetores voce quer operar:\n");
	scanf("%d", &len);
	
	struct Vetores V[len]; 												//Vetorizando o struct, criando quantos vetores o Leopardo desejar//
	k[len]; 															//Definindo quantos tamanhos será armazeno nesse vetor malloqueiro//
	
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
	
	//=== Switch para puxar as outras funcoes presentes na biblio ===// FEITO POR Twily
	
	switch (opc_smenu_vetor){
		case 1:
			j=0;
			while(j<len)
			{
			LerVet(V[j].Vet, k, j); 									//Puxa a funcao ler vetores e printa - los na tela//
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
					Soma = SomaVet(V[j].Vet, Soma, k, j);				//Puxa a função soma
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

												// --------- ESCOPO DAS FUNCOES MATRIZES ---------//

//=== Declarando as Matrizes ===// FEITO POR Twily

void DeclaraMat(int opc_smenu_matriz)
{
	int matz, i, j, k;																	//Declarando a variavel de quantidade de matriz 'matz' e possiveis contadores
	int *lin=malloc(100*sizeof(int));													//Declarando vetores para armazenar tamanhos de linhas e colunas
	int *col=malloc(100*sizeof(int));
	
	printf("  Digite quantas matrizes voce deseja operar: ");
	scanf("%d", &matz);
	struct Matrizes M[matz];
	
	for(i=0; i<matz; i++)
	{
		printf("\n  Digite o numero de linhas e colunas de sua matriz %d: ", i+1);
		scanf("%d %d", &lin[i], &col[i]);
		printf("\n");
	}
	for (j=0; j<matz; j++)																//Alocacao dinamica de linhas e colunas
	{
		M[j].Mat=malloc(col[j]*sizeof(int));
		for(i=0; i<col[j]; i++)
		{
			M[j].Mat[i]=malloc(lin[i]*sizeof(int));
			for(k=0; k<lin[j]; k++)														//Definindo elementos da matriz
			{
				printf("  Digite o elemento da linha %d e coluna %d da matriz %d: ", k+1, i+1, j+1);
				scanf("%d", &M[j].Mat[i][k]);
				printf("\n");
			}
		}
	}
	switch (opc_smenu_matriz)
	{
		case 1:
			i=0;
			while(i<matz)
			{
				LerMat(M[i].Mat, lin, col, i);											//Puxando a função ler matrizes
				i++;
			}
			menu();
			break;
		
		default:
			printf(":)\n:)\n:)\n");
			menu();
			break;
	}
}

int LerMat(int **M, int *Lin, int *Col, int Matz)
{
	int ler1, ler2;
	for (ler1=0; ler1<Col[Matz]; ler1++)
	{
		printf("|  ");
		for (ler2=0; ler2<Lin[Matz]; ler2++)
		{
			printf("%d  ", M[Col[ler1]][Lin[ler2]]);
		}
		printf(" |\n");
	}
}
