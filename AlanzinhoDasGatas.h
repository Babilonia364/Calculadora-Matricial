#include <stdio.h>
int menu();
int SomaVet(int *V1, int *V2, int n);
void DeclaraVet();
int smenu_vetor();
int smenu_matriz();


//=== Soma Vetorial ===// FEITO POR DasGatas

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

//=== Declaração de vetores ===// FEITO POR DasGatas
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
            printf("\n");
            break;
        case 2:
            printf("\n");
			void DeclaraVet();
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

int menu () 
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
