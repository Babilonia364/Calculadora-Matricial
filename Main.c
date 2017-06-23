#include <stdio.h>
#include <stdlib.h>
#include "CutieMarkCrusaders.h"

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

/*
   BUGS CONHECIDOS:
        INSIRA AQUI OS BUGS QUE ENCONTRAR...
*/

// Area de Declaracao de Funcoes:
//MEU COMPILADOR FALA QUE ESTOU DECLARANDO DUAS VEZES AS FUNCOES...

void menu();
int smenu_vet(float *V1, float *V2, int Lin1, int Lin2);
int smenu_mat(float *M1[], float *M2[], int Lin1, int Col1, int Lin2, int Col2, int Matz);

void ret_smenu_vet(float *V1, float *V2, int Lin1, int Lin2);
void ret_smenu_mat (float *M1[], float *M2[], int Lin1, int Col1, int Lin2, int Col2, int Matz);


// AREA DA FUNCAO PRINCIPAL:

void main() {
	menu();
}


// (0) Menu Principal FEITO POR SILVEIRAX
void menu() {

    int opc_menu;

    printf("==================================================\n"
           "||       CALCULADORA VETORIAL E MATRICIAL       ||\n"
           "==================================================\n"
           "  (1) Operacoes Vetoriais.\n"
           "  (2) Operacoes Matriciais.\n"
           "  (3) Sair.\n"
           "      Qual operacao deseja executar? ");
    scanf("%d", &opc_menu);

    switch(opc_menu) {
        case 1:
            printf("\n");
            InsVet();
            break;
        case 2:
            printf("\n");
            InsMat();
            break;
        case 3:
            printf("      Obrigado por utilizar este programa!\n");
            break;
        default:
            printf("\7      Opcao invalida. Digite outra opcao.\n\n");
            menu();
    }
}


// (1) Submenu dos Vetores FEITO POR SILVEIRAX
int smenu_vet(float *V1, float *V2, int Lin1, int Lin2) {

    int opc_smenu_vet;

    printf("==================================================\n"
           "||             OPERACOES  VETORIAIS             ||\n"
           "==================================================\n"
           "  (1) Inserir vetores.\n"
           "  (2) Exibir vetores inseridos.\n"
           "  (3) Adicao vetorial.\n"
           "  (4) Subtracao vetorial.\n"
           "  (5) Produto de um vetor por um numero real.\n"
           "  (6) Produto escalar entre vetores.\n"
           "  (7) Norma vetorial.\n"
           "  (8) Voltar ao Menu Principal.\n"
           "  (9) Sair.\n"
           "      Qual operacao deseja executar? ");
    scanf("%d", &opc_smenu_vet);
    printf("\n");

    switch (opc_smenu_vet) {
        case 1:
            printf("==================================================\n"
                   "||               INSERIR  VETORES               ||\n"
                   "==================================================\n");
			printf("\n");
			InsVet();
            ret_smenu_vet(V1, V2, Lin1, Lin2);
            break;

        case 2:
            printf("==================================================\n"
                   "||              VETORES  INSERIDOS              ||\n"
                   "==================================================\n");
            ExiVet(V1, Lin1);
			ExiVet(V2, Lin2);
            ret_smenu_vet(V1, V2, Lin1, Lin2);
            printf("\n");
            break;

        case 3:
            printf("\n");
			SomaVet(V1, V2, Lin1, Lin2);
			ret_smenu_vet(V1, V2, Lin1, Lin2);
            break;
        case 4:
            printf("\n");
			SubVet(V1, V2, Lin1, Lin2);
			ret_smenu_vet(V1, V2, Lin1, Lin2);
            break;
        case 5:
		{
			printf("\n");
			int op=0, lac=0;
			printf("Digite 1 para operar o Vetor 1 com um real\nDigite 2 para operar o Vetor 2 com um real\nDigite 3 para sair");
			scanf("&d", &op);
			while(lac!=1)
			{
				switch(op)
				{
					case 1:
						VetPlusReal (V1, Lin1);
						lac=1;
						break;
					case 2:
						VetPlusReal (V2, Lin2);
						lac=1;
						break;
					case 3:
						lac=1;
						break;
					default:
						printf("Opcao invalida\n");
						lac=1;
						break;
				}
			}
			ret_smenu_vet(V1, V2, Lin1, Lin2);
            break;
		}
        case 8:
			SairVet(V1, V2);
            menu();
            break;
        case 9:
			SairVet(V1, V2);
            printf("      Obrigado por utilizar este programa!\n");
            break;
        default:
            printf("\7      Opcao invalida. Digite outra opcao.\n \n");
            smenu_vet(V1, V2, Lin1, Lin2);
    }
}


// (2) Submenu das Matrizes FEITO POR SILVEIRAX
int smenu_mat(float *M1[], float *M2[], int Lin1, int Col1, int Lin2, int Col2, int Matz) {

    int opc_smenu_mat;

    printf("==================================================\n"
           "||             OPERACOES MATRICIAIS             ||\n"
           "==================================================\n"
           "  (1) Inserir matrizes.\n"
           "  (2) Exibir matrizes inseridas.\n"
           "  (3) Verificador de matrizes especiais.\n"
           "  (4) Adicao matricial.\n"
           "  (5) Subtracao matricial.\n"
           "  (6) Produto de uma matriz por um numero real.\n"
           "  (7) Produto matricial.\n"
           "  (8) Determinante.\n"
           "  (9) Voltar ao Menu Principal.\n"
           "  (0) Sair.\n"
           "      Qual operacao deseja executar? ");
    scanf("%d", &opc_smenu_mat);
    printf("\n");

    switch (opc_smenu_mat) {
        case 1:
            printf("\n");
			InsMat(); //Declara os vetores todos de novo
            break;
        case 2:
			printf("\n");
			ExiMat(M1, Lin1, Col1);
			ExiMat(M2, Lin2, Col2);
			ret_smenu_mat (M1, M2, Lin1, Col1, Lin2, Col2, Matz);
            break;
        case 3:
		{
            printf("\n");
			int op=0, lac=0;							//Variaveis de controle
			printf("\n");
			printf("Digite 1 para operar a matriz 1\nDigite 2 para operar a matriz 2\nDigite 3 para retornar\n");
			scanf("%d", &op);
			while(lac!=1)
			{
				switch (op)
				{
					case 1:
						Simetrica(M1, Lin1, Col1);
						lac=1;
						break;
					case 2:
						Simetrica(M2, Lin2, Col2);
						lac=1;
						break;
					case 3:
						lac =1;
						break;
					default:
						printf("Operacao Invalida\n");
						lac =1;
						break;
				}
			}
			ret_smenu_mat (M1, M2, Lin1, Col1, Lin2, Col2, Matz);
			break;
		}
        case 4:
            printf("\n");
			AuxSoma(M1, M2, Lin1, Col1, Lin2, Col2, Matz);
			ret_smenu_mat (M1, M2, Lin1, Col1, Lin2, Col2, Matz);
            break;
        case 5:
            printf("\n");
            break;
        case 6:
		{
            printf("\n");
			int op=0, lac=0;							//Variaveis de controle
			printf("\n");
			printf("Digite 1 para operar a matriz 1\nDigite 2 para operar a matriz 2\nDigite 3 para retornar\n");
			scanf("%d", &op);
			while(lac!=1)
			{
				switch (op)
				{
					case 1:
						MatPlusReal(M1, Lin1, Col1);
						lac=1;
						break;
					case 2:
						MatPlusReal(M2, Lin2, Col2);
						lac=1;
						break;
					case 3:
						lac =1;
						break;
					default:
						printf("Operacao Invalida, tente novamente\n");
						lac=1;
						break;
				}
			}
			ret_smenu_mat (M1, M2, Lin1, Col1, Lin2, Col2, Matz);
            break;
		}
        case 7:
            printf("\n");
            break;
        case 8:
		{
			printf("\n");
			int op=0, lac=0;							//Variaveis de controle
			printf("Digite 1 para operar a matriz 1\nDigite 2 para operar a matriz 2\nDigite 3 para retornar\n");
			scanf("%d", &op);
			while(lac!=1)
			{
				switch(op)
				{
					case 1:
						Determinante(M1, Lin1, Col1);
						lac=1;
						break;
					case 2:
						Determinante(M2, Lin2, Col2);
						lac=1;
						break;
					case 3:
						lac=1;
						break;
					default:
						printf("Operacao invalida\n");
						lac=1;
						break;
				}
			}
			ret_smenu_mat (M1, M2, Lin1, Col1, Lin2, Col2, Matz);
            break;
		}
		case 9:
			Sair(M1, M2);
			break;
        case 0:
			Sair(M1, M2);
            printf("      Obrigado por utilizar este programa!\n");
            break;
        default:
            printf("\7      Opcao invalida. Digite outra opcao.\n\n");
            menu();
    }
}



// FUNCOES ADICIONAIS:

void ret_smenu_vet (float *V1, float *V2, int Lin1, int Lin2) {
    printf("  Pressione ENTER para voltar ao menu anterior.");
    getchar();
    getchar();
    smenu_vet(V1, V2, Lin1, Lin2);
}

void ret_smenu_mat (float *M1[], float *M2[], int Lin1, int Col1, int Lin2, int Col2, int Matz) {
    printf("  Pressione ENTER para voltar ao menu anterior.");
    getchar();
    getchar();
    smenu_mat(M1, M2, Lin1, Col1, Lin2, Col2, Matz);
}
