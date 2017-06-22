#include <stdio.h>
#include <stdlib.h>
//Cabecalho com funcoes//
void menu();
												// --------- FUNCOES DOS VETORES --------- //
float* SomaVet(float *V1, float *V2, int n, int n2, int S);
void DeclaraVet(int opc_smenu_vetor);
int LerVet(float *V1, int L);
int LerMat(float *M[], int Lin, int Col, int Matz);
												// --------- FUNCOES DAS MATRIZES --------- //
void DeclaraMat(int opc_smenu_matriz);
												// --------- ESCOPO DAS FUNCOES VETORES ---------//

struct Vetores 															//Struct para definir N vetores//
{
	float *Vet;
	int linha;
};

struct Matrizes 														//Struct para definir N Matrizes//
{
	float **Mat;
	int linha, coluna;
};

//=== Ler Vetores ===// FEITO POR Twily

int LerVet(float *V1, int L) 											//Passa 1 vetor e 1 inteiro para a funcao o vetor a ser lido e seu tamanho//
{
	int m;
	printf("| ");
	for (m = 0; m<L; m++) 												//Le o vetor e printa na tela//
	{
		printf("%f ", V1[m]);
	}
	printf("|\n\n");
}

//=== Soma Vetorial ===// FEITO POR Twily

float* SomaVet(float *V1, float *V2, int n, int n2, int S) 								//Passa 2 vetores e seu tamanho na tela//
{
	int m;
	for(m=0; m<n; m++) 
	{
		if(S>=1)
		{
			if(n==n2) 													//Faz a soma caso haja 2 vetores e eles sejam de tamanhos iguais//
			{
				V2[m]=V1[m]+V2[m];
				printf("%f ", V2[m]);
			} else
			{								
				printf("Vetores de tamanhos diferentes, operacao invalida");
			}
		}
	}
	printf("\n\n");
	return V2;
}

//=== Declaração de vetores ===// FEITO POR Twily

void DeclaraVet(int opc_smenu_vetor)
{
	int len, i=0,j=0; 													//Declara quantos vetores ele quer 'len' e uma variaveis de controle i e j//
	
	printf("Digite quantos vetores voce quer operar:\n");
	scanf("%d", &len);
	
	struct Vetores V[len]; 												//Vetorizando o struct, criando quantos vetores o Leopardo desejar//
	struct Vetores Soma;
	
	for (i=0; i<len; i++)
	{
		printf("Digite o tamanho do vetor %d\n", i+1);
		scanf("%d", &V[i].linha);
		if(i>=1)														//Se for a segunda vez que o laco roda
		{
			if(V[i].linha>=V[i-1].linha)
			{
				Soma.linha=V[i].linha;
			} else {Soma.linha=V[i-1].linha;}
		}
	}
	Soma.Vet=malloc(Soma.linha*sizeof(float));							//Declarando o vetor que armazenara a soma
	for(j=0; j<len; j++)
	{
		V[j].Vet = malloc(V[j].linha*sizeof(float));
		for(i=0; i<V[j].linha; i++)
		{
			printf("Digite o elemento %d do vetor %d: ", i+1, j+1);
			scanf("%f", &V[j].Vet[i]);
			printf("\n");
		}
	}
	
	//=== Switch para puxar as outras funcoes presentes na biblio ===// FEITO POR Twily
	
	switch (opc_smenu_vetor){
		case 1:
			j=0;
			while(j<len)
			{
			LerVet(V[j].Vet, V[j].linha); 									//Puxa a funcao ler vetores e printa - los na tela//
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
					Soma.Vet = SomaVet(V[j].Vet, Soma.Vet, V[j].linha, Soma.linha, j);				//Puxa a função soma
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
	printf("  Digite quantas matrizes voce deseja operar: ");
	scanf("%d", &matz);
	struct Matrizes M[matz];
	
	for(i=0; i<matz; i++)
	{
		printf("\n  Digite o numero de linhas de sua matriz %d: ", i+1);
		scanf("%d", &M[i].linha);
		printf("\n  Digite o numero de colunas de sua matriz %d: ", i+1);
		scanf("%d", &M[i].coluna);
		printf("\n");
	}
	for (k=0; k<matz; k++)																	//Alocacao dinamica de linhas e colunas
	{																						//M[2][3]
		M[k].Mat=malloc(M[k].coluna*sizeof(float));
		for(i=0; i<M[k].coluna; i++)
		{
			M[k].Mat[i]=malloc(M[k].linha*sizeof(float));
			for(j=0; j<M[k].linha; j++)														//Definindo elementos da matriz
			{
				printf("  Digite o elemento da linha %d e coluna %d da matriz %d: ", j+1, i+1, k+1);
				scanf("%f", &M[k].Mat[i][j]);
			}
		}
	}
	switch (opc_smenu_matriz)
	{
		case 1:
			i=0;
			while(i<matz)
			{
				LerMat(M[i].Mat, M[i].linha, M[i].coluna, i);											//Puxando a funcao ler matrizes
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

int LerMat(float *M[], int Lin, int Col, int Matz)
{
	int ler1, ler2;
	for (ler1=0; ler1<Col; ler1++)
	{
		printf("|  ");
		for (ler2=0; ler2<Lin; ler2++)
		{
			printf("%3f  ", M[ler1][ler2]);
		}
		printf(" |\n");
	}
}
