#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct Cliente{
char nome[30];
char endereco[30];
int telefone[15];
int senha[7];
char cpf[12];
}TCliente;
    TCliente Cliente[100];

void ImprimirCliente(TCliente *Cliente);

#endif // CLIENTE_H_INCLUDED
