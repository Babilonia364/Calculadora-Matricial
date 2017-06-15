#include <stdio.h>
#include "CutieMarkCrusaders.h"
void menu();
int smenu_vetor();
int smenu_matriz();

void main()
{
	menu ();
}

/*MALLOC EU SEI USAR, MAS O COMANDO FREE QUE E BOM... Bom que da 'raquear' uns pc maroto deixando ponteiro aberto hihihihihehehehahahhaha
Camila e Carlos, fazer subtração vetorial e produto escalar xoxo*/


//=== Submenu dos Vetores ===// FEITO POR SILVEIRAX

int smenu_vetor () 
{

    // Area de Declaracao de Variaveis:

    int opc_smenu_vetor;

    // Area do Algoritmo:

    printf("==================================================\n");
    printf("||             OPERACOES  VETORIAIS             ||\n");
    printf("==================================================\n");
    printf("  (1) Ler vetores.\n");
    printf("  (2) Adicao vetorial.\n");
    printf("  (3) Subtracao vetorial.\n");
    printf("  (4) Produto escalar.\n");
    printf("  (5) Produto vetorial.\n");
    printf("  (6) Voltar ao Menu Principal.\n");
    printf("  (7) Sair.\n");
    printf("      Qual operacao deseja executar? ");
    scanf("%d", &opc_smenu_vetor);

    switch (opc_smenu_vetor) 
	{
        case 1:
			DeclaraVet(opc_smenu_vetor);
            printf("\n");
            break;
        case 2:
			DeclaraVet(opc_smenu_vetor);
            printf("\n");
            break;
        case 3:
            printf("\n");
            break;
        case 4:
            printf("\n");
            break;
        case 5:
            printf("\n");
            break;
        case 6:
            menu();
            break;
        case 7:
            printf("      Obrigado por utilizar este programa!\n");
            break;
        default:
            printf("      Opcao invalida. Digite outra opcao.\n");
            smenu_vetor();
    }
}

//=== Submenu das Matrizes ===// FEITO POR SILVEIRAX

int smenu_matriz () 
{

    // Area de Declaracao de Variaveis:

    int opc_smenu_matriz;

    // Area do Algoritmo:

    printf("==================================================\n");
    printf("||             OPERACOES MATRICIAIS             ||\n");
    printf("==================================================\n");
    printf("  (1) Ler matrizes.\n");
    printf("  (2) Verificador de matrizes especiais.\n");
    printf("  (3) Adicao matricial.\n");
    printf("  (4) Subtracao matricial.\n");
    printf("  (5) Produto matricial.\n");
    printf("  (6) Divisao matricial.\n");
    printf("  (7) Determinantes.\n");
    printf("  (8) Voltar ao Menu Principal.\n");
    printf("  (9) Sair.\n");
    printf("      Qual operacao deseja executar? ");
    scanf("%d", &opc_smenu_matriz);

    switch (opc_smenu_matriz) 
	{
        case 1:
            printf("\n");
            break;
        case 2:
            printf("\n");
            break;
        case 3:
            printf("\n");
            break;
        case 4:
            printf("\n");
            break;
        case 5:
            printf("\n");
            break;
        case 6:
            printf("\n");
            break;
        case 7:
            printf("\n");
            break;
        case 8:
            menu();
            break;
        case 9:
            printf("      Obrigado por utilizar este programa!\n");
            break;
        default:
            printf("      Opcao invalida. Digite outra opcao.\n");
            smenu_matriz();
    }
}

//=== Menu Principal ===// FEITO POR SILVEIRAX

void menu () 
{

    // Area de Declaracao de Variaveis:

    int opc_menu;

    // Area do Algoritmo:

    printf("==================================================\n");
    printf("||       CALCULADORA VETORIAL E MATRICIAL       ||\n");
    printf("==================================================\n");
    printf("  (1) Operacoes Vetoriais.\n");
    printf("  (2) Operacoes Matriciais.\n");
    printf("  (3) Sair.\n");
    printf("      Qual operacao deseja executar? ");
    scanf("%d", &opc_menu);

    switch(opc_menu) 
	{
        case 1:
            smenu_vetor();
            break;
        case 2:
            smenu_matriz();
            break;
        case 3:
            printf("      Obrigado por utilizar este programa!\n");
            break;
        default:
            printf("      Opcao invalida. Digite outra opcao.\n");
            menu();
    }
}
