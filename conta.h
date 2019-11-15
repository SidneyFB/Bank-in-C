#include "cliente.h"

typedef struct Data{
int dia;
int mes;
int ano;
int hora;
int minu;
int seg;
}TData;
    TData Data[100];

typedef struct Conta{
int numero;
TCliente cliente;
TData dataAbertura;
float saldo;
int ativa;
}TConta;
    TConta Conta[100];

void depositar(TConta conta,float valor);
int debitar(TConta conta, float quantia);
float quantia;
void imprimirConta(TConta conta);
