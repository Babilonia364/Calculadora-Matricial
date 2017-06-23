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
int smenu_vet(float *V1, float *V2, int Lin1, int Lin2);
int smenu_mat(float *M1[], float *M2[], int Lin1, int Col1, int Lin2, int Col2, int Matz);

// FUNCOES DOS VETORES:

void InsVet();
void ExiVet(float *V1, int L);
void SairVet(float *V1, float *V2);
void SomaVet(float *V1, float *V2, int Lin1, int Lin2);
void SubVet(float *V1, float *V2, int Lin1, int Lin2);
void VetPlusReal (float *V1, int Lin1);


// FUNCOES DAS MATRIZES:

void FillLinCol(int *Lin, int *Col, int Matz);
void InsMat();
void Sair(float *M1[], float *M2[]);
void ExiMat(float *M[], int Lin, int Col);
void AuxSoma(float *M1[], float *M2[], int Lin1, int Col1, int Lin2, int Col2, int Matz);
void MatPlusReal(float *M[], int Lin, int Col);
void Determinante(float *M[], int Lin, int Col);
void Simetrica(float *M[], int Lin, int Col);
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

struct Determinante {
	float soma, multi, det;
};


/* (1) FUNCOES COM VETORES */

// (1.1) Inserir Vetores FEITO POR Twily

void InsVet() {

    // Declarar quantos vetores se quer 'len' e variaveis de controle i e j.

	int len=2, i = 0, j = 0;

    // Vetorizar o struct e criar quantos vetores se desejar.

	struct Vetores V[len];

	for (i = 0; i < len; i++) {												//Declarando o numero de linhas dos 2 vetores
		printf("  Insira o numero de coordenadas do vetor %d: ", i + 1);
		scanf("%d", &V[i].linha);
	}
    printf("\n");
	for (j = 0; j < len; j++) {
		V[j].Vet = malloc(V[j].linha * sizeof(float));
		for(i = 0; i < V[j].linha; i++) {
			printf("  Insira o elemento %d do vetor %d: ", i + 1, j + 1);
			scanf("%f", &V[j].Vet[i]);
		}
	}
	printf("\n");
	smenu_vet(V[0].Vet, V[1].Vet, V[0].linha, V[1].linha);
}


// (1.2) Exibir Vetores Inseridos:

    // Passa 1 vetor e 1 inteiro para a funcao o vetor a ser lido e seu tamanho.

void ExiVet(float *V1, int L) {

	int m;

    // Le o vetor e imprime na tela:

	printf("  ( ");
	for (m = 0; m < L; m++) {
		printf("%.1f ", V1[m]);
	}
	printf(") \n");
}

// Soma Vetorial FEITO POR Twily:

    // Passa 2 vetores e seu tamanho na tela:

void SomaVet(float *V1, float *V2, int Lin1, int Lin2) {
	if (Lin1 == Lin2) {		// Faz a soma caso haja 2 vetores e eles sejam de tamanhos iguais
		float *Soma2 = malloc(Lin1 * sizeof(float));
		int m;
		printf("(  ");
		for (m = 0; m < Lin1; m++) 
		{
			Soma2[m] = V1[m]+V2[m];
			printf("%f ", Soma2[m]);
		}
		printf(" )\n");
		free (Soma2);
	} else {printf("Quantidade de elementos incompatível, reescreva os vetores e tente novamente\n");}
}

//Subtracao vetorial, análogo a soma
void SubVet(float *V1, float *V2, int Lin1, int Lin2)
{
	if(Lin1==Lin2)
	{
		float *Subt=malloc(Lin1*sizeof(float));
		int m, n, lac=0;
		printf("Digite 1 para subtrair V2 de V1\nDigite 2 para subtrair V1 de V2\nDigite 3 para sair\n");
		scanf("%d", &n);
		while(lac!=1)
		{
			printf("( ");
			for(m=0; m<Lin1; m++)
			{
				switch(n)
				{
				case 1:
				{
					Subt[m]=V1[m]-V2[m];
					printf("%f ", Subt[m]);
					lac = 1;
					break;
				}
				case 2:
				{
					Subt[m]=V2[m]-V1[m];
					printf("%f", Subt[m]);
					lac = 1;
					break;
				}
				case 3:
					lac = 1;
					break;
				default:
					printf(" Operacao invalida ");
					break;
				}
			}
			printf(" )\n");
		}
	} else {printf("Quantidade de elementos incompatível, reescreva os vetores e tente novamente\n");}
}

void VetPlusReal (float *V1, int Lin1)
{
	int m;
	float r;
	printf("(  ");
	for(m=0; m<Lin1; m++)
	{
		printf("%f ", V1[m]);
	}
	printf(" )\n");
}

void SairVet(float *V1, float *V2)
{
	free(V1);
	free(V2);
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

void Determinante(float *M[], int Lin, int Col)
{
	if(Lin==Col)
	{
		if(Lin<=3)
		{
			switch(Lin)
			{
				case 1:
					printf("A determinante e: %f\n", M[0][0]);
					break;
				case 2:
				{
					int x, y, n;																		//Contadores
					struct Determinante Det[2];
					for(n=0; n<2; n++)																	//0 diagonal principal, 1 diagonal secundaria
					{
						Det[n].multi=1;
						Det[n].soma=0;
					}
					for(n=0; n<1; n++)																	//Inicio do algoritimo de calculo de matriz 2x2
					{
						for(x=0; x<2; x++)
						{
							y=(x+n)%2;														//O calculo da variavel y e circular, ou seja, sempre que y for 2
							Det[0].multi=Det[0].multi*M[x][y];								//O mod atribuira o valor dele a 0, assim podemos percorrer toda
						}																	//A matriz.
						Det[0].soma=Det[0].soma+Det[0].multi;
					}
					for(n=1; n<2; n++)
					{
						for(x=0; x<2; x++)
						{
							y=(x+n)%2;
							Det[1].multi=Det[1].multi*M[y][x];
						}
						Det[1].soma=Det[1].soma+Det[1].multi;
					}
					Det[0].det=Det[0].soma-Det[1].soma;
					printf("A determinante e: %f\n", Det[0].det);
					break;
				}
				case 3:
				{
					int x, y, n;																		//Contadores
					struct Determinante Det[2];
					for(n=0; n<2; n++)																	//0 diagonal principal, 1 diagonal secundaria
					{
						Det[n].multi=1;
						Det[n].soma=0;
					}
					for(n=0; n<3; n++)																	//Inicio do algoritimo de calculo de matriz 2x2
					{
						for(x=0; x<3; x++)
						{
							y=(x+n)%3;														//O calculo da variavel y e circular, ou seja, sempre que y for 2
							Det[0].multi=Det[0].multi*M[x][y];								//O mod atribuira o valor dele a 0, assim podemos percorrer toda
						}																	//A matriz.
						Det[0].soma=Det[0].soma+Det[0].multi;
					}
					for(n=2; n<5; n++)
					{
						for(x=0; x<3; x++)
						{
							y=(n-x)%3;
							Det[1].multi=Det[1].multi*M[y][x];
						}
						Det[1].soma=Det[1].soma+Det[1].multi;
					}
					Det[0].det=Det[0].soma-Det[1].soma;
					printf("A determinante e: %f\n", Det[0].det);
					break;
				}
				default:
					printf("Erro #001");
					break;
			}
		}else {printf("Matriz quadrada maior que 3 elementos\nO programa nao conseguira calcular a determinante\n");}
	} else {printf("Nao e uma matriz quadrada\nO programa nao conseguira calcular a determinante\n");}
}

void Simetrica(float *M[], int Lin, int Col)
{
	if (Lin == Col)						//Verifica se a matriz e quadrada
	{
		int n, m, cont=0;
		for(m=0; m<Lin; m++)
		{
			for(n=0; n<Col; n++)
			{
				if(M[m][n]==M[n][m])	//Percorre a matriz toda contando quantos elementos iguais ela tem
				{
					cont++;
				}
			}
		}
		if(cont==(Lin*Col))
		{
			printf("Matriz simetrica");
		}else {printf("Nao e simetrica");}
	} else {printf("Nao e simetrica pois nao e quadrada\n");}
}
