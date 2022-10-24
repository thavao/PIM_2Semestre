#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int id, idade;
	char cpf[50], nome[50], email[50], sexo;
	float altura, peso;
}Cliente;
//criar strutc de cardapio, onde, de acordo com uma conta 'peso altura sexo', ele recebera um tipo de variacao de comida.
void Cabecalho(){
printf("---------------------------------------------------------------------------------------------------------------------\n");
printf("                                                 nome da empresa                                                     \n");
printf("---------------------------------------------------------------------------------------------------------------------\n");
}

Cliente CadastroCliente(){
        fflush(stdin);
        Cliente clienteNovo;
        system("cls");
        Cabecalho();
        printf("### Menu de registro ###\n");
        printf("Insira suas informações de acordo com o pedido: \n");
        printf("------------------------------------------------\n");
        printf("Informe seu cpf |sem pontuacoes|: \n");
        gets(clienteNovo.cpf);
        fflush(stdin);
        printf("Informe seu nome: \n");
        fflush(stdin);
        gets(clienteNovo.nome);
        printf("Informe sua idade: \n");
        scanf("%d", &clienteNovo.idade);
        while(clienteNovo.idade <= 0 || clienteNovo.idade > 130){
            printf("Idade inválida informada, informe novamente: \n");
             scanf("%d", &clienteNovo.idade);
        }
        fflush(stdin);
        printf("Informe seu email: \n");
        gets(clienteNovo.email);
        fflush(stdin);
        printf("informe seu sexo |'M' ou 'F'|: \n");
        scanf("%c", &clienteNovo.sexo);
        clienteNovo.sexo = toupper(clienteNovo.sexo);
        while(clienteNovo.sexo != 'M' && clienteNovo.sexo != 'F'){
            printf("Sexo invalido informado, informe novamente: \n");
            scanf("%c", &clienteNovo.sexo);
            fflush(stdin);
        }
        fflush(stdin);
        printf("Informe seu peso: \n");
        scanf("%f", &clienteNovo.peso);
        while(clienteNovo.peso <= 0){
            printf("Peso inválido informado, informe novamente: ");
             scanf("%f", &clienteNovo.peso);
        }
        printf("Informe sua altura |em cm|: \n");
        scanf("%f", &clienteNovo.altura);
        while(clienteNovo.altura <= 0 || clienteNovo.altura > 300){
            printf("Altura inválida, informe novamente em cm: ");
            scanf("%f", &clienteNovo.altura);
        } //fazer metodos de definir tipos de cardapios prontos.
        return clienteNovo;
}

void menuInicial(Cliente *ListaClientes){
    system("cls");
    Cabecalho();
    int op;
    printf(" ### Menu inicial ### \n");
    printf("O que voce gostaria de realizar: \n");
    printf("[0]Sair \n[1]Cadastrar-se \n[2]Gerar Cardapio \n");
    scanf("%d", &op);
    while(op < 0 || op > 2){
        printf("Opcao invalida, insira outro valor: ");
        scanf("%d", &op);
    }
    switch(op){
    case 0:
        printf("Funcao ainda nao desenvolvida!\n");
        system("pause");
        menuInicial(ListaClientes);
        //sair do programa.
        break;
    case 1: ;
        Cliente clienteCadastrado;
        clienteCadastrado = CadastroCliente(*ListaClientes);
        for(int i = 0;i < 1000; i++){
            if(ListaClientes[i].cpf == 0){
                ListaClientes[i] = clienteCadastrado;
                i = 1002;
            }
        }
        printf("Cliente cadastrado com sucesso, para ver o seu cardapio, vá ao menu 'Gerar Cardapio\n");
        system("pause");
        break;
    case 2:
        printf("Funcao ainda nao desenvolvida!\n");
        system("pause");
        menuInicial(ListaClientes);
        //verificar o cpf do cliente, se existir mostrar o valor dele, se nao avisar que nao esta cadastrado e voltar ao menu.
        break;
    default:
        break;
    }
}
void main()//passar vetor como ponteiro!!
{
    setlocale(LC_ALL, "Portuguese");
    Cliente ListaClientes[1000];
    Cabecalho();
    printf("Bem vindo a -nome da empresa-\n");
    system("pause");
    system("cls");
    fflush(stdin);
    menuInicial(ListaClientes);
}
