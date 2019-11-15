#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "cliente.h"
#include "gerenciaCliente.h"
#include "conta.h"

/*Codigo desenvido por @Sidney Faccioli Bueno, os direitos de uso do codigo estao reservados.
    caso utilize o codigo tenha respeito por ele, algumas variaveis estao confusas mas nao a conflito
    APS(Atividade pratica supervisionada),
    Universidade Anhembi Morumbi;

    Data de desenvolvimento 11/11/2019;
    */




//Variaveis
struct tm *data_hora_atual;
time_t segundos;
char sair[4], tipo_criar;
char resposta1[4];
char ficar[4];
int acessar = 0;
int i, z=0;
int back = 0;
int gerente;

//Cabecalho
void cabecalho()
{
    printf("\n======================================");

    printf("\n Banco Union");

    printf("\n======================================");

    printf("\n\n\n");
}

//Introducao
void introducao()
{
    cabecalho();
    printf("Bem Vindo, voce possui uma conta conosco? (Sim/Nao)\n");
    gets(sair);
}
void ImprimirCliente(TCliente *Cliente)
{
    int t=0;
    system("cls");
    cabecalho();
    if (strcmp(sair, "NAO") == 0 || strcmp(sair, "Nao") == 0 || strcmp(sair, "nao") == 0)
    {
        do
        {
            system("cls");
            cabecalho();
            z = z + 1;

            printf("Por favor complete as informacoes abaixo\n\n");
            fflush(stdin);

            printf("Nome: ");
            fgets(Cliente[z].nome,30,stdin);
            fflush(stdin);

            printf("Telefone: ");
            scanf("%i", &Cliente[z].telefone);
            fflush(stdin);

            printf("Endereco: ");
            fgets(Cliente[z].endereco,30,stdin);
            fflush(stdin);

            printf("CPF: ");
            scanf("%s", &Cliente[z].cpf);
            fflush(stdin);

            system("cls");
            cabecalho();
            printf("Aqui esta suas informacoes:\n\n");

            printf("Nome: %s", Cliente[z].nome);

            printf("Telefone: %i\n", *Cliente[z].telefone);

            printf("Endereco: %s", Cliente[z].endereco);

            printf("CPF: %s\n", Cliente[z].cpf);

            printf("\nAs informacoes acima estao corretas? Sim/Nao\n");
            gets(resposta1);

            if (strcmp(resposta1, "SIM") == 0 || strcmp(resposta1, "Sim") == 0 || strcmp(resposta1, "sim") == 0)
            {
                Conta[z].saldo = 0;
                Data[z].dia = data_hora_atual->tm_mday;
                Data[z].mes = data_hora_atual->tm_mon+1;
                Data[z].ano = data_hora_atual->tm_year+1900;
                Data[z].hora = data_hora_atual->tm_hour;
                Data[z].minu = data_hora_atual->tm_min;
                Data[z].seg = data_hora_atual->tm_sec;

                system("cls");
                cabecalho();

                printf("Obrigado %sPor escolher nosso Banco\n\n", Cliente[z].nome);

                printf("Por favor digite uma senha numerica de 6 digitos.\n");
                scanf("%i", &Cliente[z].senha);

                system("cls");
                cabecalho();

                printf("Suas informacoes de acesso sao:\n");

                printf("Numero da conta: %i \n", z);

                printf("Senha: %i\n\n", *Cliente[z].senha);
                printf("\nSalve suas informacoes, elas sao importantes para acessar sua conta.\n");
                printf("Nos nunca iremos pedir sua senha, mantenha ela segura!\n\n\n");

                acessar = 1;
                Sleep(6000);
                system("pause");
            }
            if (strcmp(resposta1, "NAO") == 0 || strcmp(resposta1, "Nao") == 0 || strcmp(resposta1, "nao") == 0)
            {
                z = z - 1;
                t = 1;
            }
        }
        while(t==1);
    }
}
void Login()
{

    int tentativas = 3;
    int b = 3;
    int j;
    int Pass;



    if (strcmp(sair, "SIM") == 0 || strcmp(sair, "Sim") == 0 || strcmp(sair, "sim") == 0 || acessar == 1)
    {

        do
        {
            system("cls");
            cabecalho();

            printf("Numero da conta: ");

            scanf("%i", &i);

            printf("\nSenha: ");

            scanf("%i", &Pass);

            if(Pass == *Cliente[i].senha)
            {
                system("cls");
                cabecalho();
                printf("Acessando.");
                Sleep(1200);
                system("cls");
                cabecalho();
                printf("Acessando..");
                Sleep(1200);
                system("cls");
                cabecalho();
                printf("Acessando...");
                Sleep(1500);
                system("cls");
                cabecalho();
                printf("Acesso concedido!");
                Sleep(1200);


                b = 2;
            }
            else
            {

                tentativas = tentativas - 1;

                printf("Dados incorretos, tentativas restantes [%i]\n\n", tentativas);
                b = 0;
                system("pause");

                // se exceder o numero de tentativas

                if(tentativas == 0)
                {

                    system("cls");
                    cabecalho();
                    printf("Voce atingiu o numero maximo de tentivas, rede desconectada.\n\n");

                    exit(0);

                }

                b = 1;



            }

        }
        while(b == 1);

    }



}
void transferir()
{


    char resp_2[4];
    char Aresp[7];
    int a;
    int t;
    int y;
    float transferencia;

    do
    {
        t = 0;
        system("cls");
        cabecalho();

        printf("Qual numero da conta que deseja transferir\n");
        printf("Conta: ");
        scanf("%i", &a);
        system("cls");
        cabecalho();
        printf("DADOS:\n");
        printf("Nome: %s", Cliente[a].nome);
        printf("CPF: %s\n", Cliente[a].cpf);
        printf("Telefone: %i", *Cliente[a].telefone);
        fflush(stdin);
        printf("\n\nAs informacoes da conta a ser tranferida estao corretas? (Sim/Nao)\n");
        gets(resp_2);

        if (strcmp(resp_2, "SIM") == 0 || strcmp(resp_2, "Sim") == 0 || strcmp(resp_2, "sim") == 0)
        {
            system("cls");
            cabecalho();
            printf("Qual valor a ser transferido: (EX: 12.8)\nR$: ");
            scanf("%f", &transferencia);

            if(transferencia <= Conta[i].saldo && transferencia > 0)
            {
                system("cls");
                cabecalho();
                Conta[i].saldo = Conta[i].saldo - transferencia;
                Conta[a].saldo = Conta[a].saldo + transferencia;
                printf("A transferencia no valor de R$: %.2f , foi realizada com sucesso.\n", transferencia);
                printf("Voce tem disponivel: %.2f \n\n", Conta[i].saldo);
                Sleep(1200);

            }
            else
            {
                system("cls");
                cabecalho();
                printf("Saldo Insuficiente. Tente Novamente.\n\n\n");
                system("pause");
                a = 0;
            }
        }
        if (strcmp(resp_2, "NAO") == 0 || strcmp(resp_2, "Nao") == 0 || strcmp(resp_2, "nao") == 0)
        {

            a = 0;
            t = 1;

        }
    fflush(stdin);
    system("cls");
cabecalho();
    printf("Voce desejar voltar, sair ou tentar?\n");
    gets(Aresp);
    if (strcmp(Aresp, "VOLTAR") == 0 || strcmp(Aresp, "Voltar") == 0 || strcmp(Aresp, "voltar") == 0)
    {
        t=0;
        back = 1;
    }
    if (strcmp(Aresp, "SAIR") == 0 || strcmp(Aresp, "Sair") == 0 || strcmp(Aresp, "sair") == 0)
    {
        exit(0);
    }
    if (strcmp(Aresp, "TENTAR") == 0 || strcmp(Aresp, "Tentar") == 0 || strcmp(Aresp, "tentar") == 0)
    {
        t = 1;
    }
    }while(t==1);
}
void saque()
{
    char Aresp[7];
    float saque;
    int Pass;
    int tentativas = 3;
    int b = 1;
    int y = 1;

    do
    {
        system("cls");
        cabecalho();
        printf("Qua valor voce deseja sacar?\n");
        printf("R$: ");
        scanf("%f", &saque);
        if(saque <= Conta[i].saldo && saque > 0)
        {
            do
            {
                system("cls");
                cabecalho();
                printf("Por favor confirme a senha de 6 digitos:\n");
                scanf("%i", &Pass);
                if(Pass == *Cliente[i].senha)
                {
                    system("cls");
                    cabecalho();
                    printf("Acesso Permitido");
                    Sleep(1200);
                    system("cls");
                    cabecalho();
                    printf("Atualizando Conta");
                    Conta[i].saldo = Conta[i].saldo - saque;
                    Sleep(1200);
                    system("cls");
                    cabecalho();
                    printf("Contando notas");
                    Sleep(1500);
                    system("cls");
                    cabecalho();
                    printf("Finalizado! Por favor retire o dinheiro abaixo.\n");
                    printf("Voce tem disponivel: %.2f \n\n", Conta[i].saldo);
                    Sleep(1200);


                }
                else
                {

                    tentativas = tentativas - 1;

                    printf("Dados incoretos, tentativas restantes [%i]\n\n", tentativas);
                    b = 0;
                    system("pause");

                    // se exceder o numero de tentativas

                    if(tentativas == 0)
                    {

                        system("cls");
                        cabecalho();
                        printf("Voce atingiu o numero maximo de tentivas, rede desconectada.\n\n");

                        exit(0);

                    }
                }


            }
            while(b == 0);
        }
        else
        {
            system("cls");
            cabecalho();
            printf("Saldo Insuficiente. Tente Novamente.\n\n\n");
            system("pause");
        }
    system("cls");
    cabecalho();
    fflush(stdin);
    printf("Voce desejar voltar, sair ou tentar?\n");
    gets(Aresp);
    if (strcmp(Aresp, "VOLTAR") == 0 || strcmp(Aresp, "Voltar") == 0 || strcmp(Aresp, "voltar") == 0)
    {
        y = 1;
        back = 1;
    }
    if (strcmp(Aresp, "SAIR") == 0 || strcmp(Aresp, "Sair") == 0 || strcmp(Aresp, "sair") == 0)
    {
        exit(0);
    }
    if (strcmp(Aresp, "TENTAR") == 0 || strcmp(Aresp, "Tentar") == 0 || strcmp(Aresp, "tentar") == 0)
    {
        y=0;
    }
    }while( y == 0);
}
void mudarconta()
{

        int a;
        int d = 99;
        int Pass;
        int back = 0;
        char Aresp[4];
        char volt[7];

        back = 0;
        system("cls");
        cabecalho();
        printf("Digite a senha do Gerente:\n");
        scanf("%i", &Pass);

        if(Pass == gerente){
                system("cls");
                cabecalho();
                fflush(stdin);
                printf("Qual o numero da conta que deseja alterar.\nConta: ");
                scanf("%i", &a);
            system("cls");
            cabecalho();
            printf("Esses sao os dados atuais da conta: %.3i\n\n", a);
            printf("Nome: %s", Cliente[a].nome);
            printf("Telefone: %i\n", *Cliente[a].telefone);
            printf("Endereco: %s", Cliente[a].endereco);
            printf("CPF: %s\n", Cliente[a].cpf);
            printf("Senha: %i \n\n", *Cliente[a].senha);
            printf("\nPor favor digite as novas informacoes\n");
            fflush(stdin);
            printf("Nome: ");
            fgets(Cliente[d].nome,30,stdin);
            fflush(stdin);

            printf("Telefone: ");
            scanf("%i", &Cliente[d].telefone);
            fflush(stdin);

            printf("Endereco: ");
            fgets(Cliente[d].endereco,30,stdin);
            fflush(stdin);

            printf("CPF: ");
            scanf("%s", &Cliente[d].cpf);
            fflush(stdin);

            printf("Senha: ");
            scanf("%i", &Cliente[d].senha);
            fflush(stdin);

            system("cls");
            cabecalho();
            printf("Estas serao as novas informacoes:\n");
            printf("Nome: %s", Cliente[d].nome);

            printf("Telefone: %i\n", *Cliente[d].telefone);

            printf("Endereco: %s", Cliente[d].endereco);
            printf("CPF: %s\n", &Cliente[d].cpf);
            printf("Senha: %i \n\n", *Cliente[d].senha);
            printf("Voce realmente deseja alterar? (Sim/Nao)\n");
            gets(Aresp);

                if (strcmp(Aresp, "SIM") == 0 || strcmp(Aresp, "Sim") == 0 || strcmp(Aresp, "sim") == 0){
                  system("cls");
                  cabecalho();
                  strcpy(Cliente[a].nome, Cliente[d].nome);
                  *Cliente[a].telefone = *Cliente[d].telefone;
                  strcpy(Cliente[a].endereco, Cliente[d].endereco);
                    memcpy(Cliente[a].cpf, Cliente[d].cpf, 12);
                  *Cliente[a].senha =  *Cliente[d].senha;


                  printf("Informacoes alteradas.\n\n");
            printf("Nome: %s", Cliente[a].nome);

            printf("Telefone: %i\n", *Cliente[a].telefone);

            printf("Endereco: %s", Cliente[a].endereco);
            printf("CPF: %s\n", &Cliente[a].cpf);
            printf("Senha: %i \n\n", *Cliente[a].senha);
                }
         if (strcmp(Aresp, "NAO") == 0 || strcmp(Aresp, "Nao") == 0 || strcmp(Aresp, "nao") == 0){
             back = 1;
            system("cls");
            cabecalho();
         }


        }else{
            system("cls");
            cabecalho();
            printf("Senha do Gerente invalida!\n\n");
            exit(0);
        }

    fflush(stdin);
    printf("\nVoce desejar voltar ou sair? (Voltar/Sair)\n");
    gets(volt);
    if (strcmp(volt, "VOLTAR") == 0 || strcmp(volt, "Voltar") == 0 || strcmp(volt, "voltar") == 0)
    {
        back = 1;
    }
    if (strcmp(volt, "SAIR") == 0 || strcmp(volt, "Sair") == 0 || strcmp(volt, "sair") == 0)
    {
        exit(0);
    }
}
void addfundos()
{

        int a;
        float transferencia;
        int Pass;
        int back = 0;
        char volt[7];

        back = 0;
        system("cls");
        cabecalho();
        printf("Digite a senha do Gerente:\n");
        scanf("%i", &Pass);

        if(Pass == gerente){
                system("cls");
                cabecalho();
                fflush(stdin);
                printf("Qual o numero da conta que deseja adicionar fundos: ");
                scanf("%i", &a);
            system("cls");
            cabecalho();
            printf("Saldo da conta atual %.2f\n\n", Conta[a].saldo);
            printf("Qual valor a ser adicionado? (EX: 12.8)\nR$: ");
            scanf("%f", &transferencia);

            system("cls");
            cabecalho();
            Conta[a].saldo = Conta[a].saldo + transferencia;
            printf("SUCESSO! O valor de R$%.2f foi depositado na conta: %.3i\n", transferencia, a);
            printf("Saldo atual da conta: R$%.2f\n\n", Conta[a].saldo);
            Sleep(1800);
        }else{
            system("cls");
            cabecalho();
            printf("Senha do Gerente invalida!\n\n");
            exit(0);
        }

    fflush(stdin);
    printf("\nVoce desejar voltar ou sair? (Voltar/Sair)\n");
    gets(volt);
    if (strcmp(volt, "VOLTAR") == 0 || strcmp(volt, "Voltar") == 0 || strcmp(volt, "voltar") == 0)
    {
        back = 1;
    }
    if (strcmp(volt, "SAIR") == 0 || strcmp(volt, "Sair") == 0 || strcmp(volt, "sair") == 0)
    {
        exit(0);
    }
}
void infoconta()
{
        int a;
        int Pass;
        int back = 0;
        char volt[7];

        back = 0;
        system("cls");
        cabecalho();
        printf("Digite a senha do Gerente:\n");
        scanf("%i", &Pass);

        if(Pass == gerente){
                system("cls");
                cabecalho();
                fflush(stdin);
                printf("Qual o numero da conta que deseja pesquisar:  ");
                scanf("%i", &a);
            system("cls");
            cabecalho();
            printf("Conta: %.3i\n", a);
            printf("Nome: %s", Cliente[a].nome);
            printf("Telefone: %i\n", *Cliente[a].telefone);
            printf("Endereco: %s", Cliente[a].endereco);
            printf("CPF: %s\n", Cliente[a].cpf);
            printf("Momento de criacao da conta: %.2d/%.2d/%.2d as %.2d:%.2d:%.2d\n", Data[a].dia, Data[a].mes, Data[a].ano, Data[a].hora, Data[a].minu, Data[a].seg);
            printf("Senha: %i\n", *Cliente[a].senha);
            printf("Saldo: %.2f \n\n", Conta[a].saldo);

}else{
            system("cls");
            cabecalho();
            printf("Senha do Gerente invalida!\n\n");
            exit(0);
            }

    fflush(stdin);
    printf("\nVoce desejar voltar ou sair? (Voltar/Sair)\n");
    gets(volt);
    if (strcmp(volt, "VOLTAR") == 0 || strcmp(volt, "Voltar") == 0 || strcmp(volt, "voltar") == 0)
    {
        back = 1;
    }
    if (strcmp(volt, "SAIR") == 0 || strcmp(volt, "Sair") == 0 || strcmp(volt, "sair") == 0)
    {
        exit(0);
    }
}
int main()
{
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    int op;
    int back = 0;
    int retorn = 0;


    gerente = 123321;

    strcpy(Cliente[0].nome, "Sidney Faccioli Bueno\n");
    strcpy(Cliente[0].endereco, "Avenida Leonardo da Vinci\n");
    memcpy(Cliente[0].cpf, "46467380827", 12);
    *Cliente[0].senha = 123456;
    *Cliente[0].telefone = 976715466;
    Conta[0].saldo = 100;
    Conta[1].saldo = 50;

    do{
    fflush(stdin);
    system("cls");
    introducao();
    ImprimirCliente(&Cliente);
    Login();
    do{
        retorn = 0;
        back = 0;
        system("cls");
        cabecalho();
        printf("Hoje e dia: %d/%d/%d\n\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900);
        printf("Bem Vindo ao Banco Union, aqui voce nao e apenas nosso cliente, e nosso amigo.\n");
        printf("Caso sua conta tenha alguma problema fale com um de nossos atendentes.\n");
        printf("Escolha uma das opcoes de nosso menu para continuar.\n\n");
        printf("Saldo: %.2f \n\n\n", Conta[i].saldo);
        printf("Menu:\n");
        printf("1 - Transferencia\n");
        printf("2 - Saque\n");
        printf("3 - Editar informacoes\n");
        printf("4 - Cadastrar/Login\n");
        printf("5 - Depositar\n");
        printf("6 - Informacoes de uma conta\n");
        printf("9 - Sair");
        printf("\n\nOPCAO: ");
        scanf("%i", &op);

        switch(op)
        {

        case 1:
            transferir();
            back = 1;
            break;

        case 2:
            saque();
            back = 1;
            break;

        case 3:
            mudarconta();
            back = 1;
            break;

        case 4:
            retorn = 9;
            break;

        case 5:
            addfundos();
            back = 1;
            break;

        case 6:
            infoconta();
            back = 1;
            break;

        case 9:
            exit(0);
        }

        fflush(stdin);
        }while(back == 1);

        }while(retorn == 9);


    return 0;
}

