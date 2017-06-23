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
int smenu_mat(float *M1[], float *M2[], int Lin1, int Col1, int Lin2, int Col2, int Matz);

// FUNCOES DOS VETORES:

void InsVet(int opc_smenu_vet);
void ExiVet(float *V1, int L);
float* SomaVet(float *V1, float *V2, int n, int n2, int S);


// FUNCOES DAS MATRIZES:

void FillLinCol(int *Lin, int *Col, int Matz);
void InsMat();
void Sair(float *M1[], float *M2[]);
void ExiMat(float *M[], int Lin, int Col);
void AuxSoma(float *M1[], float *M2[], int Lin1, int Col1, int Lin2, int Col2, int Matz);
void MatPlusReal(float *M[], int Lin, int Col);
float** FillMat(float *M[], int Lin, int Col, int Matz);
float** ADDMat(float *M1[], float *M2[], int Lin2, int Col2);



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

void InsVet(int opc_smenu_vet) {

    // Declarar quantos vetores se quer 'len' e variaveis de controle i e j.

	int len, i = 0, j = 0;

	printf("  Insira o numero de vetores a se operar: ");
	scanf("%d", &len);
	printf("\n");

    // Vetorizar o struct e criar quantos vetores se desejar.

	struct Vetores V[len];
	struct Vetores Soma;

	for (i = 0; i < len; i++) {
		printf("  Insira o numero de coordenadas do vetor %d: ", i + 1);
		scanf("%d", &V[i].linha);

    // Se for a segunda vez que o laco roda

		if(i >= 1) {
			if (V[i].linha>=V[i-1].linha) {
                Soma.linha=V[i].linha;
			}
			else {
                Soma.linha=V[i-1].linha;
            }
		}
	}

	Soma.Vet = malloc(Soma.linha * sizeof(float));  // Declarando o vetor que armazenara a soma

    printf("\n");
	for (j = 0; j < len; j++) {
		V[j].Vet = malloc(V[j].linha * sizeof(float));
		for(i = 0; i < V[j].linha; i++) {
			printf("  Insira o elemento %d do vetor %d: ", i + 1, j + 1);
			scanf("%f", &V[j].Vet[i]);
		}
	}
	printf("\n");


// (1.2) Exibir Vetores Inseridos:

    // Passa 1 vetor e 1 inteiro para a funcao o vetor a ser lido e seu tamanho.

void ExiVet(float *V1, int L) {

	int m;

    // Le o vetor e imprime na tela:

	printf("  ( ");
	for (m = 0; m < L; m++) {
		printf("%.1f ", V1[m]);
	}
	printf(")\n \n");
}

// Soma Vetorial FEITO POR Twily:

    // Passa 2 vetores e seu tamanho na tela:

float* SomaVet(float *V1, float *V2, int n, int n2, int S) {

	float *Soma2 = malloc(n * sizeof(float));
	int m;

	for (m = 0; m < n; m++) {
		Soma2[m] = V1[m];
		if(S >= 1) {

			// Faz a soma caso haja 2 vetores e eles sejam de tamanhos iguais

			if (n == n2) {
				V2[m] = Soma2[m] + V2[m];
				printf("%f ", V2[m]);
			}
			else {
				printf("\7      Vetores de tamanho diferentes. Digite outra opcao.\n \n");
			}
		}
	}
	printf("\n\n");
	free (Soma2);
	return V2;
}


// SWITCH PARA PUXAR FUNÇÕES DA BIBLIOTECA --- FEITO POR Twily:

	switch (opc_smenu_vet){
		case 1:
			j = 0;
			while (j < len) {             // Puxa a funcao ler vetores e printa-los na tela
			ExiVet(V[j].Vet, V[j].linha);
			j++;
			}
			break;
		case 2:
		    break;
		case 3:
			if (len >= 2) {
				j = 0;
				while(j < len) {
					Soma.Vet = SomaVet(V[j].Vet, Soma.Vet, V[j].linha, Soma.linha, j);				// Puxa a função soma
					j++;
				}
			} else {printf(":)\n:)\n:)\n");}
			break;
		default:
			printf("\7      Opcao invalida. Digite outra opcao.\n \n");
			break;
	}
}


/* ESCOPO DAS FUNCOES COM MATRIZES */

//Funcao para mudar o valor das linhas e colunas das matrizes da funcao principal
void FillLinCol(int *Lin, int *Col, int Matz)
{
	int Linha, Coluna;
	printf("\n  Digite o numero de linhas de sua matriz %d: ", Matz + 1);
	scanf("%d", &Linha);
	printf("\n  Digite o numero de colunas de sua matriz %d: ", Matz + 1);
	scanf("%d", &Coluna);
	printf("\n");
	*Lin=Linha;					//Fazendo isso, podemos mudar o valor das linhas e colunas sem precisar dar return, ou seja
	*Col=Coluna;				//Uma funcao void com 2 returns, MAGIA NEGRA!!!
}

// Declarando as Matrizes FEITO POR Twily:

float** FillMat(float *M[], int Lin, int Col, int Matz) {					//Funcao de preenchimento de matrizes, so existe porque serve para N vetores
																				// Declarando contadores
	int i, j;
	float **Mat;
																			// Alocacao dinamica de linhas e colunas
	Mat = malloc(Col * sizeof(float));
	for (i = 0; i < Col; i++) 
	{
		Mat[i] = malloc(Lin * sizeof(float));
		for(j = 0; j < Lin; j++) 
		{
			printf("  Digite o elemento da linha %d e coluna %d da matriz %d: ", i+1, j+1, Matz+1);
			scanf("%f", &Mat[i][j]);
			M[i][j]=Mat[i][j];												//Usando a matriz recem criada para preencher a matriz antiga
		}
	}
	free(Mat);
	return M;
}

void InsMat()			//Agora essa funcao chama o submenu 2, assim, os structs com os vetores ficam fora das funcoes e podem ser chamados pelo submenu dos
{						//vetores sem perdermos os vetores ou sem eles serem resetados

	int matz=2, i, j, k;						//matz sera o numero de matrizes existentes
	int *lin, *col;								//Declarando ponteiros que apontarao para linha e coluna
	struct Matrizes M[matz];
	printf("\n");
	for (k=0; k<matz; k++)
	{
		lin=&M[k].linha;
		col=&M[k].coluna;
		FillLinCol(lin, col, k);									//Definindo os valores das linhas e colunas
		M[k].Mat = malloc(M[k].coluna*sizeof(float));
		for (i = 0; i < M[k].coluna; i++) 
		{
			M[k].Mat[i] = malloc(M[k].linha * sizeof(float));
		}
		M[k].Mat=FillMat(M[k].Mat, M[k].linha, M[k].coluna, k);		//Preenchendo a matriz
	}
	smenu_mat(M[0].Mat, M[1].Mat, M[0].linha, M[0].coluna, M[1].linha, M[1].coluna, matz);
}

// Exibir Matrizes FEITO POR Twily

void ExiMat(float *M[], int Lin, int Col) 		//Recebe a matriz, sua linha e sua coluna
{
	int ler1, ler2;								//Variaveis para percorrer a matriz
	printf("\n");
	for (ler1 = 0; ler1 < Col; ler1++) {
		printf("|  ");
		for (ler2 = 0; ler2 < Lin; ler2++) {
			printf("%f  ", M[ler1][ler2]);
		}
		printf(" |\n");
	}
}


//Funcao de soma de matrizes //
float** ADDMat(float *M1[], float *M2[], int Lin2, int Col2)						//Funcao que executa a soma de N vetores, mas no trabalho vai executar so 2 :)
{			//Recebe Matriz Soma da funcao auxiliar, matriz 2 declarada na funcao de declaracao, linha da matriz 2 e coluna da matriz 2 e a contadora das N matrizes
	int m, n;
	for (m=0; m<Col2; m++)
	{
		printf("| ");
		for (n=0; n<Lin2; n++)
		{
			M1[m][n]=M2[m][n]+M1[m][n];
			printf("%f ", M1[m][n]);
		}
		printf(" |\n");
	}
	return M1;
}

void AuxSoma(float *M1[], float *M2[], int Lin1, int Col1, int Lin2, int Col2, int Matz)	//Funcao para auxiliar a soma criando uma variavel que vai receber a soma
{			//Recebe Matriz 1 e 2 declaradas na funcao de declaracao, linhas e colunas das respectivas matrizes, alem da quantidade das N matrizes existentes
	if(Col1 == Col2 && Lin1 == Lin2)
	{
		struct Matrizes Soma;	//Cria um struct soma para poder receber os valores de M1, que e outro struc soma, se fosse float tentando receber de um
		int m, n;				//float de dentro do struct daria erro, nao sei o porque
		Soma.Mat=malloc(Col1*sizeof(float));
		for(m=0; m<Col1; m++)
		{
			Soma.Mat[m]=malloc(Lin1*sizeof(float));
		}
		for(m=0; m<Col1; m++)
		{
			for(n=0; n<Lin1; n++)
			{
				Soma.Mat[m][n]=M1[m][n];
			}
		}
		Soma.Mat=ADDMat(Soma.Mat, M2, Lin2, Col2);
		free(Soma.Mat);
	} else
	{
		printf("Matrizes de tamanhos invalidos, reescreva a matriz e tente novamente\n");
	}
}

void Sair(float *M1[], float *M2[])
{
	free (M1);							//Desalocando espaço na memoria que as matrizes sugavam, essas suguinhas
	free (M2);
}

void MatPlusReal(float *M[], int Lin, int Col)
{
	int m, n;
	float r;												//Declarando numero real
	printf("Digite o numero real que vc quer operar: ");
	printf("\n");
	scanf("%f", &r);
	for(m=0; m<Col; m++)
	{
		printf("|	");
		for(n=0; n<Lin; n++)
		{
			printf("%f ", M[m][n]*r);
		}
		printf("	|\n");
	}
}
