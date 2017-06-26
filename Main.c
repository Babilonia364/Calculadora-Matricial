#include <stdio.h>
#include <stdlib.h>
#include "vetorematriz.h"

/********************************************************
 *            UNIVERSIDADE ESTADUAL DO CEARA            *
 *           CENTRO  DE CIENCIAS E TECNOLOGIA           *
 *            CURSO DE CIENCIA DA COMPUTACAO            *
 *    DISCIPLINA  Introducao a Ciencia da Computacao    *
 *                                                      *
 *                                     Data: 25/06/2017 *
 *                                                      *
 * Professor: Leonardo Sampaio Rocha                    *
 *                                                      *
 * Alunos: Alan Pereira de Vasconcelos Junior   1394102 *
 *         Camila Alves Barbosa                 1394330 *
 *         Joao Alison de Moraes Silveira       1387122 *
 *******************************************************/


// AREA DE DECLARACAO DAS FUNCOES:

void menu();
int smenu_vet(float *V1, float *V2, int Lin1, int Lin2);
int smenu_mat(float *M1[], float *M2[], int Lin1, int Col1, int Lin2, int Col2, int Matz);

void ret_smenu_vet(float *V1, float *V2, int Lin1, int Lin2);
void ret_smenu_mat (float *M1[], float *M2[], int Lin1, int Col1, int Lin2, int Col2, int Matz);


// AREA DA FUNCAO PRINCIPAL:

void main() {
	menu();
}



// (0) MENU PRINCIPAL

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
            printf("\n"
                   "==================================================\n"
                   "         INSIRA  OS  DADOS  DE 2 VETORES:         \n"
                   "==================================================\n");
            InsVet();
            break;
        case 2:
            printf("\n"
                   "==================================================\n"
                   "         INSIRA OS  DADOS  DE 2 MATRIZES:         \n"
                   "==================================================\n");
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



// (1) SUBMENU DOS VETORES

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
           "  (7) Voltar ao Menu Principal.\n"
           "  (8) Sair.\n"
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
                   "==================================================\n"
                   "  Os Vetores inseridos foram:                     \n");
            ExiVet(V1, Lin1);
			printf("\n");
			ExiVet(V2, Lin2);
            printf("\n");
            ret_smenu_vet(V1, V2, Lin1, Lin2);
            break;

        case 3:
            printf("==================================================\n"
                   "||                ADICAO VETORIAL               ||\n"
                   "==================================================\n");
			AddVet(V1, V2, Lin1, Lin2);
			printf("\n");
			ret_smenu_vet(V1, V2, Lin1, Lin2);
            break;
        case 4:
            printf("==================================================\n"
                   "||              SUBTRACAO VETORIAL              ||\n"
                   "==================================================\n");
			SubVet(V1, V2, Lin1, Lin2);
			printf("\n");
			ret_smenu_vet(V1, V2, Lin1, Lin2);
            break;
        case 5:
            printf("==================================================\n"
                   "||       PRODUTO DE VETOR POR NUMERO REAL       ||\n"
                   "==================================================\n");
			VetXReal(V1, V2, Lin1, Lin2);
			printf("\n");
            ret_smenu_vet(V1, V2, Lin1, Lin2);
            break;
        case 6:
            printf("==================================================\n"
                   "||        PRODUTO ESCALAR  ENTRE VETORES        ||\n"
                   "==================================================\n");
            ProdEsc(V1, V2, Lin1, Lin2);
            printf("\n");
            ret_smenu_vet(V1, V2, Lin1, Lin2);
            break;
        case 7:
			SairVet(V1, V2);
            menu();
            break;
        case 8:
			SairVet(V1, V2);
            printf("      Obrigado por utilizar este programa!\n");
            break;
        default:
            printf("\7      Opcao invalida. Digite outra opcao.\n \n");
            smenu_vet(V1, V2, Lin1, Lin2);
        }
}


// (2) SUBMENU DAS MATRIZES

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
			printf("==================================================\n"
                   "||               INSERIR MATRIZES               ||\n"
                   "==================================================\n");
			InsMat();                                                 //  Declara os vetores todos de novo.
            break;
        case 2:
            printf("==================================================\n"
                   "||              MATRIZES INSERIDAS              ||\n"
                   "==================================================\n"
                   "  As Matrizes inseridas foram:                    \n");
			ExiMat(M1, Lin1, Col1);
			printf("\n");
			ExiMat(M2, Lin2, Col2);
			printf("\n");
			ret_smenu_mat (M1, M2, Lin1, Col1, Lin2, Col2, Matz);
            break;
        case 3: {
            printf("==================================================\n"
                   "||         VERIFICAR MATRIZES ESPECIAIS         ||\n"
                   "==================================================\n");

			int op = 0, lac = 0;         	//  Variaveis de controle.

			printf("  (1) Operar matriz 1.           \n"
                   "  (2) Operar matriz 2.           \n"
                   "  (3) Retornar ao menu anterior. \n"
                   "  Qual operacao deseja executar? ");
			scanf("%d", &op);
			printf("\n");
			while (lac != 1) {
				switch (op) {
					case 1:
						printf("  A matriz transposta e:\n");
						Transposta(M1, Lin1, Col2);
						printf("\n");
						Simetrica(M1, Lin1, Col1);
						printf("\n");
						lac = 1;
						break;
					case 2:
						printf("  A matriz transposta e:\n");
						Transposta(M2, Lin1, Col2);
						printf("\n");
						Simetrica(M2, Lin2, Col2);
						printf("\n");
						lac = 1;
						break;
					case 3:
						lac = 1;
						break;
					default:
						printf("\7  Operacao invalida. Tente novamente.\n");
						printf("\n");
						lac = 1;
						break;
				}
			}
			ret_smenu_mat (M1, M2, Lin1, Col1, Lin2, Col2, Matz);
			break;
		}
        case 4:
            printf("==================================================\n"
                   "||               ADICAO MATRICIAL               ||\n"
                   "==================================================\n"
                   "  A soma das Matrizes resulta em:                 \n");
			AuxSoma(M1, M2, Lin1, Col1, Lin2, Col2, Matz);
			printf("\n");
			ret_smenu_mat (M1, M2, Lin1, Col1, Lin2, Col2, Matz);
            break;
        case 5:
            printf("==================================================\n"
                   "||             SUBTRACAO  MATRICIAL             ||\n"
                   "==================================================\n"
                   "  A diferenca das Matrizes resulta em:            \n");
            AuxSub(M1, M2, Lin1, Col1, Lin2, Col2, Matz);
            printf("\n");
            ret_smenu_mat (M1, M2, Lin1, Col1, Lin2, Col2, Matz);
            break;
        case 6: {
            printf("==================================================\n"
                   "||      PRODUTO DE MATRIZ  POR NUMERO REAL      ||\n"
                   "==================================================\n");

			int opc = 0, lac = 0;            //  Variaveis de controle.

			printf("  (1) Operar matriz 1.           \n"
                   "  (2) Operar matriz 2.           \n"
                   "  (3) Retornar ao menu anterior. \n"
                   "  Qual operacao deseja executar? ");
            scanf("%d", &opc);
			while (lac != 1) {
				switch (opc) {
					case 1:
						MatXReal(M1, Lin1, Col1);
						printf("\n");
						lac = 1;
						break;
					case 2:
						MatXReal(M2, Lin2, Col2);
						printf("\n");
						lac = 1;
						break;
					case 3:
						lac = 1;
						break;
					default:
						printf("\7  Operacao Invalida. Tente novamente.\n");
						printf("\n");
						lac = 1;
						break;
				}
			}
			ret_smenu_mat (M1, M2, Lin1, Col1, Lin2, Col2, Matz);
            break;
		}
        case 7:
            printf("==================================================\n"
                   "||              PRODUTO  MATRICIAL              ||\n"
                   "==================================================\n");
            MultMat (M1, M2, Lin1, Col1, Lin2, Col2);
            printf("\n");
            ret_smenu_mat (M1, M2, Lin1, Col1, Lin2, Col2, Matz);
            break;
        case 8: {
			printf("==================================================\n"
                   "||                 DETERMINANTE                 ||\n"
                   "==================================================\n");

			int opc = 0, lac = 0;        //  Variaveis de controle.

			printf("  (1) Operar matriz 1.           \n"
                   "  (2) Operar matriz 2.           \n"
                   "  (3) Retornar ao menu anterior. \n"
                   "  Qual operacao deseja executar? ");
            scanf("%d", &opc);
			printf("\n");
			while(lac != 1) {
				switch(opc) {
					case 1:
						Determinante(M1, Lin1, Col1);
						printf("\n");
						lac = 1;
						break;
					case 2:
						Determinante(M2, Lin2, Col2);
						printf("\n");
						lac = 1;
						break;
					case 3:
						lac = 1;
						break;
					default:
						printf("  Operacao invalida. Tente novamente.\n");
						lac = 1;
						break;
				}
			}
			ret_smenu_mat (M1, M2, Lin1, Col1, Lin2, Col2, Matz);
            break;
		}
		case 9:
			SairMat(M1, M2);
			menu();
			break;
        case 0:
			SairMat(M1, M2);
            printf("      Obrigado por utilizar este programa!\n");
            break;
        default:
            printf("\7      Opcao invalida. Insira outra opcao.\n\n");
            smenu_mat(M1, M2, Lin1, Col1, Lin2, Col2, Matz);
    }
}



// FUNCOES ADICIONAIS:

void ret_smenu_vet (float *V1, float *V2, int Lin1, int Lin2) {
    printf("  Pressione ENTER para voltar ao menu anterior.");
    getchar();
    getchar();
    smenu_vet(V1, V2, Lin1, Lin2);
};

void ret_smenu_mat (float *M1[], float *M2[], int Lin1, int Col1, int Lin2, int Col2, int Matz) {
    printf("  Pressione ENTER para voltar ao menu anterior.");
    getchar();
    getchar();
    smenu_mat(M1, M2, Lin1, Col1, Lin2, Col2, Matz);
};
