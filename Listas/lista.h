#ifndef LISTA_H
#define LISTA_H

typedef struct no{
    int info;
    struct no *prox;
}lista;


lista* inserir (lista *l, int info);
lista *remover (lista *l, int info);
void printa (lista *l);
lista* inverter (lista *l);
lista*concatena (lista *l1, lista *l2);
lista* intercalar (lista *l1, lista *l2);
int vazia(lista*l);


#endif