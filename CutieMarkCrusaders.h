#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********************************************************
 *            UNIVERSIDADE ESTADUAL DO CEARA            *
 *           CENTRO  DE CIENCIAS E TECNOLOGIA           *
 *            CURSO DE CIENCIA DA COMPUTACAO            *
 *    DISCIPLINA  Introducao a Ciencia da Computacao    *
 *                                                      *
 *                                     Data: 21/06/2017 *
 *                                                      *
 * Professor: Leonardo Sampaio Rocha                    *
 *                                                      *
 * Alunos: Alan Pereira de Vasconcelos Junior   1394102 *
 *         Camila Alves Barbosa                 1394330 *
 *         Joao Alison de Moraes Silveira       1387122 *
 *******************************************************/

// AREA DE DECLARACAO DE FUNCOES:

void menu();

// FUNCOES DOS VETORES:

void InsVet(int opc_smenu_vet);
void ExiVet(float *V1, int L);
float* SomaVet(float *V1, float *V2, int n, int n2, int S);


// FUNCOES DAS MATRIZES:

void InsMat(int opc_smenu_mat);
int ExiMat(float *M, int Lin, int Col, int Matz);



// AREA DE DECLARACAO DOS STRUCTS:

//Struct para definir N vetores:

struct Vetores {
	float *Vet;
	int linha;
};

//Struct para definir N Matrizes:

struct Matrizes {
	float **Mat;
	int linha, coluna;
};



/* (1) FUNCOES COM VETORES */

// (1.1) Inserir Vetores FEITO POR Twily

//=== Declaração de vetores ===// FEITO POR Twily

void InsVet(int opc_smenu_vet)
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

	switch (opc_smenu_vet){
		case 1:
			j=0;
			while(j<len)
			{
			ExiVet(V[j].Vet, V[j].linha); 									//Puxa a funcao ler vetores e printa - los na tela//
			j++;
			}
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

// (1.2) Exibir Vetores Inseridos

    // Passa 1 vetor e 1 inteiro para a funcao o vetor a ser lido e seu tamanho.

void ExiVet(float *V1, int L) {

	int m;

    // Le o vetor e printa na tela.

	printf("  ( ");
	for (m = 0; m < L; m++) {
		printf("%.1f ", V1[m]);
	}
	printf(")\n\n");
}


//=== Soma Vetorial ===// FEITO POR Twily

float* SomaVet(float *V1, float *V2, int n, int n2, int S) 								//Passa 2 vetores e seu tamanho na tela//
{
	float *Soma2=malloc(n*sizeof(float));
	int m;
	for(m=0; m<n; m++)
	{
		Soma2[m]=V1[m];
		if(S>=1)
		{
			if(n==n2) 													//Faz a soma caso haja 2 vetores e eles sejam de tamanhos iguais//
			{
				V2[m]=Soma2[m]+V2[m];
				printf("%f ", V2[m]);
			} else
			{
				printf("Vetores de tamanhos diferentes, operacao invalida");
			}
		}
	}
	printf("\n\n");
	free (Soma2);
	return V2;
}

/* ESCOPO DAS FUNCOES COM MATRIZES */

// Declarando as Matrizes FEITO POR Twily:

void InsMat(int opc_smenu_mat) {            // Declarando a variavel de quantidade de matriz 'matz' e possiveis contadores
	int matz, i, j, k;
	printf("  Digite quantas matrizes voce deseja operar: ");
	scanf("%d", &matz);
	struct Matrizes M[matz];

	for (i = 0; i < matz; i++) {
		printf("\n  Digite o numero de linhas de sua matriz %d: ", i + 1);
		scanf("%d", &M[i].linha);
		printf("\n  Digite o numero de colunas de sua matriz %d: ", i + 1);
		scanf("%d", &M[i].coluna);
		printf("\n");
	}

// Alocacao dinamica de linhas e colunas

	for (k = 0; k < matz; k++) {
		M[k].Mat = malloc(M[k].coluna * sizeof(float));
		for (i = 0; i < M[k].coluna; i++) {
			M[k].Mat[i] = malloc(M[k].linha * sizeof(float));

			// Definindo elementos da matriz

			for(j = 0; j < M[k].linha; j++) {
				printf("  Digite o elemento da linha %d e coluna %d da matriz %d: ", i+1, j+1, k+1);
				scanf("%f", &M[k].Mat[i][j]);
			}
		}
	}

	switch (opc_smenu_mat) {      // (Puxar a funcao ler matrizes)
		case 1:
			i = 0;
			while(i < matz) {
				ExiMat(&M[i].Mat[0][0], M[i].linha, M[i].coluna, i);
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

// Exibir Matrizes FEITO POR Twily

int ExiMat(float *M, int Lin, int Col, int Matz) {

	int ler1, ler2;

	for (ler1 = 0; ler1 < Col; ler1++) {
		printf("|  ");
		for (ler2 = 0; ler2 < Lin; ler2++) {
			printf("%f  ", *(M + (ler2 * 1) + ler1));
		}
		printf(" |\n");
	}
}
