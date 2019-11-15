#include "cliente.h"

TCliente clientes[10];
int totalClientes=0;

void ImprimirCliente(TCliente *Cliente);
int existeCpf(TCliente cliente);
char* listarCliente();
